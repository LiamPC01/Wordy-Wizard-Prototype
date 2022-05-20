// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupActor.h"

#include "WordWizardCharacter.h"


// Sets default values
APickupActor::APickupActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	TBox->SetGenerateOverlapEvents(true);
	TBox->OnComponentBeginOverlap.AddDynamic(this, &APickupActor::TriggerEnter);
	TBox->OnComponentEndOverlap.AddDynamic(this, &APickupActor::TriggerExit);

	RootComponent = TBox;

	SM_TBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box Mesh"));
	SM_TBox->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void APickupActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APickupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ObjectSpin();

}

void APickupActor::TriggerEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}

void APickupActor::TriggerExit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void APickupActor::ObjectSpin()
{
	if(BSpins)
	{
		ObjectRotation.Yaw += 1;
		SetActorRotation(ObjectRotation, ETeleportType::TeleportPhysics);
	}
}

