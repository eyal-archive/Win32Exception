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

	wchar_t const* Win32Exception::message() const noexcept
	{
		DWORD languageId = MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US);

		return message(languageId);
	}

	wchar_t const* Win32Exception::message(DWORD languageId) const noexcept
	{
		DWORD flags = FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_ALLOCATE_BUFFER;

		LPWSTR buffer = nullptr;

		DWORD length = FormatMessageW(flags, nullptr, _errorCode, languageId, (LPWSTR)&buffer, 0, nullptr);

		std::wstring message;

		if (length == 0)
		{
			std::wstring formatMessageErrCode = std::to_wstring(GetLastError());

			std::wstring formatMessageFailedForErrCode = std::to_wstring(_errorCode);

			message = L"FormatMessage failed with code '" + formatMessageErrCode + L"'.\r\n\r\nFormatMessage failed to reterive the Win32 error message for code '" + formatMessageFailedForErrCode + L"'.";
		}
		else
		{
			message = buffer;

			LocalFree(buffer);
		}

		return ToWideChar::from(message);
	}
}


