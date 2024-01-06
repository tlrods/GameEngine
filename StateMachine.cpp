#include "StateMachine.h"
#include "IEngineState.h"
#include "EngineState.h"
#include "Helpers.h"
#include "MenuState.h"
#include "DebugState.h"

StateManager::StateManager(): m_pActiveState(nullptr), m_pMenuState(nullptr), m_pDebugState(nullptr)
{
}

StateManager::~StateManager()
{
	SAFE_DELETE(m_pMenuState);
	SAFE_DELETE(m_pDebugState);
}

bool StateManager::InitializeStates()
{
	m_pMenuState = new MenuState(IEngineState::StateType::Menu);
	m_pDebugState = new DebugState(IEngineState::StateType::Debug);

	m_pDebugState->SetPrevious(*m_pMenuState);

	if (m_pMenuState && m_pDebugState)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool StateManager::TransitionState(IEngineState::StateType& eType)
{
	switch (eType)
	{
	case IEngineState::StateType::Menu:
		m_pActiveState = m_pMenuState;
		break;
	case IEngineState::StateType::Debug:
		m_pActiveState = m_pDebugState;
		break;
	default:
		break;
	}
	return false;
}
