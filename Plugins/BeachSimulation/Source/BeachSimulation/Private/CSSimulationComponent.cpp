// Fill out your copyright notice in the Description page of Project Settings.


#include "CSSimulationComponent.h"

IMPLEMENT_GLOBAL_SHADER_PARAMETER_STRUCT(FParticleParameters, "Particle");
IMPLEMENT_GLOBAL_SHADER_PARAMETER_STRUCT(FParticleTypeParameters, "ParticleType");
#if CS_GRID_USE == 1
IMPLEMENT_SHADER_TYPE(, FBeachSimulationGridConstructionCS, TEXT("/BeachSimulationShaders/Private/ParticleSimulation.usf"), TEXT("MainGridBuildShader"), SF_Compute);
#endif
IMPLEMENT_SHADER_TYPE(, FBeachSimulationPressureCS, TEXT("/BeachSimulationShaders/Private/ParticleSimulation.usf"), TEXT("MainPressureShader"), SF_Compute);
IMPLEMENT_SHADER_TYPE(, FBeachSimulationForcesCS, TEXT("/BeachSimulationShaders/Private/ParticleSimulation.usf"), TEXT("MainForcesShader"), SF_Compute);
IMPLEMENT_SHADER_TYPE(, FBeachSimulationIntegrateCS, TEXT("/BeachSimulationShaders/Private/ParticleSimulation.usf"), TEXT("MainIntegrateShader"), SF_Compute);

UCSSimulationComponent::UCSSimulationComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCSSimulationComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCSSimulationComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);

    //PooledParticles.SafeRelease();
}

void UCSSimulationComponent::SetDomain(const FVector& Min, const FVector& Max)
{
    DomainMin = Min;
    DomainMax = Max;
}

void UCSSimulationComponent::SpawnParticles(const FVector& Min, const FVector& Max, const FCSParticleType& Type, const FVector& InitialVelocity)
{
    FVector SpawnDomainMin = Min.ComponentMax(DomainMin), SpawnDomainMax = Max.ComponentMin(DomainMax);

    if (SpawnDomainMax.ComponentMax(SpawnDomainMin) != SpawnDomainMax || SpawnDomainMin == SpawnDomainMax)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, 
                TEXT("No intersection of the spawn region and simulation domain found!"));
        }
        return;
    }
    
    unsigned int TypeIndex = ParticleTypes.Num();
    float step = Type.Mass / Type.RestDensity;
    for (float x = SpawnDomainMin.X; x <= SpawnDomainMax.X; x += step)
    {
        for (float y = SpawnDomainMin.Y; y <= SpawnDomainMax.Y; y += step)
        {
            for (float z = SpawnDomainMin.Z; z <= SpawnDomainMax.Z; z += step)
            {
                FCSParticle p{ {x, y, z}, TypeIndex, InitialVelocity, 0.f, {0.f, 0.f, 0.f}, 0.f };
                ParticlesBuff.Add(p);
            }
        }
    }
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Spawned %i particles!"), (ParticlesBuff.Num() - ParticlesNumber)));
    }
    ParticlesNumber = ParticlesBuff.Num();
    ParticleTypes.Add(Type);
    Recompute = true;
    PoolCreated = false;

}

void UCSSimulationComponent::SwapParticleBuffers()
{
    Recompute = true;
}

TArray<FCSParticle>* UCSSimulationComponent::GetComputedParticles()
{
    return &ParticlesBuff;
}

void UCSSimulationComponent::CopyBufferFromGPU(FRHICommandListImmediate& RHICmdList, TRefCountPtr<FRDGPooledBuffer>& Source, void* Destination, SIZE_T Size)
{
    if (Source.IsValid())
    {
        void* GPUSource = RHICmdList.LockStructuredBuffer(Source->GetStructuredBufferRHI(), 0, Size, RLM_ReadOnly);
        FMemory::Memcpy(Destination, GPUSource, Size);
        RHICmdList.UnlockStructuredBuffer(Source->GetStructuredBufferRHI());
    }
}

