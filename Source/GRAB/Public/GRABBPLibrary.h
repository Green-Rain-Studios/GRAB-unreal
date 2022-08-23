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
	FString Metadata;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GRAB|Asset Data")
	FString Uploader;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GRAB|Asset Data")
	FString Timestamp;
};

UCLASS()
class GRAB_API UGRABBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "GRAB sample test testing"), Category = "GRABTesting")
	static float GRABSampleFunction(float Param);
};
