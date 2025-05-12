// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_CONSTANTS_GUARD
#define SAPPHIRE_MATHS_CONSTANTS_GUARD

/**
*	\file Constants.hpp
* 
*	\brief Maths \b Constants definition file.
* 
*	\ingroup Maths_Angle
*	\{
*/


namespace SA
{
	namespace Maths
	{
		/// PI constant.
		template <typename T = double>
		static constexpr T Pi = T{ 3.1415926535897932384 };

		/// 2 * PI constant.
		template <typename T = double>
		static constexpr T PiX2 = T{ 2.0 } *Pi<T>;

		/// PI / 2 constant.
		template <typename T = double>
		static constexpr T PiOv2 = Pi<T> / T{ 2.0 };

		/// PI / 3 constant.
		template <typename T = double>
		static constexpr T PiOv3 = Pi<T> / T{ 3.0 };

		/// PI / 4 constant.
		template <typename T>
		static constexpr T PiOv4 = Pi<T> / T{ 4.0 };

		/// PI / 6 constant.
		template <typename T = double>
		static constexpr T PiOv6 = Pi<T> / T{ 6.0 };

		/// Conversion constant to convert degree to radian.
		template <typename T = double>
		static constexpr T DegToRad = Pi<T> / T{ 180.0 };

		/// Conversion constant to convert radian to degree.
		template <typename T = double>
		static constexpr T RadToDeg = T{ 180.0 } / Pi<T>;
	}
}


/** \} */

#endif // GUARD
