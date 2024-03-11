// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/SFGAS_TestFloatingPawn.h"
#include "AbilitySystemComponent.h"
#include "Player/SFGAS_PlayerState.h"
#include "EnhancedInputComponent.h"
#include "GA/SFGA_AdjustSpeed.h"

ASFGAS_TestFloatingPawn::ASFGAS_TestFloatingPawn()
{
	ASC = nullptr;

	// Input
	static ConstructorHelpers::FObjectFinder<UInputAction> IA_AdjustSpeedRef( TEXT( "/Script/EnhancedInput.InputAction'/Game/GAS_Practice/InputSystem/InputAction/IA_AdjustSpeed.IA_AdjustSpeed'" ) );
	if ( IA_AdjustSpeedRef.Object )
	{
		IA_AdjustSpeed = IA_AdjustSpeedRef.Object;
	}
}

UAbilitySystemComponent* ASFGAS_TestFloatingPawn::GetAbilitySystemComponent() const
{
	return ASC;
}

void ASFGAS_TestFloatingPawn::PossessedBy( AController* NewController )
{
	// 네트워크 멀티플레이 프레임워크에서는 서버에서만 호출됨
	Super::PossessedBy( NewController );

	auto* GAS_PlayerState = GetPlayerState<ASFGAS_PlayerState>();
	if ( GAS_PlayerState )
	{
		ASC = GAS_PlayerState->GetAbilitySystemComponent();
		ASC->InitAbilityActorInfo( GAS_PlayerState, this );

		SetupGASInputComponent();

		// Debug
		APlayerController* PlayerController = CastChecked<APlayerController>( NewController );
		PlayerController->ConsoleCommand( TEXT( "showdebug abilitysystem" ) );
	}
}

void ASFGAS_TestFloatingPawn::SetupPlayerInputComponent( UInputComponent* PlayerInputComponent )
{
	Super::SetupPlayerInputComponent( PlayerInputComponent );

	SetupGASInputComponent();
}

void ASFGAS_TestFloatingPawn::SetupGASInputComponent()
{
	if ( IsValid( ASC ) && IsValid( InputComponent ) )
	{
		auto* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>( InputComponent );

		for ( const auto& [Key, StartInputAbility] : StartInputAbilities )
		{
			if ( StartInputAbility == USFGA_AdjustSpeed::StaticClass() )
			{
				EnhancedInputComponent->BindAction( IA_AdjustSpeed, ETriggerEvent::Triggered, this, &ThisClass::GAS_InputPressed, Key );
			}
		}

	}
}

void ASFGAS_TestFloatingPawn::GAS_InputPressed( const FInputActionValue& Value, int32 InputId )
{
	FGameplayEventData Payload;
	Payload.EventMagnitude = Value.GetMagnitude();

	auto Spec = ASC->FindAbilitySpecFromInputID( InputId );
	if ( Spec )
	{
		ASC->TryActivateAbility(Spec->Handle);
	}
}

void ASFGAS_TestFloatingPawn::GAS_InputReleased( const FInputActionValue& Value, int32 InputId )
{
}
