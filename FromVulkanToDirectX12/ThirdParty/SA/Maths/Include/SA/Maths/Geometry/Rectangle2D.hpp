// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_RECT2D_GUARD
#define SAPPHIRE_MATHS_RECT2D_GUARD

#include <SA/Maths/Space/Vector2.hpp>

#include <SA/Support/Pragma.hpp>

/**
*	\file Rectangle2D.hpp
*
*	\brief <b>Rectangle 2D</b> type implementation.
*
*	\ingroup Maths_Geometry
*	\{
*/


namespace SA
{
	/**
	*	\brief \e Rectangle2D Sapphire's class.
	*
	*	\tparam T	Type of the rectangle..
	*/
	template <typename T>
	struct Rect2D
	{
		SA_PRAGMA_SDWARN_MSVC(4201)

		union
		{
			/// offset.
			Vec2<T> offset = Vec2<T>();

			struct
			{
				/// alias for offset.x
				T x;

				/// alias for offset.y
				T y;
			};
		};

		union
		{
			/// extents.
			Vec2<T> extent = Vec2<T>();

			struct
			{
				/// alias for extent.x
				T width;

				/// alias for extent.y
				T height;
			};
		};

		SA_PRAGMA_EDWARN_MSVC()

		/// Default constructor.
		Rect2D() = default;

		/**
		 * @brief Constructor from offset and extent.
		 * 
		 * @param _offset Offset
		 * @param _extent Extent
		 */
		Rect2D(const Vec2<T>& _offset, const Vec2<T>& _extent) noexcept :
			offset{ _offset },
			extent{ _extent }
		{
		}

		/**
		 * @brief Constructor from (x, y) (offset) and (width, height) (extent).
		 * 
		 * @param _x 		X offset value.
		 * @param _y 		Y offset value
		 * @param _width 	Width extent value.
		 * @param _height 	Height extent value.
		 */
		Rect2D(T _x, T _y, T _width, T _height) noexcept :
			offset{ _x, _y },
			extent{ _width, _height }
		{
		}
	};


//{ Aliases

	/// Alias for int32 Rect2D.
	using Rect2Di = Rect2D<int32_t>;

	/// Alias for uint32 Rect2D.
	using Rect2Dui = Rect2D<uint32_t>;

	/// Alias for float Rect2D.
	using Rect2Df = Rect2D<float>;

	/// Alias for double Rect2D.
	using Rect2Dd = Rect2D<double>;


	/// Template alias of Rect2D.
	template <typename T>
	using Rectangle2D = Rect2D<T>;

	/// Alias for int32 Rect2D.
	using Rectangle2Di = Rectangle2D<int32_t>;

	/// Alias for uint32 Rect2D.
	using Rectangle2Dui = Rectangle2D<uint32_t>;

	/// Alias for float Rect2D.
	using Rectangle2Df = Rectangle2D<float>;

	/// Alias for double Rect2D.
	using Rectangle2Dd = Rectangle2D<double>;


//}
}


/** \} */

#endif // GUARD
