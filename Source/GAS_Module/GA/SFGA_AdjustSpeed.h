// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "SFGA_AdjustSpeed.generated.h"

/**
 * 
 */
UCLASS()
class GAS_MODULE_API USFGA_AdjustSpeed : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	USFGA_AdjustSpeed();

public:
	virtual void ActivateAbility( const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData ) override;
	virtual void EndAbility( const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled ) override;

protected:
	TSubclassOf<class UGameplayEffect> GE_AdjustSpeedClass;
};
