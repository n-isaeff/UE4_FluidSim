// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BeachSimulation/Public/BeachSimulationActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBeachSimulationActor() {}
// Cross Module References
	BEACHSIMULATION_API UClass* Z_Construct_UClass_ABeachSimulationActor_NoRegister();
	BEACHSIMULATION_API UClass* Z_Construct_UClass_ABeachSimulationActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_BeachSimulation();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	BEACHSIMULATION_API UClass* Z_Construct_UClass_UParticleVisualizerComponent_NoRegister();
	BEACHSIMULATION_API UClass* Z_Construct_UClass_UExternalForceComponent_NoRegister();
	BEACHSIMULATION_API UClass* Z_Construct_UClass_UParticleSpawnComponent_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FBox();
// End Cross Module References
	void ABeachSimulationActor::StaticRegisterNativesABeachSimulationActor()
	{
	}
	UClass* Z_Construct_UClass_ABeachSimulationActor_NoRegister()
	{
		return ABeachSimulationActor::StaticClass();
	}
	struct Z_Construct_UClass_ABeachSimulationActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DomainMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DomainMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ParticleVisualizer_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ParticleVisualizer;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LocalForces_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LocalForces_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_LocalForces;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ParticleSpawners_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ParticleSpawners_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ParticleSpawners;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Domain_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Domain;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_KernelSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_KernelSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GasConst_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_GasConst;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RestDensity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RestDensity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ViscosityConst_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ViscosityConst;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxVelocity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxVelocity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BoundariesFactor_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BoundariesFactor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BoundariesForce_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BoundariesForce;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BoundariesForceRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BoundariesForceRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TimeCoefficient_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TimeCoefficient;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GravityForce_MetaData[];
