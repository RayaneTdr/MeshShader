// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_NOT_EQUALS_0_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_NOT_EQUALS_0_GUARD

#include <SA/Logger/Exceptions/Exception_NotEquals.hpp>
#include <SA/Logger/Exceptions/Exception_Equals0.hpp>

/**
*	\file Exception_NotEquals0.hpp
*
*	\brief <b>Not Equals 0</b> Exception type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace SA
{
	/// Not Equals 0 exception implementation.
	class Exception_NotEquals0 : public Exception_NotEquals
	{
	public:
		/**
		*	\e Value move Constructor.
		*
		*	\param[in] _exc		Equals 0 exception to be reversed.
		*/
		Exception_NotEquals0(Exception_Equals0&& _exc) noexcept :
			Exception_NotEquals(std::move(_exc))
		{
		}
	};

	/// \cond Internal

	/// Define NotEquals0 Exception creation method.
	#define __SA_CREATE_EXCEPTION_NotEquals0(_baseInfo, _lhs) SA::Exception_NotEquals0(\
		__SA_CREATE_EXCEPTION_Equals0(_baseInfo, _lhs)\
	)

	/// \endcond
}

/**
*	\example Exception_NotEquals0Tests.cpp
*	Examples and Unitary Tests for Exception_NotEquals0.
*/


/** \} */

#endif // GUARD
