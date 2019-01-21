// Fill out your copyright notice in the Description page of Project Settings.

#include "ColorButton.h"


// Sets default values for this component's properties
UColorButton::UColorButton()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UColorButton::BeginPlay()
{
	Super::BeginPlay();

	if (!textRenderActor)
	{
		UE_LOG(LogTemp, Error, TEXT("textRenderActor ColorButton not found !"));
		return;
	}
	textRender = textRenderActor->FindComponentByClass<UTextRenderComponent>();

	// ...
	
}


// Called every frame
void UColorButton::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UColorButton::OnButtonClic() {

	if (activated)
	{
		activated = false;
		textRenderActor->FindComponentByClass<UTextColor>()->SetPower(twoPower,activated);
	}
	else 
	{
		activated = true;
		textRenderActor->FindComponentByClass<UTextColor>()->SetPower(twoPower,activated);
	}
}

int UColorButton::GetTwoPower(){
	return twoPower;
}

bool UColorButton::GetActivated(){
	return activated;
}