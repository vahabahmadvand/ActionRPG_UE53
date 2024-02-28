// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ActionRPG.h"
#include "RPGInventoryInterface.generated.h"

/**
 * Interface for actors that provide a set of RPGItems bound to ItemSlots
 * This exists so RPGCharacterBase can query inventory without doing hacky player controller casts
 * It is designed only for use by native classes
 */
UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class URPGInventoryInterface : public UInterface
{
	GENERATED_BODY()
};

class ACTIONRPG_API IRPGInventoryInterface
{
	GENERATED_BODY()

public:
	/** Returns the map of items to data */
	virtual const TMap<URPGItem*, FRPGItemData>& GetInventoryDataMap() const = 0;

	/** Returns the map of slots to items */
	virtual const TMap<FRPGItemSlot, URPGItem*>& GetSlottedItemMap() const = 0;

	/** Gets the delegate for inventory item changes */
	virtual FOnInventoryItemChangedNative& GetInventoryItemChangedDelegate() = 0;

	/** Gets the delegate for inventory slot changes */
	virtual FOnSlottedItemChangedNative& GetSlottedItemChangedDelegate() = 0;

	/** Gets the delegate for when the inventory loads */
	virtual FOnInventoryLoadedNative& GetInventoryLoadedDelegate() = 0;
};

