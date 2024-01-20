#include <iostream>
#include "WindowsInput.h"
#include "Helpers.h"
#include "InputManager.h"

HHOOK keyboardHook;

LRESULT CALLBACK WindowsInput::KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0) {
        KBDLLHOOKSTRUCT* pKeyStruct = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);
        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
            switch (pKeyStruct->vkCode)
            {
            case '1':
                InputManager::GetInstance()->SetKeyPressed(KeyCode::Ichi);
                break;
            case '2':
                InputManager::GetInstance()->SetKeyPressed(KeyCode::Ni);
                break;
            case '3':
                InputManager::GetInstance()->SetKeyPressed(KeyCode::San);
                break;
            case '4':
                InputManager::GetInstance()->SetKeyPressed(KeyCode::Shi);
                break;
            case 'Q':
                InputManager::GetInstance()->SetKeyPressed(KeyCode::Q);
                break;
            case 'W':
                InputManager::GetInstance()->SetKeyPressed(KeyCode::W);
                break;
            case 'E':
                InputManager::GetInstance()->SetKeyPressed(KeyCode::E);
                break;
            case 'R':
                InputManager::GetInstance()->SetKeyPressed(KeyCode::R);
                break;
            case 'A':
                InputManager::GetInstance()->SetKeyPressed(KeyCode::A);
                break;
            case 'S':
                InputManager::GetInstance()->SetKeyPressed(KeyCode::S);
                break;
            case 'D':
                InputManager::GetInstance()->SetKeyPressed(KeyCode::D);
                break;
            case 'F':
                InputManager::GetInstance()->SetKeyPressed(KeyCode::F);
                break;
            case 'Z':
                InputManager::GetInstance()->SetKeyPressed(KeyCode::Z);
                break;
            case 'X':
                InputManager::GetInstance()->SetKeyPressed(KeyCode::X);
                break;
            case 'C':
                InputManager::GetInstance()->SetKeyPressed(KeyCode::C);
                break;
            case VK_SPACE:
                InputManager::GetInstance()->SetKeyPressed(KeyCode::Space);
                break;
            case VK_RETURN:
                InputManager::GetInstance()->SetKeyPressed(KeyCode::Enter);
                break;
            case VK_ESCAPE:
                InputManager::GetInstance()->SetKeyPressed(KeyCode::Escape);
                break;
            case VK_UP:
                InputManager::GetInstance()->SetKeyPressed(KeyCode::Up);
                break;
            case VK_LEFT:
                InputManager::GetInstance()->SetKeyPressed(KeyCode::Left);
                break;
            case VK_RIGHT:
                InputManager::GetInstance()->SetKeyPressed(KeyCode::Right);
                break;
            case VK_DOWN:
                InputManager::GetInstance()->SetKeyPressed(KeyCode::Down);
                break;
            case VK_LMENU:
                InputManager::GetInstance()->SetKeyPressed(KeyCode::Alt);
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
                InputManager::GetInstance()->SetKeyReleased(KeyCode::Ichi);
                break;
            case '2':
                InputManager::GetInstance()->SetKeyReleased(KeyCode::Ni);
                break;
            case '3':
                InputManager::GetInstance()->SetKeyReleased(KeyCode::San);
                break;
            case '4':
                InputManager::GetInstance()->SetKeyReleased(KeyCode::Shi);
                break;
            case 'Q':
                InputManager::GetInstance()->SetKeyReleased(KeyCode::Q);
                break;
            case 'W':
                InputManager::GetInstance()->SetKeyReleased(KeyCode::W);
                break;
            case 'E':
                InputManager::GetInstance()->SetKeyReleased(KeyCode::E);
                break;
            case 'R':
                InputManager::GetInstance()->SetKeyReleased(KeyCode::R);
                break;
            case 'A':
                InputManager::GetInstance()->SetKeyReleased(KeyCode::A);
                break;
            case 'S':
                InputManager::GetInstance()->SetKeyReleased(KeyCode::S);
                break;
            case 'D':
                InputManager::GetInstance()->SetKeyReleased(KeyCode::D);
                break;
            case 'F':
                InputManager::GetInstance()->SetKeyReleased(KeyCode::F);
                break;
            case 'Z':
                InputManager::GetInstance()->SetKeyReleased(KeyCode::Z);
                break;
            case 'X':
                InputManager::GetInstance()->SetKeyReleased(KeyCode::X);
                break;
            case 'C':
                InputManager::GetInstance()->SetKeyReleased(KeyCode::C);
                break;
            case VK_SPACE:
                InputManager::GetInstance()->SetKeyReleased(KeyCode::Space);
                break;
            case VK_RETURN:
                InputManager::GetInstance()->SetKeyReleased(KeyCode::Enter);
                break;
            case VK_ESCAPE:
                InputManager::GetInstance()->SetKeyReleased(KeyCode::Escape);
                break;
            case VK_UP:
                InputManager::GetInstance()->SetKeyReleased(KeyCode::Up);
                break;
            case VK_LEFT:
                InputManager::GetInstance()->SetKeyReleased(KeyCode::Left);
                break;
            case VK_RIGHT:
                InputManager::GetInstance()->SetKeyReleased(KeyCode::Right);
                break;
            case VK_DOWN:
                InputManager::GetInstance()->SetKeyReleased(KeyCode::Down);
                break;
            case VK_LMENU:
                InputManager::GetInstance()->SetKeyReleased(KeyCode::Alt);
                break;
            default:
                break;
            }
        }
    }

    // Pass the event to the next hook in the chain
    return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}

//WindowsInput::WindowsInput(Input* pInput)
//{
//    m_pInput = pInput;
//}

WindowsInput::WindowsInput()
{
}

WindowsInput::~WindowsInput()
{
}

void WindowsInput::Initialize()
{
	keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, WindowsInput::KeyboardProc, GetModuleHandle(nullptr), 0);

    //MSG msg;
    //while (GetMessage(&msg, nullptr, 0, 0)) {
    //    TranslateMessage(&msg);
    //    DispatchMessage(&msg);
    //}
}