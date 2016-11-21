// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "DungeonEscape.h"
#include "DungeonEscapeGameMode.h"
#include "DungeonEscapePlayerController.h"
#include "DungeonEscapeCharacter.h"

ADungeonEscapeGameMode::ADungeonEscapeGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ADungeonEscapePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}