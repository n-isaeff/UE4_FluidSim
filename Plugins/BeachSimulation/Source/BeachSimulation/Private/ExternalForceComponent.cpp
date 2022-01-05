#include "ExternalForceComponent.h"

UExternalForceComponent::UExternalForceComponent() : Force(new FExternalLocalForce())
{
	PrimaryComponentTick.bCanEverTick = true;
	DirectionMesh = CreateDefaultSubobject<UStaticMeshComponent>("ForceDirMesh");
	RegionMesh = CreateDefaultSubobject<UStaticMeshComponent>("ForceRegionMesh");
	DirectionMesh->SetupAttachment(RegionMesh);
}


void UExternalForceComponent::BeginPlay()
{
	Super::BeginPlay();
	if (DirectionMesh) DirectionMesh->SetVisibility(false);
	if (RegionMesh) RegionMesh->SetVisibility(false);
	if (DirectionMesh->GetStaticMesh() && RegionMesh->GetStaticMesh())
	{
		FVector DefaultDir{ 1.0, 0, 0 };
		FRotator DirRotator = DirectionMesh->GetRelativeTransform().Rotator();
		FVector Dir = (DirRotator.RotateVector(DefaultDir)).GetSafeNormal();
		FBox Region = RegionMesh->GetStaticMesh()->GetBounds().GetBox().TransformBy(RegionMesh->GetComponentTransform());
		SetForce(Dir * Strength, Region);
	}
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
	bIsSet = true;
}

FExternalLocalForceRef UExternalForceComponent::GetForceRef()
{
	return Force;
}

