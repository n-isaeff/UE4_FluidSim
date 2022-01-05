#include "..\Public\SimulationParticle.h"

void FExternalForce::ApplyForce(FParticle* p, const float mass)
{
	p->Force += Force;
}

FParticle::FParticle(const FVector& pos, char t) : Position{ pos }, NewPosition{ pos }, Type{ t }
{
}


void FGravityForce::ApplyForce(FParticle* p, const float mass)
{
	p->Force += Force * mass * p->Rho;
}

void FDomainGridCell::InsertParticle(FParticle* p)
{
#ifdef DOMAINGRID_ASYNC 
	FScopeLock lock(&*CellLockObject);
#endif
	Particles.push_back(p);
}

void FDomainGridCell::RemoveParticle(FParticle* p)
{
#ifdef DOMAINGRID_ASYNC 
	FScopeLock lock(&*CellLockObject);
#endif
	for (int32 i = 0; i < Particles.size(); i++)
	{
		if (&*p == &*Particles[i])
		{
			Particles.erase(Particles.begin() + i);
			break;
		}
	}
}

void FDomainGridCell::GetParticles(TArray<FParticle*>* ps)
{
	for (int32 i = 0; i < Particles.size(); i++)
	{
		ps->Add(&*Particles[i]);
	}
}

FDomainGrid::FDomainGrid() : CellSize{0}, MinPosition{0}, GridSize{0}
{
}

FDomainGrid::FDomainGrid(float kernelSize, const FVector& Min, const FVector& Max) : CellSize{ kernelSize }, MinPosition{ Min }, InvCellSize{ 1.f / kernelSize }
{

	FVector V = Max - Min;
	GridSize = {
		FMath::Floor(V.X / kernelSize) + 1,
		FMath::Floor(V.Y / kernelSize) + 1,
		FMath::Floor(V.Z / kernelSize) + 1
	};

	Grid.reserve(GridSize.X);
	for (int x = 0; x < GridSize.X; x++)
	{
		Grid.push_back(std::vector<std::vector<FDomainGridCell>>());
		Grid[x].reserve(GridSize.Y);
		for (int y = 0; y < GridSize.Y; y++)
		{
			Grid[x].push_back(std::vector<FDomainGridCell>());
			Grid[x][y].reserve(GridSize.Z);
			for (int z = 0; z < GridSize.Z; z++)
			{
				Grid[x][y].push_back(FDomainGridCell());
			}
		}
	}
}

void FDomainGrid::InsertParticle(FParticle* p)
{
	GetCell(GetCellIndex(p->Position))->InsertParticle(p);
}

void FDomainGrid::RemoveParticle(FParticle* p)
{
	GetCell(GetCellIndex(p->Position))->RemoveParticle(p);
}

void FDomainGrid::RemoveParticleByRef(FParticle* p, const FVector& position)
{
	GetCell(GetCellIndex(position))->RemoveParticle(p);
}

void FDomainGrid::UpdateParticle(FParticle* p, const FVector& oldPosition)
{
	if (GetCellIndex(oldPosition) == GetCellIndex(p->Position)) return;
	RemoveParticleByRef(p, oldPosition);
	InsertParticle(p);
}

void FDomainGrid::GetNeighborParticles(FParticle* p, TArray<FParticle*>* ps)
{
	const auto Cp = GetCellIndex(p->Position);
	const FIntVector Cmin = {
		FMath::Clamp(Cp.X - 1, 0, (int)GridSize.X - 1),
		FMath::Clamp(Cp.Y - 1, 0, (int)GridSize.Y - 1),
		FMath::Clamp(Cp.Z - 1, 0, (int)GridSize.Z - 1)
	};

	const FIntVector Cmax = {
		FMath::Clamp(Cp.X + 1, 0, (int)GridSize.X - 1),
		FMath::Clamp(Cp.Y + 1, 0, (int)GridSize.Y - 1),
		FMath::Clamp(Cp.Z + 1, 0, (int)GridSize.Z - 1)
	};
	for (int x = Cmin.X; x <= Cmax.X; x++)
	{
		for (int y = Cmin.Y; y <= Cmax.Y; y++)
		{
			for (int z = Cmin.Z; z <= Cmax.Z; z++)
			{
				GetCell({ x, y, z })->GetParticles(ps);
			}
		}
	}
}

void FDomainGrid::ForNeighborParticles(FParticle* pi, TFunction<void(FParticle*, FParticle*, float)> body, float maxDist2)
{
	const auto Cp = GetCellIndex(pi->Position);
	const FIntVector Cmin = {
		FMath::Clamp(Cp.X - 1, 0, (int)GridSize.X - 1),
		FMath::Clamp(Cp.Y - 1, 0, (int)GridSize.Y - 1),
		FMath::Clamp(Cp.Z - 1, 0, (int)GridSize.Z - 1)
	};

	const FIntVector Cmax = {
		FMath::Clamp(Cp.X + 1, 0, (int)GridSize.X - 1),
		FMath::Clamp(Cp.Y + 1, 0, (int)GridSize.Y - 1),
		FMath::Clamp(Cp.Z + 1, 0, (int)GridSize.Z - 1)
	};
	for (int x = Cmin.X; x <= Cmax.X; x++)
	{
		for (int y = Cmin.Y; y <= Cmax.Y; y++)
		{
			for (int z = Cmin.Z; z <= Cmax.Z; z++)
			{
				auto* Cell = GetCell({ x, y, z });
				for (auto* pj : Cell->Particles)
				{
					if (pi != pj)
					{
						const float dist2 = (pi->Position - pj->Position).SizeSquared();
						if (dist2 <= maxDist2)
						{
							body(pi, pj, dist2);
						}
					}
				}
			}
		}
	}
}

