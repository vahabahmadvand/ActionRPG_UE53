// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ActionRPG.h"
#include "RPGTypes.h"
#include "Abilities/RPGAbilityTypes.h"
#include "RPGBlueprintLibrary.generated.h"

/**
 * Game-specific blueprint library
 * Most games will need to implement one or more blueprint function libraries to expose their native code to blueprints
 */
UCLASS()
class URPGBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:
	/** Show the native loading screen, such as on a map transfer. If bPlayUntilStopped is false, it will be displayed for PlayTime and automatically stop */
	UFUNCTION(BlueprintCallable, Category = Loading)
	static void PlayLoadingScreen(bool bPlayUntilStopped, float PlayTime);

	/** Turns off the native loading screen if it is visible. This must be called if bPlayUntilStopped was true */
	UFUNCTION(BlueprintCallable, Category = Loading)
	static void StopLoadingScreen();

	/** Returns true if this is being run from an editor preview */
	UFUNCTION(BlueprintPure, Category = Loading)
	static bool IsInEditor();

	/** Equality operator for ItemSlot */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (RPGItemSlot)", CompactNodeTitle = "==", Keywords = "== equal"), Category = Inventory)
	static bool EqualEqual_RPGItemSlot(const FRPGItemSlot& A, const FRPGItemSlot& B);

	/** Inequality operator for ItemSlot */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "NotEqualEqual (RPGItemSlot)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = Inventory)
	static bool NotEqual_RPGItemSlot(const FRPGItemSlot& A, const FRPGItemSlot& B);

	/** Validity check for ItemSlot */
	UFUNCTION(BlueprintPure, Category = Inventory)
	static bool IsValidItemSlot(const FRPGItemSlot& ItemSlot);

	/** Checks if spec has any effects */
	UFUNCTION(BlueprintPure, Category = Ability)
	static bool DoesEffectContainerSpecHaveEffects(const FRPGGameplayEffectContainerSpec& ContainerSpec);

	/** Checks if spec has any targets */
	UFUNCTION(BlueprintPure, Category = Ability)
	static bool DoesEffectContainerSpecHaveTargets(const FRPGGameplayEffectContainerSpec& ContainerSpec);

	/** Adds targets to a copy of the passed in effect container spec and returns it */
	UFUNCTION(BlueprintCallable, Category = Ability, meta = (AutoCreateRefTerm = "HitResults,TargetActors"))
	static FRPGGameplayEffectContainerSpec AddTargetsToEffectContainerSpec(const FRPGGameplayEffectContainerSpec& ContainerSpec, const TArray<FHitResult>& HitResults, const TArray<AActor*>& TargetActors);

	/** Applies container spec that was made from an ability */
	UFUNCTION(BlueprintCallable, Category = Ability)
	static TArray<FActiveGameplayEffectHandle> ApplyExternalEffectContainerSpec(const FRPGGameplayEffectContainerSpec& ContainerSpec);

	//Returns the project version set in the 'Project Settings' > 'Description' section of the editor
	UFUNCTION(BlueprintPure, Category = "Project")
	static FString GetProjectVersion();
};
