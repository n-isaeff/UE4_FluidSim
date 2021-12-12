// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "GlobalShader.h"
#include "UniformBuffer.h"
#include "RHICommandList.h"
#include "RenderGraphBuilder.h"
#include "RenderGraphUtils.h"
#include "ShaderParameterStruct.h"

#include "CSSimulationParticle.h"

#include "CSSimulationComponent.generated.h"

#define NUM_THREADS_PER_GROUP_X 1024
#define NUM_THREADS_PER_GROUP_Y 1
#define NUM_THREADS_PER_GROUP_Z 1
#define NUM_THREADS_PER_GROUP (NUM_THREADS_PER_GROUP_X * NUM_THREADS_PER_GROUP_Y * NUM_THREADS_PER_GROUP_Z)

#define CS_GRID_USE 1

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FParticleParameters,)
	SHADER_PARAMETER(FVector,		Position)
	SHADER_PARAMETER(FVector,		NewPosition)
	SHADER_PARAMETER(unsigned int,	Type)
	SHADER_PARAMETER(FVector,		Velocity)
	SHADER_PARAMETER(float,			Rho)
	SHADER_PARAMETER(FVector,		Force)
	SHADER_PARAMETER(float,			P)
END_GLOBAL_SHADER_PARAMETER_STRUCT()

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FParticleTypeParameters, )
	SHADER_PARAMETER(float, Mass)
	SHADER_PARAMETER(float, RestDensity)
	SHADER_PARAMETER(float, Viscosity)
	SHADER_PARAMETER(float, GasConst)
	SHADER_PARAMETER(float, BoundariesFriction)
END_GLOBAL_SHADER_PARAMETER_STRUCT()

BEGIN_SHADER_PARAMETER_STRUCT(FBeachSimulationCommonParams,)
	SHADER_PARAMETER(float, DeltaTime)
	SHADER_PARAMETER(float, KernelSize)
	SHADER_PARAMETER(float, MaxVelocity)
	SHADER_PARAMETER(FVector, DomainMin)
	SHADER_PARAMETER(FVector, DomainMax)

	SHADER_PARAMETER_RDG_BUFFER_SRV(StructuredBuffer<FParticleTypeParameters>, ParticleTypes)
	SHADER_PARAMETER_RDG_BUFFER_UAV(RWStructuredBuffer<FParticleParameters>, ParticlesOut)
END_SHADER_PARAMETER_STRUCT()

#if CS_GRID_USE == 1
BEGIN_SHADER_PARAMETER_STRUCT(FBeachSimulationGridParams, )
	SHADER_PARAMETER(int, CellMaxCount)
	SHADER_PARAMETER(FIntVector, Dimensions)
	SHADER_PARAMETER(float, CellSize)

	SHADER_PARAMETER_RDG_BUFFER_UAV(RWStructuredBuffer<int>, Indices)
	SHADER_PARAMETER_RDG_BUFFER_UAV(RWStructuredBuffer<int>, CellCounts)
END_SHADER_PARAMETER_STRUCT()

class FBeachSimulationGridConstructionCS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FBeachSimulationGridConstructionCS)
	SHADER_USE_PARAMETER_STRUCT(FBeachSimulationGridConstructionCS, FGlobalShader)

public:
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_STRUCT(FBeachSimulationCommonParams, Common)
		SHADER_PARAMETER_STRUCT(FBeachSimulationGridParams, Grid)
	END_SHADER_PARAMETER_STRUCT()

public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
	}

	static inline void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);

		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_X"), NUM_THREADS_PER_GROUP_X);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Y"), NUM_THREADS_PER_GROUP_Y);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Z"), NUM_THREADS_PER_GROUP_Z);
		OutEnvironment.SetDefine(TEXT("GRID_USE"), CS_GRID_USE);
	}
};
#endif

class FBeachSimulationPressureCS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FBeachSimulationPressureCS)
	SHADER_USE_PARAMETER_STRUCT(FBeachSimulationPressureCS, FGlobalShader)

