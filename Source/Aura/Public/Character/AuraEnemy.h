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
	AAuraEnemy();

	// Enemy interface
	void HighlightActor() override;
	void UnHighlightActor() override;

	// Combat interface
	int32 GetPlayerLevel() override;
protected:
	void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;
protected:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;
};
