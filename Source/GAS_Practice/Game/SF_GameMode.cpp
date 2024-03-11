// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/SF_GameMode.h"
#include "Pawn/SF_TestFloatingPawn.h"
#include "Controller/SF_TestPawnController.h"

ASF_GameMode::ASF_GameMode()
{	
	DefaultPawnClass = ASF_TestFloatingPawn::StaticClass();

	PlayerControllerClass = ASF_TestPawnController::StaticClass();
}

void ASF_GameMode::StartPlay()
{
	Super::StartPlay();
}
