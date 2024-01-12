#include "Input.h"
#include "WindowsInput.h"
#include <unordered_map>

class InputManager
{
public:
	static InputManager& getInstance();

	void KeyPressed(KeyCode);
	void KeyReleased(KeyCode);

private:
	InputManager();
	~InputManager();

	Input* m_pInput;
	WindowsInput* m_pWindowsInput;

	std::unordered_map<KeyCode, bool> m_PressedKeys;
};