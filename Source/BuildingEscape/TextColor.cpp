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
	intR = FMath::RandRange(0, 255);
	intG = FMath::RandRange(0, 255);
	intB = FMath::RandRange(0, 255);

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

void UTextColor::SetPower(int _pow, bool _add) {
	
	if(_add){

		switch (_pow)
			{
			case 0:
				digit0 = 1;
				totalCount += pow(2, _pow);
				break;
			case 1:
				digit1 = 1;
				totalCount += pow(2, _pow);
				break;
			case 2:
				digit2 = 1;
				totalCount += pow(2, _pow);
				break;
			case 3:
				digit3 = 1;
				totalCount += pow(2, _pow);
				break;
			case 4:
				digit4 = 1;
				totalCount += pow(2, _pow);
				break;
			case 5:
				digit5 = 1;
				totalCount += pow(2, _pow);
				break;
			case 6:
				digit6 = 1;
				totalCount += pow(2, _pow);
				break;
			case 7:
				digit7 = 1;
				totalCount += pow(2, _pow);
				break;
			default:
				break;
			}
	}
	else {
		switch (_pow)
			{
			case 0:
				digit0 = 0;
				totalCount -= pow(2, _pow);
				break;
			case 1:
				digit1 = 0;
				totalCount -= pow(2, _pow);
				break;
			case 2:
				digit2 = 0;
				totalCount -= pow(2, _pow);
				break;
			case 3:
				digit3 = 0;
				totalCount -= pow(2, _pow);
				break;
			case 4:
				digit4 = 0;
				totalCount -= pow(2, _pow);
				break;
			case 5:
				digit5 = 0;
				totalCount -= pow(2, _pow);
				break;
			case 6:
				digit6 = 0;
				totalCount -= pow(2, _pow);
				break;
			case 7:
				digit7 = 0;
				totalCount -= pow(2, _pow);
				break;
			default:
				break;
			}
	}

	UpdateText();

}

void UTextColor::UpdateText(){
	
	textRender->SetText(FString::FromInt(digit7) + FString::FromInt(digit6) + FString::FromInt(digit5) + FString::FromInt(digit4) + FString::FromInt(digit3) + FString::FromInt(digit2) + FString::FromInt(digit1) + FString::FromInt(digit0));
}

int UTextColor::GetTotalCount()
{
	return totalCount;
}

bool UTextColor::GetRDone()
{
	return rDone;
}
bool UTextColor::GetGDone()
{
	return gDone;
}
bool UTextColor::GetBDone()
{
	return bDone;
}


// Called every frame
void UTextColor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(textRenderActorR != nullptr && !rDone)
	{
		if (textRenderActorR->FindComponentByClass<UTextColor>()->GetTotalCount() == intR)
		{
			rDone = true;
			UE_LOG(LogTemp, Error, TEXT("R done !"));
		}
	}
	if(textRenderActorG != nullptr && !gDone)
	{
		if (textRenderActorG->FindComponentByClass<UTextColor>()->GetTotalCount() == intG)
		{
			gDone = true;
			UE_LOG(LogTemp, Error, TEXT("G done !"));
		}
	}
	if(textRenderActorB != nullptr && !bDone)
	{
		if (textRenderActorB->FindComponentByClass<UTextColor>()->GetTotalCount() == intB)
		{
			bDone = true;
			UE_LOG(LogTemp, Error, TEXT("B done !"));
		}
	}
}

