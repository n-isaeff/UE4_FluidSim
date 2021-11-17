// Fill out your copyright notice in the Description page of Project Settings.


#include "BeachSimulationActor.h"
#include "Kismet/KismetMathLibrary.h"

// BOUNDARIES_TYPE: 1 - naive negation of the velocity, 2 - reflect velocity 
#define BOUNDARIES_TYPE 3 
// FOREACHPARTICLE_TYPE: 1 - seq, 2 - parallel
#define FOREACHPARTICLE_TYPE 2 
// CLOSESTNEIGHBOR_TYPE: 1 - naive, 2 - uniform grid asds (thread safe - for unsafe version see SimulationParticle.h), 
// 3 - grid with inplace arithmetics (no need to copy neighbor particle pointers), 
// 4 - same as 3 but the neighbors are computed only once per frame (requires #define PARTICLE_STORENEIGHBORS 1 - see SimulationParticle.h) 
#define CLOSESTNEIGHBOR_TYPE 4 
// INTEGRATION_TYPE: 1 - Euler, 2 - leapfrog
#define INTEGRATION_TYPE 1


ABeachSimulationActor::ABeachSimulationActor()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = DomainMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DomainMesh"));
#if INSTANCED_VIS
	ParticleVisualizer = CreateDefaultSubobject<UParticleInstancedComponent>(TEXT("ParticleViz"));
#else
	ParticleVisualizer = CreateDefaultSubobject<UParticleSphereComponent>(TEXT("ParticleViz"));
#endif
	ParticleSpawners.Add(CreateDefaultSubobject<UParticleSpawnComponent>(TEXT("InitialSpawner")));

}

void ABeachSimulationActor::BeginPlay()
{
	Super::BeginPlay();
	InitializedHalfVelocities = false;
	if(DomainMesh) DomainMesh->SetVisibility(false);

	Domain = DomainMesh->GetStaticMesh()->GetBounds().GetBox().TransformBy(DomainMesh->GetRelativeTransform());
	//const auto rl = RootComponent->GetComponentLocation();
	//if (GEngine)
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Root location (%f, %f, %f)"), rl.X, rl.Y, rl.Z));

	//calculate consts
	KernelSize = FMath::Max(0.1f, KernelSize);
	KernelSizeSquared = KernelSize * KernelSize;

	GaussianKernelConst = 315.f / (64.f * UKismetMathLibrary::GetPI() * FMath::Pow(KernelSize, 9.f));
	SpikyKernelConst = 45.f / (UKismetMathLibrary::GetPI() * FMath::Pow(KernelSize, 6.f));
	ViscKernelConst = 45.f / (UKismetMathLibrary::GetPI() * FMath::Pow(KernelSize, 6.f));

#if CLOSESTNEIGHBOR_TYPE >= 2
	ParticlesASDS = FDomainGrid(KernelSize, Domain.Min, Domain.Max);
#endif

	//gravity force
	if (GravityForce)
	{
		ExternalForces.Add(FExternalForceRef(new FGravityForce()));
	}

#if BOUNDARIES_TYPE == 3
	ExternalForces.Add(FExternalForceRef(new FBoudriesForce(BoundariesForceRadius, BoundariesForce, Domain.Min, Domain.Max)));
#endif

	//FVector p = Domain.GetCenter();
	//SpawnParticlesCube(p, 15.f, 13, ParticleMass, 1.f);

}

void ABeachSimulationActor::ForClosestParticles(FParticle* pi, TFunction<void(FParticle*, FParticle*, float)> body, float maxDist)
{
#if CLOSESTNEIGHBOR_TYPE == 1
	//naive approach: cycle though all particles
	for (int j = 0; j < Particles.Num(); j++)
	{
		//FParticleRef pj = Particles[j];
		if (&*Particles[j] == &*pi) continue;
		float distSquared = (pi->Position - Particles[j]->Position).SizeSquared();
		if (distSquared <= maxDist)
		{
			body(pi, &*Particles[j], distSquared);
		}
	}
#elif CLOSESTNEIGHBOR_TYPE == 2
	TArray<FParticle*> ClosestParticles;
	ParticlesASDS.GetNeighborParticles(pi, &ClosestParticles);
	for (int j = 0; j < ClosestParticles.Num(); j++)
	{
		//FParticleRef pj = Particles[j];
		if (ClosestParticles[j] == pi) continue;
		float distSquared = (pi->Position - ClosestParticles[j]->Position).SizeSquared();
		if (distSquared <= maxDist)
		{
			body(pi, ClosestParticles[j], distSquared);
		}
	}
#elif CLOSESTNEIGHBOR_TYPE == 3
	ParticlesASDS.ForNeighborParticles(pi, [&](FParticle* p, FParticle* pj, float dist2)
		{
			if (dist2 <= KernelSizeSquared)
			{
				body(p, pj, dist2);
			}
		});
#elif CLOSESTNEIGHBOR_TYPE == 4
	for (auto* pj : pi->Neighbors)
	{
		if (pi == pj) continue;
		float dist2 = (pi->Position - pj->Position).SizeSquared();
		if (dist2 <= maxDist)
		{
			body(pi, pj, dist2);
		}
	}
#endif
}

