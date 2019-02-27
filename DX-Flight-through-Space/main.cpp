#include "Win32_64Application.h"
#include "DXWindow.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	DXWindow pSample( 1280, 720, L"Flight through space");
	return Win32_64Application::Run(&pSample, hInstance);
}