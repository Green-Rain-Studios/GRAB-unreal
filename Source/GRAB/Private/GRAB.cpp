// Copyright Epic Games, Inc. All Rights Reserved.

#include "GRAB.h"
#include "GRABSettings.h"

#define LOCTEXT_NAMESPACE "FGRABModule"

void FGRABModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	// Load settings into the project settings menu
	const UGRABSettings* GRABSettings = GetDefault<UGRABSettings>();
	
}

void FGRABModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGRABModule, GRAB)