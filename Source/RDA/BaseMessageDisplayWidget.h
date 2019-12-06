// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MessageReceiver.h"
#include "BaseMessageDisplayWidget.generated.h"

/**
 * 
 */
UCLASS()
class RDA_API UBaseMessageDisplayWidget : public UUserWidget
{
	GENERATED_BODY()
	
	virtual void NativeConstruct() override;

	void MessageReceived(const struct FTestMessage& InMessage);

private:

	TUniquePtr<UMessageReceiver> MessageReceiver;

	UPROPERTY(meta=(BindWidget))
	class UTextBlock* MessageTxt;
};
