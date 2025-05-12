// Copyright (c) 2023 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_ENGINE_TRANSFORM_ROTATE_AXIS_FUNCTOR_GUARD
#define SAPPHIRE_ENGINE_TRANSFORM_ROTATE_AXIS_FUNCTOR_GUARD

#include <SA/Maths/Transform/Functors/TransformFunctor.hpp>

#include <SA/Maths/Space/Vector3.hpp>

#include <SA/Maths/Transform/Components/TransformRotation.hpp>

/**
 * @file TransformRotateAxisFunctor.hpp
 * 
 * @brief Transform rotate axis functor definition.
 * 
 * @ingroup Maths_Transform
 * @{
 */


namespace SA
{
	/**
	 * @brief Compute rotated axis from transform.
	 * Functor implementation.
	 */
	class TrRotateAxisFunctor
	{
	public:
		/**
		 * @brief Compute rotated axis from transform and input axis.
		 * 
		 * @tparam T 		Transform type.
		 * @tparam TrArgs 	Tansform components.
		 * @param _tr 		Input transform used for rotation (if any).
		 * @param _axis 	Input axis to rotate.
		 * @return Vec3<T> 	Rotated axis from transform.
		 */
		template <typename T, template <typename> typename... TrArgs>
		Vec3<T> operator()(const Tr<T, TrArgs...>& _tr, const Vec3<T>& _axis)
		{
			if constexpr (TrHasComponent<TrRotation>())
				return _tr.rotation * _axis;
			else
				return _axis;
		}
	};
}


/** @} */

#endif // GUARD
