// Fill out your copyright notice in the Description page of Project Settings.


#include "GRABSettings.h"

#define LOCTEXT_NAMESPACE "GRAB"

UGRABSettings::UGRABSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CategoryName = TEXT("Plugins");
	SectionName  = TEXT("G.R.A.B.");

	FFMPEGLocation.FilePath = FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("GRAB"), TEXT("Extras"), TEXT("ffmpeg"), TEXT("ffmpeg.exe"));
}

bool UGRABSettings::CanEditChange(const FProperty* InProperty) const
{
	bool bCanEditChange = Super::CanEditChange(InProperty);
	
	return bCanEditChange;
}

void UGRABSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

FText UGRABSettings::GetSectionText() const
{
	return LOCTEXT("SettingsDisplayName", "G.R.A.B.");
}
