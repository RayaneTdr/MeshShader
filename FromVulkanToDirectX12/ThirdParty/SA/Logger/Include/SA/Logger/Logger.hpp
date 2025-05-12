// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_LOGGER_GUARD
#define SAPPHIRE_LOGGER_LOGGER_GUARD

#include <SA/Logger/LoggerBase.hpp>

/**
*	\file Logger.hpp
*
*	\brief <b>Logger</b> class implementation.
*
*	\ingroup Logger
*	\{
*/


namespace SA
{
	/**
	*	\brief Basic Logger class implementation.
	* 
	*	Non-thread-safe logging.
	*/
	class Logger : public LoggerBase
	{
		/**
		* \brief Current registered frame number.
		* Use IncrementFrameNum() or SA_LOG_END_OF_FRAME() at the end of the frame to track frame number.
		*/
		uint32_t mFrameNum = 0u;

	public:

//{ Frame Num

		/// Increment current registered frame number.
		void IncrementFrameNum() override final;

		/// Get current registered frame number.
		uint32_t GetFrameNum() const override final;
//}
	};
}


/** \} */

#endif // GUARD
