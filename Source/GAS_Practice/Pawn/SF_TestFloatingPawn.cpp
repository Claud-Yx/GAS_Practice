// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/SF_TestFloatingPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"
#include "Physics/SF_Physics.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GAS_Practice.h"

// Sets default values
ASF_TestFloatingPawn::ASF_TestFloatingPawn()
{
	// Pawn
	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	// Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>( TEXT( "Mesh" ) );
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshRef( TEXT( "/Script/Engine.StaticMesh'/Game/GAS_Practice/Mesh/SM_TestFloatingPawn.SM_TestFloatingPawn'" ) );
	if ( MeshRef.Object )
	{
		Mesh->SetStaticMesh( MeshRef.Object );
	}
	Mesh->SetCollisionProfileName( CP_NoCollision );

	// Camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>( TEXT( "FollowCamera" ) );
	FollowCamera->bUsePawnControlRotation = true;

	// Attachment
	RootComponent = Mesh;
	FollowCamera->SetupAttachment( Mesh );

	// Movement
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>( TEXT( "FloatingPawnMovement" ) );
	
	// Input
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> MappingContextRef( TEXT( "/Script/EnhancedInput.InputMappingContext'/Game/GAS_Practice/InputSystem/SFIMC_FirstPerspectiveFloatingMove.SFIMC_FirstPerspectiveFloatingMove'" ) );
	if ( MappingContextRef.Object )
	{
		MappingContext = MappingContextRef.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> IA_MoveRef( TEXT( "/Script/EnhancedInput.InputAction'/Game/GAS_Practice/InputSystem/InputAction/IA_FIrstPersonMove.IA_FIrstPersonMove'" ) );
	if ( IA_MoveRef.Object )
	{
		IA_Move = IA_MoveRef.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> IA_LookRef( TEXT( "/Script/EnhancedInput.InputAction'/Game/GAS_Practice/InputSystem/InputAction/IA_FirstPersonLook.IA_FirstPersonLook'" ) );
	if ( IA_LookRef.Object )
	{
		IA_Look = IA_LookRef.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> IA_ElevateRef( TEXT( "/Script/EnhancedInput.InputAction'/Game/GAS_Practice/InputSystem/InputAction/IA_Elevate.IA_Elevate'" ) );
	ensure( IA_ElevateRef.Object );
	if ( IA_ElevateRef.Object )
	{
		SF_LOG( Log, TEXT( "IA_Elevate Found" ) );
		IA_Elevate = IA_ElevateRef.Object;
	}
}

// Called when the game starts or when spawned
void ASF_TestFloatingPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ASF_TestFloatingPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	auto PlayerController = CastChecked<APlayerController>( GetController() );
	if ( UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>( PlayerController->GetLocalPlayer() ) )
	{
		Subsystem->ClearAllMappings();
		if ( MappingContext )
		{
			Subsystem->AddMappingContext( MappingContext, 0 );
		}
	}

	auto EnhancedInputComponent = CastChecked<UEnhancedInputComponent>( PlayerInputComponent );

	EnhancedInputComponent->BindAction( IA_Move, ETriggerEvent::Triggered, this, &ThisClass::Move );
	EnhancedInputComponent->BindAction( IA_Elevate, ETriggerEvent::Triggered, this, &ThisClass::Elevate );
	EnhancedInputComponent->BindAction( IA_Look, ETriggerEvent::Triggered, this, &ThisClass::Look );
}

void ASF_TestFloatingPawn::Move( const FInputActionValue& Value )
{
	FVector MovementVector = Value.Get<FVector>();

	const FRotator DirectionVector = Controller->GetControlRotation();

	const FVector ForwardDirection = FRotationMatrix( DirectionVector ).GetUnitAxis( EAxis::X );
	const FVector RightDirection = FRotationMatrix( DirectionVector ).GetUnitAxis( EAxis::Y );
	const FVector UpDirection = FRotationMatrix( DirectionVector ).GetUnitAxis( EAxis::Z );

	AddMovementInput( ForwardDirection, MovementVector.X );
	AddMovementInput( RightDirection, MovementVector.Y );
	AddMovementInput( UpDirection, MovementVector.Z );
}

void ASF_TestFloatingPawn::Elevate( const FInputActionValue& Value )
{
	float MovementMagnitude = Value.Get<float>();

	AddMovementInput( FVector::UpVector, MovementMagnitude );
}

void ASF_TestFloatingPawn::Look( const FInputActionValue& Value )
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddControllerYawInput( LookAxisVector.X );
	AddControllerPitchInput( LookAxisVector.Y );
}