void UCSSimulationComponent::CalculateSimulationStepRDG()
{
    if (Recompute && ParticlesBuff.Num() > 0)
    {

        ENQUEUE_RENDER_COMMAND(SimulationShader)
            ([&](FRHICommandListImmediate& RHICmdList)
                {
                    check(IsInRenderingThread());
                    FRDGBuilder GraphBuilder(RHICmdList);
                    FRDGBufferRef ParticlesRef;

                    if (PoolCreated)
                    {
                        ParticlesRef = GraphBuilder.RegisterExternalBuffer(PooledParticles);
                    }
                    else {
                        PoolCreated = true;
                        PooledParticles.SafeRelease();
                        ParticlesRef = CreateStructuredBuffer(
                            GraphBuilder,
                            TEXT("BeachSimParticlesOut"),
                            sizeof(FCSParticle),
                            ParticlesBuff.Num(),
                            ParticlesBuff.GetData(),
                            sizeof(FCSParticle) * ParticlesBuff.Num(),
                            ERDGInitialDataFlags::None);
                    }
                    FRDGBufferUAVRef ParticlesUAVRef = GraphBuilder.CreateUAV(ParticlesRef);

                    FRDGBufferRef ParticleTypesRef = CreateStructuredBuffer(
                        GraphBuilder,
                        TEXT("BeachSimParticleTypes"),
                        sizeof(FCSParticleType),
                        ParticleTypes.Num(),
                        ParticleTypes.GetData(),
                        sizeof(FCSParticleType) * ParticleTypes.Num(), ERDGInitialDataFlags::None);
                    FRDGBufferSRVRef ParticleTypesSRVRef = GraphBuilder.CreateSRV(ParticleTypesRef);

                    FBeachSimulationCommonParams* CommonParameters = GraphBuilder.AllocParameters<FBeachSimulationCommonParams>();
                    CommonParameters->DeltaTime = TimeStep;
                    CommonParameters->KernelSize = KernelSize;
                    CommonParameters->MaxVelocity = MaxVelocity;
                    CommonParameters->ParticleTypes = ParticleTypesSRVRef;
                    CommonParameters->ParticlesOut = ParticlesUAVRef;
                    CommonParameters->DomainMax = DomainMax;
                    CommonParameters->DomainMin = DomainMin;

#if CS_GRID_USE == 1
                    FVector V = DomainMax - DomainMin;
                    V /= CellSize;
                    FIntVector GridDimensions = FIntVector(FMath::Floor(V.X), FMath::Floor(V.Y), FMath::Floor(V.Z));
                    UINT CellNumber = GridDimensions.X * GridDimensions.Y * GridDimensions.Z;
                    UINT IndicesNumber = CellNumber * CellParticleCount;
                    FRDGBufferRef GridIndicesRef;
                    if (GridIndices.Num() != IndicesNumber)
                    {
                        GridIndices.Init(-1, IndicesNumber);
                        GridIndicesRef = CreateStructuredBuffer(
                            GraphBuilder,
                            TEXT("BeachSimGridIndices"),
                            sizeof(int),
                            IndicesNumber,
                            GridIndices.GetData(),
                            IndicesNumber * sizeof(int), ERDGInitialDataFlags::None);
                    }
                    else {
                        GridIndicesRef = GraphBuilder.RegisterExternalBuffer(PooledIndices);
                    }
                    FRDGBufferUAVRef GridIndicesUAV = GraphBuilder.CreateUAV(GridIndicesRef);

                    if (GridCounts.Num() != CellNumber)
                        GridCounts.Init(-1, CellNumber);
                    FRDGBufferRef GridCellCountsRef = CreateStructuredBuffer(
                        GraphBuilder,
                        TEXT("BeachSimGridCellCounts"),
                        sizeof(int),
                        CellNumber,
                        GridCounts.GetData(),
                        CellNumber * sizeof(int), ERDGInitialDataFlags::None);
                    FRDGBufferUAVRef GridCellCountsUAV = GraphBuilder.CreateUAV(GridCellCountsRef);

                    FBeachSimulationGridParams* GridParameters = GraphBuilder.AllocParameters<FBeachSimulationGridParams>();
                    GridParameters->CellSize = CellSize;
                    GridParameters->CellMaxCount = CellNumber;
                    GridParameters->Dimensions = GridDimensions;

                    GridParameters->CellCounts = GridCellCountsUAV;
                    GridParameters->Indices = GridIndicesUAV;

                    FBeachSimulationGridConstructionCS::FParameters* GridConstrParameters = GraphBuilder.AllocParameters<FBeachSimulationGridConstructionCS::FParameters>();
                    GridConstrParameters->Common = *CommonParameters;
                    GridConstrParameters->Grid = *GridParameters;
#endif

                    FBeachSimulationPressureCS::FParameters* PressureParameters = GraphBuilder.AllocParameters<FBeachSimulationPressureCS::FParameters>();
                    PressureParameters->Common = *CommonParameters;
#if CS_GRID_USE == 1
                    PressureParameters->Grid = *GridParameters;
#endif

                    FBeachSimulationForcesCS::FParameters* ForcesParameters = GraphBuilder.AllocParameters<FBeachSimulationForcesCS::FParameters>();
                    ForcesParameters->Common = *CommonParameters;
#if CS_GRID_USE == 1
                    ForcesParameters->Grid = *GridParameters;
#endif

                    FBeachSimulationIntegrateCS::FParameters* IntegrateParameters = GraphBuilder.AllocParameters<FBeachSimulationIntegrateCS::FParameters>();
                    IntegrateParameters->Common = *CommonParameters;

#if CS_GRID_USE == 1
                    TShaderMapRef<FBeachSimulationGridConstructionCS> GridConstrShaderRef(GetGlobalShaderMap(ERHIFeatureLevel::SM5));
                    ValidateShaderParameters(GridConstrShaderRef, *GridConstrParameters);
#endif
                    TShaderMapRef<FBeachSimulationPressureCS> PressureShaderRef(GetGlobalShaderMap(ERHIFeatureLevel::SM5));
                    ValidateShaderParameters(PressureShaderRef, *PressureParameters);
                    TShaderMapRef<FBeachSimulationForcesCS> ForcesShaderRef(GetGlobalShaderMap(ERHIFeatureLevel::SM5));
                    ValidateShaderParameters(ForcesShaderRef, *ForcesParameters);
                    TShaderMapRef<FBeachSimulationIntegrateCS> IntegrateShaderRef(GetGlobalShaderMap(ERHIFeatureLevel::SM5));
                    ValidateShaderParameters(IntegrateShaderRef, *IntegrateParameters);

                    FIntVector ThreadGroupCount{ 1 + ParticlesNumber / (NUM_THREADS_PER_GROUP), 1, 1 };
                    FComputeShaderUtils::AddPass(GraphBuilder, RDG_EVENT_NAME("BeachSimulationGridConstr"), GridConstrShaderRef, GridConstrParameters,
                        ThreadGroupCount);
                    FComputeShaderUtils::AddPass(GraphBuilder, RDG_EVENT_NAME("BeachSimulationPressure"), PressureShaderRef, PressureParameters,
                        ThreadGroupCount);
                    FComputeShaderUtils::AddPass(GraphBuilder, RDG_EVENT_NAME("BeachSimulationForces"), ForcesShaderRef, ForcesParameters,
                        ThreadGroupCount);
                    FComputeShaderUtils::AddPass(GraphBuilder, RDG_EVENT_NAME("BeachSimulationCIntegrate"), IntegrateShaderRef, IntegrateParameters,
                        ThreadGroupCount);
                    GraphBuilder.QueueBufferExtraction(ParticlesRef, &PooledParticles);
#if CS_GRID_USE == 1
                    GraphBuilder.QueueBufferExtraction(GridIndicesRef, &PooledIndices);
#endif
                    GraphBuilder.Execute();

                    //CopyBufferFromGPU(RHICmdList, PooledParticles, (void*)ParticlesBuff.GetData(), ParticlesBuff.Num() * sizeof(FCSParticle));
                });
        Recompute = false;
    }
}

void UCSSimulationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    ResultsReady = false;
    CalculateSimulationStepRDG();
    ResultsReady = true;

}

