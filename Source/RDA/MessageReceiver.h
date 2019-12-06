#pragma once

#include "CoreMinimal.h"
#include "MessageReceiver.generated.h"

USTRUCT()
struct FTestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FString SomeString;

	// default constructor for the receiver
	FTestMessage() = default;
	// helper constructor for the sender
	FTestMessage(const FString& TheMessage)
		: SomeString(TheMessage)
	{
	}
};

class FMessageEndpoint;
class IMessageContext;
struct FMessageBusNotification;

DECLARE_DELEGATE_OneParam(FMessageReceivedDelegate, const FTestMessage&);

class RDA_API UMessageReceiver
{
public:

	UMessageReceiver(UMessageReceiver& MessagingSender) = delete;
	UMessageReceiver();
	~UMessageReceiver();

	void Init();

	void Shutdown();

	UFUNCTION()
	void HandleTestMessage(const FTestMessage& Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

	FMessageReceivedDelegate MessageReceivedEvent;

private:

	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> MessageEndpoint;

	static const FName EndpointName;
};