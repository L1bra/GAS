// Copyright Crutch Inc.


#include "AbilitySystem/AbilityTasks/TargetDataUnderMouse.h"
#include <AbilitySystemComponent.h>

UTargetDataUnderMouse* UTargetDataUnderMouse::CreateTargetDataUnderMouse(UGameplayAbility* OwningAbility)
{
	UTargetDataUnderMouse* MyObj = NewAbilityTask<UTargetDataUnderMouse>(OwningAbility);
	return MyObj;
}

void UTargetDataUnderMouse::Activate()
{
	const bool IsLocallyControlled = Ability->GetCurrentActorInfo()->IsLocallyControlled();
	if (IsLocallyControlled)
	{
		SendMouseCursorData();
	}
	{
		// TODO: We are on the server so listen to the target data
	}
}

void UTargetDataUnderMouse::SendMouseCursorData()
{
	// NOTE: Everything within this scope should be predicted
	FScopedPredictionWindow ScopedPrediction(AbilitySystemComponent.Get());

	APlayerController* PC = Ability->GetCurrentActorInfo()->PlayerController.Get();
	FHitResult CursorHit;
	PC->GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);

	ValidData.Broadcast(CursorHit.Location);

	FGameplayAbilityTargetDataHandle DataHandle;

	FGameplayAbilityTargetData_SingleTargetHit* Data = new FGameplayAbilityTargetData_SingleTargetHit();
	Data->HitResult = CursorHit;
	DataHandle.Add(Data);
	
	AbilitySystemComponent->ServerSetReplicatedTargetData(
		GetAbilitySpecHandle(), 
		GetActivationPredictionKey(), 
		DataHandle, 
		FGameplayTag(), 
		AbilitySystemComponent->ScopedPredictionKey
	);
	
	if (ShouldBroadcastAbilityTaskDelegates())
	{
		ValidData.Broadcast(DataHandle);
	}
}
