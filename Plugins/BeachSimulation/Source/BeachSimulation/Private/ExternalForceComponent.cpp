#include "ExternalForceComponent.h"

UExternalForceComponent::UExternalForceComponent() : Force(new FExternalLocalForce())
{
	PrimaryComponentTick.bCanEverTick = true;
	DirectionMesh = CreateDefaultSubobject<UStaticMeshComponent>("ForceDirMesh");
	RegionMesh = CreateDefaultSubobject<UStaticMeshComponent>("ForceRegionMesh");
}


void UExternalForceComponent::BeginPlay()
{
	Super::BeginPlay();
	if (DirectionMesh) DirectionMesh->SetVisibility(false);
	if (RegionMesh) RegionMesh->SetVisibility(false);
}


void UExternalForceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UExternalForceComponent::SetForce(const FVector& dir, const FBox& region)
{
	Force = FExternalLocalForceRef(new FExternalLocalForce());
	Force->Force = dir;
	Force->Region = region;
}

FExternalLocalForceRef UExternalForceComponent::GetForceRef()
{
	return Force;
}

