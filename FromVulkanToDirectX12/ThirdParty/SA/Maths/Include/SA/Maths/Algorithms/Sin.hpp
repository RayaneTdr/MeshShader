// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_SIN_GUARD
#define SAPPHIRE_MATHS_SIN_GUARD

#include <SA/Maths/Angle/Radian.hpp>

/**
*	\file Sin.hpp
*
*	\brief \b Sinus method implementation.
*
*	\ingroup Maths_Algorithms
*	\{
*/


namespace SA
{
	namespace Maths
	{
		/**
		*	\brief \e Compute the \b sine of the input.
		*
		*	\param[in] _in	Input in radian to compute sine.
		*
		*	\return Sine of the input.
		*/
		template <typename T>
		constexpr T Sin(Rad<T> _in) noexcept
		{
			return std::sin(_in.Handle());
		}

		/**
		*	\brief \e Compute the \b arc-sine of the input.
		*
		*	\param[in] _in	Input to compute arc-sine.
		*
		*	\return Arc-sine in radian of the input.
		*/
		template <typename T>
		constexpr Rad<T> ASin(T _in) noexcept
		{
			return std::asin(_in);
		}
	}
}

/**
*	\example SinTests.cpp
*	Examples and Unitary Tests for Sin.
*/


/** \} */

#endif // GUARD
