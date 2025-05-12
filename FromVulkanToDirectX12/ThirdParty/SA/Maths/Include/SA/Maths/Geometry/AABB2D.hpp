// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_AABB2D_GUARD
#define SAPPHIRE_MATHS_AABB2D_GUARD

#include <SA/Maths/Space/Vector2.hpp>

/**
 * @file AABB2D.hpp
 *
 * @brief <b>AABB 2D</b> type implementation.
 *
 * @ingroup Maths_Geometry
 * @{
 */


namespace SA
{
	template <typename T>
	struct AABB3D;

	/**
	*	@brief \e AABB \e 2D Sapphire's class.
	*
	*	@tparam T	Type of the AABB.
	*/
	template <typename T>
	struct AABB2D
	{
		/// Min box component.
		Vec2<T> min;

		/// Max box component.
		Vec2<T> max;


//{ Constructors

		/// Default constructor.
		AABB2D() = default;

		/**
		 * @brief \e Value constructor from min and max.
		 * 
		 * @param _min 	Min value
		 * @param _max 	Max value.
		 */
		AABB2D(const Vec2<T>& _min, const Vec2<T>& _max);

		/**
		 * @brief Merge 2 AABB box.
		 * 
		 * @param _first 	First AABB to merge.
		 * @param _second 	Second AABB to merge.
		 */
		AABB2D(const AABB2D& _first, const AABB2D& _second);

		/**
		 * @brief Constructor from AABB3D.
		 * 
		 * @param _aabb3D 3D AABB object.
		 */
		AABB2D(const AABB3D<T>& _aabb3D) noexcept;

//}


//{ Equals

		/**
		 * @brief Wether this AABB has valid values (ie min < max);
		 * 
		 * @return true if components are valid.
		 */
		bool IsValid() const noexcept;


		/**
		*	\brief \e Compare 2 AABB2D.
		*
		*	\param[in] _other		Other AABB to compare to.
		*	\param[in] _epsilon		Epsilon value for threshold comparison.
		*
		*	\return Whether this and _other are equal.
		*/
		constexpr bool Equals(const AABB2D& _other, T _epsilon = std::numeric_limits<T>::epsilon()) const noexcept;


		/**
		*	\brief \e Compare 2 AABB equality.
		*
		*	\param[in] _rhs		Other AABB to compare to.
		*
		*	\return Whether this and _rhs are equal.
		*/
		constexpr bool operator==(const AABB2D& _rhs) const noexcept;

		/**
		*	\brief \e Compare 2 AABB inequality.
		*
		*	\param[in] _rhs		Other AABB to compare to.
		*
		*	\return Whether this and _rhs are non-equal.
		*/
		constexpr bool operator!=(const AABB2D& _rhs) const noexcept;

//}


//{ Collisions

		/**
		 * @brief Perform collision test on <b>X axis</b> only.
		 * 
		 * @param _other 	Other AABB box.
		 * 
		 * @return true if this and other collide on X axis.
		 */
		bool IsCollidingX(const AABB2D& _other) const;

		/**
		 * @brief Perform collision test on <b>Y axis</b> only.
		 * 
		 * @param _other 	Other AABB box.
		 * 
		 * @return true if this and other collide on Y axis.
		 */
		bool IsCollidingY(const AABB2D& _other) const;

		/**
		 * @brief Perform collision test on every axis.
		 * 
		 * @param _other 	Other AABB box.
		 * 
		 * @return true if this and other collide on any axis.
		 */
		bool IsColliding(const AABB2D& _other) const;

//}


//{ Geometry

		/**
		 * @brief Compute \b width (X axis) from min and max.
		 * 
		 * @return AABB width.
		 */
		float Width() const;

		/**
		 * @brief Compute \b height (Y axis) from min and max.
		 * 
		 * @return AABB height. 
		 */
		float Height() const;

		/**
		 * @brief Compute \b center from min and max.
		 * 
		 * @return AABB center.
		 */
		Vec2<T> Center() const;

		/**
		 * @brief Compute \b area from min and max.
		 * 
		 * @return AABB area 
		 */
		float Area() const;

//}

		/**
		 * @brief Merge 2 AABB2D box to create a big AABB2D which wrap both boxes.
		 * 
		 * @param _first 	First AABB object to merge.
		 * @param _second 	Second AABB object to merge.
		 * 
		 * @return AABB2D 	Big AABB box from merge.
		 */
		static AABB2D Merge(const AABB2D& _first, const AABB2D& _second);

	};


#if SA_LOGGER_IMPL

	/**
	 * @brief ToString AABB2D implementation
	 *
	 * Convert AABB2D as a string.
	 *
	 * @tparam T		Input AABB2D type.
	 *
	 * @param[in] _aabb	Input AABB2D.
	 *
	 * @return input AABB2D as a string.
	 */
	template <typename T>
	std::string ToString(const AABB2D<T>& _aabb);

#endif


//{ Aliases

	/// Alias for float AABB2D.
	using AABB2Df = AABB2D<float>;

	/// Alias for double AABB2D.
	using AABB2Dd = AABB2D<double>;

//}

}


/** @} */

#include <SA/Maths/Geometry/AABB2D.inl>

#endif // GUARD
