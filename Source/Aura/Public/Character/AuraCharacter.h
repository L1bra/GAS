// Copyright Crutch Inc.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()
public:
	AAuraCharacter();
	
	void PossessedBy(AController* NewController) override;
	void OnRep_PlayerState() override;

	/* Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/* end Combat Interface */

private:
	void InitAbilityActorInfo() override;
};
