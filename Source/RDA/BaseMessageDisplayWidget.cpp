// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseMessageDisplayWidget.h"
#include "MessageReceiver.h"
#include "Components/TextBlock.h"

void UBaseMessageDisplayWidget::NativeConstruct()
{
	MessageReceiver = MakeUnique<UMessageReceiver>();
	if (MessageReceiver.IsValid())
	{	
		MessageReceiver->MessageReceivedEvent.BindUObject(this, &UBaseMessageDisplayWidget::MessageReceived);
		MessageReceiver->Init();
	}
}

void UBaseMessageDisplayWidget::MessageReceived(const struct FTestMessage& InMessage)
{
	MessageTxt->SetText(FText::FromString(InMessage.SomeString));
}