// Fill out your copyright notice in the Description page of Project Settings.

#include "BrittleFloor.h"


// Sets default values for this component's properties
UBrittleFloor::UBrittleFloor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBrittleFloor::BeginPlay()
{
	Super::BeginPlay();


	player = GetWorld()->GetFirstPlayerController()->GetPawn();

	UE_LOG(LogTemp, Error, TEXT("%s"), *player->GetName());

	float mass = player->FindComponentByClass<UPrimitiveComponent>()->GetMass();

	UE_LOG(LogTemp, Error, TEXT("%f"), mass);

	
	// ...
	
}


// Called every frame
void UBrittleFloor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!player) {
		UE_LOG(LogTemp, Error, TEXT("player BrittleFloor not found !"));
		return;
	}


	if (player->FindComponentByClass<UPrimitiveComponent>()->GetMass() >= 100)
	{
		this->GetOwner()->Destroy();
	}

	// ...
}

void UBrittleFloor::SetActorMass(AActor * _player)
{
	float mass = _player->FindComponentByClass<UPrimitiveComponent>()->GetMass();

	_player->FindComponentByClass<UPrimitiveComponent>()->SetMassOverrideInKg(NAME_None, mass + 1, true);
}

