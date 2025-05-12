// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_LOG_RAII_GUARD
#define SAPPHIRE_LOGGER_LOG_RAII_GUARD

#include <SA/Logger/Preprocessors/LogMacro.hpp>

/**
*	\file LogRAII.hpp
*
*	\brief <b>Log RAII</b> type implementation.
*
*	\ingroup Logger
*	\{
*/


namespace SA
{
	/**
	* \brief Log RAII type implementation.
	* Delays the log at the end of the scope.
	*/
	class LogRAII
	{
		Log mHandle;

	public:
		/**
		* \brief Construct RAII with log handle.
		* 
		* \param[in] _log	Log to handle.
		*/
		LogRAII(Log&& _log);

		/// Destructor calling logger.
		~LogRAII();
	};

	/// \cond Internal

	#define __SA_SELECT_LOG_RAII_MACRO(_1, _2, _3, _4, _name, ...) _name

	#define __SA_LOG_RAII4(_str, _lvl, _chan, _dets) 		__SA_CREATE_LOG(_str, _lvl, _chan, _dets)
	#define __SA_LOG_RAII3(_str, _lvl, _chan) 				__SA_LOG_RAII4(_str, _lvl, _chan, L"")
	#define __SA_LOG_RAII2(_str, _lvl) 						__SA_LOG_RAII3(_str, _lvl, Default)
	#define __SA_LOG_RAII1(_str) 							__SA_LOG_RAII2(_str, Normal)

	/// \endcond

#if defined(DOXYGEN)

	/**
	 * \def SA_LOG_RAII((_str, _args), _lvl, _chan, _dets)
	 *
	 * \brief Sapphire Log RAII macro
	 *
	 * Helper macro to use Logger with RAII system.
	 * Create log and wait for handle destroy to submit log to logger.
	 *
	 * \param[in] _str		String message of the log. Parentheses are optionnal for single string or object.
	 * \param[in] _args		Arguments to insert in string using %<num>. Must add parentheses surrounding: (_str, _args).
	 * \param[in] _lvl		Level of the log (optional).
	 * \param[in] _chan		Channel of the log (optional).
	 * \param[in] _dets		Details string of the log (optional).
	 */
	#define SA_LOG_RAII((_str, _args), _lvl, _chan, _dets)

#elif SA_DEBUG || SA_LOG_RELEASE_OPT

	#define SA_LOG_RAII(...) SA::LogRAII __SA_EVAL_PASTE(__log_raii, __LINE__)(\
		__SA_SELECT_LOG_RAII_MACRO(__VA_ARGS__, __SA_LOG_RAII4, __SA_LOG_RAII3, __SA_LOG_RAII2, __SA_LOG_RAII1)(__VA_ARGS__)\
	);

#else

	#define SA_LOG_RAII(...) {}

#endif

}


/** \} */

#endif // SAPPHIRE_LOGGER_LOG_RAII_GUARD
