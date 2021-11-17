// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ParticleVisualizerComponent.h"
#include "ParticleSphereComponent.generated.h"

UCLASS()
class BEACHSIMULATION_API UParticleSphereComponent : public UParticleVisualizerComponent
{
	GENERATED_BODY()

public:
	UParticleSphereComponent();

	virtual void UpdateParticleGeometry(TArray<FParticleRef>* ps) override;
	
public:
	UPROPERTY(EditAnywhere)
	TArray<UStaticMeshComponent*> ParticleSpheres;

	UPROPERTY(EditAnywhere)
	UStaticMesh* BaseParticle;

	UPROPERTY(EditAnywhere)
	UMaterialInstance* Material;

	UPROPERTY(EditAnywhere)
	float ParticleSize = .01f;
};
