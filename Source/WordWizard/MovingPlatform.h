// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class WORDWIZARD_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float PitchRotateSpeed = 0;
	UPROPERTY(EditAnywhere)
	float RollRotateSpeed = 0;
	UPROPERTY(EditAnywhere)
	float YawRotateSpeed = 0;
	
	UPROPERTY(EditAnywhere)
	float XMoveSpeed = 0;
	UPROPERTY(EditAnywhere)
	float YMoveSpeed = 0;
	UPROPERTY(EditAnywhere)
	float ZMoveSpeed = 0;

	UPROPERTY(EditAnywhere)
	float StartPos = 0;
	UPROPERTY(EditAnywhere)
	float EndPos = 0;

	void RotateActor();
	void MoveActor();
	void CheckDirection();

	FVector ActorLocation = GetActorLocation();

	

	
};
