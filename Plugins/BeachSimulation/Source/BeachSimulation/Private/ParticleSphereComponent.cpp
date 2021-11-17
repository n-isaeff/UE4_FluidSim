// Fill out your copyright notice in the Description page of Project Settings.


#include "ParticleSphereComponent.h"

UParticleSphereComponent::UParticleSphereComponent()
{
	BaseParticle = CreateDefaultSubobject<UStaticMesh>(TEXT("BaseParticleMesh"));
	Material = CreateDefaultSubobject<UMaterialInstance>(TEXT("BaseParticleMaterial"));
}

void UParticleSphereComponent::UpdateParticleGeometry(TArray<FParticleRef>* ps)
{
	if (ps->Num() > ParticleSpheres.Num())
	{
		for (int i = ParticleSpheres.Num(); i < ps->Num(); i++)
		{
			ParticleSpheres.Add(NewObject<UStaticMeshComponent>(this));
			ParticleSpheres[i]->SetStaticMesh(BaseParticle);
			ParticleSpheres[i]->SetMaterial(0, Material);
			ParticleSpheres[i]->AddLocalTransform(FTransform(FRotator(0, 0, 0), FVector(0.f), FVector(ParticleSize, ParticleSize, ParticleSize)));
			ParticleSpheres[i]->RegisterComponent();
		}
	}
	if (ps->Num() < ParticleSpheres.Num())
	{
		ParticleSpheres.RemoveAt(ps->Num(), ParticleSpheres.Num() - ps->Num());
	}
	for (int i = 0; i < ps->Num(); i++)
	{
		ParticleSpheres[i]->SetWorldLocation((*ps)[i]->Position);
	}
}