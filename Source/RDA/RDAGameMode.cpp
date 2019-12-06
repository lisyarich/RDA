// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "RDAGameMode.h"
#include "RDAHUD.h"
#include "RDACharacter.h"
#include "UObject/ConstructorHelpers.h"

ARDAGameMode::ARDAGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ARDAHUD::StaticClass();
}
