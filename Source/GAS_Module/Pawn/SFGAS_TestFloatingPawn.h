// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawn/SF_TestFloatingPawn.h"
#include "AbilitySystemInterface.h"
#include "SFGAS_TestFloatingPawn.generated.h"

/**
 * 
 */
UCLASS()
class GAS_MODULE_API ASFGAS_TestFloatingPawn 
	: public ASF_TestFloatingPawn
	, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ASFGAS_TestFloatingPawn();

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void PossessedBy( AController* NewController ) override;
	virtual void SetupPlayerInputComponent( class UInputComponent* PlayerInputComponent ) override;

protected:

// Ability Section
protected:
	UPROPERTY( VisibleAnywhere, Category = GAS )
	TObjectPtr<class UAbilitySystemComponent> ASC;

	UPROPERTY( EditAnywhere, Category = GAS )
	TArray<TSubclassOf<class UGameplayAbility>> StartAbilities;

	UPROPERTY( EditAnywhere, Category = GAS )
	TMap<int32, TSubclassOf<class UGameplayAbility>> StartInputAbilities;
	
// Input Section
protected:
	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true") )
	TObjectPtr<class UInputAction> IA_AdjustSpeed;

	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true") )
	TObjectPtr<class UInputAction> IA_NormalAttack;

	void SetupGASInputComponent();
	void GAS_InputPressed( const FInputActionValue& Value, int32 InputId );
	void GAS_InputReleased( const FInputActionValue& Value, int32 InputId );
};
