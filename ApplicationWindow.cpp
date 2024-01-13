#include "ApplicationWindow.h"
#include "Application.h"
#include "Helpers.h"

using namespace Microsoft::WRL;

HWND ApplicationWindow::m_hWnd = nullptr;
Application* ApplicationWindow::m_pGameInstance = nullptr;


int ApplicationWindow::Run(HINSTANCE hInstance, int nCmdShow)
{
    if (!m_pGameInstance)
    {
        m_pGameInstance = new Application(SCREEN_WIDTH, SCREEN_HEIGHT, L"Game Engine");
    }
    // Parse the command line parameters
    int argc;
    LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
    m_pGameInstance->ParseCommandLineArgs(argv, argc);
    LocalFree(argv);

    // Setup window style flags
#if ONPC
    DWORD dwWindowStyleFlags = WS_VISIBLE | WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
#else // borderless if we ever want arcade
    DWORD dwWindowStyleFlags = WS_VISIBLE | WS_POPUP /*| WS_CAPTION */ | WS_SYSMENU | WS_MINIMIZEBOX;
#endif

    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = ApplicationWindow::WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursorW(NULL, (LPWSTR)IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(1 + COLOR_WINDOW);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = TEXT("Game Engine");

    RegisterClassEx(&wcex);
    DWORD error = GetLastError();

    // Setup the desired client area size
    RECT rWindow;
    rWindow.left = 0;
    rWindow.top = 0;
    rWindow.right = SCREEN_WIDTH;
    rWindow.bottom = SCREEN_HEIGHT;

    // Get the dimensions of a window that will have a client rect that
    // will really be the resolution we're looking for.
    AdjustWindowRectEx(&rWindow, dwWindowStyleFlags, FALSE, WS_EX_APPWINDOW);

    // Calculate the the window's dimensions
    int nWindowWidth = rWindow.right - rWindow.left;
    int nWindowHeight = rWindow.bottom - rWindow.top;

    m_hWnd = CreateWindowExW(
        WS_EX_APPWINDOW,										// extended style flags
        TEXT("Game Engine"),									// window class Name
        TEXT("GAME ENGINE!!"),									// title
        dwWindowStyleFlags,										// window style flags
        (GetSystemMetrics(SM_CXSCREEN) - nWindowWidth) / 2,		// position (x, y)
        (GetSystemMetrics(SM_CYSCREEN) - nWindowHeight) / 2,	//	- centered on the desktop
        nWindowWidth,											// width
        nWindowHeight,											// height
        HWND_DESKTOP,											// parent window handle
        NULL,													// menu handle
        hInstance,												// application instance
        NULL													// creation parameters
    );

    if (!m_hWnd)
    {
        DWORD error = GetLastError();
        return FALSE;
    }

    m_pGameInstance->Intitialize();
    ShowWindow(m_hWnd, nCmdShow);
    UpdateWindow(m_hWnd);

    // TODO: Place code here.
    MSG msg;
    HACCEL hAccelTable;

    // Initialize global strings
    OutputDebugString(L"test");

    hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GAMEENGINE));

    //Main game loop
    while (true)
    {
        if (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE) == TRUE)
        {
            if (msg.message == WM_QUIT)
            {
                m_pGameInstance->Shutdown();
                //MessageManager::GetInstance()->DeleteInstance();
                //Input::GetInstance()->DestroyInstance();
                break;
            }

            DispatchMessageW(&msg);
        }
        else
        {
            m_pGameInstance->Update();
            m_pGameInstance->Render();
            //MessageManager::GetInstance()->Update();
            //InputManager.Update();
        }
    }

    return (int)msg.wParam;
}

LRESULT ApplicationWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        // Save the DXSample* passed in to CreateWindow.
        LPCREATESTRUCT pCreateStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
        SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pCreateStruct->lpCreateParams));
    }
    return 0;

    case WM_KEYDOWN:
        if (m_pGameInstance)
        {
            m_pGameInstance->OnKeyDown(static_cast<UINT8>(wParam));
        }
        return 0;

    case WM_KEYUP:
        if (m_pGameInstance)
        {
            m_pGameInstance->OnKeyUp(static_cast<UINT8>(wParam));
        }
        return 0;

    case WM_PAINT:
        if (m_pGameInstance)
        {
            m_pGameInstance->Update();
            m_pGameInstance->Render();
        }
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    // Handle any messages the switch statement didn't.
    return DefWindowProc(hWnd, message, wParam, lParam);
}

