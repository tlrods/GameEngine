#include "Message.h"

Message::Message(MessageType type, void* data)
{
	m_eType = type;
	m_pData = data;
}

Message::Message()
{
	m_eType = MessageType::None;
	m_pData = nullptr;
}

Message::~Message() {}

MessageType Message::GetMessageType()
{
	return m_eType;
}