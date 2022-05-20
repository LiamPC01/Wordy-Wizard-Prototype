// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "PickupActor.generated.h"

UCLASS()
class WORDWIZARD_API APickupActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APickupActor();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		UShapeComponent* TBox;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SM_TBox;

	UFUNCTION()
		void TriggerEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void TriggerExit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

	void ObjectSpin();

	FRotator ObjectRotation = {0.f,0.f,0.f};
	
	UPROPERTY(EditAnywhere)
	bool BSpins = true;



	




};
