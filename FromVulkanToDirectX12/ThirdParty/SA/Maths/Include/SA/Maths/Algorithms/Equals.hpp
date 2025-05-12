// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_EQUALS_GUARD
#define SAPPHIRE_MATHS_EQUALS_GUARD

#include <limits>

/**
*	\file Equals.hpp
*
*	\brief \b Equals method implementation.
*
*	\ingroup Maths_Algorithms
*	\{
*/


namespace SA
{
	namespace Maths
	{
		/**
		*	\brief Compare two T objects.
		*
		*	\tparam T			Type of operands.
		*	\tparam EpsT		Type of epsilon.
		*
		*	\param[in] _lhs		Left hand side operand to compare.
		*	\param[in] _rhs		Right hand side operand to compare.
		*	\param[in] _epsilon	Epsilon value for threshold compare.
		*
		*	\return	True on equality, otherwise false.
		*/
		template <typename T, typename EpsT = T>
		constexpr bool Equals(const T& _lhs, const T& _rhs, EpsT _epsilon = std::numeric_limits<EpsT>::epsilon())
		{
			// Don't use std::abs for unsigned compatibility.

			return (_lhs < _rhs ? _rhs - _lhs : _lhs - _rhs) <= _epsilon;
		}


		/**
		*	\brief \e Compare one T to T(0).
		*
		*	\tparam T		Type of input.
		*	\tparam EpsT	Type of epsilon.
		*
		*	\param[in] _in			Operand to compare to 0.
		*	\param[in] _epsilon	Allowed threshold to accept equality.
		*
		*	\return Whether _in is equal to 0.
		*/
		template <typename T, typename EpsT = T>
		constexpr bool Equals0(T _in, EpsT _epsilon = std::numeric_limits<EpsT>::epsilon()) noexcept
		{
			return Equals(_in, T{ 0 }, _epsilon);
		}


		/**
		*	\brief \e Compare one T to T(1).
		*
		*	\tparam T		Type of input.
		*	\tparam EpsT	Type of epsilon.
		* 
		*	\param[in] _in			Operand to compare to 1.
		*	\param[in] _epsilon	Allowed threshold to accept equality.
		*
		*	\return Whether _in is equal to 1.
		*/
		template <typename T, typename EpsT = T>
		constexpr bool Equals1(T _in, EpsT _epsilon = std::numeric_limits<EpsT>::epsilon()) noexcept
		{
			return Equals(_in, T{ 1 }, _epsilon);
		}
	}
}

/**
*	\example EqualsTests.cpp
*	Examples and Unitary Tests for Equals.
*/


/** \} */

#endif // GUARD
