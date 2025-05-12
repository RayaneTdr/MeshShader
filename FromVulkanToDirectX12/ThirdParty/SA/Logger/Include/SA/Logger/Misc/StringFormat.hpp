// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_STRING_FORMAT_GUARD
#define SAPPHIRE_LOGGER_STRING_FORMAT_GUARD

#include <string>

namespace SA
{
	namespace Intl
	{
		template <typename StringT>
		uint32_t ReplaceAllInString(StringT& _str, const StringT& _what, const StringT& _with){

			uint32_t count = 0u;

			for(typename StringT::size_type pos{}; (pos = _str.find(_what, pos)) != _str.npos; pos += _with.size())
			{
				_str.replace(pos, _what.size(), _with);
				++count;
			}

			return count;
		}

		template <typename FirstT, typename... Args>
		void StringFormatImpl(std::wstring& _str, uint32_t _depth, FirstT&& _first, Args&&... _args)
		{
			const uint32_t count = Intl::ReplaceAllInString(_str, L'%' + std::to_wstring(_depth), ToWString(_first));

			// No more args to parse.
			// Must be constexpr for valid recursive compilation.
			if constexpr (sizeof...(Args) == 0)
				return;
			else
			{
				// No more token to parse.
				if(!count)
					return;

				StringFormatImpl(_str, _depth + 1, std::forward<Args>(_args)...);
			}
		}
	}

	template <typename FirstT, typename... Args>
	std::wstring StringFormat(FirstT _first, Args&&... _args)
	{
		// Force convert to wstring. Input might be string or any object.
		std::wstring str = SA::ToWString(std::forward<FirstT>(_first));

		// Arguments means string formatting.
		if constexpr (sizeof...(Args) != 0)
			Intl::StringFormatImpl(str, 1u, std::forward<Args>(_args)...);

		return str;
	}
}

#endif // GUARD
