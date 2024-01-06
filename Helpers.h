#pragma once

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

#define SAFE_DELETE(p)			if (p) { delete p; p = nullptr; }

#define DEBUG_STATE true //TODO: Make this read current compiler state