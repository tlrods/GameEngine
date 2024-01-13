#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define IDS_APP_TITLE  103
#define IDI_GAMEENGINE 107
#define IDI_SMALL      108
#define IDC_GAMEENGINE 109

#define SCREEN_WIDTH   1920
#define SCREEN_HEIGHT  1080

// Windows Header Files:
#include <windows.h>
#include <stdio.h>

#include <d3d12.h>
#include <dxgi1_6.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include "d3dx12.h"

#include <wrl.h>
#include <shellapi.h>

#include <stdexcept>

#define SAFE_DELETE(p)			if (p) { delete p; p = nullptr; }

#define DEBUG_STATE true //TODO: Make this read current compiler state
#define ONPC true

inline std::string HrToString(HRESULT hr)
{
    char s_str[64] = {};
    sprintf_s(s_str, "HRESULT of 0x%08X", static_cast<UINT>(hr));
    return std::string(s_str);
}

class HrException : public std::runtime_error
{
public:
    HrException(HRESULT hr) : std::runtime_error(HrToString(hr)), m_hr(hr) {}
    HRESULT Error() const { return m_hr; }
private:
    const HRESULT m_hr;
};

inline void ThrowIfFailed(HRESULT hr)
{
    if (FAILED(hr))
    {
        throw HrException(hr);
    }
}