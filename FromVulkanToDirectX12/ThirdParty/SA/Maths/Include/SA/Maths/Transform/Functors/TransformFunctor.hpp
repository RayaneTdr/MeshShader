// Copyright (c) 2023 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_FUNCTOR_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_FUNCTOR_GUARD

/**
 * @file TransformFunctor.hpp
 * 
 * @brief Transform Functor base helper definition.
 * 
 * @ingroup Maths_Transform
 * @{
 */

namespace SA
{
	// Forward declaration for children.
	template <typename T, template <typename> typename... Args>
	struct Tr;

	/**
	 * @brief Define implementation for transform specific calculation.
	 * Must implement templated operator().
	 */
	class TrFunctor;
}


/** @} */

#endif // GUARD
