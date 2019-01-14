// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerBox.h"
#include "Components/TextRenderComponent.h"
#include "CalculateMass.h"
#include "TextPoids.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UTextPoids : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTextPoids();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void MajText();

	UPROPERTY(EditAnywhere)
	ATriggerBox* triggerMass = nullptr;

	UCalculateMass* calcMass = nullptr;

	UTextRenderComponent* textRender = nullptr;
	
};
