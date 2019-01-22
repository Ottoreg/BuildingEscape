// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorCards.h"


// Sets default values for this component's properties
UDoorCards::UDoorCards()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorCards::BeginPlay()
{
	Super::BeginPlay();

	if (!trigger1) {
		UE_LOG(LogTemp, Error, TEXT("trigger1 DoorCards not found !"));
		return;
	}
	TG1 = trigger1->FindComponentByClass<UTriggerCards>();

	if (!trigger2) {
		UE_LOG(LogTemp, Error, TEXT("trigger2 DoorCards not found !"));
		return;
	}
	TG2 = trigger2->FindComponentByClass<UTriggerCards>();

	if (!trigger3) {
		UE_LOG(LogTemp, Error, TEXT("trigger3 DoorCards not found !"));
		return;
	}
	TG3 = trigger3->FindComponentByClass<UTriggerCards>();

	if (!trigger4) {
		UE_LOG(LogTemp, Error, TEXT("trigger4 DoorCards not found !"));
		return;
	}
	TG4 = trigger4->FindComponentByClass<UTriggerCards>();

	if (!trigger5) {
		UE_LOG(LogTemp, Error, TEXT("trigger5 DoorCards not found !"));
		return;
	}
	TG5 = trigger5->FindComponentByClass<UTriggerCards>();

	if (!trigger6) {
		UE_LOG(LogTemp, Error, TEXT("trigger6 DoorCards not found !"));
		return;
	}
	TG6 = trigger6->FindComponentByClass<UTriggerCards>();

	if (!trigger7) {
		UE_LOG(LogTemp, Error, TEXT("trigger7 DoorCards not found !"));
		return;
	}
	TG7 = trigger7->FindComponentByClass<UTriggerCards>();	 
	// ...
	
}


// Called every frame
void UDoorCards::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if ((TG1->GetCardIn() && TG2->GetCardIn() && TG3->GetCardIn() && TG4->GetCardIn() && TG5->GetCardIn() && TG6->GetCardIn() && TG7->GetCardIn()) == true)
	{
		OnOpenRequest.Broadcast();
	}

	// ...
}

