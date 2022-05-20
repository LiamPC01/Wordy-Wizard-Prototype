// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "ItemCatcher.generated.h"

/**
 * 
 */
UCLASS()
class WORDWIZARD_API AItemCatcher : public ATriggerBox
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	AItemCatcher();

	UFUNCTION()
	void TriggerEnter(class AActor* overlappedActor, class AActor* otherActor);

	UFUNCTION()
	void TriggerExit(class AActor* overlappedActor, class AActor* otherActor);
	
};
