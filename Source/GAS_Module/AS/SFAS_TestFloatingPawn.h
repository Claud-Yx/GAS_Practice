// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "SFAS_TestFloatingPawn.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class GAS_MODULE_API USFAS_TestFloatingPawn : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	USFAS_TestFloatingPawn();

	ATTRIBUTE_ACCESSORS( ThisClass, MovementSpeed );
	ATTRIBUTE_ACCESSORS( ThisClass, MinMovementSpeed );
	ATTRIBUTE_ACCESSORS( ThisClass, MaxMovementSpeed );

	virtual void PreAttributeChange( const FGameplayAttribute& Attribute, float& NewValue ) override;
	virtual bool PreGameplayEffectExecute( struct FGameplayEffectModCallbackData& Data ) override;
	virtual void PostGameplayEffectExecute( const struct FGameplayEffectModCallbackData& Data ) override;

protected:
	UPROPERTY( BlueprintReadOnly, Category = "Movement", Meta = (AllowPrivateAccess = true) )
	FGameplayAttributeData MovementSpeed;

	UPROPERTY( BlueprintReadOnly, Category = "Movement", Meta = (AllowPrivateAccess = true) )
	FGameplayAttributeData MinMovementSpeed;

	UPROPERTY( BlueprintReadOnly, Category = "Movement", Meta = (AllowPrivateAccess = true) )
	FGameplayAttributeData MaxMovementSpeed;
};
