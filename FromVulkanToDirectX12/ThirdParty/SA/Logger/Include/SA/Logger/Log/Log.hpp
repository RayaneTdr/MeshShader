// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_LOG_GUARD
#define SAPPHIRE_LOGGER_LOG_GUARD

#include <SA/Logger/Log/LogLevel.hpp>
#include <SA/Logger/Misc/DateTime.hpp>
#include <SA/Logger/Misc/ToString.hpp>

/**
*	\file Log.hpp
*
*	\brief \b Log type implementation.
*
*	\ingroup Logger
*	\{
*/

namespace SA
{
	/// Log type implementation.
	class Log
	{
	public:
		/// File name.
		std::wstring file;

		/// Line number.
		uint32_t line = 0u;

		/// Function name.
		std::string function;

		/// User string message.
		std::wstring msg = L"Hello, World!";

		/// Output level.
		LogLevel level = LogLevel::Normal;

		/// Output channel name.
		std::wstring chanName = L"Default";

		/// Additional details string.
		std::wstring details;

		/// Frame number.
		uint32_t frameNum = 0u;

		/// backtracing of logging call.
		std::string backtrace;

		/// Date time.
		DateTime date;


		/// Default constructor.
		Log() = default;

		/**
		*	\brief \e Value Move Constructor.
		*
		*	\param[in] _file		File of the Log.
		*	\param[in] _line		Line of the Log.
		*	\param[in] _function	Function of the Log.
		*	\param[in] _msg			Message of the Log.
		*	\param[in] _level		Level of the Log.
		*	\param[in] _chanName	Channel's name of the Log.
		*	\param[in] _details		Additional details to display.
		*	\param[in] _frameNum	Frame number of the Log.
		*	\param[in] _backtrace	backtracing of logging call.
		*/
		Log(
			std::wstring _file,
			uint32_t _line,
			std::string _function,
			std::wstring _msg = L"Hello, World!",
			LogLevel _level = LogLevel::Normal,
			std::wstring _chanName = L"Default",
			std::wstring _details = L"",
			uint32_t _frameNum = 0u,
			std::string _backtrace = ""
		) noexcept;
	};

	/**
	*	\brief ToWString implementation for log.
	*
	*	Convert log to wstring.
	*
	*	\return log as a wstring.
	*/
	std::wstring ToWString(const Log& _log);
}


/** \} */

#endif // GUARD
