#pragma once
#include <string>
#include <locale>
#include <codecvt>

namespace Yalla
{
	typedef std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> WSTRING_CONVERTER;

	class ToChar {
	public:
		static char const* from(const std::string&);

		static char const* from(const std::wstring&);
	};

	class ToString {
	public:
		static std::string from(const std::wstring&);
	};

	class ToWideChar {
	public:
		static wchar_t const* from(const std::wstring&);
	};

	class ToWideString {
	public:
		static std::wstring from(const std::string&);
	};
}