#include "Application.h"
#include "ApplicationWindow.h"
#include "StateMachine.h"
#include "RenderCore.h"
#include "MessageManager.h"
#include "InputManager.h"

using namespace Microsoft::WRL; //TODO FIX ME

Application::Application(UINT width, UINT height, std::wstring name) :
	m_width(width),
	m_height(height),
	m_title(name),
	m_useWarpDevice(false)
{
}

Application::~Application()
{

	
}



void Application::Intitialize()
{
    m_pStateManager = new StateManager;
    m_pStateManager->Initialize();

    m_pRenderer = new RenderCore(m_width, m_height, m_title);
    m_pRenderer->Initialize();
    
    m_pMessageManager = MessageManager::GetInstance();

    m_pInputManager = InputManager::GetInstance();
}

void Application::Update()
{
    m_pStateManager->Update();
    m_pRenderer->Update();
    m_pMessageManager->Update();
}

void Application::Render()
{
    m_pStateManager->Render();
    m_pRenderer->Render();
}

void Application::Shutdown()
{
    m_pRenderer->Shutdown();
    SAFE_DELETE(m_pRenderer);
    SAFE_DELETE(m_pStateManager);
    SAFE_DELETE(m_pMessageManager);
}

// Helper function for resolving the full path of assets.
std::wstring Application::GetAssetFullPath(LPCWSTR assetName)
{
    return m_assetsPath + assetName;
}

// Helper function for acquiring the first available hardware adapter that supports Direct3D 12.
// If no such adapter can be found, *ppAdapter will be set to nullptr.
_Use_decl_annotations_
void Application::GetHardwareAdapter(
    IDXGIFactory1* pFactory,
    IDXGIAdapter1** ppAdapter,
    bool requestHighPerformanceAdapter)
{
    *ppAdapter = nullptr;

    ComPtr<IDXGIAdapter1> adapter;

    ComPtr<IDXGIFactory6> factory6;
    if (SUCCEEDED(pFactory->QueryInterface(IID_PPV_ARGS(&factory6))))
    {
        for (
            UINT adapterIndex = 0;
            SUCCEEDED(factory6->EnumAdapterByGpuPreference(
                adapterIndex,
                requestHighPerformanceAdapter == true ? DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE : DXGI_GPU_PREFERENCE_UNSPECIFIED,
                IID_PPV_ARGS(&adapter)));
            ++adapterIndex)
        {
            DXGI_ADAPTER_DESC1 desc;
            adapter->GetDesc1(&desc);

            if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
            {
                // Don't select the Basic Render Driver adapter.
                // If you want a software adapter, pass in "/warp" on the command line.
                continue;
            }

            // Check to see whether the adapter supports Direct3D 12, but don't create the
            // actual device yet.
            if (SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr)))
            {
                break;
            }
        }
    }

    if (adapter.Get() == nullptr)
    {
        for (UINT adapterIndex = 0; SUCCEEDED(pFactory->EnumAdapters1(adapterIndex, &adapter)); ++adapterIndex)
        {
            DXGI_ADAPTER_DESC1 desc;
            adapter->GetDesc1(&desc);

            if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
            {
                // Don't select the Basic Render Driver adapter.
                // If you want a software adapter, pass in "/warp" on the command line.
                continue;
            }

            // Check to see whether the adapter supports Direct3D 12, but don't create the
            // actual device yet.
            if (SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr)))
            {
                break;
            }
        }
    }

    *ppAdapter = adapter.Detach();
}

// Helper function for parsing any supplied command line args.
_Use_decl_annotations_
void Application::ParseCommandLineArgs(WCHAR* argv[], int argc)
{
    for (int i = 1; i < argc; ++i)
    {
        if (_wcsnicmp(argv[i], L"-warp", wcslen(argv[i])) == 0 ||
            _wcsnicmp(argv[i], L"/warp", wcslen(argv[i])) == 0)
        {
            m_useWarpDevice = true;
            m_title = m_title + L" (WARP)";
        }
    }
}