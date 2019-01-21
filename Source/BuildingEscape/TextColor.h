// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/TextRenderComponent.h"
#include "Engine/TextRenderActor.h"
#include "Math/UnrealMathUtility.h"
#include "Containers/UnrealString.h "
#include "math.h"
#include "TextColor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UTextColor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTextColor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void InitializeText();
	void SetRandomTextColor();

	void SetColorText(int r, int g, int b);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	FString text;

	UPROPERTY(EditAnywhere)
	int colorR;
	int intR;

	UPROPERTY(EditAnywhere)
	int colorG;
	int intG;

	UPROPERTY(EditAnywhere)
	int colorB;
	int intB;

	UPROPERTY(EditAnywhere)
	ATextRenderActor* textRenderActorR = nullptr;
	
	UPROPERTY(EditAnywhere)
	ATextRenderActor* textRenderActorG = nullptr;

	UPROPERTY(EditAnywhere)
	ATextRenderActor* textRenderActorB = nullptr;

	int digit0;
	int digit1;
	int digit2;
	int digit3;
	int digit4;
	int digit5;
	int digit6;
	int digit7;

	int totalCount;

	bool rDone, gDone, bDone = false;

	bool GetRDone();
	bool GetGDone();
	bool GetBDone();

	UTextRenderComponent* textRender = nullptr;

	void SetPower(int _pow, bool _add);
	void UpdateText(); 

	int GetTotalCount();
	
};
