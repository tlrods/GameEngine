#include "MessageManager.h"
#include "MessageListener.h"
#include <windows.h>

MessageManager* MessageManager::s_Instance = nullptr;

MessageManager::MessageManager() 
{
	if (MessageManager::s_Instance == nullptr)
		MessageManager::s_Instance = this;
}

MessageManager::~MessageManager() {}

MessageManager* MessageManager::GetInstance()
{
	if (MessageManager::s_Instance == nullptr)
		MessageManager::s_Instance = new MessageManager;

	return MessageManager::s_Instance;
}

void MessageManager::DeleteInstance()
{
	MessageManager::s_Instance = nullptr;
}

bool MessageManager::Register(MessageListener* listener, MessageType msgType)
{
	if (!m_subscriptions.count(msgType))
	{   
		std::set<MessageListener*> listeners;
		m_subscriptions.insert(std::make_pair(msgType, listeners));
	}

	m_subscriptions.find(msgType)->second.insert(listener);

	return true;
}

bool MessageManager::Unregister(MessageListener* listener, MessageType msgType)
{
	//todo

	return true;
}

bool MessageManager::QueueMessage(Message msg)
{
	m_messageQueue.push(msg);

	return true;
}

bool MessageManager::Update()
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