#endif
		static void NewProp_GravityForce_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_GravityForce;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IntegrationSteps_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_IntegrationSteps;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABeachSimulationActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_BeachSimulation,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABeachSimulationActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BeachSimulationActor.h" },
		{ "ModuleRelativePath", "Public/BeachSimulationActor.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_DomainMesh_MetaData[] = {
		{ "Category", "BeachSimulationActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BeachSimulationActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_DomainMesh = { "DomainMesh", nullptr, (EPropertyFlags)0x0010000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABeachSimulationActor, DomainMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_DomainMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_DomainMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_ParticleVisualizer_MetaData[] = {
		{ "Category", "BeachSimulationActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BeachSimulationActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_ParticleVisualizer = { "ParticleVisualizer", nullptr, (EPropertyFlags)0x0010000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABeachSimulationActor, ParticleVisualizer), Z_Construct_UClass_UParticleVisualizerComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_ParticleVisualizer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_ParticleVisualizer_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_LocalForces_Inner = { "LocalForces", nullptr, (EPropertyFlags)0x0000000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UExternalForceComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_LocalForces_MetaData[] = {
		{ "Category", "BeachSimulationActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BeachSimulationActor.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_LocalForces = { "LocalForces", nullptr, (EPropertyFlags)0x0010008000000009, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABeachSimulationActor, LocalForces), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_LocalForces_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_LocalForces_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_ParticleSpawners_Inner = { "ParticleSpawners", nullptr, (EPropertyFlags)0x0000000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UParticleSpawnComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_ParticleSpawners_MetaData[] = {
		{ "Category", "BeachSimulationActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BeachSimulationActor.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_ParticleSpawners = { "ParticleSpawners", nullptr, (EPropertyFlags)0x0010008000000009, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABeachSimulationActor, ParticleSpawners), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_ParticleSpawners_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_ParticleSpawners_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_Domain_MetaData[] = {
		{ "Category", "BeachSimulationActor" },
		{ "ModuleRelativePath", "Public/BeachSimulationActor.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_Domain = { "Domain", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABeachSimulationActor, Domain), Z_Construct_UScriptStruct_FBox, METADATA_PARAMS(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_Domain_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_Domain_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_KernelSize_MetaData[] = {
		{ "Category", "BeachSimulationActor" },
		{ "ModuleRelativePath", "Public/BeachSimulationActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_KernelSize = { "KernelSize", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABeachSimulationActor, KernelSize), METADATA_PARAMS(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_KernelSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_KernelSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_GasConst_MetaData[] = {
		{ "Category", "BeachSimulationActor" },
		{ "ModuleRelativePath", "Public/BeachSimulationActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_GasConst = { "GasConst", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABeachSimulationActor, GasConst), METADATA_PARAMS(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_GasConst_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_GasConst_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_RestDensity_MetaData[] = {
		{ "Category", "BeachSimulationActor" },
		{ "ModuleRelativePath", "Public/BeachSimulationActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_RestDensity = { "RestDensity", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABeachSimulationActor, RestDensity), METADATA_PARAMS(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_RestDensity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_RestDensity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_ViscosityConst_MetaData[] = {
		{ "Category", "BeachSimulationActor" },
		{ "ModuleRelativePath", "Public/BeachSimulationActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_ViscosityConst = { "ViscosityConst", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABeachSimulationActor, ViscosityConst), METADATA_PARAMS(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_ViscosityConst_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_ViscosityConst_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_MaxVelocity_MetaData[] = {
		{ "Category", "BeachSimulationActor" },
		{ "ModuleRelativePath", "Public/BeachSimulationActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_MaxVelocity = { "MaxVelocity", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABeachSimulationActor, MaxVelocity), METADATA_PARAMS(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_MaxVelocity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_MaxVelocity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_BoundariesFactor_MetaData[] = {
		{ "Category", "BeachSimulationActor" },
		{ "ModuleRelativePath", "Public/BeachSimulationActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_BoundariesFactor = { "BoundariesFactor", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABeachSimulationActor, BoundariesFactor), METADATA_PARAMS(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_BoundariesFactor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_BoundariesFactor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_BoundariesForce_MetaData[] = {
		{ "Category", "BeachSimulationActor" },
		{ "ModuleRelativePath", "Public/BeachSimulationActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_BoundariesForce = { "BoundariesForce", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABeachSimulationActor, BoundariesForce), METADATA_PARAMS(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_BoundariesForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_BoundariesForce_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_BoundariesForceRadius_MetaData[] = {
		{ "Category", "BeachSimulationActor" },
		{ "ModuleRelativePath", "Public/BeachSimulationActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_BoundariesForceRadius = { "BoundariesForceRadius", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABeachSimulationActor, BoundariesForceRadius), METADATA_PARAMS(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_BoundariesForceRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_BoundariesForceRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_TimeCoefficient_MetaData[] = {
		{ "Category", "BeachSimulationActor" },
		{ "ModuleRelativePath", "Public/BeachSimulationActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_TimeCoefficient = { "TimeCoefficient", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABeachSimulationActor, TimeCoefficient), METADATA_PARAMS(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_TimeCoefficient_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_TimeCoefficient_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_GravityForce_MetaData[] = {
		{ "Category", "BeachSimulationActor" },
		{ "ModuleRelativePath", "Public/BeachSimulationActor.h" },
	};
#endif
	void Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_GravityForce_SetBit(void* Obj)
	{
		((ABeachSimulationActor*)Obj)->GravityForce = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_GravityForce = { "GravityForce", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ABeachSimulationActor), &Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_GravityForce_SetBit, METADATA_PARAMS(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_GravityForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_GravityForce_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_IntegrationSteps_MetaData[] = {
		{ "Category", "BeachSimulationActor" },
		{ "ModuleRelativePath", "Public/BeachSimulationActor.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_IntegrationSteps = { "IntegrationSteps", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABeachSimulationActor, IntegrationSteps), METADATA_PARAMS(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_IntegrationSteps_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_IntegrationSteps_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABeachSimulationActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_DomainMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_ParticleVisualizer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_LocalForces_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_LocalForces,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_ParticleSpawners_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_ParticleSpawners,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_Domain,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_KernelSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_GasConst,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_RestDensity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_ViscosityConst,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_MaxVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_BoundariesFactor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_BoundariesForce,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_BoundariesForceRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_TimeCoefficient,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_GravityForce,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABeachSimulationActor_Statics::NewProp_IntegrationSteps,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABeachSimulationActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABeachSimulationActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABeachSimulationActor_Statics::ClassParams = {
		&ABeachSimulationActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ABeachSimulationActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ABeachSimulationActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABeachSimulationActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABeachSimulationActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABeachSimulationActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABeachSimulationActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABeachSimulationActor, 1421903928);
	template<> BEACHSIMULATION_API UClass* StaticClass<ABeachSimulationActor>()
	{
		return ABeachSimulationActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABeachSimulationActor(Z_Construct_UClass_ABeachSimulationActor, &ABeachSimulationActor::StaticClass, TEXT("/Script/BeachSimulation"), TEXT("ABeachSimulationActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABeachSimulationActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
