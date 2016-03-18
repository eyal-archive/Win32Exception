#include "string-converter.h"

namespace Yalla
{
	std::string ToString::from(const std::wstring& value)
	{
		return (WSTRING_CONVERTER()).to_bytes(value);
	}

	std::wstring ToWideString::from(const std::string& value)
	{
		return (WSTRING_CONVERTER()).from_bytes(value);
	}

	char const* ToChar::from(const std::string& value)
	{
		char* to = new char[value.length() + 1];

		strcpy_s(to, value.size() + 1, value.c_str());

		return to;
	}

	char const* ToChar::from(const std::wstring& value)
	{
		std::string to = ToString::from(value);

		return from(to);
	}
}

