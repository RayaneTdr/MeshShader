// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_CHANNEL_NAME_GUARD
#define SAPPHIRE_LOGGER_CHANNEL_NAME_GUARD

#include <string>
#include <algorithm>

#include <SA/Support/Stringify.hpp>

namespace SA
{
	/// \cond Internal

	namespace Intl
	{
		/**
		*	\brief Remove spaces in string.
		*
		*	\param[in] _str	string to remove spaces in.
		*
		*	\return New string without spaces.
		*/
		inline std::wstring RemoveSpaces(std::wstring _str) noexcept
		{
			_str.erase(std::remove_if(_str.begin(), _str.end(), isspace), _str.end());

			return _str;
		}
	}

	#define __SA_CHAN_NAME(_chan) SA::Intl::RemoveSpaces(SA_WSTR(_chan))

	/// \endcond
}

#endif // GUARD
