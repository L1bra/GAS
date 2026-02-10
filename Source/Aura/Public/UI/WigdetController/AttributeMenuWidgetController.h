// Copyright Crutch Inc.

#pragma once

#include "CoreMinimal.h"
#include "UI/WigdetController/AuraWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAttributeMenuWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()
public:
	void BindCallbacksToDependencies() override;
	void BroadcastInitialValues() override;
};
