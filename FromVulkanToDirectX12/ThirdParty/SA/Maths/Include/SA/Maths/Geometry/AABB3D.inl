// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

namespace SA
{
//{ Constructors

	template <typename T>
	AABB3D<T>::AABB3D(const Vec3<T>& _min, const Vec3<T>& _max) :
		min{ _min },
		max{ _max }
	{
		SA_ASSERT(IsThisValid, SA.Maths.AABB.3D, L"Initialize AABB with invalid parameters: min must be < to max!");
	}

	template <typename T>
	AABB3D<T>::AABB3D(const AABB3D& _first, const AABB3D& _second)
	{
		*this = Merge(_first, _second);
	}

	template <typename T>
	AABB3D<T>::AABB3D(const AABB2D<T>& _aabb2D) noexcept :
		min{ _aabb2D.min },
		max{ _aabb2D.max }
	{
	}

//}


//{ Equals

	template <typename T>
	bool AABB3D<T>::IsValid() const noexcept
	{
		return min.x <= max.x && min.y <= max.y && min.z <= max.z;
	}


	template <typename T>
	constexpr bool AABB3D<T>::Equals(const AABB3D& _other, T _epsilon) const noexcept
	{
		return min.Equals(_other.min, _epsilon) && max.Equals(_other.max, _epsilon);
	}


	template <typename T>
	constexpr bool AABB3D<T>::operator==(const AABB3D& _rhs) const noexcept
	{
		return Equals(_rhs);
	}

	template <typename T>
	constexpr bool AABB3D<T>::operator!=(const AABB3D& _rhs) const noexcept
	{
		return !(*this == _rhs);
	}

//}


//{ Collisions

	template <typename T>
	bool AABB3D<T>::IsCollidingX(const AABB3D& _other) const
	{
		SA_ASSERT(IsThisValid, SA.Maths.AABB.3D, L"Invalid AABB: min must be < to max!");
		SA_ASSERT((IsValid, _other), SA.Maths.AABB.3D, L"Invalid AABB: min must be < to max!");

		// Check out of X bound.
		return !(min.x > _other.max.x || max.x < _other.min.x);
	}

	template <typename T>
	bool AABB3D<T>::IsCollidingY(const AABB3D& _other) const
	{
		SA_ASSERT(IsThisValid, SA.Maths.AABB.3D, L"Invalid AABB: min must be < to max!");
		SA_ASSERT((IsValid, _other), SA.Maths.AABB.3D, L"Invalid AABB: min must be < to max!");

		// Check out of Y bound.
		return !(min.y > _other.max.y || max.y < _other.min.y);
	}

	template <typename T>
	bool AABB3D<T>::IsCollidingZ(const AABB3D& _other) const
	{
		SA_ASSERT(IsThisValid, SA.Maths.AABB.3D, L"Invalid AABB: min must be < to max!");
		SA_ASSERT((IsValid, _other), SA.Maths.AABB.3D, L"Invalid AABB: min must be < to max!");

		// Check out of Z bound.
		return !(min.z > _other.max.z || max.z < _other.min.z);
	}

	template <typename T>
	bool AABB3D<T>::IsColliding(const AABB3D& _other) const
	{
		return IsCollidingX(_other) || IsCollidingY(_other) || IsCollidingZ(_other);
	}

//}


//{ Geometry

	template <typename T>
	float AABB3D<T>::Width() const
	{
		SA_ASSERT(IsThisValid, SA.Maths.AABB.3D, L"Invalid AABB: min must be < to max!");

		return max.x - min.x;
	}

	template <typename T>
	float AABB3D<T>::Height() const
	{
		SA_ASSERT(IsThisValid, SA.Maths.AABB.3D, L"Invalid AABB: min must be < to max!");

		return max.y - min.y;
	}

	template <typename T>
	float AABB3D<T>::Depth() const
	{
		SA_ASSERT(IsThisValid, SA.Maths.AABB.3D, L"Invalid AABB: min must be < to max!");

		return max.z - min.z;
	}

	template <typename T>
	Vec3<T> AABB3D<T>::Center() const
	{
		SA_ASSERT(IsThisValid, SA.Maths.AABB.3D, L"Invalid AABB: min must be < to max!");

		return min + (max - min) / 2.0f;
	}

	template <typename T>
	float AABB3D<T>::Area() const
	{
		return Width() * Height() * Depth();
	}

//}


	template <typename T>
	AABB3D<T> AABB3D<T>::Merge(const AABB3D& _first, const AABB3D& _second)
	{
		SA_ASSERT((IsValid, _first), SA.Maths.AABB.3D, L"Invalid AABB: min must be < to max!");
		SA_ASSERT((IsValid, _second), SA.Maths.AABB.3D, L"Invalid AABB: min must be < to max!");

		AABB3D merged;

		merged.min.x = std::min(_first.min.x, _second.min.x);
		merged.min.y = std::min(_first.min.y, _second.min.y);
		merged.min.z = std::min(_first.min.z, _second.min.z);

		merged.max.x = std::max(_first.max.x, _second.max.x);
		merged.max.y = std::max(_first.max.y, _second.max.y);
		merged.max.z = std::max(_first.max.z, _second.max.z);

		return merged;
	}


#if SA_LOGGER_IMPL

	template <typename T>
	std::string ToString(const AABB3D<T>& _aabb)
	{
		return "Min {" + SA::ToString(_aabb.min) + "}\tMax {" + SA::ToString(_aabb.max) + '}';
	}

#endif

}
