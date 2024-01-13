#include "MessageListener.h"
#include "MessageManager.h"
#include "Input.h"
#include "Helpers.h"

MessageListener::MessageListener() 
{
	m_uId = -1;
}

MessageListener::~MessageListener() {}

bool MessageListener::Register(MessageType msgType)
{
	if (!MessageManager::GetInstance()->Register(this, msgType))
	{
		return false;
	}

	return true;
}

bool MessageListener::Unregister(MessageType msgType)
{
	if (!MessageManager::GetInstance()->Unregister(this, msgType))
	{
		return false;
	}

	return true;
}

unsigned int MessageListener::GetId()
{
	return m_uId;
}

void MessageListener::HandleMessage(Message* msg)
{
	bool bIsGameRunning = false;

	switch ((MessageType)msg->GetMessageType())
	{
	case MessageType::GameStart:
	{
		bIsGameRunning = true;
		break;
	}
	case MessageType::GameEnd:
	{
		bIsGameRunning = false;
		break;
	}
	default:
		break;
	}
}
