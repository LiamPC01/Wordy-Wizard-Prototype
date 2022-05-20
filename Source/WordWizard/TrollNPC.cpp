// Fill out your copyright notice in the Description page of Project Settings.


#include "TrollNPC.h"

void ATrollNPC::HideTroll()
{
	FVector TrollHideLocation = {0.f,0.f,0.f};
	SetActorLocation(TrollHideLocation);
}
