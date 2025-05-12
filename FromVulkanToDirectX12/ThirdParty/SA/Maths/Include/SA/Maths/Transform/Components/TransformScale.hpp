// Copyright (c) 2023 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_SCALE_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_SCALE_GUARD

#include <SA/Maths/Space/Vector3.hpp>

#include <SA/Maths/Transform/Components/TransformComponent.hpp>
#include <SA/Maths/Transform/Components/TransformUScale.hpp>

/**
 * @file TransformScale.hpp
 * 
 * @brief Transform scale component definition.
 * 
 * @ingroup Maths_Transform
 * @{
 */


namespace SA
{
	/**
	 * @brief Transform scale component.
	 * 
	 * @tparam T Type of the Vector3
	 */
	template <typename T>
	struct TrScale
	{
		/// Handled scale.
		Vec3<T> scale = Vec3<T>::One;


	//{ Constructors
	
		/// Default constructor.
		TrScale() = default;

		/**
		 * @brief Constructor from Vec3.
		 * 
		 * @param _scale input scale.
		 */
		TrScale(const Vec3<T>& _scale) noexcept :
			scale{ _scale }
		{
		}
	
	//}


	//{ Cast

		/**
		 * @brief Cast operator.
		 * 
		 * @tparam TOut output cast type.
		 * @return TrPosition<TOut> Casted component.
		 */
		template <typename TOut>
		operator TrScale<TOut>() const noexcept
		{
			return TrScale<TOut>(scale);
		}

	//}


	protected:

	//{ Equals

		/**
		 * @brief IsZero component implementation.
		 * 
		 * @return scale.IsZero()
		 */
		constexpr bool IsZero() const noexcept
		{
			return scale.IsZero();
		}

		/**
		 * @brief IsIdentity component implementation.
		 * scale must be at Vec3::One for identity transform.
		 * 
		 * @return scale == Vec3::One
		 */
		constexpr bool IsIdentity() const noexcept
		{
			return scale == Vec3<T>::One;
		}

		/**
		 * @brief Equals component implementation.
		 * 
		 * @param _other 		other component to compare to.
		 * @param _epsilon 		epsilon max used for comparison.
		 * 
		 * @return Whether this and _other are equal.
		 */
		constexpr bool Equals(const TrScale& _other,
			T _epsilon = std::numeric_limits<T>::epsilon()) const noexcept
		{
			return scale.Equals(_other.scale, _epsilon);
		}

	//}


	//{ Lerp

		/**
		 * @brief LerpUnclamped component implementation.
		 * 
		 * @param _start 	Starting point of the lerp.
		 * @param _end 		Ending point of the lerp.
		 * @param _alpha 	Alpha of the lerp.
		 * @return Interpolated position between start and end. 
		 */
		static TrScale LerpUnclamped(const TrScale& _start, const TrScale& _end, float _alpha) noexcept
		{
			return TrScale{ Vec3<T>::LerpUnclamped(_start.scale, _end.scale, _alpha) };
		}

	//}


	//{ Operators

		/**
		 * @brief Transform multiplication implementation for scale component.
		 * 
		 * Apply scale from lhs and rhs.
		 * If no TrScale component are found in rhs bur UScale component, uses it instead.
		 * 
		 * @tparam RhsT right-hand side transform type.
		 * @param _lhs 	left-hand side transform's scale component.
		 * @param _rhs 	right-hand side transform.
		 * @return output scale component from multiplication.
		 */
		template <typename RhsT>
		static TrScale Multiply(const TrScale& _lhs, const RhsT& _rhs) noexcept
		{
			if constexpr (TrTHasComponent(RhsT)<SA::TrScale>())
			{
				// Scale component found.
				return TrScale{ _lhs.scale * _rhs.scale };
			}
			else if constexpr (TrTHasComponent(RhsT)<SA::TrUScale>())
			{
				// UScale component found instead.
				return TrScale{ _lhs.scale * _rhs.uScale };
			}
			else
			{
				// Default: forward component (lhs always has this component).

				return _lhs;
			}
		}

		
		/**
		 * @brief Transform division implementation for scale component.
		 * 
		 * Apply scale from lhs and rhs.
		 * If no TrScale component are found in rhs bur UScale component, uses it instead.
		 * 
		 * @tparam RhsT right-hand side transform type.
		 * @param _lhs 	left-hand side transform's scale component.
		 * @param _rhs 	right-hand side transform.
		 * @return output scale component from division.
		 */
		template <typename RhsT>
		static TrScale Divide(const TrScale& _lhs, const RhsT& _rhs) noexcept
		{
			if constexpr (TrTHasComponent(RhsT)<SA::TrScale>())
			{
				// Scale component found.
				return TrScale{ _lhs.scale / _rhs.scale };
			}
			else if constexpr (TrTHasComponent(RhsT)<SA::TrUScale>())
			{
				// UScale component found instead.
				return TrScale{ _lhs.scale / _rhs.uScale };
			}
			else
			{
				// Default: forward component (lhs always has this component).

				return _lhs;
			}
		}

	//}

	#if SA_LOGGER_IMPL

		/**
		 * @brief ToString logger implementation.
		 * 
		 * @return std::string position component as a string.
		 */
		std::string ToString() const
		{
			return "Scale: " + SA::ToString(scale);
		}

	#endif

	};
}


/** @} */

#endif // GUARD
