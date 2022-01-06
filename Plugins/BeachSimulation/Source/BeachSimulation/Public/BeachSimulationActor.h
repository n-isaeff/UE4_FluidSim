// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Math/Box.h"
#include "ExternalForceComponent.h"
#include "ParticleSpawnComponent.h"
#define INSTANCED_VIS 1
#if !INSTANCED_VIS
#include "ParticleSphereComponent.h"
#else
#include "ParticleInstancedComponent.h"
#endif

#include "BeachSimulationActor.generated.h"

USTRUCT()
struct BEACHSIMULATION_API FParticleTypeInfo
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
class BEACHSIMULATION_API ABeachSimulationActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ABeachSimulationActor();

protected:
	virtual void BeginPlay() override;

private:
	/**
	* Cycles through the particles whose distance to pi is less than maxDist and applies body
	*/
	void ForClosestParticles(FParticle* pi, TFunction<void(FParticle*, FParticle*, const FParticleTypeInfoInner&, float)> body, float maxDist);
	/**
	* Applies independant operation body to every particle
	*/
	void ForEachParticle(TFunction<void(FParticle*, const FParticleTypeInfoInner&)> body);

	/** Simulation functions (as described in https://lucasschuermann.com/writing/implementing-sph-in-2d) **/
	void ApplyBoundaryConditions(FParticle* pi, const FParticleTypeInfoInner& info);
	void ApplyExternalForces(FParticle* pi, const FParticleTypeInfoInner& info);

	void ComputeDensityPressure();
	void ComputeForces();
	void Integrate(float dt);

	float FindIntegrationStep();

	void UpdateParticles(float DeltaTime);
	/****/

	void SpawnParticle(const FVector& position, char type, const FVector& Fi);
	void SpawnParticles(const FBox& box, const FVector& Fi, char type, float jitter);
	void CheckParticleSpawners();
public:	
	virtual void Tick(float DeltaTime) override;

	void SpawnParticlesCube(const FVector& center, float cubeSide, int numSubdiv, char type, float jitter = 0.0f);

public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* DomainMesh;

	UPROPERTY(EditAnywhere)
	UParticleVisualizerComponent* ParticleVisualizer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UExternalForceComponent *> LocalForces;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UParticleSpawnComponent*> ParticleSpawners;

	UPROPERTY(EditAnywhere)
	FBox Domain;

	UPROPERTY(EditAnywhere)
	float KernelSize;

	/*UPROPERTY(EditAnywhere)
	float GasConst;

	UPROPERTY(EditAnywhere)
	float RestDensity;

	UPROPERTY(EditAnywhere)
	float ViscosityConst;*/

	UPROPERTY(EditAnywhere)
	float MaxVelocity;

	UPROPERTY(EditAnywhere)
	float BoundariesFactor;

	UPROPERTY(EditAnywhere)
	float BoundariesForce;

	UPROPERTY(EditAnywhere)
	float BoundariesForceRadius;

	UPROPERTY(EditAnywhere)
	bool GravityForce = true;

	UPROPERTY(EditAnywhere)
	float TimeStep = 1.f / 24.f;

	UPROPERTY(EditAnywhere)
	int NumberStepsPerFrame = 2;

	UPROPERTY(EditAnywhere)
	TArray<FParticleTypeInfo> ParticleTypeConsts;
private:
	float KernelSizeSquared;
	float GaussianKernelConst;
	float SpikyKernelConst;
	float ViscKernelConst;

	TArray<FExternalForceRef> ExternalForces;
	//naive data structure for particles
	TArray<FParticleRef> Particles;
	TArray<FParticleTypeInfoInner> ParticleTypes;

	FDomainGrid ParticlesASDS;

	bool InitializedHalfVelocities = false;
	FParticleTypeInfoInner WaterInfo;
	FParticleTypeInfoInner SandInfo;
	FBox DomainTrimmed;
};
