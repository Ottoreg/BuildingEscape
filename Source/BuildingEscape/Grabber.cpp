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
	handle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (!handle)
	{
		UE_LOG(LogTemp, Warning, TEXT("error handle doesn't exists yet"));
	}

	UInputComponent* inputC = GetOwner()->FindComponentByClass<UInputComponent>(); // input component pour Grab et Release

	if (!inputC)
	{
		UE_LOG(LogTemp, Warning, TEXT("error input component doesn't exists yet"));
	}

	inputC->BindAction("Grab", IE_Pressed, this, &UGrabber::Grabbed);
	inputC->BindAction("Grab", IE_Released, this, &UGrabber::Released);

	
}

void UGrabber::Released()
{
	UE_LOG(LogTemp, Warning, TEXT("Released"));
}

void UGrabber::Grabbed()
{

	
	FHitResult hit;
	if (GetWorld()->LineTraceSingleByObjectType(hit, startPoint, endPoint, ECollisionChannel::ECC_PhysicsBody, FCollisionQueryParams(FName(), false, GetOwner())))
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor touched name : %s grabbed"), *hit.GetActor()->GetName());
		handle->GrabComponent(hit.GetComponent(), NAME_None, hit.GetActor()->GetActorLocation(), true);
	}

}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (handle->GetGrabbedComponent() != nullptr)
	{
		player->GetPlayerViewPoint(startPoint, playerRot);
		endPoint = startPoint + playerRot.Vector() * viewDistance;
		handle->SetTargetLocation(endPoint);
	}

}

