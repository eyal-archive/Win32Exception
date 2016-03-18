#pragma once
#include <windows.h>
#include "defines.h"
#include "string-converter.h"

namespace Yalla
{
	/// <summary>
	///	Throws an exception for a Win32 error code.
	/// </summary>
	class Win32Exception : public std::exception {
	public:
		// <summary>
		/// Initializes <c>Win32Exception</c>.
		/// </summary>
		Win32Exception();

		// <summary>
		/// Initializes <c>Win32Exception</c>.
		/// </summary>
		/// <param name = "errorCode"> A Win32 error code. < / param>
		explicit Win32Exception(const DWORD errorCode);

		explicit Win32Exception(const std::string&) = delete;

		explicit Win32Exception(const char*) = delete;

		/// <summary>
		///	Resources clean-up.
		/// </summary>
		virtual ~Win32Exception() noexcept override = default;

		/// <summary>
		///	Returns a null terminated of a character sequence that may be used to identify the exception.
		/// </summary>
		/// <return> A null terminated of a character sequence that may be used to identify the exception. </return>
		EXPORT char const* what() const noexcept override;

		/// <summary>
		///	Returns a string that may be used to identify the exception.
		/// </summary>
		/// <return> A string that may be used to identify the exception. </return>
		EXPORT std::wstring message() const noexcept;

		/// <summary>
		///	Returns a string that may be used to identify the exception.
		/// </summary>
		/// <param name = "languageId"> A language identifier. < / param>
		/// <return> A string that may be used to identify the exception. </return>
		EXPORT std::wstring message(DWORD languageId) const noexcept;
	private:
		const DWORD _errorCode;
	};
}
