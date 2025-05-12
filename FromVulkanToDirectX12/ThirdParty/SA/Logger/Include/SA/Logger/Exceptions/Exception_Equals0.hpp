// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_EQUALS_0_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_EQUALS_0_GUARD

#include <SA/Logger/Exceptions/Exception_Equals.hpp>

/**
*	\file Exception_Equals0.hpp
*
*	\brief <b>Equals 0</b> Exception type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace SA
{
	/// Equals 0 exception implementation.
	class Exception_Equals0 : public Exception_Equals
	{
	public:
		/**
		*	\e Template value move Constructor.
		*
		*	\tparam T				Operands type.
		* 
		*	\param[in] _info		Base create info.
		*	\param[in] _lhs			Left hand side operand to compare to T().
		*	\param[in] _predStr		Predicate as a string.
		*/
		template <typename T>
		Exception_Equals0(
			BaseInfo _info,
			const T& _lhs,
			std::wstring _predStr = L"pred"
		) noexcept :
			Exception_Equals(
				std::move(_info),
				_lhs,
				T(),
				std::move(_predStr))
		{
		}
	};

	/// \cond Internal

	/// Define Equals0 Exception creation method.
	#define __SA_CREATE_EXCEPTION_Equals0(_baseInfo, _lhs) SA::Exception_Equals0(\
		_baseInfo,\
		_lhs,\
		SA_WSTR(_lhs) L" == " + SA::ToWString(typeid(_lhs).name()) + L"()"\
	)

	/// \endcond
}

/**
*	\example Exception_Equals0Tests.cpp
*	Examples and Unitary Tests for Exception_Equals0.
*/


/** \} */

#endif // GUARD
