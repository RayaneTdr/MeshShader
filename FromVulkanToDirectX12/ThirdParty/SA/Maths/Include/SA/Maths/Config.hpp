// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_CONFIG_GUARD
#define SAPPHIRE_MATHS_CONFIG_GUARD

/**
*	\file Maths/Config.hpp
*
*	\brief Maths specific config file.
*
*	\ingroup Maths
*	\{
*/


/**
*	\defgroup Maths Maths
*	Sapphire Suite's Maths Module.
*/

/**
*	\defgroup Maths_Algorithms Algorithms
*	Sapphire Suite's Maths Algorithms.
*	\ingroup Maths
*/

/**
*	\defgroup Maths_Space Space
*	Sapphire Suite's Maths Space.
*	\ingroup Maths
*/

/**
*	\defgroup Maths_Matrix Matrix
*	Sapphire Suite's Maths Matrix.
*	\ingroup Maths
*/

/**
*	\defgroup Maths_Angle Angle
*	Sapphire Suite's Maths Angle.
*	\ingroup Maths
*/

/**
*	\defgroup Maths_Geometry Geometry
*	Sapphire Suite's Maths Geometry.
*	\ingroup Maths
*/

/**
*	\defgroup Maths_Transform Transform
*	Sapphire Suite's Maths Transform.
*	\ingroup Maths
*/


/**
*	Whether to use SIMD implementation for Quaternion.
*	Default is disabled. Benchmark has shown that compiler already optimize calcultation at its best.
*/
#define SA_MATHS_QUATERNION_SIMD (0 || SA_CI) && SA_MATHS_INTRINSICS_OPT


/**
*	Whether to use SIMD implementation for Matrix3.
*	Default is disabled. Benchmark has shown that compiler already optimize calcultation at its best.
*/
#define SA_MATHS_MATRIX3_SIMD (0 || SA_CI) && SA_MATHS_INTRINSICS_OPT


/**
*	Whether to use SIMD implementation for Matrix4.
*	Default is disabled. Benchmark has shown that compiler already optimize calcultation at its best.
*/
#define SA_MATHS_MATRIX4_SIMD (0 || SA_CI) && SA_MATHS_INTRINSICS_OPT

/** \} */

#endif // GUARD
