#include "StateMachine.h"
#include "IEngineState.h"
#include "EngineState.h"
#include "Helpers.h"
#include "MenuState.h"
#include "DebugState.h"

#include "debugapi.h"

StateManager::StateManager(): m_pActiveState(nullptr), m_pMenuState(nullptr), m_pDebugState(nullptr)
{
}

StateManager::~StateManager()
{
	SAFE_DELETE(m_pMenuState);
	SAFE_DELETE(m_pDebugState);
}

bool StateManager::Initialize()
{
	m_pMenuState = new MenuState(IEngineState::StateType::Menu);
	m_pDebugState = new DebugState(IEngineState::StateType::Debug);

	m_pActiveState = m_pMenuState;

	if (m_pMenuState && m_pDebugState)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool StateManager::Update(unsigned long dt)
{
	return true;
}

bool StateManager::Render()
{
	switch (m_pActiveState->GetType())
	{
	case IEngineState::StateType::Menu:
	{
#if DEBUG_STATE
		if (!DEBUG_TESTEROO)
		{
			OutputDebugString(L"\n Menu State is active \n");
			DEBUG_TESTEROO = true;
		}
#endif
	}
		break;
	case IEngineState::StateType::Debug:
#if DEBUG_STATE
	{
		if (!DEBUG_TESTEROO)
		{
			OutputDebugString(L" \n Debug State is active \n");
			DEBUG_TESTEROO = true;
		}
	}
#endif
			break;
	default:
		break;
	}
	

	return true;
}

bool StateManager::TransitionState(IEngineState::StateType& eType)
{
	switch (eType)
	{
	case IEngineState::StateType::Menu:
		m_pActiveState = m_pMenuState;
#if DEBUG_STATE
		DEBUG_TESTEROO = false;
#endif
		break;
	case IEngineState::StateType::Debug:
		m_pActiveState = m_pDebugState;
#if DEBUG_STATE
		DEBUG_TESTEROO = false;
#endif
		break;
	default:
		break;
	}
	return false;
}
