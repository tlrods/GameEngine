#include "DebugState.h"
#include "Helpers.h"
#include "Player.h"

DebugState::~DebugState()
{
	SAFE_DELETE(m_pPlayer);
}

bool DebugState::Initialize()
{
	bool ret = true;

	m_pPlayer = new Player();

	if (m_pPlayer == nullptr)
	{
		ret = false;
	}

	return ret;
}

bool DebugState::Update()
{
	bool ret = true;

	m_pPlayer->Update();

	return ret;
}

bool DebugState::Render()
{
	bool ret = true;

	m_pPlayer->Render();

	return ret;
}

bool DebugState::Shutdown()
{
	bool ret = true;

	return ret;
}

IEngineState::StateType DebugState::GetType()
{
	return IEngineState::StateType::Debug;
}
