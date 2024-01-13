#include "Input.h"
#include <unordered_map>

class WindowsInput;

class InputManager
{
public:
	static InputManager* GetInstance();

	void SetKeyPressed(KeyCode);
	void SetKeyReleased(KeyCode);

	bool GetKeyPressed(KeyCode);

private:
	static InputManager* s_Instance;

	InputManager();
	~InputManager();

	Input* m_pInput;
	WindowsInput* m_pWindowsInput;

	std::unordered_map<KeyCode, bool> m_Keyboard;
};