#include "ParticleSpawnComponent.h"

UParticleSpawnComponent::UParticleSpawnComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	RegionMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpawnRegion"));
}


void UParticleSpawnComponent::BeginPlay()
{
	Super::BeginPlay();
	if (RegionMesh) RegionMesh->SetVisibility(false);
	if (SpawnAtStart)
		SpawnParticles();
}


void UParticleSpawnComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UParticleSpawnComponent::SpawnParticles()
{
	SpawnQueue.Push({ RegionMesh->GetStaticMesh()->GetBounds().GetBox().TransformBy(RegionMesh->GetComponentTransform()) , InitialVelocity });
}
