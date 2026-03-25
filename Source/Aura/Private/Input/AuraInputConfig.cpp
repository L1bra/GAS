// Copyright Crutch Inc.


#include "Input/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindAbilityInputAction(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (const FAuraInputAction& Action : AbilityInputAction)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Cant find AbilityInputAction for InputTag [%s], on InputConfig [%s]"), *InputTag.ToString(), *GetNameSafe(this));
	}
	return nullptr;
}
