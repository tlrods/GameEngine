#include "InputManager.h"
#include "Helpers.h"

void OnKeyPress(InputData& data)
{
	KeyCode code = data.keyCode;
	
	switch (code)
	{
	case KeyCode::Ichi:
		
		OutputDebugString(L"1 ");
		break;
	case KeyCode::Ni:
		OutputDebugString(L"2 ");
		break;
	case KeyCode::San:
		OutputDebugString(L"3 ");
		break;
	case KeyCode::Shi:
		OutputDebugString(L"4 ");
		break;
	case KeyCode::Q:
		OutputDebugString(L"Q ");
		break;
	case KeyCode::W:
		OutputDebugString(L"W ");
		break;
	case KeyCode::E:
		OutputDebugString(L"E ");
		break;
	case KeyCode::R:
		OutputDebugString(L"R ");
		break;
	case KeyCode::A:
		OutputDebugString(L"A ");
		break;
	case KeyCode::S:
		OutputDebugString(L"S ");
		break;
	case KeyCode::D:
		OutputDebugString(L"D ");
		break;
	case KeyCode::F:
		OutputDebugString(L"F ");
		break;
	case KeyCode::Z:
		OutputDebugString(L"Z ");
		break;
	case KeyCode::X:
		OutputDebugString(L"X ");
		break;
	case KeyCode::C:
		OutputDebugString(L"C ");
		break;
	case KeyCode::Left:
		OutputDebugString(L"< ");
		break;
	case KeyCode::Up:
		OutputDebugString(L"^ ");
		break;
	case KeyCode::Down:
		OutputDebugString(L"v ");
		break;
	case KeyCode::Right:
		OutputDebugString(L"> ");
		break;
	case KeyCode::Space:
		OutputDebugString(L"Space  ");
		break;
	case KeyCode::Enter:
		OutputDebugString(L"Enter ");
		break;
	case KeyCode::Escape:
		OutputDebugString(L"Esc ");
		break;
	default:
		break;
	}
}

void OnKeyRelease(InputData& data)
{
	KeyCode code = data.keyCode;

	switch (code)
	{
	case KeyCode::Ichi:
		OutputDebugString(L"-1 ");
		break;
	case KeyCode::Ni:
		OutputDebugString(L"-2 ");
		break;
	case KeyCode::San:
		OutputDebugString(L"-3 ");
		break;
	case KeyCode::Shi:
		OutputDebugString(L"-4 ");
		break;
	case KeyCode::Q:
		OutputDebugString(L"-Q ");
		break;
	case KeyCode::W:
		OutputDebugString(L"-W ");
		break;
	case KeyCode::E:
		OutputDebugString(L"-E ");
		break;
	case KeyCode::R:
		OutputDebugString(L"-R ");
		break;
	case KeyCode::A:
		OutputDebugString(L"-A ");
		break;
	case KeyCode::S:
		OutputDebugString(L"-S ");
		break;
	case KeyCode::D:
		OutputDebugString(L"-D ");
		break;
	case KeyCode::F:
		OutputDebugString(L"-F ");
		break;
	case KeyCode::Z:
		OutputDebugString(L"-Z ");
		break;
	case KeyCode::X:
		OutputDebugString(L"-X ");
		break;
	case KeyCode::C:
		OutputDebugString(L"-C ");
		break;
	case KeyCode::Left:
		OutputDebugString(L"-< ");
		break;
	case KeyCode::Up:
		OutputDebugString(L"-^ ");
		break;
	case KeyCode::Down:
		OutputDebugString(L"-v ");
		break;
	case KeyCode::Right:
		OutputDebugString(L"-> ");
		break;
	case KeyCode::Space:
		OutputDebugString(L"-Space  ");
		break;
	case KeyCode::Enter:
		OutputDebugString(L"-Enter ");
		break;
	case KeyCode::Escape:
		OutputDebugString(L"-Esc ");
		break;
	default:
		break;
	}
}

InputManager& InputManager::getInstance()
{
	static InputManager instance;
	return instance;
}

InputManager::InputManager()
{
	m_pInput = new Input;
	m_pInput->RegisterCallback(InputEvent::KeyPressed, OnKeyPress);
	m_pInput->RegisterCallback(InputEvent::KeyReleased, OnKeyRelease);

	m_pWindowsInput = new WindowsInput(m_pInput);
	m_pWindowsInput->Initialize();
}

InputManager::~InputManager()
{

}

void InputManager::Initialize()
{

}

//void InputManager::Initialize()
//{
//	m_pInput = new Input;
//	m_pInput->RegisterCallback(InputEvent::KeyPressed, OnKeyPress);
//	m_pInput->RegisterCallback(InputEvent::KeyReleased, OnKeyRelease);
//
//	m_pWindowsInput = new WindowsInput(m_pInput);
//	m_pWindowsInput->Initialize();
//}
//
//void InputManager::Update()
//{
//	//m_pInput->HandleKeyPress(KeyCode::Ichi, KeyModifier::None);
//}