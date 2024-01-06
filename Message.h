#pragma once

enum class MessageType
{
	None         = 0,
	GameStart    = 1,
	GameEnd      = 2,
	GameRunning  = 3
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