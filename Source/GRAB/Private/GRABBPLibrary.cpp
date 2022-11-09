// Copyright Epic Games, Inc. All Rights Reserved.

#include "GRABBPLibrary.h"
#include "GRABSettings.h"
#include "GRAB.h"

#include "JsonUtilities.h"

UGRABBPLibrary::UGRABBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

FString UGRABBPLibrary::ToJSONString(TArray<FGRABAssetData> inAssetData)
{
	// Convert entire struct to a json object and return string
	FGRABAssetArray array = {inAssetData};

	// Add all objects to one single json data
	TSharedPtr<FJsonObject> jsonObject = FJsonObjectConverter::UStructToJsonObject<FGRABAssetArray>(array);
	
	// Serialize string
	FString outputString;
	TSharedRef< TJsonWriter<TCHAR, TPrettyJsonPrintPolicy<TCHAR>> > Writer = TJsonWriterFactory< TCHAR, TPrettyJsonPrintPolicy<TCHAR> >::Create(&outputString);
	FJsonSerializer::Serialize(jsonObject.ToSharedRef(), Writer);

	return outputString;
}

FString UGRABBPLibrary::GetCurrentTime()
{
	return FDateTime::UtcNow().ToString();
}

int64 UGRABBPLibrary::GetCurrentUnixEpochTime()
{
	return FDateTime::UtcNow().ToUnixTimestamp();
}

FString UGRABBPLibrary::GetAPIKey()
{
	// Return the correct variable from settings
	const UGRABSettings* GRABSettings = GetDefault<UGRABSettings>();

	return GRABSettings->ClientKey;
}

FString UGRABBPLibrary::GetAPISecret()
{
	// Return the correct variable from settings
	const UGRABSettings* GRABSettings = GetDefault<UGRABSettings>();

	return GRABSettings->ClientSecret;
}

FString UGRABBPLibrary::GetBucketName()
{
	// Return the correct variable from settings
	const UGRABSettings* GRABSettings = GetDefault<UGRABSettings>();

	return GRABSettings->BucketName;
}

FString UGRABBPLibrary::GetBucketRegion()
{
	// Return the correct variable from settings
	const UGRABSettings* GRABSettings = GetDefault<UGRABSettings>();

	return GRABSettings->BucketRegion;
}

FString UGRABBPLibrary::GetStorageEndpoint()
{
	// Return the correct variable from settings
	const UGRABSettings* GRABSettings = GetDefault<UGRABSettings>();

	return GRABSettings->ObjectStorageEndpoint;
}

FString UGRABBPLibrary::GetBucketURL()
{
	// Return the correct variable from settings
	const UGRABSettings* GRABSettings = GetDefault<UGRABSettings>();

	return GRABSettings->BucketURL;
}

FString UGRABBPLibrary::GetFrontendEndpoint()
{
	// Return the correct variable from settings
	const UGRABSettings* GRABSettings = GetDefault<UGRABSettings>();

	return GRABSettings->Endpoint;
}

AActor* UGRABBPLibrary::GetDefaultObject(TSubclassOf<AActor> ActorClass)
{
	if (ActorClass)
	{
		return ActorClass.GetDefaultObject();
	}

	return nullptr;
}
