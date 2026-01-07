// Copyright Crutch Inc.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	void HighlightActor() override;
	void UnHighlightActor() override;
public:
	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;
};
