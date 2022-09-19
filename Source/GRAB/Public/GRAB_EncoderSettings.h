#pragma once

#include "CoreMinimal.h"
#include "GRAB_EncoderSettings.generated.h"

USTRUCT()
struct FGRAB_EncoderSettings
{
	GENERATED_BODY();

public: 
	FString Path;
	FString VideoCodec;
	FString AudioCodec;
	FString OutputFileExtension;

	bool IsValidSettings() const
	{
		return !Path.IsEmpty() && !VideoCodec.IsEmpty() && !AudioCodec.IsEmpty() && !OutputFileExtension.IsEmpty();
	}
};
