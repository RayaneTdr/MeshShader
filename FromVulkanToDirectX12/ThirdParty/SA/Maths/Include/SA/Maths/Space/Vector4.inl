// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

namespace SA
{
//{ Constructors

	template <typename T>
	constexpr Vec4<T>::Vec4(T _x, T _y, T _z, T _w) noexcept :
		x{ _x },
		y{ _y },
		z{ _z },
		w{ _w }
	{
	}

	template <typename T>
	constexpr Vec4<T>::Vec4(T _scale) noexcept :
		x{ _scale },
		y{ _scale },
		z{ _scale },
		w{ _scale }
	{
	}

	template <typename T>
	template <typename TIn>
	constexpr Vec4<T>::Vec4(const Vec4<TIn>& _other) noexcept :
		x{ static_cast<T>(_other.x) },
		y{ static_cast<T>(_other.y) },
		z{ static_cast<T>(_other.z) },
		w{ static_cast<T>(_other.w) }
	{
	}

	template <typename T>
	template <typename TIn>
	constexpr Vec4<T>::Vec4(const Vec2<TIn>& _other, T _z, T _w) noexcept :
		x{ static_cast<T>(_other.x) },
		y{ static_cast<T>(_other.y) },
		z{ _z },
		w{ _w }
	{
	}

	template <typename T>
	template <typename TIn>
	constexpr Vec4<T>::Vec4(const Vec2<TIn>& _v1, const Vec2<TIn>& _v2) noexcept :
		x{ static_cast<T>(_v1.x) },
		y{ static_cast<T>(_v1.y) },
		z{ static_cast<T>(_v2.x) },
		w{ static_cast<T>(_v2.y) }
	{
	}

	template <typename T>
	template <typename TIn>
	constexpr Vec4<T>::Vec4(const Vec3<TIn>& _other, T _w) noexcept :
		x{ static_cast<T>(_other.x) },
		y{ static_cast<T>(_other.y) },
		z{ static_cast<T>(_other.z) },
		w{ _w }
	{
	}

//}

//{ Equals

	template <typename T>
	constexpr bool Vec4<T>::IsZero() const noexcept
	{
		return Maths::Equals0(x) && Maths::Equals0(y) && Maths::Equals0(z) && Maths::Equals0(w);
	}

	template <typename T>
	constexpr bool Vec4<T>::Equals(const Vec4& _other, T _epsilon) const noexcept
	{
		return Maths::Equals(x, _other.x, _epsilon) &&
			Maths::Equals(y, _other.y, _epsilon) &&
			Maths::Equals(z, _other.z, _epsilon) &&
			Maths::Equals(w, _other.w, _epsilon);
	}


	template <typename T>
	constexpr bool Vec4<T>::operator==(const Vec4& _rhs) const noexcept
	{
		return Equals(_rhs);
	}

	template <typename T>
	constexpr bool Vec4<T>::operator!=(const Vec4& _rhs) const noexcept
	{
		return !(*this == _rhs);
	}

//}

//{ Accessors

	template <typename T>
	T* Vec4<T>::Data() noexcept
	{
		return &x;
	}

	template <typename T>
	const T* Vec4<T>::Data() const noexcept
	{
		return &x;
	}


	template <typename T>
	T& Vec4<T>::operator[](uint32_t _index)
	{
		SA_ASSERT((OutOfRange, _index, 0u, 3u), SA.Maths);

		return Data()[_index];
	}

	template <typename T>
	const T& Vec4<T>::operator[](uint32_t _index) const
	{
		SA_ASSERT((OutOfRange, _index, 0u, 3u), SA.Maths);

		return Data()[_index];
	}

//}

//{ Operators



//}


#if SA_LOGGER_IMPL

	template <typename T>
	std::string ToString(const Vec4<T>& _v)
	{
		return "X: " + SA::ToString(_v.x) +
			"\tY: " + SA::ToString(_v.y) +
			"\tZ: " + SA::ToString(_v.z) +
			"\tW: " + SA::ToString(_v.w);
	}

#endif
}
