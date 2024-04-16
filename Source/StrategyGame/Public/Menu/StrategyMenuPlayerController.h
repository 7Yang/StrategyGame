// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "StrategyMenuPlayerController.generated.h"

UCLASS(config=Game)
class AStrategyMenuPlayerController : public AStrategyPlayerController
{
	GENERATED_UCLASS_BODY()
public:
	/** We know we won't have a pawn, so we don't care */
	virtual void FailedToSpawnPawn() override {}

protected:
	virtual void SetupInputComponent() override;
};

