// Fill out your copyright notice in the Description page of Project Settings.


#include "GPUSimulationActor.h"

AGPUSimulationActor::AGPUSimulationActor()
{
	PrimaryActorTick.bCanEverTick = true;
	DomainMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DomainMesh"));

	ParticleVisualizer = CreateDefaultSubobject<UParticleInstancedComponent>(TEXT("ParticleViz"));
	Simulator = CreateDefaultSubobject<UCSSimulationComponent>(TEXT("ParticleSimulator"));

	ParticleTypes.Add(FCSParticleTypeInfo{
			1.f,
			1.f,
			5.f,
			300.f,
			0.5f
		});
}

void AGPUSimulationActor::BeginPlay()
{
	Super::BeginPlay();
	FBox DomainBox = DomainMesh->GetStaticMesh()->GetBounds().GetBox().TransformBy(DomainMesh->GetRelativeTransform());
	Simulator->SetDomain(DomainBox.Min, DomainBox.Max);
	Simulator->SpawnParticles(
		{ -5.0f, -5.0f, -5.0f },
		{ 5.0f,  5.0f,  5.0f },
		{
			ParticleTypes[0].Mass,
			ParticleTypes[0].RestDensity,
			ParticleTypes[0].Viscosity,
			ParticleTypes[0].GasConst,
			ParticleTypes[0].BoundariesFriction,
		},
		{ 0.0f, 0.f, 0.f }
	);
}

void AGPUSimulationActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Simulator->ResultsReady)
	{
		ParticleVisualizer->UpdateParticleGeometry(Simulator->GetComputedParticles());
		Simulator->SwapParticleBuffers();
	}
}

