// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Items/RPGItem.h"
#include "RPGTokenItem.generated.h"

/** Native base class for tokens/currency, should be blueprinted */
UCLASS()
class ACTIONRPG_API URPGTokenItem : public URPGItem
{
	GENERATED_BODY()

public:
	/** Constructor */
	URPGTokenItem()
	{
		ItemType = URPGAssetManager::TokenItemType;
		MaxCount = 0; // Infinite
	}
};