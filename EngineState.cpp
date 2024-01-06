#include "IEngineState.h"
#include "EngineState.h"

bool EngineState::Initialize()
{
	return false;
}

bool EngineState::Update()
{
	return false;
}

bool EngineState::Render()
{
	return false;
}

bool EngineState::Shutdown()
{
	return false;
}

IEngineState::StateType EngineState::GetType()
{
	return m_eType;
}