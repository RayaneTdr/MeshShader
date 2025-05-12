// Copyright (c) 2023 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_ROTATION_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_ROTATION_GUARD

#include <SA/Maths/Space/Quaternion.hpp>

#include <SA/Maths/Transform/Components/TransformComponent.hpp>


/**
 * @file TransformRotation.hpp
 * 
 * @brief Transform rotation component definition.
 * 
 * @ingroup Maths_Transform
 * @{
 */


namespace SA
{
	/**
	 * @brief Transform rotation component.
	 * 
	 * @tparam T Type of the Quaternion
	 */
	template <typename T>
	struct TrRotation
	{
		/// Handled rotation.
		Quat<T> rotation = Quat<T>::Identity;


	//{ Constructors

		/// Default constructor.
		TrRotation() = default;

		/**
		 * @brief Constructor from Quat.
		 * 
		 * @param _rot input rotation.
		 */
		TrRotation(const Quat<T>& _rot) noexcept :
			rotation{ _rot }
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
		operator TrRotation<TOut>() const noexcept
		{
			return TrRotation<TOut>(rotation);
		}

	//}

	protected:

	//{ Equals

		/**
		 * @brief IsZero component implementation.
		 * 
		 * @return rotation.IsZero()
		 */
		constexpr bool IsZero() const noexcept
		{
			return rotation.IsZero();
		}

		/**
		 * @brief IsIdentity component implementation.
		 * rotation must be at Quat::Identity for identity transform.
		 * 
		 * @return rotation.IsZero().
		 */
		constexpr bool IsIdentity() const noexcept
		{
			return rotation.IsIdentity();
		}

		/**
		 * @brief Equals component implementation.
		 * 
		 * @param _other 		other component to compare to.
		 * @param _epsilon 		epsilon max used for comparison.
		 * 
		 * @return Whether this and _other are equal.
		 */
		constexpr bool Equals(const TrRotation& _other,
			T _epsilon = std::numeric_limits<T>::epsilon()) const noexcept
		{
			return rotation.Equals(_other.rotation, _epsilon);
		}

	//}


	//{ Lerp

		/**
		 * @brief LerpUnclamped component implementation.
		 * Use SLerp implementation.
		 * 
		 * @param _start 	Starting point of the lerp.
		 * @param _end 		Ending point of the lerp.
		 * @param _alpha 	Alpha of the lerp.
		 * @return Interpolated rotation between start and end. 
		 */
		static TrRotation LerpUnclamped(const TrRotation& _start, const TrRotation& _end, float _alpha) noexcept
		{
			return TrRotation{ Quat<T>::SLerpUnclamped(_start.rotation, _end.rotation, _alpha) };
		}

	//}


	//{ Operators

		/**
		 * @brief Transform multiplication implementation for rotation component.
		 * 
		 * @tparam RhsT right-hand side transform type.
		 * @param _lhs 	left-hand side transform's rotation component.
		 * @param _rhs 	right-hand side transform.
		 * @return output rotation component from multiplication.
		 */
		template <typename RhsT>
		static TrRotation Multiply(const TrRotation& _lhs, const RhsT& _rhs) noexcept
		{
			if constexpr (TrTHasComponent(RhsT)<SA::TrRotation>())
			{
				// Rotation component found.

				return TrRotation{ _lhs.rotation * _rhs.rotation };
			}
			else
			{
				// Default: forward component (lhs always has this component).

				return _lhs;
			}
		}

		/**
		 * @brief Transform division implementation for rotation component.
		 * 
		 * @tparam RhsT right-hand side transform type.
		 * @param _lhs 	left-hand side transform's rotation component.
		 * @param _rhs 	right-hand side transform.
		 * @return output rotation component from division.
		 */
		template <typename RhsT>
		static TrRotation Divide(const TrRotation& _lhs, const RhsT& _rhs) noexcept
		{
			if constexpr (TrTHasComponent(RhsT)<SA::TrRotation>())
			{
				// Rotation component found.

				return TrRotation{ _lhs.rotation / _rhs.rotation };
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
		 * @return std::string rotation component as a string.
		 */
		std::string ToString() const
		{
			return "Rot: " + SA::ToString(rotation);
		}

	#endif

	};
}


/** @} */

#endif // GUARD
