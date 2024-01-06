#include "MessageListener.h"
#include "MessageHandler.h"

MessageListener::MessageListener() {}

MessageListener::~MessageListener() {}

bool MessageListener::Register(MessageType messageType)
{
	if (!MessageHandler::GetInstance()->Register(this, messageType))
	{
		return false;
	}

	return true;
}

bool MessageListener::Unregister(MessageType messageType)
{
	if (!MessageHandler::GetInstance()->Unregister(this, messageType))
	{
		return false;
	}

	return true;
}