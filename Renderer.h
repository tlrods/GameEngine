#pragma once
#include "Helpers.h" //TODO: There's a way to make all headers auto include this

class Renderer
{

public:

	void Intitialize(HWND inHWnd, HINSTANCE inHInst, UINT screenWidth, UINT screenHeight);
	void Update();
	void Render();
	void Shutdown();

	Renderer();
	~Renderer();

private:


};
