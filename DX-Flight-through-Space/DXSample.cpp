#include "DXSample.h"



DXSample::DXSample(std::wstring Name, UINT width, UINT height) :
	m_WinTitile(Name),
	m_Widht(width),
	m_Height(height)
{
	m_bCheatMode = false;
}

DXSample::~DXSample()
{
}

void DXSample::ParseCommandeLineArgs(_In_reads_(argc) WCHAR* argv[], int argc)
{

	for (int i = 1; i < argc; ++i)
	{
		//подключение читов
		if (_wcsnicmp(argv[i], L"-cheat", wcslen(argv[i])) == 0)
		{
			m_bCheatMode = true;
			m_WinTitile = m_WinTitile + L" (CHEATMODE ON)";
		}
	}
}