void ABeachSimulationActor::ForEachParticle(TFunction<void(FParticle*)> body)
{
#if FOREACHPARTICLE_TYPE == 1
	//naive walk through all particles - may be parallelized
	for (int i = 0; i < Particles.Num(); i++)
	{
		body(&*Particles[i]);
	}
#elif FOREACHPARTICLE_TYPE == 2
	ParallelFor(Particles.Num(), [&](int32 i) 
		{ 
			body(&*Particles[i]); 
		});
#endif
}

void ABeachSimulationActor::ApplyBoundaryConditions(FParticle* pi)
{
#if BOUNDARIES_TYPE == 1
#if FOREACHPARTICLE_TYPE == 2 || CLOSESTNEIGHBOR_TYPE == 2
	FVector p = pi->NewPosition;
#elif 
	FVector p = pi->Position;
#endif
	if (!Domain.IsInside(p))
	{
		pi->Velocity *= -BoundariesFactor;
#if FOREACHPARTICLE_TYPE == 2
		pi->NewPosition = Domain.GetClosestPointTo(p);
#elif 
		pi->Position = Domain.GetClosestPointTo(p);
#endif
	}
#elif BOUNDARIES_TYPE >= 2
#if FOREACHPARTICLE_TYPE == 2 || CLOSESTNEIGHBOR_TYPE == 2
	FVector p = pi->NewPosition;
#elif FOREACHPARTICLE_TYPE == 1 
	FVector p = pi->Position;
#endif

	if (!Domain.IsInsideOrOn(p))
	{
		const FVector e{ 0.0005f };
		FVector Dmin = Domain.Min - e, Dmax = Domain.Max + e;
		if (p.X >= Dmax.X || p.X <= Dmin.X)
			pi->Velocity.X *= -BoundariesFactor;
		if (p.Y >= Dmax.Y || p.Y <= Dmin.Y)
			pi->Velocity.Y *= -BoundariesFactor;
		if (p.Z >= Dmax.Z || p.Z <= Dmin.Z)
			pi->Velocity.Z *= -BoundariesFactor;
		//pi->Velocity *= BoundariesFactor;
#if FOREACHPARTICLE_TYPE == 2 || CLOSESTNEIGHBOR_TYPE == 2
		pi->NewPosition = Domain.GetClosestPointTo(p);
#elif FOREACHPARTICLE_TYPE == 1
		pi->Position = Domain.GetClosestPointTo(p);
#endif
	}

#endif

}

void ABeachSimulationActor::ApplyExternalForces(FParticle* pi)
{
	for (int i = 0; i < ExternalForces.Num(); i++)
	{
		ExternalForces[i]->ApplyForce(pi);
	}

	//for (int i = 0; i < LocalForces.Num(); i++)
	//{
	//	LocalForces[i]->GetForceRef()->ApplyForce(pi);
	//}
}

void ABeachSimulationActor::ComputeDensityPressure()
{
	ForEachParticle([&](FParticle* p) 
		{
			p->Rho = 0;
			ForClosestParticles(p, [&](FParticle* pi, FParticle* pj, float distSquared)
				{
					pi->Rho += pj->Mass * GaussianKernelConst * pow(KernelSizeSquared - distSquared, 3.f);
				}, KernelSizeSquared);
			p->Rho = FMath::Max(p->Rho, RestDensity);
			p->P = GasConst * (p->Rho - RestDensity);
		});
}

