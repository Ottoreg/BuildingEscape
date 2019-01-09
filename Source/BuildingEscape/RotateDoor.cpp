// Fill out your copyright notice in the Description page of Project Settings.

#include "RotateDoor.h"


// Sets default values for this component's properties
URotateDoor::URotateDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void URotateDoor::OpenDoor()
{
	FRotator rotation(0, openAngle, 0); // pitch YAW roll
	GetOwner()->SetActorRotation(rotation);
}

void URotateDoor::CloseDoor()
{
	FRotator rotation(0, 0, 0); // pitch YAW roll
	GetOwner()->SetActorRotation(rotation);
}

// Called when the game starts
void URotateDoor::BeginPlay()
{
	Super::BeginPlay();

	player = GetWorld()->GetFirstPlayerController()->GetPawn();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *player->GetName());

	
}


// Called every frame
void URotateDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (trigger->IsOverlappingActor(player)) {
		UE_LOG(LogTemp, Warning, TEXT("overlapping actor : %s"), *player->GetName());
		OpenDoor();
		lastTimeOpen = GetWorld()->GetTimeSeconds();
	}else if (GetWorld()->GetTimeSeconds() - lastTimeOpen > closeDelay)
	{
		CloseDoor();
	}

}

