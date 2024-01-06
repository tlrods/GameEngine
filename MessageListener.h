#pragma once

#include "Message.h"

class MessageListener
{
public:
	MessageListener();
	~MessageListener();

	bool Register(MessageType);
	bool Unregister(MessageType);
private:

};