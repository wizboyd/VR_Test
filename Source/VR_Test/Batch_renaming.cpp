// Fill out your copyright notice in the Description page of Project Settings.


#include "Batch_renaming.h"

#include "EditorUtilityLibrary.h"

#pragma region Rename_selected_Assets
void UBatch_renaming::RenameSelectedAssets(FString searchpattern, FString ReplacePattern, ESearchCase::Type searchcase)
{
	if(searchpattern.IsEmpty() || searchpattern.Equals(ReplacePattern, searchcase))
	{
		return;
	}

	TArray<UObject*> selctedobjects = UEditorUtilityLibrary::GetSelectedAssets();

	uint32 Counter = 0;

	for(UObject* Selected : selctedobjects)
	{
		if (ensure(Selected))
		{
			FString AssetName = Selected->GetName();
			if(AssetName.Contains(searchpattern,searchcase))
			{
				FString Newname = AssetName.Replace(*searchpattern, *ReplacePattern, searchcase);
				UEditorUtilityLibrary::RenameAsset(Selected, Newname);
				++Counter;
			}
		}
	}
	GiveFeedBack(TEXT("Renamed"), Counter);
}

#pragma endregion

#pragma region helper
void UBatch_renaming::printToScreen(FString Message, FColor Color)
{
	if (ensure(GEngine))
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.5f, Color, Message);
	}
}

void UBatch_renaming::GiveFeedBack(FString Method, uint32 Counter)
{
	FString Message = FString("No matching Files Found");

	FColor Color = Counter > 0 ? FColor::Green : FColor::Red;
	if (Counter > 0)
	{
		Message = Method.AppendChar(' ');
		Message.AppendInt(Counter);
		Message.Append(Counter == 1 ? TEXT(" File") : TEXT(" Files"));
	}
	printToScreen(Message, Color);
}
#pragma endregion 