void ABeachSimulationActor::ComputeForces()
{
	ForEachParticle([&](FParticle* p)
		{
			FVector Fpi{ 0, 0, 0 };
			FVector Fvi{ 0, 0, 0 };
			ForClosestParticles(p, [&](FParticle* pi, FParticle* pj, float distSquared)
				{
					const FVector rd = (pj->Position - pi->Position); // .GetSafeNormal();
					const FVector r = rd / rd.Size();
					const float 
						dr			= KernelSize - FMath::Sqrt(distSquared),
						spikeyCoeff = dr * dr,
						massRatio	= pj->Mass / pi->Mass,
						pt			= (pi->P + pj->P) / (2.0f * pi->Rho);

					Fpi -= massRatio * pt * spikeyCoeff * r;
					Fvi += massRatio * (pj->Velocity - pi->Velocity) * dr * dr;
					/*if (GEngine)
						GEngine->AddOnScreenDebugMessage(-1, 15., FColor::Yellow, FString::Printf(TEXT("Fv (%f, %f, %f)"), r.X, r.Y, r.Z));*/
				}, KernelSizeSquared);
			/*if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15., FColor::Yellow, FString::Printf(TEXT("Final Fv (%f, %f, %f)"), Fvi.X, Fvi.Y, Fvi.Z));*/
			p->Force = SpikyKernelConst * Fpi + ViscosityConst * ViscKernelConst * Fvi;
			ApplyExternalForces(p);
		});
}

void ABeachSimulationActor::Integrate(float dt)
{
#if INTEGRATION_TYPE == 2
	if (!InitializedHalfVelocities)
	{
		ForEachParticle([&](FParticle* pi)
			{
				pi->HalfVelocity = pi->Velocity + .5f * dt * pi->Force / (pi->Rho * pi->Mass);
			});
		InitializedHalfVelocities = true;
	}
#endif
	ForEachParticle([&](FParticle* pi)
		{
#if INTEGRATION_TYPE == 1
			pi->Velocity += dt * pi->Force / (pi->Rho ); //* pi->Mass
			pi->Velocity = pi->Velocity.GetClampedToMaxSize(MaxVelocity);
#if FOREACHPARTICLE_TYPE == 2 || CLOSESTNEIGHBOR_TYPE == 2
			pi->NewPosition += pi->Velocity * dt;
#else
			pi->Position += pi->Velocity * dt;
#endif
			ApplyBoundaryConditions(pi);
#elif INTEGRATION_TYPE == 2
			const FVector a = pi->Force / (pi->Rho * pi->Mass);
			pi->HalfVelocity += dt * a;
			pi->NewPosition += dt * pi->HalfVelocity;

			pi->Velocity += pi->HalfVelocity + .5f * dt * pi->HalfVelocity;
			pi->Velocity = pi->Velocity.GetClampedToMaxSize(MaxVelocity);

			ApplyBoundaryConditions(pi);
#endif
		});
}

float ABeachSimulationActor::FindIntegrationStep()
{
	float maxv2 = .0, maxc2 = .0, maxa2 = 0.;
	for (int32 i = 0; i < Particles.Num(); i++)
	{
		FParticleRef pi = Particles[i];
		float v2 = pi->Velocity.SizeSquared();
		float a2 = pi->Force.SizeSquared() / (pi->Mass * pi->Mass);
		float c2 = pi->P / pi->Rho;
		maxv2 = FMath::Max(maxv2, v2);
		maxa2 = FMath::Max(maxa2, a2);
		maxc2 = FMath::Max(maxc2, c2);
	}
	float 
		maxv = FMath::Sqrt(maxv2),
		maxc = FMath::Sqrt(maxc2),
		maxa = FMath::Sqrt(maxa2);
	float 
		vStep = KernelSize / FMath::Max(1.f, maxv),
		cStep = KernelSize / maxc,
		aStep = FMath::Sqrt(KernelSize / maxa);
	return FMath::Max(1.f / 24.f, FMath::Min(FMath::Min(vStep, cStep), aStep));
}

