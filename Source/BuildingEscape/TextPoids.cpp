// Fill out your copyright notice in the Description page of Project Settings.

#include "TextPoids.h"


// Sets default values for this component's properties
UTextPoids::UTextPoids()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTextPoids::BeginPlay()
{
	Super::BeginPlay();

	if (!triggerMass) {
		UE_LOG(LogTemp, Error, TEXT("triggerMass TextPoids not found !"));
		return;
	}
	calcMass = triggerMass->FindComponentByClass<UCalculateMass>();

	textRender = GetOwner()->FindComponentByClass<UTextRenderComponent>();

	

	// ...
	
}


// Called every frame
void UTextPoids::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MajText();

	// ...
}

void UTextPoids::MajText()
{
	if (!textRender) {
		UE_LOG(LogTemp, Error, TEXT("textRender TextPoids not found !"));
		return;
	}
	textRender->SetText(FText::AsNumber(FMath::RoundToFloat(calcMass->MajMass())));
}

