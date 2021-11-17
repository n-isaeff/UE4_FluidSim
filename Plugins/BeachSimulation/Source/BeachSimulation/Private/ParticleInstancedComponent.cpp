// Fill out your copyright notice in the Description page of Project Settings.


#include "ParticleInstancedComponent.h"

UParticleInstancedComponent::UParticleInstancedComponent()
{
	BaseParticle = CreateDefaultSubobject<UStaticMesh>(TEXT("BaseParticleMesh"));
	Material = CreateDefaultSubobject<UMaterialInstance>(TEXT("BaseParticleMaterial"));
}

void UParticleInstancedComponent::BeginPlay()
{
	Super::BeginPlay();
	if (!ParticleInstances)
	{
		ParticleInstances = NewObject<UInstancedStaticMeshComponent>(this);
		ParticleInstances->NumCustomDataFloats = 1;
		ParticleInstances->SetStaticMesh(BaseParticle);
		ParticleInstances->SetMaterial(0, Material);
		ParticleInstances->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		ParticleInstances->SetSimulatePhysics(false);

		ParticleInstances->RegisterComponent();
	}
}

void UParticleInstancedComponent::UpdateParticleGeometry(TArray<FParticleRef>* ps)
{
	
	int32 instNum = ParticleInstances->GetInstanceCount();
	if (ps->Num() > instNum)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Adding new insts...")));
		for (int i = instNum; i < ps->Num(); i++)
		{
			ParticleInstances->AddInstanceWorldSpace(FTransform(FRotator(0, 0, 0), FVector(0.f), FVector(ParticleSize, ParticleSize, ParticleSize)));
		}
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Added new insts (%d)!"), ParticleInstances->GetInstanceCount()));
	}
	if (ps->Num() < instNum)
	{
		for (int32 i = ps->Num(); i < instNum; i++)
		{
			ParticleInstances->RemoveInstance(i);
		}
	}
	TArray<FTransform> newPos;
	for (int32 i = 0; i < ps->Num(); i++)
	{
		newPos.Add(FTransform(FRotator(0, 0, 0), (*ps)[i]->Position, FVector(ParticleSize, ParticleSize, ParticleSize)));
	}
	if (!ParticleInstances->BatchUpdateInstancesTransforms(0, newPos, true, false, true))
	{
		/*if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Failed to update particle instances positions")));*/
	}
	//ParticleInstances->
	for (int32 i = 0; i < ps->Num(); i++)
	{
		if (!ParticleInstances->SetCustomDataValue(i, 0, (*ps)[i]->Velocity.SizeSquared() / (*ps)[i]->Rho, true))
		{
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Unable to supply instance data")));
		}
	}
	//ParticleInstances->BatchUpdateInstancesData
	
}
