#pragma once

#include "Message.h"
#include <vector>

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

private:
	static MessageHandler* s_Instance;

	std::vector<Message> m_messageQueue;
	std::vector<MessageListener*> m_listeners;
};