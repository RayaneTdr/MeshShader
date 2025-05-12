// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_MATRIX_MAJOR_GUARD
#define SAPPHIRE_MATHS_MATRIX_MAJOR_GUARD

#include <cstdint>

/**
*	\file MatrixMajor.hpp
* 
*	\brief <b>Matrix Major</b> enum definitions
* 
*	\ingroup Maths_Matrix
*	\{
*/


namespace SA
{
	/// Matrix major enum.
	enum class MatrixMajor : uint8_t
	{
		/// Row major standard.
		Row = 1u,

		/// Column major standard.
		Column = 2u,


		/// Default standard.
		Default = Row
	};


	/// Shortcut alias.
	using MatMaj = MatrixMajor;
}


/** \} */

#endif // GUARD
