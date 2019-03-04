#pragma once

#include "Headers.h"
#include <stdexcept>

inline std::string HrToString(HRESULT hr)
{
	char s_str[64] = {};
	sprintf_s(s_str, "HRESULT of 0x%08X", static_cast<UINT>(hr));
	return std::string(s_str);
}

class HrException : public std::runtime_error
{
public:

	HrException(HRESULT hr) : std::runtime_error(HrToString(hr)), m_hr(hr)
	{
	}

	HRESULT Error() const { return m_hr; }

private:

	const HRESULT m_hr;
};

inline void ThrowIfFailed(HRESULT hr)
{
	if (FAILED(hr))
	{
		throw HrException(hr);
	}
}

inline HRESULT ReadDataFromFile(LPCWSTR filename, byte** data, UINT* size)
{
	using namespace Microsoft::WRL;

	CREATEFILE2_EXTENDED_PARAMETERS extendedParams = {};
	extendedParams.dwSize = sizeof(CREATEFILE2_EXTENDED_PARAMETERS);
	extendedParams.dwFileAttributes = FILE_ATTRIBUTE_NORMAL;
	extendedParams.dwFileFlags = FILE_FLAG_SEQUENTIAL_SCAN;
	extendedParams.dwSecurityQosFlags = SECURITY_ANONYMOUS;
	extendedParams.lpSecurityAttributes = nullptr;
	extendedParams.hTemplateFile = nullptr;

	Wrappers::FileHandle file(CreateFile2(filename, GENERIC_READ,
		FILE_SHARE_READ, OPEN_EXISTING, &extendedParams));
	if (file.Get() == INVALID_HANDLE_VALUE)
	{
		throw std::exception();
	}

	FILE_STANDARD_INFO fileinfo = {};
	if (!GetFileInformationByHandleEx(file.Get(), FileStandardInfo, &fileinfo, sizeof(fileinfo)))
	{
		throw std::exception();
	}

	if (fileinfo.EndOfFile.HighPart != 0)
	{
		throw std::exception();
	}

	*data = reinterpret_cast<byte*>(malloc(fileinfo.EndOfFile.LowPart));
	*size = fileinfo.EndOfFile.LowPart;

	if (!ReadFile(file.Get(), *data, fileinfo.EndOfFile.LowPart, nullptr, nullptr))
	{
		throw std::exception();
	}
	return S_OK;


}
