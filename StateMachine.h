#pragma once
#include "IEngineState.h"

class EngineState;

class StateManager
{

public:

	StateManager();
	~StateManager();

	bool Initialize();
	bool Update(unsigned long dt);
	bool Render();
	bool TransitionState(IEngineState::StateType& eType);

private:

	EngineState* m_pActiveState;
	EngineState* m_pMenuState;
	EngineState* m_pDebugState;

	bool DEBUG_TESTEROO = false;
};