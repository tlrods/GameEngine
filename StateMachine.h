#pragma once
#include "IEngineState.h"

class EngineState;

class StateManager
{

public:

	StateManager();
	~StateManager();

	bool InitializeStates();
	bool TransitionState(IEngineState::StateType& eType);

private:

	EngineState* m_pActiveState;
	EngineState* m_pMenuState;
	EngineState* m_pDebugState;
};