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
	void ForClosestParticles(FParticle* pi, TFunction<void(FParticle*, FParticle*, float)> body, float maxDist);
	/**
	* Applies independant operation body to every particle
	*/
	void ForEachParticle(TFunction<void(FParticle*)> body);

	/** Simulation functions (as described in https://lucasschuermann.com/writing/implementing-sph-in-2d) **/
	void ApplyBoundaryConditions(FParticle* pi);
	void ApplyExternalForces(FParticle* pi);

	void ComputeDensityPressure();
	void ComputeForces();
	void Integrate(float dt);

	float FindIntegrationStep();

	void UpdateParticles(float DeltaTime);
	/****/

	void SpawnParticle(const FVector& position, float mass, const FVector& Fi);
	void SpawnParticles(const FBox& box, const FVector& Fi, float mass, float jitter);
	void CheckParticleSpawners();
public:	
	virtual void Tick(float DeltaTime) override;

	void SpawnParticlesCube(const FVector& center, float cubeSide, int numSubdiv, float particleMass, float jitter = 0.0f);

public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* DomainMesh;

	UPROPERTY(EditAnywhere)
	UParticleVisualizerComponent* ParticleVisualizer;

	UPROPERTY(EditAnywhere)
	TArray<UExternalForceComponent *> LocalForces;

	UPROPERTY(EditAnywhere)
	TArray<UParticleSpawnComponent*> ParticleSpawners;

	UPROPERTY(EditAnywhere)
	FBox Domain;

	UPROPERTY(EditAnywhere)
	float KernelSize;

	UPROPERTY(EditAnywhere)
	float GasConst;

	UPROPERTY(EditAnywhere)
	float RestDensity;

	UPROPERTY(EditAnywhere)
	float ViscosityConst;

	UPROPERTY(EditAnywhere)
	float MaxVelocity;

	UPROPERTY(EditAnywhere)
	float BoundariesFactor;

	UPROPERTY(EditAnywhere)
	float BoundariesForce;

	UPROPERTY(EditAnywhere)
	float BoundariesForceRadius;

	UPROPERTY(EditAnywhere)
	float TimeCoefficient = 1;

	UPROPERTY(EditAnywhere)
	bool GravityForce = true;

	UPROPERTY(EditAnywhere)
	int IntegrationSteps = 2;

	
private:
	float KernelSizeSquared;
	float GaussianKernelConst;
	float SpikyKernelConst;
	float ViscKernelConst;

	TArray<FExternalForceRef> ExternalForces;
	//naive data structure for particles
	TArray<FParticleRef> Particles;

	FDomainGrid ParticlesASDS;

	bool InitializedHalfVelocities = false;
};
