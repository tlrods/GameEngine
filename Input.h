#pragma once

#include <unordered_map>

enum class InputEvent {
	KeyPressed,
	KeyReleased
};

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

struct InputData
{
	InputEvent inputEvent;
	KeyCode keyCode;
};

typedef void (*InputEventCallback)(InputData&);

class Input
{
public:
	void RegisterCallback(InputEvent event, const InputEventCallback& callback);
	void UnregisterCallback(InputEvent event, const InputEventCallback& callback);

	void HandleKeyPress(KeyCode);
	void HandleKeyRelease(KeyCode);
private:
	std::unordered_map<InputEvent, std::vector<InputEventCallback>> m_callbacks;

	void InvokeCallbacks(InputEvent event, InputData& eventData);
};