public:
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters,)
		SHADER_PARAMETER_STRUCT(FBeachSimulationCommonParams, Common)
#if CS_GRID_USE == 1
		SHADER_PARAMETER_STRUCT(FBeachSimulationGridParams, Grid)
#endif
	END_SHADER_PARAMETER_STRUCT()


public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
	}

	static inline void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);

		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_X"), NUM_THREADS_PER_GROUP_X);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Y"), NUM_THREADS_PER_GROUP_Y);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Z"), NUM_THREADS_PER_GROUP_Z);
		OutEnvironment.SetDefine(TEXT("GRID_USE"), CS_GRID_USE);
	}
};

class FBeachSimulationForcesCS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FBeachSimulationForcesCS)
	SHADER_USE_PARAMETER_STRUCT(FBeachSimulationForcesCS, FGlobalShader)

public:
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_STRUCT(FBeachSimulationCommonParams, Common)
#if CS_GRID_USE == 1
		SHADER_PARAMETER_STRUCT(FBeachSimulationGridParams, Grid)
#endif
	END_SHADER_PARAMETER_STRUCT()


public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
	}

	static inline void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);

		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_X"), NUM_THREADS_PER_GROUP_X);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Y"), NUM_THREADS_PER_GROUP_Y);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Z"), NUM_THREADS_PER_GROUP_Z);
		OutEnvironment.SetDefine(TEXT("GRID_USE"), CS_GRID_USE);
	}
};

class FBeachSimulationIntegrateCS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FBeachSimulationIntegrateCS)
	SHADER_USE_PARAMETER_STRUCT(FBeachSimulationIntegrateCS, FGlobalShader)

public:
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_STRUCT(FBeachSimulationCommonParams, Common)
	END_SHADER_PARAMETER_STRUCT()

public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
}

	static inline void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);

		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_X"), NUM_THREADS_PER_GROUP_X);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Y"), NUM_THREADS_PER_GROUP_Y);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Z"), NUM_THREADS_PER_GROUP_Z);
		OutEnvironment.SetDefine(TEXT("GRID_USE"), CS_GRID_USE);
	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BEACHSIMULATION_API UCSSimulationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCSSimulationComponent();

protected:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	
	static void CopyBufferFromGPU(FRHICommandListImmediate& RHICmdList, TRefCountPtr<FRDGPooledBuffer>& Source, void* Destination, SIZE_T Size);
	void CalculateSimulationStepRDG();

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetDomain(const FVector& Min, const FVector& Max);
	void SpawnParticles(const FVector& Min, const FVector& Max, const FCSParticleType& Type, const FVector& InitialVelocity = { 0.f, 0.f, 0.f });

	TArray<FCSParticle>* GetComputedParticles();
	void SwapParticleBuffers();

public:
	UPROPERTY()
	int ParticlesNumber = 0;

	UPROPERTY(EditAnywhere)
	float TimeStep = 0.01f;

	UPROPERTY(EditAnywhere)
	float KernelSize = 5.f;

	UPROPERTY(EditAnywhere)
	float MaxVelocity = 100.f;

	UPROPERTY(EditAnywhere, Category = "CSGrid")
	int CellParticleCount = 100;

	UPROPERTY(EditAnywhere, Category = "CSGrid")
	float CellSize = 5.f;

	bool ResultsReady = false;
private:
	TRefCountPtr<FRDGPooledBuffer> PooledParticles;
#if CS_GRID_USE
	TRefCountPtr<FRDGPooledBuffer> PooledIndices;
#endif
	TArray<FCSParticle> ParticlesBuff;
	TArray<FCSParticleType> ParticleTypes;
#if CS_GRID_USE
	TArray<int> GridIndices, GridCounts;
#endif
	FVector DomainMin, DomainMax;
	bool Recompute = false, PoolCreated = false;
	float RestDensity = 1;
};
