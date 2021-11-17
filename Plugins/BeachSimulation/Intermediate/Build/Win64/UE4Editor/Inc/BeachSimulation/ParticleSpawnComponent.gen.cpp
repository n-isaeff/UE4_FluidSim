// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BeachSimulation/Public/ParticleSpawnComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeParticleSpawnComponent() {}
// Cross Module References
	BEACHSIMULATION_API UClass* Z_Construct_UClass_UParticleSpawnComponent_NoRegister();
	BEACHSIMULATION_API UClass* Z_Construct_UClass_UParticleSpawnComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_BeachSimulation();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	DEFINE_FUNCTION(UParticleSpawnComponent::execSpawnParticles)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SpawnParticles();
		P_NATIVE_END;
	}
	void UParticleSpawnComponent::StaticRegisterNativesUParticleSpawnComponent()
	{
		UClass* Class = UParticleSpawnComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SpawnParticles", &UParticleSpawnComponent::execSpawnParticles },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UParticleSpawnComponent_SpawnParticles_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UParticleSpawnComponent_SpawnParticles_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ParticleSpawnComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UParticleSpawnComponent_SpawnParticles_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UParticleSpawnComponent, nullptr, "SpawnParticles", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UParticleSpawnComponent_SpawnParticles_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UParticleSpawnComponent_SpawnParticles_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UParticleSpawnComponent_SpawnParticles()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UParticleSpawnComponent_SpawnParticles_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UParticleSpawnComponent_NoRegister()
	{
		return UParticleSpawnComponent::StaticClass();
	}
	struct Z_Construct_UClass_UParticleSpawnComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RegionMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RegionMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ParticleMass_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ParticleMass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InitialVelocity_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_InitialVelocity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpawnAtStart_MetaData[];
#endif
		static void NewProp_SpawnAtStart_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_SpawnAtStart;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Jitter_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Jitter;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UParticleSpawnComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_BeachSimulation,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UParticleSpawnComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UParticleSpawnComponent_SpawnParticles, "SpawnParticles" }, // 3649232633
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UParticleSpawnComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "ParticleSpawnComponent.h" },
		{ "ModuleRelativePath", "Public/ParticleSpawnComponent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_RegionMesh_MetaData[] = {
		{ "Category", "ParticleSpawnComponent" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ParticleSpawnComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_RegionMesh = { "RegionMesh", nullptr, (EPropertyFlags)0x0010000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UParticleSpawnComponent, RegionMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_RegionMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_RegionMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_ParticleMass_MetaData[] = {
		{ "Category", "ParticleSpawnComponent" },
		{ "ModuleRelativePath", "Public/ParticleSpawnComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_ParticleMass = { "ParticleMass", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UParticleSpawnComponent, ParticleMass), METADATA_PARAMS(Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_ParticleMass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_ParticleMass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_InitialVelocity_MetaData[] = {
		{ "Category", "ParticleSpawnComponent" },
		{ "Comment", "//UPROPERTY(EditAnywhere)\n//float RestDensity = 1.f;\n" },
		{ "ModuleRelativePath", "Public/ParticleSpawnComponent.h" },
		{ "ToolTip", "UPROPERTY(EditAnywhere)\nfloat RestDensity = 1.f;" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_InitialVelocity = { "InitialVelocity", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UParticleSpawnComponent, InitialVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_InitialVelocity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_InitialVelocity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_SpawnAtStart_MetaData[] = {
		{ "Category", "ParticleSpawnComponent" },
		{ "ModuleRelativePath", "Public/ParticleSpawnComponent.h" },
	};
#endif
	void Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_SpawnAtStart_SetBit(void* Obj)
	{
		((UParticleSpawnComponent*)Obj)->SpawnAtStart = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_SpawnAtStart = { "SpawnAtStart", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UParticleSpawnComponent), &Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_SpawnAtStart_SetBit, METADATA_PARAMS(Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_SpawnAtStart_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_SpawnAtStart_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_Jitter_MetaData[] = {
		{ "Category", "ParticleSpawnComponent" },
		{ "ModuleRelativePath", "Public/ParticleSpawnComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_Jitter = { "Jitter", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UParticleSpawnComponent, Jitter), METADATA_PARAMS(Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_Jitter_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_Jitter_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UParticleSpawnComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_RegionMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_ParticleMass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_InitialVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_SpawnAtStart,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UParticleSpawnComponent_Statics::NewProp_Jitter,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UParticleSpawnComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UParticleSpawnComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UParticleSpawnComponent_Statics::ClassParams = {
		&UParticleSpawnComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UParticleSpawnComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UParticleSpawnComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UParticleSpawnComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UParticleSpawnComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UParticleSpawnComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UParticleSpawnComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UParticleSpawnComponent, 918355451);
	template<> BEACHSIMULATION_API UClass* StaticClass<UParticleSpawnComponent>()
	{
		return UParticleSpawnComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UParticleSpawnComponent(Z_Construct_UClass_UParticleSpawnComponent, &UParticleSpawnComponent::StaticClass, TEXT("/Script/BeachSimulation"), TEXT("UParticleSpawnComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UParticleSpawnComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
