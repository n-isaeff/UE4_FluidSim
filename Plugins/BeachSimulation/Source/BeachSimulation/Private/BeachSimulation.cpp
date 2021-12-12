// Copyright Epic Games, Inc. All Rights Reserved.

#include "BeachSimulation.h"
#include "Runtime/Core/Public/Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FBeachSimulationModule"

void FBeachSimulationModule::StartupModule()
{
	FString PluginDir = FPaths::Combine(FPaths::Combine(FPaths::ProjectDir(), TEXT("Plugins")), TEXT("BeachSimulation"));
	FString ShaderDirectory = FPaths::Combine(PluginDir, TEXT("Shaders"));
	AddShaderSourceDirectoryMapping("/BeachSimulationShaders", ShaderDirectory);
}

void FBeachSimulationModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FBeachSimulationModule, BeachSimulation)