#include "Input.h"
#include "WindowsInput.h"
#include <unordered_map>
#include <functional>

class InputManager
{
public:
	static InputManager& getInstance();

	void Initialize();

	void KeyPressed(KeyCode);
	void KeyReleased(KeyCode);

private:
	InputManager();
	~InputManager();

	Input* m_pInput;
	WindowsInput* m_pWindowsInput;

	std::unordered_map<KeyCode, bool> m_PressedKeys;
};