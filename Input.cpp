#include "Input.h"

void Input::RegisterCallback(InputEvent event, const InputEventCallback& callback)
{
	m_callbacks[event].emplace_back(callback);
}

void Input::UnregisterCallback(InputEvent event, const InputEventCallback& callback)
{
	auto it = m_callbacks.find(event);
	if (it != m_callbacks.end())
	{
		std::vector<InputEventCallback> callbacks = it->second;

		for (std::vector<InputEventCallback>::iterator callbackIter = callbacks.begin(); callbackIter != callbacks.end(); ++callbackIter)
		{
			callbacks.erase(callbackIter);
		}
	}
}

void Input::InvokeCallbacks(InputEvent event, InputData& eventData)
{
	auto it = m_callbacks.find(event);
	if (it != m_callbacks.end())
	{
		std::vector<InputEventCallback> callbacks = it->second;

		for (InputEventCallback callback : callbacks)
		{
			callback(eventData);
		}
	}
}

void Input::HandleKeyPress(KeyCode key)
{
	InputData data{ InputEvent::KeyPressed, key};
	InvokeCallbacks(InputEvent::KeyPressed, data);
}

void Input::HandleKeyRelease(KeyCode key)
{
	InputData data{ InputEvent::KeyReleased, key};
	InvokeCallbacks(InputEvent::KeyReleased, data);
}


