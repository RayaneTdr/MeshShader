// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_AABB3D_GUARD
#define SAPPHIRE_MATHS_AABB3D_GUARD

#include <SA/Maths/Space/Vector3.hpp>

/**
 * @file AABB3D.hpp
 *
 * @brief <b>AABB 3D</b> type implementation.
 *
 * @ingroup Maths_Geometry
 * @{
 */

namespace SA
{
	template <typename T>
	struct AABB2D;

	/**
	*	@brief \e AABB \e 3D Sapphire's class.
	*
	*	@tparam T	Type of the AABB.
	*/
	template <typename T>
	struct AABB3D
	{
		/// Min box component.
		Vec3<T> min;

		/// Max box component.
		Vec3<T> max;


//{ Constructors

		/// Default constructor.
		AABB3D() = default;

		/**
		 * @brief \e Value constructor from min and max.
		 * 
		 * @param _min 	Min value
		 * @param _max 	Max value.
		 */
		AABB3D(const Vec3<T>& _min, const Vec3<T>& _max);

		/**
		 * @brief Merge 2 AABB box.
		 * 
		 * @param _first 	First AABB to merge.
		 * @param _second 	Second AABB to merge.
		 */
		AABB3D(const AABB3D& _first, const AABB3D& _second);

		/**
		 * @brief Constructor from AABB2D.
		 * 
		 * @param _aabb2D 2D AABB object.
		 */
		AABB3D(const AABB2D<T>& _aabb2D) noexcept;

//}


//{ Equals

		/**
		 * @brief Wether this AABB has valid values (ie min < max);
		 * 
		 * @return true if components are valid.
		 */
		bool IsValid() const noexcept;


		/**
		*	\brief \e Compare 2 AABB3D.
		*
		*	\param[in] _other		Other AABB to compare to.
		*	\param[in] _epsilon		Epsilon value for threshold comparison.
		*
		*	\return Whether this and _other are equal.
		*/
		constexpr bool Equals(const AABB3D& _other, T _epsilon = std::numeric_limits<T>::epsilon()) const noexcept;


		/**
		*	\brief \e Compare 2 AABB equality.
		*
		*	\param[in] _rhs		Other AABB to compare to.
		*
		*	\return Whether this and _rhs are equal.
		*/
		constexpr bool operator==(const AABB3D& _rhs) const noexcept;

		/**
		*	\brief \e Compare 2 AABB inequality.
		*
		*	\param[in] _rhs		Other AABB to compare to.
		*
		*	\return Whether this and _rhs are non-equal.
		*/
		constexpr bool operator!=(const AABB3D& _rhs) const noexcept;

//}


//{ Collisions

		/**
		 * @brief Perform collision test on <b>X axis</b> only.
		 * 
		 * @param _other 	Other AABB box.
		 * 
		 * @return true if this and other collide on X axis.
		 */
		bool IsCollidingX(const AABB3D& _other) const;

		/**
		 * @brief Perform collision test on <b>Y axis</b> only.
		 * 
		 * @param _other 	Other AABB box.
		 * 
		 * @return true if this and other collide on Y axis.
		 */
		bool IsCollidingY(const AABB3D& _other) const;

		/**
		 * @brief Perform collision test on <b>Z axis</b> only.
		 * 
		 * @param _other 	Other AABB box.
		 * 
		 * @return true if this and other collide on Z axis.
		 */
		bool IsCollidingZ(const AABB3D& _other) const;

		/**
		 * @brief Perform collision test on every axis.
		 * 
		 * @param _other 	Other AABB box.
		 * 
		 * @return true if this and other collide on any axis.
		 */
		bool IsColliding(const AABB3D& _other) const;

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
		 * @brief Compute \b depth (Z axis) from min and max.
		 * 
		 * @return AABB height. 
		 */
		float Depth() const;

		/**
		 * @brief Compute \b center from min and max.
		 * 
		 * @return AABB center.
		 */
		Vec3<T> Center() const;

		/**
		 * @brief Compute \b area from min and max.
		 * 
		 * @return AABB area 
		 */
		float Area() const;

//}


		/**
		 * @brief Merge 2 AABB3D box to create a big AABB3D which wrap both boxes.
		 * 
		 * @param _first 	First AABB object to merge.
		 * @param _second 	Second AABB object to merge.
		 * 
		 * @return AABB3D 	Big AABB box from merge.
		 */
		static AABB3D Merge(const AABB3D& _first, const AABB3D& _second);

	};


#if SA_LOGGER_IMPL

	/**
	 * @brief ToString AABB3D implementation
	 *
	 * Convert AABB3D as a string.
	 *
	 * @tparam T		Input AABB3D type.
	 *
	 * @param[in] _aabb	Input AABB3D.
	 *
	 * @return input AABB3D as a string.
	 */
	template <typename T>
	std::string ToString(const AABB3D<T>& _aabb);

#endif


//{ Aliases

	/// Alias for float AABB3D.
	using AABB3Df = AABB3D<float>;

	/// Alias for double AABB3D.
	using AABB3Dd = AABB3D<double>;

//}

}


/** @} */

#include <SA/Maths/Geometry/AABB3D.inl>

#endif // GUARD
