// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_NULLPTR_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_NULLPTR_GUARD

#include <SA/Logger/Exceptions/Exception.hpp>

/**
*	\file Exception_Nullptr.hpp
*
*	\brief <b>Nullptr Exception</b> type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace SA
{
	/// Nullptr Exception type.
	class Exception_Nullptr : public Exception
	{
	public:
		/**
		*	\e Value Constructor.
		*
		*	\param[in] _info		Base create info.
		*	\param[in] _pred		Evaluated pointer predicate.
		*	\param[in] _predStr		Predicate as a string.
		*/
		Exception_Nullptr(
			BaseInfo _info,
			bool _pred,
			std::wstring _predStr = L"ptr"
		) noexcept;
	};



	/// \cond Internal

	/// Define Nullptr Exception creation method.
	#define __SA_CREATE_EXCEPTION_Nullptr(_baseInfo, _pred) SA::Exception_Nullptr(\
		_baseInfo,\
		_pred,\
		SA_WSTR(_pred)\
	)

	/// \endcond
}

/**
*	\example Exception_NullptrTests.cpp
*	Examples and Unitary Tests for Exception_Nullptr.
*/


/** \} */

#endif // GUARD
