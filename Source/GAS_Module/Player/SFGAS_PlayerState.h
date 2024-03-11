// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "SFGAS_PlayerState.generated.h"

/**
 * 
 */
UCLASS()
class GAS_MODULE_API ASFGAS_PlayerState 
	: public APlayerState
	, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ASFGAS_PlayerState();

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = GAS )
	TObjectPtr<class UAbilitySystemComponent> ASC;

	UPROPERTY()
	TObjectPtr<class USFAS_TestFloatingPawn> AttributeSet;
	
};
