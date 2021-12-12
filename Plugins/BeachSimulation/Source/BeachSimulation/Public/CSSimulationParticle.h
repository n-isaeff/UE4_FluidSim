#pragma once

#include "CoreMinimal.h"

struct BEACHSIMULATION_API FCSParticle
{
    FVector         Position;
    //FVector         NewPosition;
    unsigned int    Type;
    FVector         Velocity;
    float           Rho;
    FVector         Force;
    float           P;
};

struct BEACHSIMULATION_API FCSParticleType
{
    float Mass;
    float RestDensity;
    float Viscosity;
    float GasConst;
    float BoundariesFriction;
};

