// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_GUARD

#include <SA/Logger/Log/Log.hpp>

/**
*	\file Exception.hpp
*
*	\brief <b>Default Exception</b> type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace SA
{
	/// Default (base) Exception type.
	class Exception : public Log
	{
	public:
		/// Base exception <b>create info</b>.
		struct BaseInfo
		{
			/// File name.
			std::wstring file;

			/// line number.
			uint32_t line;

			/// Function name.
			std::string function;

			/// LogChannel name.
			std::wstring chanName;

			/// Additional details string.
			std::wstring details;

			/// Frame num.
			uint32_t frameNum;
		};

		/**
		*	\e Value Constructor.
		* 
		*	\param[in] _info		Base create info.
		*	\param[in] _pred		Predicate used for assertion.
		*	\param[in] _msg			Message to display on assertion.
		*/
		Exception(
			BaseInfo _info,
			bool _pred,
			std::wstring _msg = L""
		) noexcept;
	};

	/// Default type of exception.
	using Exception_Default = Exception;

	
	/// \cond Internal

	/// Define Default Exception creation method.
	#define __SA_CREATE_EXCEPTION_Default(_baseInfo, _pred, ...) SA::Exception_Default(\
		_baseInfo,\
		_pred,\
		SA_WSTR(_pred) L"\tevaluated to false!"\
	)

	/// \endcond
}


/** \} */

#endif // GUARD
