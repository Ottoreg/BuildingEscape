// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerBox.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Components/PrimitiveComponent.h"
#include "CalculateMass.h"
#include "RotateDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API URotateDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URotateDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void CloseDoor();

	void OpenDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(VisibleAnywhere)
	float openAngle = -90;

	UPROPERTY(EditAnywhere)
	ATriggerBox* triggerMass = nullptr;

	UCalculateMass* calcMass = nullptr;


	AActor* player = nullptr;

	UPROPERTY(EditAnywhere)
	float closeDelay = 0.5;

	float lastTimeOpen = 0;

};
