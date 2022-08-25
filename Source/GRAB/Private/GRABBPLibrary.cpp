// Copyright Epic Games, Inc. All Rights Reserved.

#include "GRABBPLibrary.h"
#include "GRAB.h"

#include "JsonUtilities.h"

UGRABBPLibrary::UGRABBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

FString UGRABBPLibrary::ToJSONString(TArray<FGRABAssetData> inAssetData)
{
	// Convert entire struct to a json object and return string
	TSharedPtr<FJsonObject> jsonObject =  MakeShareable(new FJsonObject);

	// Add all objects to one single json data
	for(FGRABAssetData assetData : inAssetData)
	{
		TSharedPtr<FJsonObject> jo = FJsonObjectConverter::UStructToJsonObject<FGRABAssetData>(assetData);
		jsonObject->SetObjectField(assetData.Name, jo);
	}
	
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
