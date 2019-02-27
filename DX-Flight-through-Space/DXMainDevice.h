#pragma once

//#include "Headers.h"
#include <wrl.h>
#include <shellapi.h>

using Microsoft::WRL::ComPtr;

class DXMainDevice
{
	DXMainDevice();
	DXMainDevice(const DXMainDevice&) = delete;
	virtual ~DXMainDevice();

public:

	bool OnInit();
	static DXMainDevice* Get();

public:
	inline struct ID3D11Device* GetDevice() const
	{
		return m_pd3dDevice.Get();
	}

	inline struct ID3D11DeviceContext* GetDeviceContext() const
	{
		return m_pd3dDeviceContext.Get();
	}

	inline struct IDXGISwapChain1* GetSwapChain() const
	{
		return m_SwapChain.Get();
	}

	inline struct ID3D11RenderTargetView* GetRenderTargetView() const 
	{
		return m_RenderTargetView.Get();
	}

private:

	ComPtr<struct ID3D11Device> m_pd3dDevice;
	ComPtr<struct ID3D11DeviceContext> m_pd3dDeviceContext;
	ComPtr<struct IDXGISwapChain1> m_SwapChain;
	ComPtr<struct ID3D11RenderTargetView> m_RenderTargetView;
};

