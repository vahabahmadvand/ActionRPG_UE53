// Copyright Epic Games, Inc. All Rights Reserved.

#include "RPGGameModeBase.h"
#include "RPGGameStateBase.h"
#include "RPGPlayerControllerBase.h"

ARPGGameModeBase::ARPGGameModeBase()
{
	GameStateClass = ARPGGameStateBase::StaticClass();
	PlayerControllerClass = ARPGPlayerControllerBase::StaticClass();
	bGameOver = false;
}

void ARPGGameModeBase::ResetLevel() 
{
	K2_DoRestart();
}

bool ARPGGameModeBase::HasMatchEnded() const 
{
	return bGameOver;
}

void ARPGGameModeBase::GameOver()
{
	if (bGameOver == false)
	{
		K2_OnGameOver();
		bGameOver = true;
	}
}