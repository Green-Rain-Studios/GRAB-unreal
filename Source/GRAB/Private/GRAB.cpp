// Copyright Epic Games, Inc. All Rights Reserved.

#include "GRAB.h"

#include "EditorUtilitySubsystem.h"
#include "EditorUtilityWidgetBlueprint.h"
#include "GRABSettings.h"
#include "MoviePipelineCommandLineEncoderSettings.h"
#include "WidgetBlueprint.h"

#define LOCTEXT_NAMESPACE "FGRABModule"

void FGRABModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	// Load settings into the project settings menu
	const UGRABSettings* GRABSettings = GetDefault<UGRABSettings>();

	SetEncoderSettings({
						   GRABSettings->FFMPEGLocation.FilePath,
						   GRABSettings->VideoCodec,
					       GRABSettings->AudioCodec,
		                   GRABSettings->OutputFileExtension
						});

	//TODO: Uncomment to set active Default EUW tool to use
	//ActivateDefaultEUW(GRABSettings->DefaultGRABToolUI);
}

void FGRABModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

bool FGRABModule::SetEncoderSettings(const FGRAB_EncoderSettings& EncoderSettingsToUse) const
{
	if(EncoderSettingsToUse.IsValidSettings())
	{
		UMoviePipelineCommandLineEncoderSettings* EncoderSettings = GetMutableDefault<UMoviePipelineCommandLineEncoderSettings>();
		EncoderSettings->ExecutablePath = EncoderSettingsToUse.Path;
		EncoderSettings->VideoCodec = EncoderSettingsToUse.VideoCodec;
		EncoderSettings->AudioCodec = EncoderSettingsToUse.AudioCodec;
		EncoderSettings->OutputFileExtension = EncoderSettingsToUse.OutputFileExtension;

		UE_LOG(LogTemp, Display, TEXT("Successfully set Encoder Settings"));

		return true;	
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Encoder Settings failed to get set"));

	return false;
}

/*bool FGRABModule::ActivateDefaultEUW(TSubclassOf<UEditorUtilityWidget> ClassToUse)
{
	//TODO: Fix this to actually spawn the Editor
	if(ClassToUse)
	{
		if (UWidgetBlueprint* Blueprint = Cast<UWidgetBlueprint>(ClassToUse.GetDefaultObject()))
		{
			if (Blueprint->GeneratedClass->IsChildOf(UEditorUtilityWidget::StaticClass()))
			{
				UEditorUtilityWidgetBlueprint* EditorWidget = Cast<UEditorUtilityWidgetBlueprint>(Blueprint);
				if (EditorWidget)
				{
					UEditorUtilitySubsystem* EditorUtilitySubsystem = GEditor->GetEditorSubsystem<UEditorUtilitySubsystem>();
					EditorUtilitySubsystem->SpawnAndRegisterTab(EditorWidget);

					return true;
				}
			}
		}
	}

	return false;
}*/


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGRABModule, GRAB)