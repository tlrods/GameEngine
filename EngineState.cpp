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

IEngineState* EngineState::GetPrevious()
{
	return m_pPreviousState;
}

void EngineState::SetPrevious(IEngineState& pPrev)
{
	//TODO: Crashes when previous state is null
	*m_pPreviousState = pPrev;
}
