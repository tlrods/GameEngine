#pragma once

#include "Message.h"
#include <set>
#include <map>
#include <queue>

class MessageListener;

class MessageHandler
{
public:
	MessageHandler();
	~MessageHandler();

	static MessageHandler* GetInstance();
	static void DeleteInstance();

	bool Register(MessageListener*, MessageType);
	bool Unregister(MessageListener*, MessageType);
	bool QueueMessage(Message);
	bool SendMessages();

private:
	static MessageHandler* s_Instance;

	std::queue<Message> m_messageQueue;
	std::map<MessageType, std::set<MessageListener*>> m_subscriptions;
};