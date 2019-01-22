// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerBox.h"
#include "Engine/StaticMeshActor.h"
#include "TriggerCards.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UTriggerCards : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTriggerCards();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void checkCardIn();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	AStaticMeshActor* card = nullptr;

	ATriggerBox* trigger = nullptr;

	bool goodCardIn = false;

	bool GetCardIn();
	
};
