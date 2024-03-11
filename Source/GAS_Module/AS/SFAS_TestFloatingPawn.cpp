// Fill out your copyright notice in the Description page of Project Settings.


#include "AS/SFAS_TestFloatingPawn.h"
#include "GAS_Module.h"

USFAS_TestFloatingPawn::USFAS_TestFloatingPawn()
	: MovementSpeed{ 600.f }
	, MinMovementSpeed{ 600.f }
	, MaxMovementSpeed{ 5000.f }
{

}

void USFAS_TestFloatingPawn::PreAttributeChange( const FGameplayAttribute& Attribute, float& NewValue )
{
	Super::PreAttributeChange( Attribute, NewValue );

	SFGAS_LOG( Log, TEXT( "PreAttributeChange Executed !!!" ) );

	if ( Attribute == GetMovementSpeedAttribute() )
	{
		NewValue = FMath::Clamp( NewValue, GetMinMovementSpeed(), GetMaxMovementSpeed() );
	}
}

bool USFAS_TestFloatingPawn::PreGameplayEffectExecute( FGameplayEffectModCallbackData& Data )
{
	Super::PreGameplayEffectExecute( Data );

	SFGAS_LOG( Log, TEXT( "PreGameplayEffectExecute Executed !!!" ) );

	return false;
}

void USFAS_TestFloatingPawn::PostGameplayEffectExecute( const FGameplayEffectModCallbackData& Data )
{
	Super::PostGameplayEffectExecute( Data );

	SFGAS_LOG( Log, TEXT( "PostGameplayEffectExecute Executed !!!" ) );
}
