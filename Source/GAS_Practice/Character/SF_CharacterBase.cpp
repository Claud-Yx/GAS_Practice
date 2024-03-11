// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/SF_CharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Physics/SF_Physics.h"

ASF_CharacterBase::ASF_CharacterBase()
{
	// Pawn
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Capsule
	GetCapsuleComponent()->InitCapsuleSize( 42.f, 96.f );
	//GetCapsuleComponent()->SetCollisionProfileName();

	// Movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator( 0.f, 500.f, 0.f );
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.4f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Mesh
	GetMesh()->SetRelativeLocationAndRotation( FVector( 0.f, 0.f, -100.f ), FRotator( 0.f, -90.f, 0.f ) );
	GetMesh()->SetAnimationMode( EAnimationMode::AnimationBlueprint );
	GetMesh()->SetCollisionProfileName( TEXT( "CP_NoCollision" ) );


}

