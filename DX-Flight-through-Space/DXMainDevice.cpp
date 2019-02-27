#include "DXMainDevice.h"
#include <d3d11_4.h>
#include <d3d11_3.h>
#include <d3d11.h>
#include <dxgi1_3.h>
#include <dxgi.h>
#include "DXHelper.h"
#include "Win32_64Application.h"


DXMainDevice::DXMainDevice()
{
}


DXMainDevice::~DXMainDevice()
{
}

bool DXMainDevice::OnInit()
{
	//Этот флаг позволяет использовать Direct2D
	UINT createFlag = D3D11_CREATE_DEVICE_BGRA_SUPPORT;

#if defined(_DEBUG)
	createFlag |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	D3D_FEATURE_LEVEL featureLevel[] =
	{
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_1,
	};

	ComPtr <ID3D11Device> pDevice;
	ComPtr <ID3D11DeviceContext> pDeviceContext;

	ThrowIfFailed(
		D3D11CreateDevice(
			nullptr,
			D3D_DRIVER_TYPE_HARDWARE,
			nullptr,
			createFlag,
			featureLevel,
			ARRAYSIZE(featureLevel),
			D3D11_SDK_VERSION,
			&pDevice,
			nullptr,
			&pDeviceContext));

	ThrowIfFailed(pDevice.As(&m_pd3dDevice));
	ThrowIfFailed(pDeviceContext.As(&m_pd3dDeviceContext));

	DXGI_SWAP_CHAIN_DESC1  scDesc = { 0 };
	scDesc.Stereo = FALSE;
	scDesc.BufferCount = 2;
	scDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	scDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	scDesc.Width = 0;
	scDesc.Height = 0;
	scDesc.SampleDesc.Count = 1;
	scDesc.SampleDesc.Quality = 0;
	scDesc.Scaling = DXGI_SCALING_NONE;
	scDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
	scDesc.Flags = 0;

	ComPtr<IDXGIDevice2> dxgiDevice;
	ThrowIfFailed(m_pd3dDevice.As(&dxgiDevice));

	ThrowIfFailed(dxgiDevice->SetMaximumFrameLatency(1));

	ComPtr<IDXGIAdapter> dxgiAdapter;
	ThrowIfFailed(dxgiDevice->GetAdapter(&dxgiAdapter));

	ComPtr<IDXGIFactory2> dxgiFactory;
	ThrowIfFailed(dxgiAdapter->GetParent(IID_PPV_ARGS(&dxgiFactory)));

	ThrowIfFailed(
		dxgiFactory->CreateSwapChainForHwnd(
			m_pd3dDevice.Get(),
			Win32_64Application::GetHWND(),
			&scDesc,
			nullptr,
			nullptr,
			&m_SwapChain));

	ComPtr<ID3D11Texture2D> pBackBufferTexture;

	ThrowIfFailed(
		m_SwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBufferTexture)));

	ThrowIfFailed(
		m_pd3dDevice->CreateRenderTargetView(pBackBufferTexture.Get(), nullptr, &m_RenderTargetView));

	m_pd3dDeviceContext->OMSetRenderTargets(1, m_RenderTargetView.GetAddressOf(), nullptr);

	D3D11_TEXTURE2D_DESC pBackBufferDesc;
	pBackBufferTexture->GetDesc(&pBackBufferDesc);

	D3D11_VIEWPORT vp;
	vp.MaxDepth = D3D11_MAX_DEPTH;
	vp.MinDepth = D3D11_MIN_DEPTH;
	vp.TopLeftX = 0.0f;
	vp.TopLeftY = 0.0f;
	vp.Width = static_cast<FLOAT> (pBackBufferDesc.Width);
	vp.Height = static_cast<FLOAT>(pBackBufferDesc.Height);

	m_pd3dDeviceContext->RSSetViewports(1, &vp);

	return true;
}

DXMainDevice* DXMainDevice::Get()
{
	static DXMainDevice instance;
	return &instance;
}
