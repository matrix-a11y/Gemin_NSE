// Copyright Epic Games, Inc. All Rights Reserved.


#include "Gemini_NSEGameModeBase.h"

#include "MainController.h"

AGemini_NSEGameModeBase::AGemini_NSEGameModeBase()
{
	PlayerControllerClass = AMainController::StaticClass();
	DefaultPawnClass = ALumineCharacter::StaticClass();
}

