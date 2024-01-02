// WinMain.cpp : Defines the entry point for the application.
//

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define IDS_APP_TITLE  103
#define IDI_GAMEENGINE 107
#define IDI_SMALL      108
#define IDC_GAMEENGINE 109

#define SCREEN_WIDTH   1000
#define SCREEN_HEIGHT  1000

// Windows Header Files:
#include <windows.h>
#include <stdio.h>

#define ONPC 1

#if UseConsole
#include <io.h>
#include <fcntl.h>
#include <iostream>
#endif

STICKYKEYS g_StartupStickyKeys = { sizeof(STICKYKEYS), 0 };
TOGGLEKEYS g_StartupToggleKeys = { sizeof(TOGGLEKEYS), 0 };
FILTERKEYS g_StartupFilterKeys = { sizeof(FILTERKEYS), 0 };

#define MAX_LOADSTRING 100
//#define WORLDSCREENWIDTH 1600
//#define WORLDSCREENHEIGHT 900

HWND GlobalHWnd;

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	SystemParametersInfo(SPI_GETSTICKYKEYS, sizeof(STICKYKEYS), &g_StartupStickyKeys, 0);
	SystemParametersInfo(SPI_GETTOGGLEKEYS, sizeof(TOGGLEKEYS), &g_StartupToggleKeys, 0);
	SystemParametersInfo(SPI_GETFILTERKEYS, sizeof(FILTERKEYS), &g_StartupFilterKeys, 0);
	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_GAMEENGINE, szWindowClass, MAX_LOADSTRING);
	bool bSuccess = MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	OutputDebugString(L"test");

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GAMEENGINE));

	while (true)
	{
		//if (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE) == TRUE)
		//{
		//	if (msg.message == WM_QUIT)
		//	{
		//		Game.Shutdown();
		//		MessageManager::GetInstance()->DeleteInstance();
		//		//Input::GetInstance()->DestroyInstance();
		//		break;
		//	}

		//	DispatchMessageW(&msg);
		//}
		//else
		//{
		//	Game.Update();
		//	Game.Render();
		//	//			MessageManager::GetInstance()->Update();
		//	InputManager.Update();
		//}
	}

	return (int)msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursorW(NULL, (LPWSTR)IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(1 + COLOR_WINDOW);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = TEXT("REALTIMEWND");

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
#if UseConsole
	AllocConsole();

	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
	int hCrt = _open_osfhandle((long)handle_out, _O_TEXT);
	FILE* hf_out = _fdopen(hCrt, "w");
	setvbuf(hf_out, NULL, _IONBF, 1);
	*stdout = *hf_out;

	HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
	hCrt = _open_osfhandle((long)handle_in, _O_TEXT);
	FILE* hf_in = _fdopen(hCrt, "r");
	setvbuf(hf_in, NULL, _IONBF, 128);
	*stdin = *hf_in;

	HWND ConsoleWnd = GetConsoleWindow();
	if (ConsoleWnd != NULL)
	{
		HMENU hMenu = GetSystemMenu(ConsoleWnd, FALSE);
		if (hMenu != NULL) DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
		//ConsoleWnd
	}


#endif

	HWND hWnd;

	hInst = hInstance; // Store instance handle in our global variable

		// Setup window style flags
#if ONPC
	DWORD dwWindowStyleFlags = WS_VISIBLE | WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
#else // borderless if we ever want arcade
	DWORD dwWindowStyleFlags = WS_VISIBLE | WS_POPUP /*| WS_CAPTION */ | WS_SYSMENU | WS_MINIMIZEBOX;
#endif

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

	hWnd = CreateWindowExW(
		WS_EX_APPWINDOW,										// extended style flags
		TEXT("REALTIMEWND"),											// window class Name
		TEXT("GAME ENGINE!!"),												// title
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

	if (!hWnd)
	{
		DWORD error = GetLastError();
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		/*switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}*/
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	case WM_QUIT:
	{

	}
	break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

//// Message handler for about box.
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	UNREFERENCED_PARAMETER(lParam);
//	switch (message)
//	{
//	case WM_INITDIALOG:
//		return (INT_PTR)TRUE;
//
//	case WM_COMMAND:
//		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
//		{
//			EndDialog(hDlg, LOWORD(wParam));
//			return (INT_PTR)TRUE;
//		}
//		break;
//	}
//	return (INT_PTR)FALSE;
//}