void ABeachSimulationActor::UpdateParticles(float DeltaTime)
{
#if CLOSESTNEIGHBOR_TYPE == 4
	ParticlesASDS.UpdateParticleNeighbors();
#endif
	ComputeDensityPressure();
	ComputeForces();
	float dt = FindIntegrationStep();
	for (int i = 0; i < IntegrationSteps; i++)
		Integrate(dt);
#if FOREACHPARTICLE_TYPE == 2 || CLOSESTNEIGHBOR_TYPE == 2
	ForEachParticle([&](FParticle* pi)
		{
#if CLOSESTNEIGHBOR_TYPE >= 2
			const FVector oldPos = pi->Position;
			pi->Swap();
			ParticlesASDS.UpdateParticle(pi, oldPos);
#else
			pi->Swap();
#endif
		});
#endif

	/*if (GEngine)
	{
		double ct = ComputeTime - StartTime, vt = visTime - ComputeTime;
		if(ct > 0.009 || vt > 0.009 || vt > ct)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Spike: (%f, %f)"), ct, vt));
	}*/
}

void ABeachSimulationActor::SpawnParticle(const FVector& position, float mass, const FVector& Vi)
{
	Particles.Add(FParticleRef(new FParticle(position, mass)));
	Particles.Last()->Velocity = Vi;
	ParticlesASDS.InsertParticle(&*Particles[Particles.Num() - 1]);
}

void ABeachSimulationActor::SpawnParticles(const FBox& box, const FVector& Vi, float mass, float jitter)
{
	FBox ValidBox(box.Min.ComponentMax(Domain.Min), box.Max.ComponentMin(Domain.Max));
	if (GEngine) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Yellow, FString::Printf(TEXT("Min: %f %f %f"), ValidBox.Min.X, ValidBox.Min.Y, ValidBox.Min.Z));
		GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Yellow, FString::Printf(TEXT("Max: %f %f %f"), ValidBox.Max.X, ValidBox.Max.Y, ValidBox.Max.Z));
	}
	if (!ValidBox.IsValid) return;
	float dp = FMath::Pow(mass / RestDensity, 1. / 3.f);
	for (float dx = ValidBox.Min.X; dx <= ValidBox.Max.X; dx += dp)
	{
		for (float dy = ValidBox.Min.Y; dy <= ValidBox.Max.Y; dy += dp)
		{
			for (float dz = ValidBox.Min.Z; dz <= ValidBox.Max.Z; dz += dp)
			{
				FVector j(FMath::RandRange(0.f, 1.f), FMath::RandRange(0.f, 1.f), FMath::RandRange(0.f, 1.f));
				j.Normalize();
				SpawnParticle(FVector(dx, dy, dz) + j * jitter, mass, Vi);
			}
		}
	}
}

void ABeachSimulationActor::CheckParticleSpawners()
{
	for (int i = 0; i < ParticleSpawners.Num(); i++)
	{
		UParticleSpawnComponent* s = ParticleSpawners[i];
		while (s->SpawnQueue.Num() > 0)
		{
			auto spawnRequest = s->SpawnQueue.Pop();
			SpawnParticles(spawnRequest.Region, spawnRequest.InitialVelocity, s->ParticleMass, s->Jitter);
		}
	}
}

void ABeachSimulationActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto StartTime = FPlatformTime::Seconds();

	CheckParticleSpawners();
	//float dt = DeltaTime / (float) IntegrationSteps;

	//for(int i = 0; i < IntegrationSteps; i++)
	UpdateParticles(DeltaTime);

	auto ComputeTime = FPlatformTime::Seconds();

	if (ParticleVisualizer)
	{
		ParticleVisualizer->UpdateParticleGeometry(&Particles);
		auto visTime = FPlatformTime::Seconds();
	}
}

void ABeachSimulationActor::SpawnParticlesCube(const FVector& center, float cubeSide, int numSubdiv, float particleMass, float jitter)
{
	float dp = FMath::Max(cubeSide / (float) numSubdiv, FMath::Pow(particleMass / RestDensity, 1./3.f));
	for (float dx = center.X - cubeSide * 0.5f; dx <= center.X + cubeSide * 0.5f; dx += dp)
	{
		for (float dy = center.Y - cubeSide * 0.5f; dy <= center.Y + cubeSide * 0.5f; dy += dp)
		{
			for (float dz = center.Z - cubeSide * 0.5f; dz <= center.Z + cubeSide * 0.5f; dz += dp)
			{
				FVector j(FMath::RandRange(0.f, 1.f), FMath::RandRange(0.f, 1.f), FMath::RandRange(0.f, 1.f));
				j.Normalize();
				SpawnParticle(FVector(dx, dy, dz) + j * jitter, particleMass, { 0, 0, 0 });
			}
		}
	}
}
