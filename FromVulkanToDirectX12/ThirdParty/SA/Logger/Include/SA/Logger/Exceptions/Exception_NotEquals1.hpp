// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_NOT_EQUALS_1_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_NOT_EQUALS_1_GUARD

#include <SA/Logger/Exceptions/Exception_NotEquals.hpp>
#include <SA/Logger/Exceptions/Exception_Equals1.hpp>

/**
*	\file Exception_NotEquals1.hpp
*
*	\brief <b>Not Equals 1</b> Exception type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace SA
{
	/// Not Equals 1 exception implementation.
	class Exception_NotEquals1 : public Exception_NotEquals
	{
	public:
		/**
		*	\e Value move Constructor.
		*
		*	\param[in] _exc		Equals 1 exception to be reversed.
		*/
		Exception_NotEquals1(Exception_Equals1&& _exc) noexcept :
			Exception_NotEquals(std::move(_exc))
		{
		}
	};

	/// \cond Internal

	/// Define NotEquals1 Exception creation method.
	#define __SA_CREATE_EXCEPTION_NotEquals1(_baseInfo, _lhs) SA::Exception_NotEquals1(\
		__SA_CREATE_EXCEPTION_Equals1(_baseInfo, _lhs)\
	)

	/// \endcond
}

/**
*	\example Exception_NotEquals1Tests.cpp
*	Examples and Unitary Tests for Exception_NotEquals1.
*/


/** \} */

#endif // GUARD
