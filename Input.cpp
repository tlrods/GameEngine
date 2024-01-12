#include "Input.h"

void Input::RegisterCallback(InputEvent event, const EventCallback& callback)
{
	m_callbacks[event].emplace_back(callback);
}

void Input::UnregisterCallback(InputEvent event, const EventCallback& callback)
{
	auto it = m_callbacks.find(event);
	if (it != m_callbacks.end())
	{
		std::vector<EventCallback> callbacks = it->second;

		for (std::vector<EventCallback>::iterator callbackIter = callbacks.begin(); callbackIter != callbacks.end(); ++callbackIter)
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
		std::vector<EventCallback> callbacks = it->second;

		for (EventCallback callback : callbacks)
		{
			callback(eventData);
		}
	}
}

void Input::HandleKeyPress(KeyCode key, KeyModifier mod)
{
	InputData data{ InputEvent::KeyPressed, key, mod };
	InvokeCallbacks(InputEvent::KeyPressed, data);
}

void Input::HandleKeyRelease(KeyCode key, KeyModifier mod)
{
	InputData data{ InputEvent::KeyReleased, key, mod };
	InvokeCallbacks(InputEvent::KeyReleased, data);
}


