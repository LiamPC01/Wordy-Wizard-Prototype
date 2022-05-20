// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTeleportBox.h"

AMyTeleportBox::AMyTeleportBox()
{
	OnActorBeginOverlap.AddDynamic(this, &AMyTeleportBox::EnterTeleporter);
	OnActorEndOverlap.AddDynamic(this, &AMyTeleportBox::ExitTeleporter);
	bIsTeleporting = false;
}

void AMyTeleportBox::BeginPlay()
{
	Super::BeginPlay();
}

void AMyTeleportBox::EnterTeleporter(class AActor* overlappedActor, class AActor* otherActor)
{
	if (otherActor && otherActor != this)
	{
		if (otherTele)
		{
			AWordWizardCharacter* character = Cast<AWordWizardCharacter>(otherActor);
			if (character && !otherTele->bIsTeleporting)
			{
				bIsTeleporting = true;
				character->SetActorRotation(otherTele->GetActorRotation());
				character->GetController()->SetControlRotation(character-> GetActorRotation());
				character->SetActorLocation(otherTele->GetActorLocation());
			}
		}
	}
}

void AMyTeleportBox::ExitTeleporter(class AActor* overlappedActor, class AActor* otherActor)
{
	if (otherActor && otherActor != this)
	{
		if (otherTele && !bIsTeleporting)
		{
			otherTele->bIsTeleporting = false;
		}
	}
}