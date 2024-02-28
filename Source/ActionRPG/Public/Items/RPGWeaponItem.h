// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Items/RPGItem.h"
#include "RPGWeaponItem.generated.h"

/** Native base class for weapons, should be blueprinted */
UCLASS()
class ACTIONRPG_API URPGWeaponItem : public URPGItem
{
	GENERATED_BODY()

public:
	/** Constructor */
	URPGWeaponItem()
	{
		ItemType = URPGAssetManager::WeaponItemType;
	}

	/** Weapon actor to spawn */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon)
	TSubclassOf<AActor> WeaponActor;
};