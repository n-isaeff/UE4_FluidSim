// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "SimulationParticle.h"

#include "ExternalForceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BEACHSIMULATION_API UExternalForceComponent : public UActorComponent
{
	GENERATED_BODY()
private:
	void UpdateForce();

public:	
	UExternalForceComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	//UFUNCTION(CallInEditor)
	void SetForce(const FVector& dir, const FBox& region);

	UFUNCTION(BlueprintCallable)
	void EnableForce();
	UFUNCTION(BlueprintCallable)
	void DisableForce();

	FExternalLocalForceRef GetForceRef();

public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* DirectionMesh;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RegionMesh;

	UPROPERTY(EditAnywhere)
	float Strength = 100;

	UPROPERTY(EditAnywhere)
	bool StartsEnabled = true;

	bool bIsSet = false;
private:
	FExternalLocalForceRef Force;
	float StrengthInner = 0;
};
