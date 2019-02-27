#pragma once

#include "DXSample.h"

class DXSample;

class DXWindow : public DXSample
{
public:
	DXWindow(UINT width, UINT height, std::wstring title);
	virtual ~DXWindow();

	// Inherited via DXSample
	virtual void OnInit() override;
	virtual void Render() override;
	virtual void UpdateFrame() override;
};

