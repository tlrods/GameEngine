#include "MessageHandler.h"

MessageHandler* MessageHandler::s_Instance = nullptr;

MessageHandler::MessageHandler() {}

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

bool MessageHandler::Register(MessageListener* listener, MessageType messageType)
{
	//todo

	return true;
}

bool MessageHandler::Unregister(MessageListener* listener, MessageType messageType)
{
	//todo

	return true;
}