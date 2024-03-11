// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/SFGAS_PlayerState.h"
#include "AbilitySystemComponent.h"
#include "AS/SFAS_TestFloatingPawn.h"

ASFGAS_PlayerState::ASFGAS_PlayerState()
{
	ASC = CreateDefaultSubobject<UAbilitySystemComponent>( TEXT( "ASC" ) );

	AttributeSet = CreateDefaultSubobject<USFAS_TestFloatingPawn>( TEXT( "AttributeSet" ) );
}

UAbilitySystemComponent* ASFGAS_PlayerState::GetAbilitySystemComponent() const
{
	return ASC;
}