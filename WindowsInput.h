#pragma once

#include "Helpers.h"

class WindowsInput
{
public:
	WindowsInput();
	virtual ~WindowsInput();
	void Initialize();

	static LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);

	//virtual void RegisterCallback(InputEvent event, const InputEventCallback& callback);
	//virtual void UnregisterCallback(InputEvent event, const InputEventCallback& callback);
private:

};