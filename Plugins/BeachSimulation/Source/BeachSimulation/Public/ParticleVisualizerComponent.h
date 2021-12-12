// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "SimulationParticle.h"

#include "CSSimulationParticle.h"

#include "ParticleVisualizerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BEACHSIMULATION_API UParticleVisualizerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UParticleVisualizerComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
public:
	virtual void UpdateParticleGeometry(TArray<FParticleRef>* ps);
	virtual void UpdateParticleGeometry(TArray<FCSParticle>* ps);

private:

};
