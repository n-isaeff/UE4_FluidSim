// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "Math/Box.h"

#include "ParticleSpawnComponent.generated.h"

struct BEACHSIMULATION_API FSpawnQueueEntry
{
	FBox Region;
	FVector InitialVelocity;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BEACHSIMULATION_API UParticleSpawnComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UParticleSpawnComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SpawnParticles();

public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RegionMesh;

	UPROPERTY(EditAnywhere)
	float ParticleMass = 1.f;

	//UPROPERTY(EditAnywhere)
	//float RestDensity = 1.f;

	UPROPERTY(EditAnywhere)
	FVector InitialVelocity;

	UPROPERTY(EditAnywhere)
	bool SpawnAtStart = true;

	UPROPERTY(EditAnywhere)
	float Jitter = 0.f;
	
	TArray<FSpawnQueueEntry> SpawnQueue;
};
