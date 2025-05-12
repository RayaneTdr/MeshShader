// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TAN_GUARD
#define SAPPHIRE_MATHS_TAN_GUARD

#include <SA/Maths/Angle/Radian.hpp>

/**
*	\file Tan.hpp
*
*	\brief \b Tangent method implementation.
*
*	\ingroup Maths_Algorithms
*	\{
*/


namespace SA
{
	namespace Maths
	{
		/**
		*	\brief \e Compute the \b tangent of the input.
		*
		*	\param[in] _in	Input in radian to compute tangent.
		*
		*	\return Tangent of the input.
		*/
		template <typename T>
		constexpr T Tan(Rad<T> _in) noexcept
		{
			return std::tan(_in.Handle());
		}

		/**
		*	\brief \e Compute the \b arc-tangent of the input.
		*
		*	\param[in] _in	Input to compute arc-tangent.
		*
		*	\return Arc-tangent in radian of the input.
		*/
		template <typename T>
		constexpr Rad<T> ATan(T _in) noexcept
		{
			return std::atan(_in);
		}


		/**
		*	\brief \e Compute the \b arc-tangent 2 of _y / _x.
		*
		*	\param[in] _y	Y term to compute arc-tangent 2.
		*	\param[in] _x	X term to compute arc-tangent 2.
		*
		*	\return Arc-tangent 2 in radian of the inputs.
		*/
		template <typename T>
		constexpr Rad<T> ATan2(T _y, T _x) noexcept
		{
			return std::atan2(_y, _x);
		}
	}
}

/**
*	\example TanTests.cpp
*	Examples and Unitary Tests for Tan.
*/


/** \} */

#endif // GUARD
