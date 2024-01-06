#include "MessageHandler.h"
#include "MessageListener.h"
#include <windows.h>

MessageHandler* MessageHandler::s_Instance = nullptr;

MessageHandler::MessageHandler() 
{
	if (MessageHandler::s_Instance == nullptr)
		MessageHandler::s_Instance = this;
}

MessageHandler::~MessageHandler() {}

MessageHandler* MessageHandler::GetInstance()
{
	if (MessageHandler::s_Instance == nullptr)
		MessageHandler::s_Instance = new MessageHandler;

	return MessageHandler::s_Instance;
}

void MessageHandler::DeleteInstance()
{
	MessageHandler::s_Instance = nullptr;
}

bool MessageHandler::Register(MessageListener* listener, MessageType msgType)
{
	if (!m_subscriptions.count(msgType))
	{   
		std::set<MessageListener*> listeners;
		m_subscriptions.insert(std::make_pair(msgType, listeners));
	}

	/*std::vector<MessageListener*> listeners = m_subscriptions.find(msgType)->second;

	for (std::vector<MessageListener*>::iterator it = listeners.begin(); it != listeners.end(); ++it)
	{
		if ((*it) == listener)
		{
			OutputDebugString(L"Failed to register listener - already registered.");
			return false;
		}
	}

	listeners.push_back(listener);*/

	m_subscriptions.find(msgType)->second.insert(listener);

	return true;
}

bool MessageHandler::Unregister(MessageListener* listener, MessageType msgType)
{
	//todo

	return true;
}

bool MessageHandler::QueueMessage(Message msg)
{
	m_messageQueue.push(msg);

	return true;
}

bool MessageHandler::SendMessages()
{
	while (!m_messageQueue.empty())
	{
		Message currentMessage = m_messageQueue.front();

		std::set<MessageListener*> listeners = m_subscriptions.find(currentMessage.GetMessageType())->second;

		for (auto it = listeners.begin(); it != listeners.end(); ++it)
		{
			(*it)->HandleMessage(currentMessage);
		}

		m_messageQueue.pop();
	}

	return true;
}
