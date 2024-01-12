#include <iostream>
#include "Input.h"
#include "WindowsInput.h"
#include "Helpers.h"

HHOOK keyboardHook;
Input* m_pInput;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0) {
        KBDLLHOOKSTRUCT* pKeyStruct = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);
        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
            switch (pKeyStruct->vkCode)
            {
            case '1':
                m_pInput->HandleKeyPress(KeyCode::Ichi, KeyModifier::None);
                break;
            case '2':
                m_pInput->HandleKeyPress(KeyCode::Ni, KeyModifier::None);
                break;
            case '3':
                m_pInput->HandleKeyPress(KeyCode::San, KeyModifier::None);
                break;
            case '4':
                m_pInput->HandleKeyPress(KeyCode::Shi, KeyModifier::None);
                break;
            case 'Q':
                m_pInput->HandleKeyPress(KeyCode::Q, KeyModifier::None);
                break;
            case 'W':
                m_pInput->HandleKeyPress(KeyCode::W, KeyModifier::None);
                break;
            case 'E':
                m_pInput->HandleKeyPress(KeyCode::E, KeyModifier::None);
                break;
            case 'R':
                m_pInput->HandleKeyPress(KeyCode::R, KeyModifier::None);
                break;
            case 'A':
                m_pInput->HandleKeyPress(KeyCode::A, KeyModifier::None);
                break;
            case 'S':
                m_pInput->HandleKeyPress(KeyCode::S, KeyModifier::None);
                break;
            case 'D':
                m_pInput->HandleKeyPress(KeyCode::D, KeyModifier::None);
                break;
            case 'F':
                m_pInput->HandleKeyPress(KeyCode::F, KeyModifier::None);
                break;
            case 'Z':
                m_pInput->HandleKeyPress(KeyCode::Z, KeyModifier::None);
                break;
            case 'X':
                m_pInput->HandleKeyPress(KeyCode::X, KeyModifier::None);
                break;
            case 'C':
                m_pInput->HandleKeyPress(KeyCode::C, KeyModifier::None);
                break;
            case VK_SPACE:
                m_pInput->HandleKeyPress(KeyCode::Space, KeyModifier::None);
                break;
            case VK_RETURN:
                m_pInput->HandleKeyPress(KeyCode::Enter, KeyModifier::None);
                break;
            case VK_ESCAPE:
                m_pInput->HandleKeyPress(KeyCode::Escape, KeyModifier::None);
                break;
            case VK_UP:
                m_pInput->HandleKeyPress(KeyCode::Up, KeyModifier::None);
                break;
            case VK_LEFT:
                m_pInput->HandleKeyPress(KeyCode::Left, KeyModifier::None);
                break;
            case VK_RIGHT:
                m_pInput->HandleKeyPress(KeyCode::Right, KeyModifier::None);
                break;
            case VK_DOWN:
                m_pInput->HandleKeyPress(KeyCode::Down, KeyModifier::None);
                break;
            case VK_LMENU:
                m_pInput->HandleKeyPress(KeyCode::Alt, KeyModifier::None);
                break;
            default:
                break;
            }
        }
        else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP) {
            // Handle key up event
            switch (pKeyStruct->vkCode)
            {
            case '1':
                m_pInput->HandleKeyRelease(KeyCode::Ichi, KeyModifier::None);
                break;
            case '2':
                m_pInput->HandleKeyRelease(KeyCode::Ni, KeyModifier::None);
                break;
            case '3':
                m_pInput->HandleKeyRelease(KeyCode::San, KeyModifier::None);
                break;
            case '4':
                m_pInput->HandleKeyRelease(KeyCode::Shi, KeyModifier::None);
                break;
            case 'Q':
                m_pInput->HandleKeyRelease(KeyCode::Q, KeyModifier::None);
                break;
            case 'W':
                m_pInput->HandleKeyRelease(KeyCode::W, KeyModifier::None);
                break;
            case 'E':
                m_pInput->HandleKeyRelease(KeyCode::E, KeyModifier::None);
                break;
            case 'R':
                m_pInput->HandleKeyRelease(KeyCode::R, KeyModifier::None);
                break;
            case 'A':
                m_pInput->HandleKeyRelease(KeyCode::A, KeyModifier::None);
                break;
            case 'S':
                m_pInput->HandleKeyRelease(KeyCode::S, KeyModifier::None);
                break;
            case 'D':
                m_pInput->HandleKeyRelease(KeyCode::D, KeyModifier::None);
                break;
            case 'F':
                m_pInput->HandleKeyRelease(KeyCode::F, KeyModifier::None);
                break;
            case 'Z':
                m_pInput->HandleKeyRelease(KeyCode::Z, KeyModifier::None);
                break;
            case 'X':
                m_pInput->HandleKeyRelease(KeyCode::X, KeyModifier::None);
                break;
            case 'C':
                m_pInput->HandleKeyRelease(KeyCode::C, KeyModifier::None);
                break;
            case VK_SPACE:
                m_pInput->HandleKeyRelease(KeyCode::Space, KeyModifier::None);
                break;
            case VK_RETURN:
                m_pInput->HandleKeyRelease(KeyCode::Enter, KeyModifier::None);
                break;
            case VK_ESCAPE:
                m_pInput->HandleKeyRelease(KeyCode::Escape, KeyModifier::None);
                break;
            case VK_UP:
                m_pInput->HandleKeyRelease(KeyCode::Up, KeyModifier::None);
                break;
            case VK_LEFT:
                m_pInput->HandleKeyRelease(KeyCode::Left, KeyModifier::None);
                break;
            case VK_RIGHT:
                m_pInput->HandleKeyRelease(KeyCode::Right, KeyModifier::None);
                break;
            case VK_DOWN:
                m_pInput->HandleKeyRelease(KeyCode::Down, KeyModifier::None);
                break;
            case VK_LMENU:
                m_pInput->HandleKeyRelease(KeyCode::Alt, KeyModifier::None);
                break;
            default:
                break;
            }
        }
    }

    // Pass the event to the next hook in the chain
    return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}

WindowsInput::WindowsInput(Input* pInput)
{
    m_pInput = pInput;
}

WindowsInput::~WindowsInput()
{
}

void WindowsInput::Initialize()
{
	keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, GetModuleHandle(nullptr), 0);

    //MSG msg;
    //while (GetMessage(&msg, nullptr, 0, 0)) {
    //    TranslateMessage(&msg);
    //    DispatchMessage(&msg);
    //}
}