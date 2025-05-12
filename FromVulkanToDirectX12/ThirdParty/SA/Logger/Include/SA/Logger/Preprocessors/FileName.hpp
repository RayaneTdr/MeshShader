// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_FILE_NAME_GUARD
#define SAPPHIRE_LOGGER_FILE_NAME_GUARD

namespace SA
{
	/// \cond Internal

	namespace Intl
	{
		/**
		*	\brief \e Getter of file name from file path.
		*
		*	\param[in] _filePath	Full path to the file.
		*
		*	\returns pointer to the file name in _filePath.
		*/
		const wchar_t* FileNameFromPath(const wchar_t* _filePath) noexcept;
	}

	#define __SA_FILE_NAME SA::Intl::FileNameFromPath(SA_WIDE(__FILE__))

	/// \endcond
}

#endif // GUARD
