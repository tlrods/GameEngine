#pragma once
#include "Helpers.h" //TODO: There's a way to make all headers auto include this

class StateManager;
class RenderCore;
class MessageManager;
class InputManager;

class Application
{

public:

	Application(UINT width, UINT height, std::wstring name);
	~Application();

	void Intitialize();
	void Update();
	void Render();
	void Shutdown();

	// Samples override the event handlers to handle specific messages.
	virtual void OnKeyDown(UINT8 /*key*/) {}
	virtual void OnKeyUp(UINT8 /*key*/) {}

	// Accessors.
	UINT GetWidth() const { return m_width; }
	UINT GetHeight() const { return m_height; }
	const WCHAR* GetTitle() const { return m_title.c_str(); }

	void ParseCommandLineArgs(_In_reads_(argc) WCHAR* argv[], int argc);

protected:
	std::wstring GetAssetFullPath(LPCWSTR assetName);

	void GetHardwareAdapter(
		_In_ IDXGIFactory1* pFactory,
		_Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter,
		bool requestHighPerformanceAdapter = false);

	// Viewport dimensions.
	UINT m_width;
	UINT m_height;
	float m_aspectRatio;

	// Adapter info.
	bool m_useWarpDevice;

private:

	// Root assets path.
	std::wstring m_assetsPath;

	// Window title.
	std::wstring m_title;

	HINSTANCE hInst;

	//move this to a scene or something stop reinventing the wheel
	StateManager* m_pStateManager;
	RenderCore* m_pRenderer;
	MessageManager* m_pMessageManager;
	InputManager* m_pInputManager;

	unsigned long m_ulGameTime = 0;
};
