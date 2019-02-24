#include "Win32_64Application.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	DXSample pSample(L"Flight through space", 1280, 720);
	return Win32_64Application::Run(&pSample, hInstance);
}