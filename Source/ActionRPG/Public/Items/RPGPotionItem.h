// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Items/RPGItem.h"
#include "RPGPotionItem.generated.h"

/** Native base class for potions, should be blueprinted */
UCLASS()
class ACTIONRPG_API URPGPotionItem : public URPGItem
{
	GENERATED_BODY()

public:
	/** Constructor */
	URPGPotionItem()
	{
		ItemType = URPGAssetManager::PotionItemType;
	}
};