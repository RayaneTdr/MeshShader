// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_NOT_EQUALS_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_NOT_EQUALS_GUARD

#include <SA/Logger/Exceptions/Exception_Equals.hpp>

/**
*	\file Exception_NotEquals.hpp
*
*	\brief <b>Not Equals</b> Exception base type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace SA
{
	/// Not Equals exception base type.
	class Exception_NotEquals : public Exception
	{
	public:
		/**
		*	\e Value Constructor.
		*
		*	\param[in] _exc		Equals exception to be reversed.
		*/
		Exception_NotEquals(Exception_Equals&& _exc) noexcept;
	};


	/// \cond Internal

	/// Define NotEquals Exception creation method.
	#define __SA_CREATE_EXCEPTION_NotEquals(_baseInfo, _lhs, _rhs) SA::Exception_NotEquals(\
		__SA_CREATE_EXCEPTION_Equals(_baseInfo, _lhs, _rhs)\
	)

	/// \endcond
}

/**
*	\example Exception_NotEqualsTests.cpp
*	Examples and Unitary Tests for Exception_NotEquals.
*/


/** \} */

#endif // GUARD
