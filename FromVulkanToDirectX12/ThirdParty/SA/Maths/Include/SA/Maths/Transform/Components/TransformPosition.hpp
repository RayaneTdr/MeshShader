// Copyright (c) 2023 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_POSITION_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_POSITION_GUARD

#include <SA/Maths/Space/Vector3.hpp>

#include <SA/Maths/Transform/Components/TransformComponent.hpp>
#include <SA/Maths/Transform/Components/TransformRotation.hpp>

/**
 * @file TransformPosition.hpp
 * 
 * @brief Transform position component definition.
 * 
 * @ingroup Maths_Transform
 * @{
 */


namespace SA
{
	/**
	 * @brief Transform position component.
	 * 
	 * @tparam T Type of the Vector3
	 */
	template <typename T>
	struct TrPosition
	{
		/// Handled position.
		Vec3<T> position;


	//{ Constructors
	
		/// Default constructor.
		TrPosition() = default;

		/**
		 * @brief Constructor from Vec3.
		 * 
		 * @param _pos input position.
		 */
		TrPosition(const Vec3<T>& _pos) noexcept :
			position{ _pos }
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
		operator TrPosition<TOut>() const noexcept
		{
			return TrPosition<TOut>(position);
		}

	//}

	protected:

	//{ Equals

		/**
		 * @brief IsZero component implementation.
		 * 
		 * @return position.IsZero()
		 */
		constexpr bool IsZero() const noexcept
		{
			return position.IsZero();
		}

		/**
		 * @brief IsIdentity component implementation.
		 * position must be at Vec3::Zero for identity transform.
		 * 
		 * @return position.IsZero().
		 */
		constexpr bool IsIdentity() const noexcept
		{
			// Position is Zero in identity transform.
			return position.IsZero();
		}

		/**
		 * @brief Equals component implementation.
		 * 
		 * @param _other 		other component to compare to.
		 * @param _epsilon 		epsilon max used for comparison.
		 * 
		 * @return Whether this and _other are equal.
		 */
		constexpr bool Equals(const TrPosition& _other,
			T _epsilon = std::numeric_limits<T>::epsilon()) const noexcept
		{
			return position.Equals(_other.position, _epsilon);
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
		static TrPosition LerpUnclamped(const TrPosition& _start, const TrPosition& _end, float _alpha) noexcept
		{
			return TrPosition{ Vec3<T>::LerpUnclamped(_start.position, _end.position, _alpha) };
		}

	//}


	//{ Operators

		/**
		 * @brief Transform multiplication implementation for position component.
		 * 
		 * Apply translation to transform in local-space.
		 * If lhs has rotation component, rotate (rhs) translation before application.
		 * 
		 * @tparam LhsT left-hand side transform type.
		 * @tparam RhsT right-hand side transform type.
		 * @param _lhs 	left-hand side transform.
		 * @param _rhs 	right-hand side transform.
		 * @return output position component from multiplication.
		 */
		template <typename LhsT, typename RhsT>
		static TrPosition Multiply(const LhsT& _lhs, const RhsT& _rhs) noexcept
		{
			if constexpr (TrTHasComponent(RhsT)<SA::TrPosition>())
			{
				// Position component found.

				if constexpr (TrTHasComponent(LhsT)<TrRotation>())
				{
					// Self rotation component found.
					// Apply translation with rotation:
					// position + rotation.Rotate(_other.position)

					return TrPosition{ _lhs.position + _lhs.rotation.Rotate(_rhs.position) };
				}
				else
				{
					// No rotation: apply translation.
					return TrPosition{ _lhs.position + _rhs.position };
				}
			}
			else
			{
				// Default: forward component (lhs always has this component).

				return _lhs;
			}
		}


		/**
		 * @brief Transform division implementation for position component.
		 * 
		 * Apply -translation to transform in local-space.
		 * If lhs has rotation component, rotate (rhs) translation before application.
		 * 
		 * @tparam LhsT left-hand side transform type.
		 * @tparam RhsT right-hand side transform type.
		 * @param _lhs 	left-hand side transform.
		 * @param _rhs 	right-hand side transform.
		 * @return output position component from division.
		 */
		template <typename LhsT, typename RhsT>
		static TrPosition Divide(const LhsT& _lhs, const RhsT& _rhs) noexcept
		{
			if constexpr (TrTHasComponent(RhsT)<SA::TrPosition>())
			{
				// Position component found.

				if constexpr (TrTHasComponent(LhsT)<TrRotation>())
				{
					// Self rotation component found.
					// Apply inverse translation with rotation:
					// position - rotation.Rotate(_other.position)

					return TrPosition{ _lhs.position - _lhs.rotation.Rotate(_rhs.position) };
				}
				else
				{
					// No rotation: apply inverse translation.
					return TrPosition{ _lhs.position - _rhs.position };
				}
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
			return "Pos: " + SA::ToString(position);
		}

	#endif

	};
}


/** @} */

#endif // GUARD
