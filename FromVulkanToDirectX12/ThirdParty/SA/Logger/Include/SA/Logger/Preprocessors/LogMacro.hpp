// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_LOG_MACRO_GUARD
#define SAPPHIRE_LOGGER_LOG_MACRO_GUARD

#include <iostream>

#include <SA/Support/Debug.hpp>

#include <SA/Logger/Log/Log.hpp>
#include <SA/Logger/Misc/StringFormat.hpp>
#include <SA/Logger/Preprocessors/FileName.hpp>
#include <SA/Logger/Preprocessors/FunctionName.hpp>
#include <SA/Logger/Preprocessors/ChannelName.hpp>
#include <SA/Logger/Preprocessors/Unparenthese.hpp>

/**
*	\file LogMacro.hpp
*
*	\brief \b Log Helper \b Macros implementation.
*
*	\ingroup Logger_Macro
*	\{
*/


namespace SA
{
//{ Callback

	class LoggerBase;

	/// Global Debug namespace
	namespace Debug
	{
		/// Logger instance.
		extern LoggerBase* logger;

		/// Simple logger callback.
		extern void (*logCB)(SA::Log);

		/**
		* \brief Initialize default logger for single-thread use.
		* Console color and file output.
		*/
		void InitDefaultLogger();

		/**
		* \brief Initialize default logger for multi-thread use.
		* Console color and file output.
		*/
		void InitDefaultLoggerThread();


		/// \cond Internal

		namespace Intl
		{
			void DefaultLogCallback(SA::Log _log);
		}

		/// \endcond
	}

	/// \cond Internal

	#define __SA_LOGGER(_log)\
		if (SA::Debug::logger)\
			SA::Debug::logger->Log(_log);\
		else if (SA::Debug::logCB)\
			SA::Debug::logCB(_log);\
		else\
			std::cerr << "Try logging with invalid logger instance or callback! Initialize SA::Debug::logger or SA::Debug::logCB." << std::endl;

	#define __SA_LOG_FRAME_NUM\
		SA::Debug::logger ? SA::Debug::logger->GetFrameNum() : 0u

	/// \endcond

//}


	/// \cond Internal

	//#define __SA_TRY_FAST_WIDE(_str) std::is_same_v<std::remove_extent_t<std::remove_reference_t<decltype(_str)>>, const char> ? (SA_WIDE(_str)) : SA::ToWString(_str)

	#define __SA_CREATE_LOG(_str, _lvl, _chan, _dets) SA::Log(\
		__SA_FILE_NAME,\
		__LINE__,\
		__SA_FUNC_NAME,\
		SA::StringFormat(__SA_UNPARENT(_str)),\
		SA::LogLevel::_lvl,\
		__SA_CHAN_NAME(_chan),\
		SA::StringFormat(__SA_UNPARENT(_dets)),\
		__SA_LOG_FRAME_NUM,\
		std::string()\
	)

	// TODO: Add backtrace.

	#define __SA_SELECT_LOG_MACRO(_1, _2, _3, _4, _5, _name, ...) _name

	#define __SA_LOG4(_str, _lvl, _chan, _dets)				__SA_LOGGER(__SA_CREATE_LOG(_str, _lvl, _chan, _dets));
	#define __SA_LOG5(_str, _lvl, _chan, _dets, _postCmd)	{ __SA_LOG4(_str, _lvl, _chan, _dets) _postCmd; }
	#define __SA_LOG3(_str, _lvl, _chan)					__SA_LOG4(_str, _lvl, _chan, L"")
	#define __SA_LOG2(_str, _lvl)							__SA_LOG3(_str, _lvl, Default)
	#define __SA_LOG1(_str)									__SA_LOG2(_str, Normal)

	#define __SA_COND_LOG(_pred, _lvl, ...)		if(!(_pred)) SA_LOG(L"{ " SA_WSTR(_pred) " }\tevaluated to false!", _lvl, ##__VA_ARGS__)

	/// \endcond

#if defined(DOXYGEN)

	/**
	*	\def SA_LOG_END_OF_FRAME()
	* 
	*	\brief Sapphire Log end of frame macro.
	* 
	*	Helper macro to track frame number used for logging.
	*/
	#define SA_LOG_END_OF_FRAME()

	/**
	*	\def SA_LOG((_str, _args), _lvl, _chan, _dets)
	*
	*	\brief Sapphire Log macro.
	*
	*	Helper macro to use Debug::Log.
	*
	*	\param[in] _str		String message of the log. Parentheses are optionnal for single string or object.
	*	\param[in] _args	Arguments to insert in string using %<num>. Must add parentheses surrounding: (_str, _args). 
	*	\param[in] _lvl		Level of the log (optional).
	*	\param[in] _chan	Channel of the log (optional).
	*	\param[in] _dets	Details string of the log (optional).
	*/
	#define SA_LOG((_str, _args), _lvl, _chan, _dets)

	/**
	*	\def SA_WARN(_pred, _chan, _dets, _postCmd)
	*
	*	\brief Sapphire Log "warning if" macro.
	*
	*	Helper macro to use conditionnal Debug::Log warning.
	*
	*	\param[in] _pred	predicate of the Log. Output warnings on false.
	*	\param[in] _chan	Channel of the log.
	*	\param[in] _dets	Details string of the log (optional).
	*	\param[in] _postCmd	Post-log command on true predicate, usually for return value (optional).
	*/
	#define SA_WARN(_pred, _chan, _dets, _postCmd)

	/**
	*	\def SA_ERROR(_pred, _chan, _dets, _postCmd)
	*
	*	\brief Sapphire Log "error if" macro.
	*
	*	Helper macro to use conditionnal Debug::Log error.
	*
	*	\param[in] _pred	predicate of the Log. Output error on false.
	*	\param[in] _chan	Channel of the log (optional).
	*	\param[in] _dets	Details string of the log (optional).
	*	\param[in] _postCmd	Post-log command on true predicate, usually for return value (optional).
	*/
	#define SA_ERROR(_pred, _chan, _dets, _postCmd)

#elif SA_DEBUG || SA_LOG_RELEASE_OPT

	#define SA_LOG_END_OF_FRAME() { if(SA::Debug::logger) SA::Debug::logger->IncrementFrameNum(); }

	#define SA_LOG(...) { __SA_SELECT_LOG_MACRO(__VA_ARGS__, __SA_LOG5, __SA_LOG4, __SA_LOG3, __SA_LOG2, __SA_LOG1)(__VA_ARGS__) }

	#define SA_WARN(_pred, ...) { __SA_COND_LOG(_pred, Warning, ##__VA_ARGS__) }

	#define SA_ERROR(_pred, ...) { __SA_COND_LOG(_pred, Error, ##__VA_ARGS__) }

#else

	#define SA_LOG_END_OF_FRAME() {}

	#define SA_LOG(...) {}

	#define SA_WARN(...) {}

	#define SA_ERROR(...) {}

#endif
}


/** \} */

#endif // GUARD
