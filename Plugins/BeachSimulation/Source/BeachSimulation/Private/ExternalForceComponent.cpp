#include "ExternalForceComponent.h"

void UExternalForceComponent::UpdateForce()
{
	if (DirectionMesh->GetStaticMesh() && RegionMesh->GetStaticMesh())
	{
		FVector DefaultDir{ 1.0, 0, 0 };
		FRotator DirRotator = DirectionMesh->GetRelativeTransform().Rotator();
		FVector Dir = (DirRotator.RotateVector(DefaultDir)).GetSafeNormal();
		FBox Region = RegionMesh->GetStaticMesh()->GetBounds().GetBox().TransformBy(RegionMesh->GetComponentTransform());
		SetForce(Dir * Strength, Region);
	}
}

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
	UpdateForce();
	if (!StartsEnabled) DisableForce();
}


void UExternalForceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UExternalForceComponent::SetForce(const FVector& dir, const FBox& region)
{
	if(!bIsSet)
		Force = FExternalLocalForceRef(new FExternalLocalForce());
	Force->Force = dir;
	Force->Region = region;
	bIsSet = true;
}

void UExternalForceComponent::EnableForce()
{
	Strength = StrengthInner;
	UpdateForce();
}

void UExternalForceComponent::DisableForce()
{
	StrengthInner = Strength;
	Strength = 0;
	UpdateForce();
}

FExternalLocalForceRef UExternalForceComponent::GetForceRef()
{
	return Force;
}

