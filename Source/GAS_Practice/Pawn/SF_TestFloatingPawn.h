// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "SF_TestFloatingPawn.generated.h"

UCLASS()
class GAS_PRACTICE_API ASF_TestFloatingPawn : public APawn
{
	GENERATED_BODY()

public:
	ASF_TestFloatingPawn();

protected:
	virtual void BeginPlay() override;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

// Camera Section
protected:
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true") )
	TObjectPtr<class UCameraComponent> FollowCamera;

// Mesh Section
protected:
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Mesh, Meta = (AllowPrivateAccess = "true") )
	TObjectPtr<class UStaticMeshComponent> Mesh;

	// Movement Section
protected:
	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = Movement, Meta = (AllowPrivateAccess = "true") )
	TObjectPtr<class UFloatingPawnMovement> FloatingPawnMovement;

// Input Section
protected:
	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true") )
	TObjectPtr<class UInputMappingContext> MappingContext;

	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true") )
	TObjectPtr<class UInputAction> IA_Move;

	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true") )
	TObjectPtr<class UInputAction> IA_Elevate;

	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true") )
	TObjectPtr<class UInputAction> IA_Look;

	void Move( const FInputActionValue& Value );
	void Elevate( const FInputActionValue& Value );
	void Look( const FInputActionValue& Value );

};
