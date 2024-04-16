// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Perception/PawnSensingComponent.h"
#include "StrategyAISensingComponent.generated.h"

/**
 * SensingComponent encapsulates sensory (ie sight and hearing) settings and functionality for an Actor,
 * allowing the actor to see/hear Pawns in the world. It does *not* enable hearing and sight sensing by default.
 */
UCLASS(config=Game)
class UStrategyAISensingComponent : public UPawnSensingComponent
{
	GENERATED_UCLASS_BODY()

	virtual void InitializeComponent() override;

	/** See if there are interesting sounds and sights that we want to detect, and respond to them if so. */
	virtual void UpdateAISensing() override;

	/** Check pawn to see if we want to check visibility on him */
	virtual bool ShouldCheckVisibilityOf(class APawn* Pawn) const override;

	/** Are we capable of sensing anything (and do we have any callbacks that care about sensing)? If so, calls UpdateAISensing(). */
	virtual bool CanSenseAnything() const;

	/** list of known targets */
	UPROPERTY()
	TArray<TWeakObjectPtr<AActor>> KnownTargets;

protected:
	UPROPERTY(config)
	float SightDistance;
};
