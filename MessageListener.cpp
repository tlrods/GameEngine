#include "MessageListener.h"
#include "MessageHandler.h"

MessageListener::MessageListener() 
{
	m_uId = -1;
}

MessageListener::~MessageListener() {}

bool MessageListener::Register(MessageType msgType)
{
	if (!MessageHandler::GetInstance()->Register(this, msgType))
	{
		return false;
	}

	return true;
}

bool MessageListener::Unregister(MessageType msgType)
{
	if (!MessageHandler::GetInstance()->Unregister(this, msgType))
	{
		return false;
	}

	return true;
}

unsigned int MessageListener::GetId()
{
	return m_uId;
}

void MessageListener::HandleMessage(Message msg)
{
	bool bIsGameRunning = false;

	switch ((MessageType)msg.GetMessageType())
	{
	case MessageType::GameRunning:
		bIsGameRunning = true;
	default:
		break;
	}
}
