#include <unordered_map>

enum class KeyCode
{
	Ichi = 0,
	Ni,
	San,
	Shi,
	Q,
	W,
	E,
	R,
	A,
	S,
	D,
	F,
	Z,
	X,
	C,
	Left,
	Up,
	Down,
	Right,
	Space,
	Enter,
	Escape,
	Alt,

	KeyCodeEnd
};

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

	//Input* m_pInput;
	//WindowsInput* m_pWindowsInput;

	std::unordered_map<KeyCode, bool> m_Keyboard;
};