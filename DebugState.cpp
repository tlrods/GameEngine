#include "DebugState.h"

bool DebugState::Initialize()
{
	return false;
}

bool DebugState::Update()
{
	return false;
}

bool DebugState::Render()
{
	return false;
}

bool DebugState::Shutdown()
{
	return false;
}

IEngineState::StateType DebugState::GetType()
{
	return IEngineState::StateType::Debug;
}

IEngineState* DebugState::GetPrevious()
{
	return nullptr;
}

void DebugState::SetPrevious(IEngineState& pPrev)
{
}
