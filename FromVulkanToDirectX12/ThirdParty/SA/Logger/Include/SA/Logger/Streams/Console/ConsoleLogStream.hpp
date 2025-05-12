// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_CONSOLE_LOG_STREAM_GUARD
#define SAPPHIRE_LOGGER_CONSOLE_LOG_STREAM_GUARD

#include <SA/Logger/Streams/ALogStream.hpp>
#include <SA/Logger/Streams/Console/ConsoleColorTheme.hpp>

/**
*	\file ConsoleLogStream.hpp
*
*	\brief Log <b>console stream</b> type implementation.
*
*	\ingroup Logger_Console
*	\{
*/


namespace SA
{
	/// Console log stream implementation.
	class ConsoleLogStream : public ALogStream
	{
		void Output(const Log& _log) override final;

	public:
		/// Color theme.
		ConsoleColorTheme theme;


		void Flush() override final;
	};
}


/** \} */

#endif // GUARD
