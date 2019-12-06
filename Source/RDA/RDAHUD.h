// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RDAHUD.generated.h"

UCLASS()
class ARDAHUD : public AHUD
{
	GENERATED_BODY()

public:
	ARDAHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	virtual void BeginPlay() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

	TSubclassOf<class UBaseMessageDisplayWidget> MessageWidgetClass;

	class UBaseMessageDisplayWidget* MessageWidget;
};

