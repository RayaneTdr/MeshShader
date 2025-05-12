// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_EQUALS_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_EQUALS_GUARD

#include <SA/Logger/Exceptions/Exception.hpp>

/**
*	\file Exception_Equals.hpp
*
*	\brief \b Equals Exception base type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace SA
{
/// Equals exception base type.
	class Exception_Equals : public Exception
	{
	public:
		/**
		*	\e Template value Constructor.
		*
		*	Use default operator==
		*
		*	\tparam T				Operands type.
		* 
		*	\param[in] _info		Base create info.
		*	\param[in] _lhs			Left hand side operand.
		*	\param[in] _rhs			Left hand side operand.
		*	\param[in] _predStr		Predicate as a string.
		*/
		template <typename T>
		Exception_Equals(
			BaseInfo _info,
			const T& _lhs,
			const T& _rhs,
			std::wstring _predStr = L"pred"
		) noexcept :
			Exception(std::move(_info),
			_lhs == _rhs,
			std::move(_predStr) + L" => { " + ToWString(_lhs) + L" == " + ToWString(_rhs)+ L" }: Values must be equal.")
		{
		}


		/**
		*	\e Float value Constructor.
		* 
		*	Perform NearlyEquals (epsilon).
		*
		*	\param[in] _info		Base create info.
		*	\param[in] _lhs			Left hand side float operand.
		*	\param[in] _rhs			Left hand side float operand.
		*	\param[in] _predStr		Predicate as a string.
		*/
		Exception_Equals(
			BaseInfo _info,
			float _lhs,
			float _rhs,
			std::wstring _predStr = L"pred"
		) noexcept;


		/**
		*	\e Double value move Constructor.
		* 
		*	Perform NearlyEquals (epsilon).
		*
		*	\param[in] _info		Base create info.
		*	\param[in] _lhs			Left hand side double operand.
		*	\param[in] _rhs			Left hand side double operand.
		*	\param[in] _predStr		Predicate as a string.
		*/
		Exception_Equals(
			BaseInfo _info,
			double _lhs,
			double _rhs,
			std::wstring _predStr = L"pred"
		) noexcept;
	};


	/// \cond Internal

	/// Define Equals Exception creation method.
	#define __SA_CREATE_EXCEPTION_Equals(_baseInfo, _lhs, _rhs) SA::Exception_Equals(\
		_baseInfo,\
		_lhs,\
		_rhs,\
		L"\'" SA_WSTR(_lhs) L"\' == \'" SA_WSTR(_rhs) L"\'"\
	)

	/// \endcond
}

/**
*	\example Exception_EqualsTests.cpp
*	Examples and Unitary Tests for Exception_Equals.
*/


/** \} */

#endif // GUARD
