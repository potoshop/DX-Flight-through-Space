#include "Win32_64Application.h"


HWND Win32_64Application::m_hwnd = nullptr;

Win32_64Application::Win32_64Application()
{
}


Win32_64Application::~Win32_64Application()
{
}

int Win32_64Application::Run(DXSample* pSample, HINSTANCE hInstance)
{
	//Читаем команды запуска приложения
	int argc;
	LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
	pSample->ParseCommandeLineArgs(argv, argc);
	LocalFree(argv);

	WNDCLASSEX wnd = { 0 };
	wnd.cbSize = sizeof(WNDCLASSEX);
	wnd.style = CS_HREDRAW | CS_VREDRAW;
	wnd.lpfnWndProc = WndProc;
	wnd.hInstance = hInstance;
	wnd.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wnd.lpszClassName = L"DXWinApp";
	RegisterClassEx(&wnd);

	RECT winRect = { 0, 0, static_cast<long> (pSample->GetWinWidth()), static_cast<long> (pSample->GetWinHeight())};
	AdjustWindowRect(&winRect, WS_OVERLAPPEDWINDOW, FALSE);

	
	m_hwnd = CreateWindow(
		wnd.lpszClassName,
		pSample->GetTitle().c_str(),
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		winRect.right - winRect.left,
		winRect.bottom - winRect.top,
		nullptr,
		nullptr,
		hInstance,
		pSample);

	ShowWindow(m_hwnd, SW_SHOW);
	SetForegroundWindow(m_hwnd);
	SetFocus(m_hwnd);

	MSG msg = { };

	//Обработчик событий
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return static_cast<char> (msg.wParam);
}

LRESULT CALLBACK Win32_64Application::WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	DXSample* pSample = reinterpret_cast<DXSample*> (GetWindowLongPtr(m_hwnd, GWLP_USERDATA));
	switch (msg)
	{

		case WM_CREATE:
		{
			//Записываем инфу о DXSample
			LPCREATESTRUCT pCreateStruct = reinterpret_cast<LPCREATESTRUCT>(lparam);
			SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pCreateStruct->lpCreateParams));
			break;
		}

		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}

		case WM_KEYDOWN:
		{
			//TODO: Временно
			if (wparam == VK_ESCAPE)
			{
				PostQuitMessage(0);
			}
			break;
		}
			
	}

	return DefWindowProc(hwnd, msg, wparam, lparam);
}
