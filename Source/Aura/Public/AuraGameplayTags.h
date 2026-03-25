// Copyright Crutch Inc.

#pragma once

#include "CoreMinimal.h"
#include <GameplayTagContainer.h>


/**
 *	AuraGameplayTags
 * 
 * Singleton containing native Gameplay Tags
 */

struct FAuraGameplayTags
{
public:
	static FAuraGameplayTags& Get()
	{
		static FAuraGameplayTags instance;
		return instance;
	}

	static void InitializeNativeGameplayTags();
public:
	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Intelligence;
	FGameplayTag Attributes_Primary_Resilience;
	FGameplayTag Attributes_Primary_Vigor;

	FGameplayTag Attributes_Secondary_Armor;
	FGameplayTag Attributes_Secondary_ArmorPenetration;
	FGameplayTag Attributes_Secondary_BlockChance;
	FGameplayTag Attributes_Secondary_CritHitChance;
	FGameplayTag Attributes_Secondary_CritHitDamage;
	FGameplayTag Attributes_Secondary_CritHitResistance;
	FGameplayTag Attributes_Secondary_HealthRegeneration;
	FGameplayTag Attributes_Secondary_ManaRegeneration;
	FGameplayTag Attributes_Secondary_MaxHealth;
	FGameplayTag Attributes_Secondary_MaxMana;

	FGameplayTag InputTag_LMB;
	FGameplayTag InputTag_RMB;
	FGameplayTag InputTag_1;
	FGameplayTag InputTag_2;
	FGameplayTag InputTag_3;
	FGameplayTag InputTag_4;
private:
	FAuraGameplayTags() {}
	~FAuraGameplayTags() {}
	FAuraGameplayTags(const FAuraGameplayTags&) = delete;
	FAuraGameplayTags& operator=(const FAuraGameplayTags&) = delete;
	FAuraGameplayTags(FAuraGameplayTags&&) = delete;
	FAuraGameplayTags& operator=(FAuraGameplayTags&&) = delete;
private:
	//static FAuraGameplayTags instance;
};