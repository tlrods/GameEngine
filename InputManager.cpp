#include "InputManager.h"
#include "Helpers.h"
#include "WindowsInput.h"

InputManager* InputManager::s_Instance = nullptr;

void OnKeyPress(InputData& data)
{
	InputManager::GetInstance()->SetKeyPressed(data.keyCode);
}

void OnKeyRelease(InputData& data)
{
	InputManager::GetInstance()->SetKeyReleased(data.keyCode);
}

InputManager* InputManager::GetInstance()
{
	if (InputManager::s_Instance == nullptr)
		InputManager::s_Instance = new InputManager;

	return InputManager::s_Instance;
}

InputManager::InputManager()
{
	m_pInput = new Input;
	m_pInput->RegisterCallback(InputEvent::KeyPressed, OnKeyPress);
	m_pInput->RegisterCallback(InputEvent::KeyReleased, OnKeyRelease);

	m_pWindowsInput = new WindowsInput(m_pInput);
	m_pWindowsInput->Initialize();

	for (int i = 0; i != (int)KeyCode::KeyCodeEnd; ++i)
	{
		m_Keyboard[(KeyCode)i] = false;
	}
}

InputManager::~InputManager()
{
	SAFE_DELETE(m_pInput);
	SAFE_DELETE(m_pWindowsInput);
}

void InputManager::SetKeyPressed(KeyCode code)
{
	// testing input
	if (m_Keyboard[code] == false)
	{
		switch (code)
		{
		case KeyCode::Ichi:
			OutputDebugString(L"1 pressed. ");
			break;
		case KeyCode::Ni:
			OutputDebugString(L"2 pressed. ");
			break;
		case KeyCode::San:
			OutputDebugString(L"3 pressed. ");
			break;
		case KeyCode::Shi:
			OutputDebugString(L"4 pressed. ");
			break;
		case KeyCode::Q:
			OutputDebugString(L"Q pressed. ");
			break;
		case KeyCode::W:
			OutputDebugString(L"W pressed. ");
			break;
		case KeyCode::E:
			OutputDebugString(L"E pressed. ");
			break;
		case KeyCode::R:
			OutputDebugString(L"R pressed. ");
			break;
		case KeyCode::A:
			OutputDebugString(L"A pressed. ");
			break;
		case KeyCode::S:
			OutputDebugString(L"S pressed. ");
			break;
		case KeyCode::D:
			OutputDebugString(L"D pressed. ");
			break;
		case KeyCode::F:
			OutputDebugString(L"F pressed. ");
			break;
		case KeyCode::Z:
			OutputDebugString(L"Z pressed. ");
			break;
		case KeyCode::X:
			OutputDebugString(L"X pressed. ");
			break;
		case KeyCode::C:
			OutputDebugString(L"C pressed. ");
			break;
		case KeyCode::Left:
			OutputDebugString(L"< pressed. ");
			break;
		case KeyCode::Up:
			OutputDebugString(L"^ pressed. ");
			break;
		case KeyCode::Down:
			OutputDebugString(L"v pressed. ");
			break;
		case KeyCode::Right:
			OutputDebugString(L"> pressed. ");
			break;
		case KeyCode::Space:
			OutputDebugString(L"Space pressed. ");
			break;
		case KeyCode::Enter:
			OutputDebugString(L"Enter pressed. ");
			break;
		case KeyCode::Escape:
			OutputDebugString(L"Esc pressed. ");
			break;
		default:
			OutputDebugString(L"Unknown key pressed. ");
			break;
		}
	}

	m_Keyboard[code] = true;
}

void InputManager::SetKeyReleased(KeyCode code)
{
	// testing input
	if (m_Keyboard[code] == true)
	{
		switch (code)
		{
		case KeyCode::Ichi:
			OutputDebugString(L"1 unpressed. ");
			break;
		case KeyCode::Ni:
			OutputDebugString(L"2 unpressed. ");
			break;
		case KeyCode::San:
			OutputDebugString(L"3 unpressed. ");
			break;
		case KeyCode::Shi:
			OutputDebugString(L"4 unpressed. ");
			break;
		case KeyCode::Q:
			OutputDebugString(L"Q unpressed. ");
			break;
		case KeyCode::W:
			OutputDebugString(L"W unpressed. ");
			break;
		case KeyCode::E:
			OutputDebugString(L"E unpressed. ");
			break;
		case KeyCode::R:
			OutputDebugString(L"R unpressed. ");
			break;
		case KeyCode::A:
			OutputDebugString(L"A unpressed. ");
			break;
		case KeyCode::S:
			OutputDebugString(L"S unpressed. ");
			break;
		case KeyCode::D:
			OutputDebugString(L"D unpressed. ");
			break;
		case KeyCode::F:
			OutputDebugString(L"F unpressed. ");
			break;
		case KeyCode::Z:
			OutputDebugString(L"Z unpressed. ");
			break;
		case KeyCode::X:
			OutputDebugString(L"X unpressed. ");
			break;
		case KeyCode::C:
			OutputDebugString(L"C unpressed. ");
			break;
		case KeyCode::Left:
			OutputDebugString(L"< unpressed. ");
			break;
		case KeyCode::Up:
			OutputDebugString(L"^ unpressed. ");
			break;
		case KeyCode::Down:
			OutputDebugString(L"v unpressed. ");
			break;
		case KeyCode::Right:
			OutputDebugString(L"> unpressed. ");
			break;
		case KeyCode::Space:
			OutputDebugString(L"Space unpressed. ");
			break;
		case KeyCode::Enter:
			OutputDebugString(L"Enter unpressed. ");
			break;
		case KeyCode::Escape:
			OutputDebugString(L"Esc unpressed. ");
			break;
		default:
			OutputDebugString(L"Unknown key unpressed. ");
			break;
		}
	}

	m_Keyboard[code] = false;
}

bool InputManager::GetKeyPressed(KeyCode code)
{
	if (m_Keyboard.find(code) != m_Keyboard.end())
	{
		return m_Keyboard[code];
	}

	OutputDebugString(L"InputManager::GetKeyPressed: Cannot find key.");

	return false;
}