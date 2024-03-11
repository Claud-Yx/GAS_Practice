// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/SF_CharacterBase.h"
#include "SF_PC_ConquerorBot.generated.h"

/**
 * SF: StarForge
 * PC: PlayerCharacter
 */
UCLASS()
class GAS_PRACTICE_API ASF_PC_ConquerorBot : public ASF_CharacterBase
{
	GENERATED_BODY()
	
public:
	ASF_PC_ConquerorBot();

protected:
	virtual void BeginPlay() override;

// Camera Section
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, Meta=(AllowPrivateAccess="true"))
	TObjectPtr<class USpringArmComponent> CameraArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, Meta=(AllowPrivateAccess="true"))
	TObjectPtr<class UCameraComponent> MainCamera;

};
