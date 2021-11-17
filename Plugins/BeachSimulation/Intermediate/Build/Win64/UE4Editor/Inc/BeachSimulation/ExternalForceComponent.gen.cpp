// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BeachSimulation/Public/ExternalForceComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeExternalForceComponent() {}
// Cross Module References
	BEACHSIMULATION_API UClass* Z_Construct_UClass_UExternalForceComponent_NoRegister();
	BEACHSIMULATION_API UClass* Z_Construct_UClass_UExternalForceComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_BeachSimulation();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FBox();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UExternalForceComponent::execSetForce)
	{
		P_GET_STRUCT_REF(FVector,Z_Param_Out_dir);
		P_GET_STRUCT_REF(FBox,Z_Param_Out_region);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetForce(Z_Param_Out_dir,Z_Param_Out_region);
		P_NATIVE_END;
	}
	void UExternalForceComponent::StaticRegisterNativesUExternalForceComponent()
	{
		UClass* Class = UExternalForceComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetForce", &UExternalForceComponent::execSetForce },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics
	{
		struct ExternalForceComponent_eventSetForce_Parms
		{
			FVector dir;
			FBox region;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_dir_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_dir;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_region_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_region;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics::NewProp_dir_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics::NewProp_dir = { "dir", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ExternalForceComponent_eventSetForce_Parms, dir), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics::NewProp_dir_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics::NewProp_dir_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics::NewProp_region_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics::NewProp_region = { "region", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ExternalForceComponent_eventSetForce_Parms, region), Z_Construct_UScriptStruct_FBox, METADATA_PARAMS(Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics::NewProp_region_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics::NewProp_region_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics::NewProp_dir,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics::NewProp_region,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/ExternalForceComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UExternalForceComponent, nullptr, "SetForce", nullptr, nullptr, sizeof(ExternalForceComponent_eventSetForce_Parms), Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UExternalForceComponent_SetForce()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UExternalForceComponent_SetForce_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UExternalForceComponent_NoRegister()
	{
		return UExternalForceComponent::StaticClass();
	}
	struct Z_Construct_UClass_UExternalForceComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DirectionMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DirectionMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RegionMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RegionMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UExternalForceComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_BeachSimulation,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UExternalForceComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UExternalForceComponent_SetForce, "SetForce" }, // 4213037787
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UExternalForceComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "ExternalForceComponent.h" },
		{ "ModuleRelativePath", "Public/ExternalForceComponent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UExternalForceComponent_Statics::NewProp_DirectionMesh_MetaData[] = {
		{ "Category", "ExternalForceComponent" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ExternalForceComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UExternalForceComponent_Statics::NewProp_DirectionMesh = { "DirectionMesh", nullptr, (EPropertyFlags)0x0010000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UExternalForceComponent, DirectionMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UExternalForceComponent_Statics::NewProp_DirectionMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UExternalForceComponent_Statics::NewProp_DirectionMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UExternalForceComponent_Statics::NewProp_RegionMesh_MetaData[] = {
		{ "Category", "ExternalForceComponent" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ExternalForceComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UExternalForceComponent_Statics::NewProp_RegionMesh = { "RegionMesh", nullptr, (EPropertyFlags)0x0010000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UExternalForceComponent, RegionMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UExternalForceComponent_Statics::NewProp_RegionMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UExternalForceComponent_Statics::NewProp_RegionMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UExternalForceComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UExternalForceComponent_Statics::NewProp_DirectionMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UExternalForceComponent_Statics::NewProp_RegionMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UExternalForceComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UExternalForceComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UExternalForceComponent_Statics::ClassParams = {
		&UExternalForceComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UExternalForceComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UExternalForceComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UExternalForceComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UExternalForceComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UExternalForceComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UExternalForceComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UExternalForceComponent, 2142982628);
	template<> BEACHSIMULATION_API UClass* StaticClass<UExternalForceComponent>()
	{
		return UExternalForceComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UExternalForceComponent(Z_Construct_UClass_UExternalForceComponent, &UExternalForceComponent::StaticClass, TEXT("/Script/BeachSimulation"), TEXT("UExternalForceComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UExternalForceComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
