#include "DXWindow.h"
#include "DXMainDevice.h"


#include <d3d11.h>
#include <dxgi1_3.h>
#include <dxgi.h>

DXWindow::DXWindow(UINT width, UINT height, std::wstring title) :
	DXSample(title, width, height)
{

}

DXWindow::~DXWindow()
{
}

void DXWindow::OnInit()
{
	DXMainDevice::Get()->OnInit();
}

void DXWindow::Render()
{

	IDXGISwapChain1* pSwapChain = DXMainDevice::Get()->GetSwapChain();
	if (!pSwapChain)
	{
		return;
	}

	pSwapChain->Present(1, 0);
}

void DXWindow::UpdateFrame()
{

	ID3D11DeviceContext* pDeviceContext = DXMainDevice::Get()->GetDeviceContext();
	if (!pDeviceContext)
	{
		return;
	}

	float Color[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	pDeviceContext->ClearRenderTargetView(DXMainDevice::Get()->GetRenderTargetView(), Color);

}
