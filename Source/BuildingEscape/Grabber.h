// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void Released();

	void Grabbed();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;



private:

	APlayerController* player = nullptr; // Référence sur player pour récupérer le player view point

	UPhysicsHandleComponent* handle = nullptr; // Référence sur mon PhysicsHandle pour gérer le grab et release

	FVector startPoint;

	FRotator playerRot;

	FVector endPoint;

	UPROPERTY(EditAnyWhere)
	float viewDistance = 250;  // Distance Maximale de grab

};
