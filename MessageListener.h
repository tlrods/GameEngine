#pragma once

#include "Message.h"

class MessageListener
{
public:
	MessageListener();
	~MessageListener();

	bool Register(MessageType);
	bool Unregister(MessageType);
	unsigned int GetId();
	virtual void HandleMessage(Message*);
private:
	unsigned int m_uId;
};