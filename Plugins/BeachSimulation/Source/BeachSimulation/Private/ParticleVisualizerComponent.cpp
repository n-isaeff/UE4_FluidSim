// Fill out your copyright notice in the Description page of Project Settings.


#include "ParticleVisualizerComponent.h"

UParticleVisualizerComponent::UParticleVisualizerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


void UParticleVisualizerComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


void UParticleVisualizerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UParticleVisualizerComponent::UpdateParticleGeometry(TArray<FParticleRef>* ps)
{
}

