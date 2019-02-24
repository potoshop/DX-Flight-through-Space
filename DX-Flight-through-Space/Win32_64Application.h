#pragma once
#include "DXSample.h"

class DXSample;

class Win32_64Application
{
public:
	Win32_64Application();
	virtual ~Win32_64Application();

	static int Run(DXSample* pSample, HINSTANCE hInstance);
	static HWND GetHWND() { return m_hwnd;}

protected:

	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
private:

	static HWND m_hwnd;
};

