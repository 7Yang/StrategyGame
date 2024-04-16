// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "StrategyGame.h"
#include "StrategySpectatorPawn.h"
#include "StrategyCameraComponent.h"
#include "StrategySpectatorPawnMovement.h"

AStrategySpectatorPawn::AStrategySpectatorPawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UStrategySpectatorPawnMovement>(Super::MovementComponentName))
{
	bAddDefaultMovementBindings = false;
	GetCollisionComponent()->SetCollisionProfileName(UCollisionProfile::NoCollision_ProfileName);
	StrategyCameraComponent = CreateDefaultSubobject<UStrategyCameraComponent>(TEXT("StrategyCameraComponent"));
}

void AStrategySpectatorPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("MoveRight",   this, &AStrategySpectatorPawn::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &AStrategySpectatorPawn::MoveForward);

	PlayerInputComponent->BindAction("ZoomOut", IE_Pressed, this, &AStrategySpectatorPawn::OnMouseScrollUp);
	PlayerInputComponent->BindAction("ZoomIn",  IE_Pressed, this, &AStrategySpectatorPawn::OnMouseScrollDown);
}

void AStrategySpectatorPawn::OnMouseScrollUp()
{
    StrategyCameraComponent->OnZoomIn();
}

void AStrategySpectatorPawn::OnMouseScrollDown()
{
    StrategyCameraComponent->OnZoomOut();
}

void AStrategySpectatorPawn::MoveForward(float Val)
{
	StrategyCameraComponent->MoveForward( Val );
}

void AStrategySpectatorPawn::MoveRight(float Val)
{
	StrategyCameraComponent->MoveRight( Val );
}

UStrategyCameraComponent* AStrategySpectatorPawn::GetStrategyCameraComponent()
{
	return StrategyCameraComponent;
}

