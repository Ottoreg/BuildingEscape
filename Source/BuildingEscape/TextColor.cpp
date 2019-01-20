// Fill out your copyright notice in the Description page of Project Settings.

#include "TextColor.h"


// Sets default values for this component's properties
UTextColor::UTextColor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UTextColor::BeginPlay()
{
	Super::BeginPlay();
	textRender = GetOwner()->FindComponentByClass<UTextRenderComponent>();
	InitializeText();
	
}

void UTextColor::InitializeText()
{
	if (!textRender) {
		UE_LOG(LogTemp, Error, TEXT("textRender TextColor not found !"));
		return;
	}

	if (text == "") {
		textRender->SetText("Random");
	}
	else {
		textRender->SetText(text);
	}
	if ((colorR || colorG || colorB) != 0)
	{
		textRender->SetTextRenderColor(FColor(colorR, colorG, colorB, 255));
	}
	else{
		SetRandomTextColor();
	}
}

void UTextColor::SetRandomTextColor()
{
	int intR = FMath::RandRange(0, 255);
	int intG = FMath::RandRange(0, 255);
	int intB = FMath::RandRange(0, 255);

	textRender->SetTextRenderColor(FColor(intR, intG, intB, 255));
	SetColorText(intR, intG, intB);
}

void UTextColor::SetColorText(int r, int g, int b)
{
	uint8 intR[2] = { r };
	uint8 intG[2] = { g };
	uint8 intB[2] = { b };

	FString hexR, hexG, hexB;

	hexR = BytesToHex(intR, 1);
	hexG = BytesToHex(intG, 1);
	hexB = BytesToHex(intB, 1);

	textRender->SetText("#" + hexR + hexG + hexB);
}



// Called every frame
void UTextColor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

