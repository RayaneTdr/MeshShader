// Copyright (c) 2023 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_USCALE_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_USCALE_GUARD

#include <SA/Maths/Transform/Components/TransformComponent.hpp>

/**
 * @file TransformUScale.hpp
 * 
 * @brief Transform uniform scale component definition.
 * 
 * @ingroup Maths_Transform
 * @{
 */


namespace SA
{
	/**
	 * @brief Transform uniform scale component.
	 * 
	 * @tparam T Type of the scale.
	 */
	template <typename T>
	struct TrUScale
	{
		/// Handled uniform scale.
		T uScale = T(1);


	//{ Constructors

		/// Default constructor.
		TrUScale() = default;

		/**
		 * @brief Constructor from T.
		 * 
		 * @param _uscale input uniform scale.
		 */
		TrUScale(T _uscale) noexcept :
			uScale{ _uscale }
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
		operator TrUScale<TOut>() const noexcept
		{
			return TrUScale<TOut>(uScale);
		}

	//}

	protected:

	//{ Equals

		/**
		 * @brief IsZero component implementation.
		 * 
		 * @return uScale == T(0)
		 */
		constexpr bool IsZero() const noexcept
		{
			return SA::Maths::Equals0(uScale);
		}

		/**
		 * @brief IsIdentity component implementation.
		 * uniform scale must == 1 for identity transform.
		 * 
		 * @return uScale == T(1)
		 */
		constexpr bool IsIdentity() const noexcept
		{
			return SA::Maths::Equals1(uScale);
		}

		/**
		 * @brief Equals component implementation.
		 * 
		 * @param _other 		other component to compare to.
		 * @param _epsilon 		epsilon max used for comparison.
		 * 
		 * @return Whether this and _other are equal.
		 */
		constexpr bool Equals(const TrUScale& _other,
			T _epsilon = std::numeric_limits<T>::epsilon()) const noexcept
		{
			return Maths::Equals(uScale, _other.uScale, _epsilon);
		}

	//}


	//{ Lerp

		/**
		 * @brief LerpUnclamped component implementation.
		 * 
		 * @param _start 	Starting point of the lerp.
		 * @param _end 		Ending point of the lerp.
		 * @param _alpha 	Alpha of the lerp.
		 * @return Interpolated uniform scale between start and end. 
		 */
		static TrUScale LerpUnclamped(const TrUScale& _start, const TrUScale& _end, float _alpha) noexcept
		{
			return TrUScale{ Maths::LerpUnclamped(_start.uScale, _end.uScale, _alpha) };
		}

	//}


	//{ Operators

		/**
		 * @brief Transform multiplication implementation for uniform scale component.
		 * 
		 * @tparam RhsT right-hand side transform type.
		 * @param _lhs 	left-hand side transform's UScale component.
		 * @param _rhs 	right-hand side transform.
		 * @return output uscale component from multiplication.
		 */
		template <typename RhsT>
		static TrUScale Multiply(const TrUScale& _lhs, const RhsT& _rhs) noexcept
		{
			if constexpr (TrTHasComponent(RhsT)<SA::TrUScale>())
			{
				// UScale component found.

				return TrUScale{ _lhs.uScale * _rhs.uScale };
			}
			else
			{
				// Default: forward component (lhs always has this component).

				return _lhs;
			}
		}

		/**
		 * @brief Transform division implementation for uniform scale component.
		 * 
		 * @tparam RhsT right-hand side transform type.
		 * @param _lhs 	left-hand side transform's UScale component.
		 * @param _rhs 	right-hand side transform.
		 * @return output uscale component from division.
		 */
		template <typename RhsT>
		static TrUScale Divide(const TrUScale& _lhs, const RhsT& _rhs) noexcept
		{
			if constexpr (TrTHasComponent(RhsT)<SA::TrUScale>())
			{
				// UScale component found.

				return TrUScale{ _lhs.uScale / _rhs.uScale };
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
			return "UScale: " + SA::ToString(uScale);
		}

	#endif

	};
}


/** @} */

#endif // GUARD
