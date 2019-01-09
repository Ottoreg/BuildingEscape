// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	player = GetWorld()->GetFirstPlayerController();
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector startPoint;
	FRotator playerRot;
	player->GetPlayerViewPoint(startPoint, playerRot);
	//UE_LOG(LogTemp, Warning, TEXT("location : %s , rotation : %s"), *startPoint.ToString(), *playerRot.ToString());
	FVector endPoint = startPoint + playerRot.Vector()*viewDistance;

	FHitResult hit;

	if (GetWorld()->LineTraceSingleByObjectType(hit, startPoint, endPoint, ECollisionChannel::ECC_PhysicsBody, FCollisionQueryParams(FName(), false, GetOwner())))
	{
		FString nameActorTouched;
		nameActorTouched = hit.GetActor()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Actor touched name : %s"), *nameActorTouched);
	}

}

