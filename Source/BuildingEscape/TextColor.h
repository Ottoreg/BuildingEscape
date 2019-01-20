// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/TextRenderComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Containers/UnrealString.h "
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

	UPROPERTY(EditAnywhere)
	int colorG;

	UPROPERTY(EditAnywhere)
	int colorB;

	UTextRenderComponent* textRender = nullptr;

	
};