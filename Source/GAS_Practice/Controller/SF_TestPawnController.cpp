// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/SF_TestPawnController.h"

void ASF_TestPawnController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly GameOnlyInputMode;
	SetInputMode( GameOnlyInputMode );
}
