// Copyright Epic Games, Inc. All Rights Reserved.

#include "RobotWarsGameMode.h"
#include "RobotWarsPlayerController.h"
#include "RobotWarsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARobotWarsGameMode::ARobotWarsGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ARobotWarsPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}