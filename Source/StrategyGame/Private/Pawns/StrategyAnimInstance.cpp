// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "StrategyGame.h"
#include "StrategyAnimInstance.h"

UStrategyAnimInstance::UStrategyAnimInstance(const FObjectInitializer& ObjectInitializer) 
    : Super(ObjectInitializer)
{
}

void UStrategyAnimInstance::AnimNotify_Melee(UAnimNotify* Notify)
{
	AStrategyChar* const MyChar = Cast<AStrategyChar>(TryGetPawnOwner());
	if (MyChar)
	{
		MyChar->OnMeleeImpactNotify();
	}
}
