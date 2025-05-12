// Copyright (c) 2023 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_TRS_MATRIX_FUNCTOR_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_TRS_MATRIX_FUNCTOR_GUARD

#include <SA/Maths/Transform/Functors/TransformFunctor.hpp>

#include <SA/Maths/Matrix/Matrix4.hpp>

#include <SA/Maths/Transform/Components/TransformPosition.hpp>
#include <SA/Maths/Transform/Components/TransformRotation.hpp>
#include <SA/Maths/Transform/Components/TransformScale.hpp>
#include <SA/Maths/Transform/Components/TransformUScale.hpp>

/**
 * @file TransformTRSMatrixFunctor.hpp
 * 
 * @brief Transform TRS Matrix functor definition.
 * 
 * @ingroup Maths_Transform
 * @{
 */


namespace SA
{
	/**
	 * @brief Compute TRS Matrix from Transform.
	 * Order is applied from right to left: (T * (R * S)).
	 * Functor implementation.
	 */
	class TrTRSMatrixFunctor
	{
		template <typename T, template <typename> typename... TrArgs>
		Vec3<T> ComputeScale(const Tr<T, TrArgs...>& _tr)
		{
			// Get global scale from components.

			if constexpr (TrHasComponent<TrScale>() && TrHasComponent<TrUScale>())
				return _tr.scale * _tr.uScale;
			else if constexpr (TrHasComponent<TrScale>())
				return _tr.scale;
			else if constexpr (TrHasComponent<TrUScale>())
				return _tr.uScale;
			else
				return Vec3<T>::One;
		}

		template <typename T>
		void ApplyScaleToRotation(const Vec3<T>& _scale, Mat4<T>& _rot)
		{
			/*
			*	Optimization of R * S.
			*
			*	R {						S {
			*		{ a, b, c, 0 },			{ Sx, 0, 0, 0 },
			*		{ d, e, f, 0 },			{ 0, Sy, 0, 0 },
			*		{ g, h, i, 0 },			{ 0, 0, Sz, 0 },
			*		{ 0, 0, 0, 1 }			{ 0, 0, 0, 1}
			*	}						}
			*
			*
			*	Result {
			*		{ a Sx, b Sy, c Sz, 0 },
			*		{ d Sx, e Sy, f Sz, 0 },
			*		{ g Sx, h Sy, i Sz, 0 },
			*		{ 0, 0, 0, 1 }
			*	}
			*
			*/

			_rot.e00 *= _scale.x;
			_rot.e01 *= _scale.y;
			_rot.e02 *= _scale.z;

			_rot.e10 *= _scale.x;
			_rot.e11 *= _scale.y;
			_rot.e12 *= _scale.z;

			_rot.e20 *= _scale.x;
			_rot.e21 *= _scale.y;
			_rot.e22 *= _scale.z;
		}

		template <typename T>
		void ApplyTranslation(const Vec3<T>& _trsl, Mat4<T>& _rot)
		{
			/*
			*	Optimization of T * M with:
			*
			*	T {						M {
			*		{ 1, 0, 0, Tx },		{ a, b, c, 0 },
			*		{ 0, 1, 0, Ty },		{ d, e, f, 0 },
			*		{ 0, 0, 1, Tz },		{ g, h, i, 0 },
			*		{ 0, 0, 0, 1 }			{ 0, 0, 0, 1}
			*	}						}
			*
			*
			*	Result {
			*		{ a, b, c, Tx },
			*		{ d, e, f, Ty },
			*		{ g, h, i, Tz },
			*		{ 0, 0, 0, 1 }
			*	}
			*
			*/

			_rot.e03 = _trsl.x;
			_rot.e13 = _trsl.y;
			_rot.e23 = _trsl.z;
		}

	public:
		/**
		 * @brief Compute matrix from input transform.
		 * Functor implementation.
		 * 
		 * @tparam T 		Transform type.
		 * @tparam TrArgs 	Transform components.
		 * @param _tr 		Input transform.
		 * @return Mat4<T> 	Computed matrix from transform.
		 */
		template <typename T, template <typename> typename... TrArgs>
		Mat4<T> operator()(const Tr<T, TrArgs...>& _tr)
		{
			Mat4<T> out = Mat4<T>::Identity;

			const Vec3<T> scale = ComputeScale(_tr);
			constexpr bool bHasScale = TrHasComponent<TrScale>() || TrHasComponent<TrUScale>();

			if constexpr (TrHasComponent<TrRotation>())
			{
				out = Mat4<T>::MakeRotation(_tr.rotation);

				if constexpr (bHasScale)
					ApplyScaleToRotation(scale, out);
			}
			else if constexpr (bHasScale)
			{
				// Scale but no rotation: simple scale matrix.

				out =  Mat4<T>::MakeScale(scale);
			}

			if constexpr (TrHasComponent<TrPosition>())
				ApplyTranslation(_tr.position, out);

			return out;
		}
	};
}


/** @} */

#endif // GUARD
