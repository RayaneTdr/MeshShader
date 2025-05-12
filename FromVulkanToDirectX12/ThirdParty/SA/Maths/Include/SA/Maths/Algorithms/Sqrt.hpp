// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_SQRT_GUARD
#define SAPPHIRE_MATHS_SQRT_GUARD

#include <cmath>

#include <SA/Maths/Debug.hpp>

/**
*	\file Sqrt.hpp
* 
*	\brief <b>Square Root</b> algorithm implementation.
* 
*	\ingroup Maths_Algorithms
*	\{
*/


namespace SA
{
	namespace Maths
	{
		/**
		*	\brief \e Compute the <b> square root </b> of the input as float.
		*
		*	\tparam T		Input Type.
		* 
		*	\param[in] _in	Input to compute square root.
		*
		*	\return Square Root of the input.
		*/
		template <typename T>
		T Sqrt(T _in)
		{
			SA_ASSERT((Default, _in >= T(0)), SA.Maths, (L"Compute square root of negative number: [%1]", _in));

			return std::sqrt(_in);
		}
	}
}

/**
*	\example SqrtTests.cpp
*	Examples and Unitary Tests for Sqrt.
*/


/** \} */

#endif // GUARD
