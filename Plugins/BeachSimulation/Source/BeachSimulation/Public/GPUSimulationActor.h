// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ParticleInstancedComponent.h"
#include "CSSimulationComponent.h"

#include "GPUSimulationActor.generated.h"

USTRUCT()
struct BEACHSIMULATION_API FCSParticleTypeInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		float Mass;
	UPROPERTY(EditAnywhere)
		float RestDensity;
	UPROPERTY(EditAnywhere)
		float Viscosity;
	UPROPERTY(EditAnywhere)
		float GasConst;
	UPROPERTY(EditAnywhere)
		float BoundariesFriction;
};

UCLASS()
class BEACHSIMULATION_API AGPUSimulationActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AGPUSimulationActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
	UParticleVisualizerComponent* ParticleVisualizer;

	UPROPERTY(EditAnywhere)
	UCSSimulationComponent* Simulator;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* DomainMesh;

	UPROPERTY(EditANywhere)
	TArray<FCSParticleTypeInfo> ParticleTypes;
};
