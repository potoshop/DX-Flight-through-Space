#include "DXShader.h"
#include <d3d11.h>
#include "DXSampleHelper.h"


DXShader::DXShader()
{
}


DXShader::~DXShader()
{
}

bool DXShader::CreateShader(DXSHADER_TYPE type)
{
	return true;
}

void DXShader::Render()
{
}

void DXShader::SetShader(DXShader* NewShader)
{
}

bool DXShader::CreateVertexShader(LPCWSTR FileName, LPCSTR FuncName, ID3D10Blob** OutBlob)
{
	return false;
}

bool DXShader::CreatePixelShader(LPCWSTR FileName, LPCSTR FuncName, ID3D10Blob** OutBlob)
{
	return false;
}

bool DXShader::LoadShader(LPCWSTR FileName, LPCSTR FuncName, LPCSTR sVer, ID3D10Blob** OutBlob)
{
	auto loadVSTask = 

	return true;
}
