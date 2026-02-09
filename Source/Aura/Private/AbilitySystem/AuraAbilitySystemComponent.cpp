// Copyright Crutch Inc.


#include "AbilitySystem/AuraAbilitySystemComponent.h"

#include "AuraGameplayTags.h"
#include <Engine/Engine.h>

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);

	const FAuraGameplayTags& AuraGameplayTags = FAuraGameplayTags::Get();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Tag: %s"), *AuraGameplayTags.Attributes_Secondary_Armor.ToString()));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Tag: %s"), *AuraGameplayTags.Attributes_Secondary_ArmorPenetration.ToString()));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Tag: %s"), *AuraGameplayTags.Attributes_Secondary_BlockChance.ToString()));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Tag: %s"), *AuraGameplayTags.Attributes_Secondary_CritHitChance.ToString()));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Tag: %s"), *AuraGameplayTags.Attributes_Secondary_CritHitDamage.ToString()));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Tag: %s"), *AuraGameplayTags.Attributes_Secondary_CritHitResistance.ToString()));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Tag: %s"), *AuraGameplayTags.Attributes_Secondary_HealthRegeneration.ToString()));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Tag: %s"), *AuraGameplayTags.Attributes_Secondary_ManaRegeneration.ToString()));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Tag: %s"), *AuraGameplayTags.Attributes_Secondary_MaxHealth.ToString()));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Tag: %s"), *AuraGameplayTags.Attributes_Secondary_MaxMana.ToString()));

}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
}
