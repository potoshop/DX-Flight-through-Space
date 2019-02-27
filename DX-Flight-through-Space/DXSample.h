#pragma once

#include "Headers.h"

class DXSample
{
public:
	DXSample(std::wstring Name, UINT width, UINT height);
	virtual ~DXSample();

	inline std::wstring GetTitle() const { return m_WinTitile; }
	inline UINT GetWinWidth() const { return m_Widht; }
	inline UINT GetWinHeight() const { return m_Height; }

	void ParseCommandeLineArgs(_In_reads_(argc) WCHAR* argv [], int argc);
public:

	virtual void OnInit() = 0;
	virtual void Render() = 0;
	virtual void UpdateFrame() = 0;

private:
	std::wstring m_WinTitile;
	UINT m_Widht;
	UINT m_Height;


	bool m_bCheatMode;
};

