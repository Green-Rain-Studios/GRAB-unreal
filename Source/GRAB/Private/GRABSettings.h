// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "EditorUtilityWidget.h"
#include "GRABSettings.generated.h"

/**
 * Configure the G.R.A.B plugin
 */
UCLASS(config=Engine, defaultconfig)
class GRAB_API UGRABSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UGRABSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

#if WITH_EDITOR
	//~ UObject interface
	virtual bool CanEditChange(const FProperty* InProperty) const override;
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

	//~ UDeveloperSettings interface
	virtual FText GetSectionText() const override;
#endif
	/**
	* Single bucket name which G.R.A.B. will connect with (eg. my-bucket)
	*/
	UPROPERTY(config, EditAnywhere, Category="Object Storage (S3 Compatible)")
	FString BucketName;

	/**
	 * The region where your object storage bucket is located. (eg. us-east-1)
	 */
	UPROPERTY(config, EditAnywhere, Category="Object Storage (S3 Compatible)")
	FString BucketRegion;

	/**
	 * The object storage endpoint provided by your storage provider. This usually does not have a bucket name.
	 * (eg. https://us-east-1.amazonwebservices.com)
	 */
	UPROPERTY(config, EditAnywhere, Category="Object Storage (S3 Compatible)")
	FString ObjectStorageEndpoint;

	/**
	 * The full bucket URL (eg. https://my-bucket.us-east-1.amazonwebservices.com)
	 */
	UPROPERTY(config, EditAnywhere, Category="Object Storage (S3 Compatible)")
	FString BucketURL;

	/**
	 * The client key associated with this bucket obtained from your object storage provider.
	 */
	UPROPERTY(config, EditAnywhere, Category="Object Storage (S3 Compatible)")
	FString ClientKey;

	/**
	 * The client secret associated with this bucket obtained from your object storage provider.
	 */
	UPROPERTY(config, EditAnywhere, Category="Object Storage (S3 Compatible)")
	FString ClientSecret;

	/**
	 * Location to the FFMPEG binary. Leave as-is to use the bundled one, or browse to your own executable
	 */
	UPROPERTY(config, EditAnywhere, Category="GRAB", DisplayName="FFMPEG Location", meta=(ConfigRestartRequired=true))
	FFilePath FFMPEGLocation;

	/*
	 * Video codec to use
	 */
	UPROPERTY(config, EditAnywhere, Category="GRAB", DisplayName="Video Codec", meta=(ConfigRestartRequired=true))
	FString VideoCodec;

	
	/*
	 * Audio codec to use
	 */
	UPROPERTY(config, EditAnywhere, Category="GRAB", DisplayName="Audio Codec", meta=(ConfigRestartRequired=true))
	FString AudioCodec;

	/*
	 * File extension to use
	 */
	UPROPERTY(config, EditAnywhere, Category="GRAB", DisplayName="Output File Type", meta=(ConfigRestartRequired=true))
	FString OutputFileExtension;

	/**
	 * The tool widget class to be launched when the project is opened
	 */
	UPROPERTY(config, EditAnywhere, Category="GRAB", meta=(ConfigRestartRequired=true))
	TSubclassOf<class UEditorUtilityWidget> DefaultGRABToolUI;
};