#if PARTICLE_STORENEIGHBORS == 1
void FDomainGrid::UpdateParticleNeighbors()
{
	ForEachCell([&](const FIntVector& ci)
		{
			auto* c = GetCell(ci);
			for (auto* pi : c->Particles)
			{
				pi->Neighbors.clear();
				ForCellNeighbors(ci, [&](FDomainGridCell* cj)
					{
						pi->Neighbors.insert(pi->Neighbors.end(), cj->Particles.begin(), cj->Particles.end());
					});
			}
		});
}
#endif
FIntVector FDomainGrid::GetCellIndex(const FVector& position)
{
	FVector trimmed = ((position - MinPosition) * InvCellSize).BoundToBox({ 0,0,0 }, GridSize); //  .GetMin(GridSize);
	return { FMath::FloorToInt(trimmed.X), FMath::FloorToInt(trimmed.Y), FMath::FloorToInt(trimmed.Z) };
}

FDomainGridCell* FDomainGrid::GetCell(const FIntVector& index)
{
	return &Grid[index.X][index.Y][index.Z];
}

void FDomainGrid::ForCellNeighbors(const FIntVector& index, TFunction<void(FDomainGridCell*)> body)
{
	const auto Cp = index;
	const FIntVector Cmin = {
		FMath::Clamp(Cp.X - 1, 0, (int)GridSize.X - 1),
		FMath::Clamp(Cp.Y - 1, 0, (int)GridSize.Y - 1),
		FMath::Clamp(Cp.Z - 1, 0, (int)GridSize.Z - 1)
	};

	const FIntVector Cmax = {
		FMath::Clamp(Cp.X + 1, 0, (int)GridSize.X - 1),
		FMath::Clamp(Cp.Y + 1, 0, (int)GridSize.Y - 1),
		FMath::Clamp(Cp.Z + 1, 0, (int)GridSize.Z - 1)
	};
	for (int x = Cmin.X; x <= Cmax.X; x++)
	{
		for (int y = Cmin.Y; y <= Cmax.Y; y++)
		{
			for (int z = Cmin.Z; z <= Cmax.Z; z++)
			{
				auto* Cell = GetCell({ x, y, z });
				body(Cell);
			}
		}
	}
}

void FDomainGrid::ForEachCell(TFunction<void(const FIntVector&)> foo)
{
	for (int x = 0; x < GridSize.X; x++)
	{
		for (int y = 0; y < GridSize.Y; y++)
		{
			for (int z = 0; z < GridSize.Z; z++)
			{
				foo({ x, y, z });
			}
		}
	}
}

void FExternalLocalForce::ApplyForce(FParticle* p, const float mass)
{
	if (Region.IsInside(p->Position))
	{
		p->Force += Force;
	}
}
//
//void FPlaneProximityForce::ApplyForce(FParticle* p)
//{
//	float coef = Radius - FMath::Clamp(FMath::Abs(FVector::DotProduct(p->Position, Normal) - Offset), 0.f, Radius);
//	//if (GEngine)
//	//	GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Yellow, FString::Printf(TEXT("%f"), coef));
//	p->Force += M * coef;
//}

void FBoudriesForce::ApplyForce(FParticle* p, const float mass)
{
	const FVector pos = p->Position;
	const FVector Dmin = (pos - Min).GetAbs(), Dmax = (pos - Max).GetAbs();
	if (Dmin.X < Radius)
	{
		p->Force += (Dmin.X) * Strength * FVector(1, 0, 0) / Radius;
	}
	if (Dmax.X < Radius)
	{
		p->Force += (Dmax.X) * Strength * FVector(-1, 0, 0) / Radius;
	}

	if (Dmin.Y < Radius)
	{
		p->Force += (Dmin.Y) * Strength * FVector(0, 1, 0) / Radius;
	}
	if (Dmax.Y < Radius)
	{
		p->Force += (Dmax.Y) * Strength * FVector(0, -1, 0) / Radius;
	}

	if (Dmin.Z < Radius)
	{
		p->Force += (Dmin.Z) * Strength * FVector(0, 0, 1) / Radius;
	}
	if (Dmax.Z < Radius)
	{
		p->Force += (Dmax.Z) * Strength * FVector(0, 0, -1) / Radius;
	}
}

void FParticleTypeInfoInner::CalculateConsts()
{
	InvMass = 1 / Mass;
	InvMass2 = InvMass * InvMass;
}
