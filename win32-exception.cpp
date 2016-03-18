#include "win32-exception.h"

namespace Yalla
{
	Win32Exception::Win32Exception()
		: _errorCode(E_FAIL)
	{
	}

	Win32Exception::Win32Exception(const DWORD errorCode)
		: _errorCode(errorCode)
	{
	}

	char const* Win32Exception::what() const noexcept
	{
		DWORD languageId = MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US);

		std::wstring msg = message(languageId);

		return ToChar::from(msg);
	}

	std::wstring Win32Exception::message() const noexcept
	{
		DWORD languageId = MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL);

		return message(languageId);
	}

	std::wstring Win32Exception::message(DWORD languageId) const noexcept
	{
		DWORD flags = FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_ALLOCATE_BUFFER;

		LPWSTR buffer = nullptr;

		DWORD length = FormatMessageW(flags, nullptr, _errorCode, languageId, (LPWSTR)&buffer, 0, nullptr);

		std::wstring message;

		if (length == 0)
		{
			std::wstring errorCode = std::to_wstring(GetLastError());

			message = L"Cannot get the error message. FormatMessage failed with code '" + errorCode + L"'.";
		}
		else
		{
			message = buffer;

			LocalFree(buffer);
		}

		return message;
	}
}


