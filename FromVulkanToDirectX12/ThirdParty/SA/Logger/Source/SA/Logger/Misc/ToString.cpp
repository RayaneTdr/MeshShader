// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <Misc/ToString.hpp>

#include <cstring>
#include <codecvt>
#include <locale>

#include <SA/Support/Debug.hpp>
#include <SA/Support/API/Windows.hpp>

namespace SA
{
//{ ToString

	namespace Intl
	{
		std::string ToStringBinary(const char* _data, uint64_t _size) noexcept
		{
			static constexpr char table[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

			std::string res;

			res.reserve(3 * _size + 1);

			res += '<';

			for (const char* it = _data + _size - 1; it >= _data; --it)
			{
				res += table[(*it & 0xF0) >> 4];
				res += table[*it & 0x0F];

				res += '-';
			}

			res.back() = '>';

			return res;
		}
	}


	std::string ToString(const char& _char)
	{
		return std::string(1u, _char);
	}

	std::string ToString(const char* _cstr)
	{
		return std::string(_cstr);
	}

	std::string ToString(const std::string& _str) noexcept
	{
		return _str;
	}

	std::string ToString(std::string&& _str) noexcept
	{
		return std::move(_str);
	}

//}


//{ ToWString

	std::wstring ToWString(const char& _char)
	{
		return std::wstring(1u, _char);
	}

	std::wstring ToWString(const char* _cstr)
	{
#if SA_WIN

		// strlen does not count '\0'
		const int srcByteSize = static_cast<int>(strlen(_cstr)) * sizeof(char);

		if(srcByteSize == 0)
			return std::wstring();

		// Compute converted size.
		const int wsize = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, _cstr, srcByteSize, nullptr, 0);

		std::wstring out;
		out.resize(wsize);

		// Convert.
		const int res = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, _cstr, srcByteSize, out.data(), wsize);

		(void)res;

#if SA_DEBUG

		// Function failed.
		if (res == 0)
			return std::wstring(L"Invalid ToWString conversion. Error code [" + std::to_wstring(GetLastError()) + L"]");

#endif

		return out;

#else
		
		return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(_cstr);

#endif
	}

	std::wstring ToWString(const wchar_t& _char)
	{
		return std::wstring(1u, _char);
	}

	std::wstring ToWString(const wchar_t* _cstr)
	{
		return std::wstring(_cstr);
	}

	std::wstring ToWString(const std::string& _str)
	{
#if SA_WIN

		if (_str.empty())
			return std::wstring();

		const int srcByteSize = static_cast<int>(_str.size() * sizeof(std::string::value_type));

		// Compute converted size.
		const int wsize = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, _str.data(), srcByteSize, nullptr, 0);

		std::wstring out;
		out.resize(wsize);

		// Convert.
		const int res = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, _str.data(), srcByteSize, out.data(), wsize);

		(void)res;

#if SA_DEBUG

		// Function failed.
		if (res == 0)
			return std::wstring(L"Invalid ToWString conversion. Error code [" + std::to_wstring(GetLastError()) + L"]");

#endif

		return out;

#else

		return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(_str);

#endif

	}

	std::wstring ToWString(const std::wstring& _str) noexcept
	{
		return _str;
	}

	std::wstring ToWString(std::wstring&& _str) noexcept
	{
		return std::move(_str);
	}

//}
}
