// Fill out your copyright notice in the Description page of Project Settings.


#include "GA/SFGA_AdjustSpeed.h"
#include "AbilitySystemComponent.h"

USFGA_AdjustSpeed::USFGA_AdjustSpeed()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;

	static ConstructorHelpers::FClassFinder<UGameplayEffect> GE_ClassRef( TEXT( "" ) );
}

void USFGA_AdjustSpeed::ActivateAbility( const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData )
{
	Super::ActivateAbility( Handle, ActorInfo, ActivationInfo, TriggerEventData );

	auto ASC = ActorInfo->AbilitySystemComponent.Get();

	if ( ASC )
	{
		auto EffectContext = ASC->MakeEffectContext();
		EffectContext.AddSourceObject( this );
		//auto EffectSpecHandle = ASC->MakeOutgoingSpec()

	}
}

void USFGA_AdjustSpeed::EndAbility( const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled )
{
	Super::EndAbility( Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled );
}
