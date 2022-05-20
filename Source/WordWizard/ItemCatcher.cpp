// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemCatcher.h"
#include "PickupActor.h"
#include "TrollItem.h"
#include "TrollNPC.h"

AItemCatcher::AItemCatcher()
{
	OnActorBeginOverlap.AddDynamic(this, &AItemCatcher::TriggerEnter);
	OnActorEndOverlap.AddDynamic(this, &AItemCatcher::TriggerExit);
}

void AItemCatcher::BeginPlay()
{
	Super::BeginPlay();
}

void AItemCatcher::TriggerEnter(class AActor* overlappedActor, class AActor* otherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("AItemCatcher TriggerEnter"));
/*
	if(otherActor->IsA(ATrollItem::StaticClass()))
	{ 
		// Destroy or move Troll NPC
		ATrollNPC* Troll = Cast<ATrollNPC>(???);
		if(Troll != nullptr)
		{
			Troll->HideTroll();
		}
	}
	*/
}

void AItemCatcher::TriggerExit(class AActor* overlappedActor, class AActor* otherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("AItemCatcher TriggerExit"));
}
