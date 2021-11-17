#pragma once

#include "CoreMinimal.h"
#include "ParticleVisualizerComponent.h"

#include "Components/InstancedStaticMeshComponent.h"

#include "ParticleInstancedComponent.generated.h"

/**
 * 
 */
UCLASS()
class BEACHSIMULATION_API UParticleInstancedComponent : public UParticleVisualizerComponent
{
	GENERATED_BODY()
	
public:
	UParticleInstancedComponent();

	virtual void UpdateParticleGeometry(TArray<FParticleRef>* ps) override;

protected:
	virtual void BeginPlay() override;

public:
	//UPROPERTY(EditAnywhere)
	UInstancedStaticMeshComponent* ParticleInstances;

	UPROPERTY(EditAnywhere)
	UStaticMesh* BaseParticle;

	UPROPERTY(EditAnywhere)
	UMaterialInstance* Material;

	UPROPERTY(EditAnywhere)
	float ParticleSize = .01f;
};
