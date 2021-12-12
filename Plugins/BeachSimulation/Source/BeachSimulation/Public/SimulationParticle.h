#pragma once

#include "CoreMinimal.h"
#include "Math/Box.h"

#include <vector>

// Inspired by https://github.com/rlguy/SPHFluidSim

#define DOMAINGRID_ASYNC 1

#define PARTICLE_STORENEIGHBORS 1
#define PARTICLE_HALFSTEP 0

struct BEACHSIMULATION_API FParticleTypeInfoInner
{
	float Mass, RestDensity, Viscosity, GasConst, BoundariesFriction;
	FParticleTypeInfoInner() {}
	inline FParticleTypeInfoInner(float m, float rho, float v, float g, float b)
		: Mass{ m }
		, RestDensity{ rho }
		, Viscosity{ v }
		, GasConst{ g }
		, BoundariesFriction{ b }
	{}

	void CalculateConsts();
	float InvMass, InvMass2;
};

struct BEACHSIMULATION_API FParticle
{
	FVector NewPosition = { 0.f, 0.f, 0.f }, Position, Velocity = { 0.f, 0.f, 0.f }, Force = { 0.f, 0.f, 0.f };
#if PARTICLE_HALFSTEP == 1
	FVector HalfVelocity = { 0.f, 0.f, 0.f };
#endif
	float Rho = 0.f, P = 0.f; // , Mass = 1.f;
	char Type = 0;

#if PARTICLE_STORENEIGHBORS == 1
	std::vector<FParticle*> Neighbors;
#endif

	FParticle(const FVector& pos, char t);
	inline void Swap() { Position = NewPosition; }

};

typedef TSharedRef<FParticle, ESPMode::ThreadSafe> FParticleRef;

struct BEACHSIMULATION_API FExternalForce
{
	FVector Force;
	FExternalForce() {};
	inline FExternalForce(const FVector& f) : Force{ f } {};
	virtual void ApplyForce(FParticle* p, const float mass);
};

typedef TSharedRef<FExternalForce> FExternalForceRef;

struct BEACHSIMULATION_API FGravityForce : public FExternalForce
{
	inline FGravityForce() : FExternalForce(FVector(0.f, 0.f, -9.8f)) {}

	virtual void ApplyForce(FParticle* p, const float mass) override;
};


struct BEACHSIMULATION_API FBoudriesForce : public FExternalForce
{
	float Radius, Strength;
	FVector Min, Max;
	FBoudriesForce(float r, float s, const FVector& min, const FVector& max) : Radius{ r }, Strength{ s }, Min{ min }, Max{ max }{}

	virtual void ApplyForce(FParticle* p, const float mass) override;
};

struct BEACHSIMULATION_API FExternalLocalForce : public FExternalForce
{
	FBox Region;

	virtual void ApplyForce(FParticle* p, const float mass) override;
};

typedef TSharedRef<FExternalLocalForce> FExternalLocalForceRef;

struct BEACHSIMULATION_API FDomainGridCell
{
	std::vector<FParticle*> Particles;
#ifdef DOMAINGRID_ASYNC
	TSharedRef<FCriticalSection> CellLockObject;

	FDomainGridCell() : CellLockObject{ TSharedRef<FCriticalSection>(new FCriticalSection())} { }

#endif

	void InsertParticle(FParticle* p);
	void RemoveParticle(FParticle* p);
	void GetParticles(TArray<FParticle*>* ps);
};

typedef std::vector<std::vector<std::vector<FDomainGridCell>>> GridArray3D;

struct BEACHSIMULATION_API FDomainGrid
{
	FDomainGrid();
	FDomainGrid(float kernelSize, const FVector& Min, const FVector& Max);

	void InsertParticle(FParticle* p);
	void RemoveParticle(FParticle* p);
	void RemoveParticleByRef(FParticle* p, const FVector& position);
	void UpdateParticle(FParticle* p, const FVector& oldPosition);
	void GetNeighborParticles(FParticle* p, TArray<FParticle*>* ps);
	void ForNeighborParticles(FParticle* p, TFunction<void(FParticle*, FParticle*, float)> body, float maxDist2);

#if PARTICLE_STORENEIGHBORS == 1
	void UpdateParticleNeighbors();
#endif
private:
	FIntVector GetCellIndex(const FVector& position);
	FDomainGridCell* GetCell(const FIntVector& index);
	void ForCellNeighbors(const FIntVector& index, TFunction<void(FDomainGridCell*)> body);
	void ForEachCell(TFunction<void(const FIntVector&)> foo);

public:
	float CellSize;
	FVector MinPosition;
	FVector GridSize;
	GridArray3D Grid;

private:
	float InvCellSize;
};
