#include "Application.h"
#include "StateMachine.h"

void Application::Intitialize(HWND inHWnd, HINSTANCE inHInst, UINT screenWidth, UINT screenHeight)
{
	hWnd = inHWnd;
	hInst = inHInst;

	m_pStateManager = new StateManager;
	m_pStateManager->Initialize();
}

void Application::Update()
{
	m_pStateManager->Update();
}

void Application::Render()
{
	m_pStateManager->Render();
}

void Application::Shutdown()
{
}

Application::Application()
{
}

Application::~Application()
{
}
