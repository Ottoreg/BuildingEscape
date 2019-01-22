// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TriggerCards.h"
#include "DoorCards.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorCardsEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UDoorCards : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorCards();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	ATriggerBox* trigger1 = nullptr;
	UTriggerCards* TG1;
	UPROPERTY(EditAnywhere)
	ATriggerBox* trigger2 = nullptr;
	UTriggerCards* TG2;
	UPROPERTY(EditAnywhere)
	ATriggerBox* trigger3 = nullptr;
	UTriggerCards* TG3;
	UPROPERTY(EditAnywhere)
	ATriggerBox* trigger4 = nullptr;
	UTriggerCards* TG4;
	UPROPERTY(EditAnywhere)
	ATriggerBox* trigger5 = nullptr;
	UTriggerCards* TG5;
	UPROPERTY(EditAnywhere)
	ATriggerBox* trigger6 = nullptr;
	UTriggerCards* TG6;
	UPROPERTY(EditAnywhere)
	ATriggerBox* trigger7 = nullptr;
	UTriggerCards* TG7;

	UPROPERTY(BlueprintAssignable)
	FDoorCardsEvent OnOpenRequest;
};
