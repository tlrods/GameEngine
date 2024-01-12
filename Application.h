#pragma once
#include "Helpers.h" //TODO: There's a way to make all headers auto include this

class StateManager;
class MessageManager;

class Application
{

public:

	void Intitialize(HWND inHWnd, HINSTANCE inHInst, UINT screenWidth, UINT screenHeight);
	void Update();
	void Render();
	void Shutdown();

	Application();
	~Application();

private:

	HWND hWnd;
	HINSTANCE hInst;

	StateManager* m_pStateManager;
	MessageManager* m_pMessageManager;
};
