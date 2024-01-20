#include "StateMachine.h"
#include "IEngineState.h"
#include "EngineState.h"
#include "Helpers.h"
#include "MenuState.h"
#include "DebugState.h"
#include "InputManager.h"
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

	m_pActiveState = m_pMenuState;

	if (m_pMenuState)
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
	//idk wtf-ing point this serves, probably just want some kind of polymorphism
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

	if (InputManager::GetInstance()->GetKeyPressed(KeyCode::Enter))
	{
		if (m_pActiveState->GetType() == IEngineState::StateType::Menu)
		{
			if (m_pDebugState == nullptr)
			{
				m_pDebugState = new DebugState(IEngineState::StateType::Debug);
				m_pDebugState->Initialize();
			}
			m_pActiveState = m_pDebugState;
		}
	}

	m_pActiveState->Update();

	return true;
}

bool StateManager::Render()
{
	m_pActiveState->Render();

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
		if (m_pDebugState == nullptr)
		{
			m_pDebugState = new DebugState(IEngineState::StateType::Debug);
			m_pDebugState->Initialize();
		}
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
