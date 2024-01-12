#pragma once

#include "Message.h"
#include <set>
#include <map>
#include <queue>

class MessageListener;

class MessageManager
{
public:
	MessageManager();
	~MessageManager();

	static MessageManager* GetInstance();
	static void DeleteInstance();

	bool Register(MessageListener*, MessageType);
	bool Unregister(MessageListener*, MessageType);
	bool QueueMessage(Message);
	bool Update();

private:
	static MessageManager* s_Instance;

	std::queue<Message> m_messageQueue;
	std::map<MessageType, std::set<MessageListener*>> m_subscriptions;
};