#pragma once
#include "DXResurce.h"
#include <wrl.h>

using Microsoft::WRL::ComPtr;

struct ID3D11VertexShader;
struct ID3D11PixelShader;
struct ID3D11InputLayout;
struct ID3D10Blob;

class DXShader : public DXResurce
{
public:

	enum class DXSHADER_TYPE : UINT8
	{
		DXSHADER_TYPE_BASEFILL,
	};

public:

	DXShader() = default;
	virtual ~DXShader() = default;

	bool CreateShader(DXSHADER_TYPE type);
	void Render();
	void SetShader(DXShader* NewShader);

private:

	bool CreateVertexShader(LPCWSTR FileName, LPCSTR FuncName, ID3D10Blob** OutBlob);
	bool CreatePixelShader(LPCWSTR FileName, LPCSTR FuncName, ID3D10Blob** OutBlob);

	bool LoadShader(LPCWSTR FileName, LPCSTR FuncName, LPCSTR sVer, ID3D10Blob** OutBlob);

private:
	ComPtr<ID3D11VertexShader> m_vertex_shader;
	ComPtr<ID3D11PixelShader> m_pixel_sheader;
	ComPtr<ID3D11InputLayout> m_input_layout;

	const std::string m_base_vshader = "Data\\VS.hlsl";
	const std::string m_fill_pshader = "Data\\Fill.hlsl";
	const std::string m_main_func_shader = "main";

};

