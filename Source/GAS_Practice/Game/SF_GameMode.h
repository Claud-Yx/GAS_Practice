// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SF_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class GAS_PRACTICE_API ASF_GameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ASF_GameMode();

	virtual void StartPlay() override;
};
