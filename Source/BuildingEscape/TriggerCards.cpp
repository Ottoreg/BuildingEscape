// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerCards.h"


// Sets default values for this component's properties
UTriggerCards::UTriggerCards()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTriggerCards::BeginPlay()
{
	Super::BeginPlay();

	trigger = (ATriggerBox*)GetOwner();

	// ...
	
}

void UTriggerCards::checkCardIn()
{
	TSet<AActor*> overlappingActors;
	if (!trigger) {
		UE_LOG(LogTemp, Error, TEXT("trigger CalculateMass not found !"));
		return;
	}
	trigger->GetOverlappingActors(overlappingActors);

	for (AActor* actor : overlappingActors)
	{
		if (actor == card)
		{
			goodCardIn = true;
			UE_LOG(LogTemp, Error, TEXT("good card in !"));
		}
		else {
			goodCardIn = false;
			UE_LOG(LogTemp, Warning, TEXT("wrong card in !"));
		}
	}

}


// Called every frame
void UTriggerCards::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	checkCardIn();
	// ...
}

bool UTriggerCards::GetCardIn()
{
	return goodCardIn;
}

