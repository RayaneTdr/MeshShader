// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_CONSOLE_COLOR_THEME_GUARD
#define SAPPHIRE_LOGGER_CONSOLE_COLOR_THEME_GUARD

#include <SA/Logger/Log/LogLevel.hpp>
#include <SA/Logger/Streams/Console/ConsoleColor.hpp>

/**
*	\file ConsoleColorTheme.hpp
* 
*	\brief Define color theme by LogLevel.
* 
*	\ingroup Logger_Console
*	\{
*/

namespace SA
{
	/**
	*	Console color theme by LogLevel.
	*/
	struct ConsoleColorTheme
	{
		/// Normal level color.
		uint8_t normal = CslColor::Bright_FG;

		/// Info level color.
		uint8_t info = CslColor::Blue_FG | CslColor::Bright_FG;

		/// Warning level color.
		uint8_t warning = CslColor::Yellow_FG;

		/// Error level color.
		uint8_t error = CslColor::Red_FG | CslColor::Bright_FG;

		/// Assert Success level color.
		uint8_t assertSuccess = CslColor::Green_FG | CslColor::Bright_FG;

		/// Assert Failure level color.
		uint8_t assertFailure = CslColor::Magenta_FG | CslColor::Bright_FG;


		/**
		*	\brief convert theme to data type.
		* 
		*	\returns this as uint8_t data.
		*/
		const uint8_t* Data() const;

		/**
		*	\brief Set console color from log level using theme.
		* 
		*	\param[in] _lvl		LogLevel to use for theme.
		*/
		void SetConsoleColorFromLevel(LogLevel _lvl) const;
	};
}


/** \} */

#endif // GUARD
