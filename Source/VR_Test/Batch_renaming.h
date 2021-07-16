// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetActionUtility.h"
#include "Batch_renaming.generated.h"

/**
 * 
 */
UCLASS()
class VR_TEST_API UBatch_renaming : public UAssetActionUtility
{
	GENERATED_BODY()

public:
		UFUNCTION(CallInEditor)
		void RenameSelectedAssets(FString searchpattern, FString ReplacePattern, ESearchCase::Type searchcase);

private:
	void printToScreen(FString Message, FColor Color);

	void GiveFeedBack(FString Method, uint32 Counter);
};
