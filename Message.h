#pragma once

enum class MessageType
{
	MSG_NONE       = 0,
	MSG_GAME_START = 1,
	MSG_GAME_END   = 2
};

class Message
{
public:
	Message(MessageType, void*);
	Message();
	~Message();

	MessageType GetMessageType();
private:
	MessageType m_eType;
	void* m_pData;
};