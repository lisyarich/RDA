#include "MessageReceiver.h"
#include "IMessageContext.h"
#include "MessageEndpoint.h"
#include "MessageEndpointBuilder.h"

const FName UMessageReceiver::EndpointName = FName(TEXT("RemoteDepdloyment"));

UMessageReceiver::UMessageReceiver()
{
}

UMessageReceiver::~UMessageReceiver()
{
}

void UMessageReceiver::Init()
{  
	MessageEndpoint = FMessageEndpoint::Builder(EndpointName)
		.Handling<FTestMessage>(this, &UMessageReceiver::HandleTestMessage);

	if (MessageEndpoint.IsValid())
		MessageEndpoint->Subscribe<FTestMessage>();
}

void UMessageReceiver::Shutdown()
{	
	MessageEndpoint.Reset();
}

void UMessageReceiver::HandleTestMessage(const FTestMessage& Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	UE_LOG(LogTemp, Warning, TEXT("We just received a test message that said: %s"), *Message.SomeString);
	MessageReceivedEvent.ExecuteIfBound(Message);
}