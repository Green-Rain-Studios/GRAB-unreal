// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GRAB_EncoderSettings.h"
#include "Modules/ModuleManager.h"

class UWidgetBlueprint;
class UEditorUtilityWidget;

class FGRABModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	bool SetEncoderSettings(const FGRAB_EncoderSettings& EncoderSettingsToUse) const;

	bool ActivateDefaultEUW(TSubclassOf<UEditorUtilityWidget> ClassToUse);
};