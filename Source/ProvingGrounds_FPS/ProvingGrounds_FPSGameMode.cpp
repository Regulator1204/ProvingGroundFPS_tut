// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ProvingGrounds_FPSGameMode.h"
#include "ProvingGrounds_FPSHUD.h"
#include "ProvingGrounds_FPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProvingGrounds_FPSGameMode::AProvingGrounds_FPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AProvingGrounds_FPSHUD::StaticClass();
}
