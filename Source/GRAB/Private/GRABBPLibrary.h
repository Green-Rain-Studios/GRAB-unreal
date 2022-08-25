// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "GRABBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*/

USTRUCT(BlueprintType, Category="GRAB", meta=(DisplayName = "GRAB Asset Data"))
struct GRAB_API FGRABAssetData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GRAB|Asset Data")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GRAB|Asset Data")
	FString Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GRAB|Asset Data")
	FDirectoryPath Path;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GRAB|Asset Data")
	TArray<FString> References;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GRAB|Asset Data")
	TArray<FDirectoryPath> ReferenceDirs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GRAB|Asset Data")
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GRAB|Asset Data")
	FString Tags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GRAB|Asset Data")
	FString Uploader;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GRAB|Asset Data")
	FString Timestamp;
	UPROPERTY(BlueprintReadWrite, Category="GRAB|Asset Data")
	FString ThumbnailURL;
	UPROPERTY(BlueprintReadWrite, Category="GRAB|Asset Data")
	FString VideoURL;
};

UCLASS()
class GRAB_API UGRABBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintPure, Category="GRAB|Asset Data")
	static FString ToJSONString(TArray<FGRABAssetData> inAssetData);

	UFUNCTION(BlueprintPure, Category="GRAB")
	static FString GetCurrentTime();

	UFUNCTION(BlueprintPure, Category="GRAB")
	static FString GetAPIKey();

	UFUNCTION(BlueprintPure, Category="GRAB")
	static FString GetAPISecret();
};
