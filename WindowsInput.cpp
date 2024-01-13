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
                m_pInput->HandleKeyPress(KeyCode::Ichi);
                break;
            case '2':
                m_pInput->HandleKeyPress(KeyCode::Ni);
                break;
            case '3':
                m_pInput->HandleKeyPress(KeyCode::San);
                break;
            case '4':
                m_pInput->HandleKeyPress(KeyCode::Shi);
                break;
            case 'Q':
                m_pInput->HandleKeyPress(KeyCode::Q);
                break;
            case 'W':
                m_pInput->HandleKeyPress(KeyCode::W);
                break;
            case 'E':
                m_pInput->HandleKeyPress(KeyCode::E);
                break;
            case 'R':
                m_pInput->HandleKeyPress(KeyCode::R);
                break;
            case 'A':
                m_pInput->HandleKeyPress(KeyCode::A);
                break;
            case 'S':
                m_pInput->HandleKeyPress(KeyCode::S);
                break;
            case 'D':
                m_pInput->HandleKeyPress(KeyCode::D);
                break;
            case 'F':
                m_pInput->HandleKeyPress(KeyCode::F);
                break;
            case 'Z':
                m_pInput->HandleKeyPress(KeyCode::Z);
                break;
            case 'X':
                m_pInput->HandleKeyPress(KeyCode::X);
                break;
            case 'C':
                m_pInput->HandleKeyPress(KeyCode::C);
                break;
            case VK_SPACE:
                m_pInput->HandleKeyPress(KeyCode::Space);
                break;
            case VK_RETURN:
                m_pInput->HandleKeyPress(KeyCode::Enter);
                break;
            case VK_ESCAPE:
                m_pInput->HandleKeyPress(KeyCode::Escape);
                break;
            case VK_UP:
                m_pInput->HandleKeyPress(KeyCode::Up);
                break;
            case VK_LEFT:
                m_pInput->HandleKeyPress(KeyCode::Left);
                break;
            case VK_RIGHT:
                m_pInput->HandleKeyPress(KeyCode::Right);
                break;
            case VK_DOWN:
                m_pInput->HandleKeyPress(KeyCode::Down);
                break;
            case VK_LMENU:
                m_pInput->HandleKeyPress(KeyCode::Alt);
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
                m_pInput->HandleKeyRelease(KeyCode::Ichi);
                break;
            case '2':
                m_pInput->HandleKeyRelease(KeyCode::Ni);
                break;
            case '3':
                m_pInput->HandleKeyRelease(KeyCode::San);
                break;
            case '4':
                m_pInput->HandleKeyRelease(KeyCode::Shi);
                break;
            case 'Q':
                m_pInput->HandleKeyRelease(KeyCode::Q);
                break;
            case 'W':
                m_pInput->HandleKeyRelease(KeyCode::W);
                break;
            case 'E':
                m_pInput->HandleKeyRelease(KeyCode::E);
                break;
            case 'R':
                m_pInput->HandleKeyRelease(KeyCode::R);
                break;
            case 'A':
                m_pInput->HandleKeyRelease(KeyCode::A);
                break;
            case 'S':
                m_pInput->HandleKeyRelease(KeyCode::S);
                break;
            case 'D':
                m_pInput->HandleKeyRelease(KeyCode::D);
                break;
            case 'F':
                m_pInput->HandleKeyRelease(KeyCode::F);
                break;
            case 'Z':
                m_pInput->HandleKeyRelease(KeyCode::Z);
                break;
            case 'X':
                m_pInput->HandleKeyRelease(KeyCode::X);
                break;
            case 'C':
                m_pInput->HandleKeyRelease(KeyCode::C);
                break;
            case VK_SPACE:
                m_pInput->HandleKeyRelease(KeyCode::Space);
                break;
            case VK_RETURN:
                m_pInput->HandleKeyRelease(KeyCode::Enter);
                break;
            case VK_ESCAPE:
                m_pInput->HandleKeyRelease(KeyCode::Escape);
                break;
            case VK_UP:
                m_pInput->HandleKeyRelease(KeyCode::Up);
                break;
            case VK_LEFT:
                m_pInput->HandleKeyRelease(KeyCode::Left);
                break;
            case VK_RIGHT:
                m_pInput->HandleKeyRelease(KeyCode::Right);
                break;
            case VK_DOWN:
                m_pInput->HandleKeyRelease(KeyCode::Down);
                break;
            case VK_LMENU:
                m_pInput->HandleKeyRelease(KeyCode::Alt);
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