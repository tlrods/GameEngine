#pragma once

//#include <functional>
#include <unordered_map>

enum class InputEvent {
	KeyPressed,
	KeyReleased
};

enum class KeyCode
{
	Ichi, 
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
	Alt
};

enum class KeyModifier
{
	None,
	Alt
};

struct InputData
{
	InputEvent event;
	KeyCode keyCode;
	KeyModifier modifier;
};

typedef void (*EventCallback)(InputData&);
//using EventCallback = std::function<void(InputData&)>;

class Input
{
public:
	void RegisterCallback(InputEvent event, const EventCallback& callback);
	void UnregisterCallback(InputEvent event, const EventCallback& callback);

	void HandleKeyPress(KeyCode key, KeyModifier modifier);
	void HandleKeyRelease(KeyCode key, KeyModifier modifier);
private:
	std::unordered_map<InputEvent, std::vector<EventCallback>> m_callbacks;

	void InvokeCallbacks(InputEvent event, InputData& eventData);
};