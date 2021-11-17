// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BeachSimulation/Public/ParticleSphereComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeParticleSphereComponent() {}
// Cross Module References
	BEACHSIMULATION_API UClass* Z_Construct_UClass_UParticleSphereComponent_NoRegister();
	BEACHSIMULATION_API UClass* Z_Construct_UClass_UParticleSphereComponent();
	BEACHSIMULATION_API UClass* Z_Construct_UClass_UParticleVisualizerComponent();
	UPackage* Z_Construct_UPackage__Script_BeachSimulation();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstance_NoRegister();
// End Cross Module References
	void UParticleSphereComponent::StaticRegisterNativesUParticleSphereComponent()
	{
	}
	UClass* Z_Construct_UClass_UParticleSphereComponent_NoRegister()
	{
		return UParticleSphereComponent::StaticClass();
	}
	struct Z_Construct_UClass_UParticleSphereComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ParticleSpheres_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ParticleSpheres_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ParticleSpheres;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseParticle_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BaseParticle;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Material_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Material;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ParticleSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ParticleSize;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UParticleSphereComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UParticleVisualizerComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_BeachSimulation,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UParticleSphereComponent_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ParticleSphereComponent.h" },
		{ "ModuleRelativePath", "Public/ParticleSphereComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_ParticleSpheres_Inner = { "ParticleSpheres", nullptr, (EPropertyFlags)0x0000000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_ParticleSpheres_MetaData[] = {
		{ "Category", "ParticleSphereComponent" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ParticleSphereComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_ParticleSpheres = { "ParticleSpheres", nullptr, (EPropertyFlags)0x0010008000000009, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UParticleSphereComponent, ParticleSpheres), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_ParticleSpheres_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_ParticleSpheres_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_BaseParticle_MetaData[] = {
		{ "Category", "ParticleSphereComponent" },
		{ "ModuleRelativePath", "Public/ParticleSphereComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_BaseParticle = { "BaseParticle", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UParticleSphereComponent, BaseParticle), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_BaseParticle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_BaseParticle_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_Material_MetaData[] = {
		{ "Category", "ParticleSphereComponent" },
		{ "ModuleRelativePath", "Public/ParticleSphereComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_Material = { "Material", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UParticleSphereComponent, Material), Z_Construct_UClass_UMaterialInstance_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_Material_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_Material_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_ParticleSize_MetaData[] = {
		{ "Category", "ParticleSphereComponent" },
		{ "ModuleRelativePath", "Public/ParticleSphereComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_ParticleSize = { "ParticleSize", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UParticleSphereComponent, ParticleSize), METADATA_PARAMS(Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_ParticleSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_ParticleSize_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UParticleSphereComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_ParticleSpheres_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_ParticleSpheres,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_BaseParticle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_Material,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UParticleSphereComponent_Statics::NewProp_ParticleSize,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UParticleSphereComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UParticleSphereComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UParticleSphereComponent_Statics::ClassParams = {
		&UParticleSphereComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UParticleSphereComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UParticleSphereComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UParticleSphereComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UParticleSphereComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UParticleSphereComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UParticleSphereComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UParticleSphereComponent, 3512044894);
	template<> BEACHSIMULATION_API UClass* StaticClass<UParticleSphereComponent>()
	{
		return UParticleSphereComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UParticleSphereComponent(Z_Construct_UClass_UParticleSphereComponent, &UParticleSphereComponent::StaticClass, TEXT("/Script/BeachSimulation"), TEXT("UParticleSphereComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UParticleSphereComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
