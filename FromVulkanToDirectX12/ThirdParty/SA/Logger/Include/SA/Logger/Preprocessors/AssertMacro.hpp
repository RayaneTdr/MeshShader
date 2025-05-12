// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_ASSERT_MACRO_GUARD
#define SAPPHIRE_LOGGER_ASSERT_MACRO_GUARD

#include <SA/Logger/Preprocessors/LogMacro.hpp>

/**
*	\file AssertMacro.hpp
*
*	\brief \b Assert Helper \b Macros implementation.
*
*	\ingroup Logger_Macro
*	\{
*/


namespace SA
{
//{ Callback

	/// \cond Internal

	#define __SA_ASSERT(_exc)\
		if (SA::Debug::logger)\
			SA::Debug::logger->Assert(std::move(_exc));\
		else if (SA::Debug::logCB)\
			SA::Debug::logCB(_exc);\
		else\
			std::cerr << "Try logging with invalid logger instance or callback! Initialize SA::Debug::logger or SA::Debug::logCB." << std::endl;

	/// \endcond

//}

	/// \cond Internal

	#define __SA_CREATE_EXCEPTION_TYPE(_chan, _dets, _type, ...) __SA_CREATE_EXCEPTION_##_type(\
		(SA::Exception::BaseInfo{\
			__SA_FILE_NAME,\
			__LINE__,\
			__SA_FUNC_NAME,\
			__SA_CHAN_NAME(_chan),\
			_dets,\
			__SA_LOG_FRAME_NUM\
		}),\
		##__VA_ARGS__\
	)

	#define __SA_CREATE_EXCEPTION(_type_params, _chan, _dets)\
		__SA_EVAL_PASTE(__SA_CREATE_, EXCEPTION_TYPE(_chan, _dets, __SA_UNPARENT(_type_params)))


	#define __SA_SELECT_ASSERT_MACRO(_1, _2, _3, _name, ...) _name

	#define __SA_ASSERT3(_type_params, _chan, _dets){\
		auto exc = __SA_CREATE_EXCEPTION(_type_params, _chan, SA::StringFormat(__SA_UNPARENT(_dets)));\
		__SA_ASSERT(exc);\
		if(exc.level == SA::LogLevel::AssertFailure) throw exc;\
	}
	#define __SA_ASSERT2(_type_params, _chan) __SA_ASSERT3(_type_params, _chan, L"")
	#define __SA_ASSERT1(_type_params) __SA_ASSERT2(_type_params, Default)


	#define __SA_THROW3(_type_params, _chan, _dets){\
			auto exc = __SA_CREATE_EXCEPTION(_type_params, _chan, SA::StringFormat(__SA_UNPARENT(_dets)));\
			__SA_ASSERT(exc);\
			throw exc;\
		}
	#define __SA_THROW2(_type_params, _chan) __SA_THROW3(_type_params, _chan, L"")
	#define __SA_THROW1(_type_params) __SA_THROW2(_type_params, Default)

	/// \endcond

#if defined(DOXYGEN)

	/**
	*	\def SA_THROW((_type, _params...), _chan, _dets)
	*
	*	\brief Sapphire Throw macro.
	*
	*	Helper macro to force call throw with Debug::Assert.
	*
	*	\param[in] _type		Type of the exception.
	*	\param[in] _params...	Parameters used for the exception type.
	*	\param[in] _chan		Channel of the assert (optional).
	*	\param[in] _dets		Additional details string of the exception (optional).
	*/
	#define SA_THROW((_type, _params...), _chan, _dets)

	/**
	*	\def SA_ASSERT((_type, _params...), _chan, _dets)
	*
	*	\brief Sapphire Assertion macro.
	*
	*	Helper macro to use Debug::Assert.
	*
	*	\param[in] _type		Type of the exception.
	*	\param[in] _params...	Parameters used for the exception type.
	*	\param[in] _chan		Channel of the assert (optional).
	*	\param[in] _dets		Additional details string of the exception (optional).
	*/
	#define SA_ASSERT((_type, _params...), _chan, _dets)

#elif SA_DEBUG || SA_LOG_RELEASE_OPT

	#define SA_THROW(...){ __SA_SELECT_ASSERT_MACRO(__VA_ARGS__, __SA_THROW3, __SA_THROW2, __SA_THROW1)(__VA_ARGS__) }

	#define SA_ASSERT(...) { __SA_SELECT_ASSERT_MACRO(__VA_ARGS__, __SA_ASSERT3, __SA_ASSERT2, __SA_ASSERT1)(__VA_ARGS__) }

#else

	#define SA_THROW(...) {}

	#define SA_ASSERT(...) {}

#endif

}


/** \} */

#endif // GUARD
