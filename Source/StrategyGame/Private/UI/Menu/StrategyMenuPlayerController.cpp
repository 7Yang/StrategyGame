// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "StrategyGame.h"
#include "StrategyMenuPlayerController.h"
#include "Camera/PlayerCameraManager.h"

AStrategyMenuPlayerController::AStrategyMenuPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PlayerCameraManagerClass = APlayerCameraManager::StaticClass();
}

void AStrategyMenuPlayerController::SetupInputComponent()
{
	APlayerController::SetupInputComponent();
}