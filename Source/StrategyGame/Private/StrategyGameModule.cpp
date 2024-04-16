// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "StrategyGame.h"
#include "StrategyHUDWidgetStyle.h"
#include "StrategyMenuWidgetStyle.h"
#include "StrategyHUDSoundsWidgetStyle.h"

class FStrategyGameModule : public FDefaultGameModuleImpl
{
	virtual void StartupModule() override
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(FStrategyStyle::GetStyleSetName());
		FStrategyStyle::Initialize();
	}

	virtual void ShutdownModule() override
	{
		FStrategyStyle::Shutdown();
	}
};

DEFINE_LOG_CATEGORY(LogGame)

IMPLEMENT_PRIMARY_GAME_MODULE(FStrategyGameModule, StrategyGame, "StrategyGame");
