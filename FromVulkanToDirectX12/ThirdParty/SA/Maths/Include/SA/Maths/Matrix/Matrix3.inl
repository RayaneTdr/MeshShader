// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

namespace SA
{
//{ Constants

	template <typename T, MatrixMajor major>
	const Mat3<T, major> Mat3<T, major>::Zero
	{
		T(0), T(0), T(0),
		T(0), T(0), T(0),
		T(0), T(0), T(0)
	};

	template <typename T, MatrixMajor major>
	const Mat3<T, major> Mat3<T, major>::Identity
	{
		T(1), T(0), T(0),
		T(0), T(1), T(0),
		T(0), T(0), T(1)
	};

//}

//{ Constructors

	template <typename T, MatrixMajor major>
	template <typename TIn, MatrixMajor majorIn>
	constexpr Mat3<T, major>::Mat3(const Mat3<TIn, majorIn>& _other) noexcept :
		Intl::Mat3_Base<T, major>(
			static_cast<T>(_other.e00), static_cast<T>(_other.e01), static_cast<T>(_other.e02),
			static_cast<T>(_other.e10), static_cast<T>(_other.e11), static_cast<T>(_other.e12),
			static_cast<T>(_other.e20), static_cast<T>(_other.e21), static_cast<T>(_other.e22)
		)
	{
	}

	template <typename T, MatrixMajor major>
	template <typename TIn, MatrixMajor majorIn>
	constexpr Mat3<T, major>::Mat3(const Mat4<TIn, majorIn>& _other) noexcept :
		Intl::Mat3_Base<T, major>(
			static_cast<T>(_other.e00), static_cast<T>(_other.e01), static_cast<T>(_other.e02),
			static_cast<T>(_other.e10), static_cast<T>(_other.e11), static_cast<T>(_other.e12),
			static_cast<T>(_other.e20), static_cast<T>(_other.e21), static_cast<T>(_other.e22)
		)
	{
	}

//}

//{ Equals

	template <typename T, MatrixMajor major>
	constexpr bool Mat3<T, major>::IsZero() const noexcept
	{
		// Allows constexpr.

		return
			Maths::Equals0(e00) && Maths::Equals0(e01) && Maths::Equals0(e02) &&
			Maths::Equals0(e10) && Maths::Equals0(e11) && Maths::Equals0(e12) &&
			Maths::Equals0(e20) && Maths::Equals0(e21) && Maths::Equals0(e22);
	}

	template <typename T, MatrixMajor major>
	constexpr bool Mat3<T, major>::IsIdentity() const noexcept
	{
		// Allows constexpr.

		return
			Maths::Equals1(e00) && Maths::Equals0(e01) && Maths::Equals0(e02) &&
			Maths::Equals0(e10) && Maths::Equals1(e11) && Maths::Equals0(e12) &&
			Maths::Equals0(e20) && Maths::Equals0(e21) && Maths::Equals1(e22);
	}

	template <typename T, MatrixMajor major>
	constexpr bool Mat3<T, major>::Equals(const Mat3& _other, T _epsilon) const noexcept
	{
		// Allows constexpr.

		return
			Maths::Equals(e00, _other.e00, _epsilon) && Maths::Equals(e01, _other.e01, _epsilon) && Maths::Equals(e02, _other.e02, _epsilon) &&
			Maths::Equals(e10, _other.e10, _epsilon) && Maths::Equals(e11, _other.e11, _epsilon) && Maths::Equals(e12, _other.e12, _epsilon) &&
			Maths::Equals(e20, _other.e20, _epsilon) && Maths::Equals(e21, _other.e21, _epsilon) && Maths::Equals(e22, _other.e22, _epsilon);
	}


	template <typename T, MatrixMajor major>
	constexpr bool Mat3<T, major>::operator==(const Mat3& _rhs) const noexcept
	{
		return Equals(_rhs);
	}

	template <typename T, MatrixMajor major>
	constexpr bool Mat3<T, major>::operator!=(const Mat3& _rhs) const noexcept
	{
		return !(*this == _rhs);
	}

//}

//{ Accessors

	template <typename T, MatrixMajor major>
	T* Mat3<T, major>::Data() noexcept
	{
		return &e00;
	}

	template <typename T, MatrixMajor major>
	const T* Mat3<T, major>::Data() const noexcept
	{
		return &e00;
	}


	template <typename T, MatrixMajor major>
	T& Mat3<T, major>::At(uint32_t _index)
	{
		SA_ASSERT((OutOfRange, _index, 0u, 8u), SA/Maths);

		return Data()[_index];
	}

	template <typename T, MatrixMajor major>
	const T& Mat3<T, major>::At(uint32_t _index) const
	{
		SA_ASSERT((OutOfRange, _index, 0u, 8u), SA/Maths);

		return Data()[_index];
	}

	template <typename T, MatrixMajor major>
	T& Mat3<T, major>::At(uint32_t _x, uint32_t _y)
	{
		SA_ASSERT((OutOfRange, _x, 0u, 3u), SA/Maths);
		SA_ASSERT((OutOfRange, _y, 0u, 3u), SA/Maths);

		return Data()[_x * 3u + _y];
	}

	template <typename T, MatrixMajor major>
	const T& Mat3<T, major>::At(uint32_t _x, uint32_t _y) const
	{
		SA_ASSERT((OutOfRange, _x, 0u, 3u), SA/Maths);
		SA_ASSERT((OutOfRange, _y, 0u, 3u), SA/Maths);

		return Data()[_x * 3u + _y];
	}


	template <typename T, MatrixMajor major>
	T& Mat3<T, major>::operator[](uint32_t _index)
	{
		return At(_index);
	}

	template <typename T, MatrixMajor major>
	const T& Mat3<T, major>::operator[](uint32_t _index) const
	{
		return At(_index);
	}

//}


//{ Transpose

	template <typename T, MatrixMajor major>
	Mat3<T, major>& Mat3<T, major>::Transpose() noexcept
	{
		std::swap(e01, e10);
		std::swap(e02, e20);
		std::swap(e12, e21);

		return *this;
	}

	template <typename T, MatrixMajor major>
	constexpr Mat3<T, major> Mat3<T, major>::GetTransposed() const noexcept
	{
		// Allows constexpr.

		return Mat3(
			e00, e10, e20,
			e01, e11, e21,
			e02, e12, e22
		);
	}

//}

//{ Inverse

	template <typename T, MatrixMajor major>
	T Mat3<T, major>::Determinant() const noexcept
	{
		return
			e00 * e11 * e22 +
			e01 * e12 * e20 +
			e02 * e10 * e21 -
			e20 * e11 * e02 -
			e21 * e12 * e00 -
			e22 * e10 * e01;
	}

	template <typename T, MatrixMajor major>
	Mat3<T, major>& Mat3<T, major>::Inverse()
	{
		return *this = GetInversed();
	}

	template <typename T, MatrixMajor major>
	Mat3<T, major> Mat3<T, major>::GetInversed() const
	{
		const T det = Determinant();

		SA_ASSERT((NotEquals0, det), SA.Maths, L"Determinant must be != 0 to compute inverse matrix");

		return (1.0f / det) * Mat3(
			e11 * e22 - e21 * e12, e02 * e21 - e01 * e22, e01 * e12 - e11 * e02,
			e12 * e20 - e10 * e22, e00 * e22 - e20 * e02, e02 * e10 - e00 * e12,
			e10 * e21 - e20 * e11, e01 * e20 - e00 * e21, e00 * e11 - e10 * e01
		);
	}

//}

//{ Lerp

	template <typename T, MatrixMajor major>
	Mat3<T, major> Mat3<T, major>::Lerp(const Mat3& _start, const Mat3& _end, float _alpha) noexcept
	{
		return Maths::Lerp(_start, _end, _alpha);
	}

	template <typename T, MatrixMajor major>
	Mat3<T, major> Mat3<T, major>::LerpUnclamped(const Mat3& _start, const Mat3& _end, float _alpha) noexcept
	{
		return Maths::LerpUnclamped(_start, _end, _alpha);
	}

//}

//{ Transform

	template <typename T, MatrixMajor major>
	Mat3<T, major> Mat3<T, major>::MakeRotation(const Quat<T>& _rot) noexcept
	{
		SA_WARN(_rot.IsNormalized(), SA.Maths, L"Quaternion should be normalized!");

		// Sources: https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation

		const T XW2 = T(2) * _rot.x * _rot.w;
		const T XX2 = T(2) * _rot.x * _rot.x;
		const T XY2 = T(2) * _rot.x * _rot.y;
		const T XZ2 = T(2) * _rot.x * _rot.z;

		const T YW2 = T(2) * _rot.y * _rot.w;
		const T YY2 = T(2) * _rot.y * _rot.y;
		const T YZ2 = T(2) * _rot.y * _rot.z;

		const T ZW2 = T(2) * _rot.z * _rot.w;
		const T ZZ2 = T(2) * _rot.z * _rot.z;

		return Mat3(
			T(1) - YY2 - ZZ2, XY2 - ZW2, XZ2 + YW2,
			XY2 + ZW2, T(1) - XX2 - ZZ2, YZ2 - XW2,
			XZ2 - YW2, YZ2 + XW2, T(1) - XX2 - YY2
		);
	}

	template <typename T, MatrixMajor major>
	Mat3<T, major> Mat3<T, major>::MakeScale(const Vec3<T>& _scale) noexcept
	{
		Mat3 result = Mat3::Identity;

		result.e00 = _scale.x;
		result.e11 = _scale.y;
		result.e22 = _scale.z;

		return result;
	}

//}


//{ Operators

	template <typename T, MatrixMajor major>
	template <typename TIn, MatrixMajor majorIn>
	Mat3<T, major>& Mat3<T, major>::operator=(const Mat3<TIn, majorIn> _rhs) noexcept
	{
		e00 = static_cast<T>(_rhs.e00);
		e01 = static_cast<T>(_rhs.e01);
		e02 = static_cast<T>(_rhs.e02);

		e10 = static_cast<T>(_rhs.e10);
		e11 = static_cast<T>(_rhs.e11);
		e12 = static_cast<T>(_rhs.e12);

		e20 = static_cast<T>(_rhs.e20);
		e21 = static_cast<T>(_rhs.e21);
		e22 = static_cast<T>(_rhs.e22);

		return *this;
	}

	template <typename T, MatrixMajor major>
	constexpr Mat3<T, major> Mat3<T, major>::operator-() const noexcept
	{
		// Allows constexpr

		return Mat3(
			-e00, -e01, -e02,
			-e10, -e11, -e12,
			-e20, -e21, -e22
		);
	}

	template <typename T, MatrixMajor major>
	template <typename TIn>
	Mat3<T, major> Mat3<T, major>::operator*(TIn _scale) const noexcept
	{
		return Mat3(
			(T)(e00 * _scale), (T)(e01 * _scale), (T)(e02 * _scale),
			(T)(e10 * _scale), (T)(e11 * _scale), (T)(e12 * _scale),
			(T)(e20 * _scale), (T)(e21 * _scale), (T)(e22 * _scale)
		);
	}

	template <typename T, MatrixMajor major>
	template <typename TIn>
	Mat3<T, major> Mat3<T, major>::operator/(TIn _scale) const
	{
		SA_ASSERT((NotEquals0, _scale), SA.Maths, L"Unscale matrix by 0 (division by 0)!");

		return Mat3(
			(T)(e00 / _scale), (T)(e01 / _scale), (T)(e02 / _scale),
			(T)(e10 / _scale), (T)(e11 / _scale), (T)(e12 / _scale),
			(T)(e20 / _scale), (T)(e21 / _scale), (T)(e22 / _scale)
		);
	}

	template <typename T, MatrixMajor major>
	Mat3<T, major> Mat3<T, major>::operator+(const Mat3& _rhs) const noexcept
	{
		return Mat3(
			e00 + _rhs.e00, e01 + _rhs.e01, e02 + _rhs.e02,
			e10 + _rhs.e10, e11 + _rhs.e11, e12 + _rhs.e12,
			e20 + _rhs.e20, e21 + _rhs.e21, e22 + _rhs.e22
		);
	}

	template <typename T, MatrixMajor major>
	Mat3<T, major> Mat3<T, major>::operator-(const Mat3& _rhs) const noexcept
	{
		return Mat3(
			e00 - _rhs.e00, e01 - _rhs.e01, e02 - _rhs.e02,
			e10 - _rhs.e10, e11 - _rhs.e11, e12 - _rhs.e12,
			e20 - _rhs.e20, e21 - _rhs.e21, e22 - _rhs.e22
		);
	}

	template <typename T, MatrixMajor major>
	Mat3<T, major> Mat3<T, major>::operator*(const Mat3& _rhs) const noexcept
	{
		return Mat3(
			e00 * _rhs.e00 + e01 * _rhs.e10 + e02 * _rhs.e20,
			e00 * _rhs.e01 + e01 * _rhs.e11 + e02 * _rhs.e21,
			e00 * _rhs.e02 + e01 * _rhs.e12 + e02 * _rhs.e22,

			e10 * _rhs.e00 + e11 * _rhs.e10 + e12 * _rhs.e20,
			e10 * _rhs.e01 + e11 * _rhs.e11 + e12 * _rhs.e21,
			e10 * _rhs.e02 + e11 * _rhs.e12 + e12 * _rhs.e22,

			e20 * _rhs.e00 + e21 * _rhs.e10 + e22 * _rhs.e20,
			e20 * _rhs.e01 + e21 * _rhs.e11 + e22 * _rhs.e21,
			e20 * _rhs.e02 + e21 * _rhs.e12 + e22 * _rhs.e22
		);
	}

	template <typename T, MatrixMajor major>
	Mat3<T, major> Mat3<T, major>::operator/(const Mat3& _rhs) const
	{
		return *this * _rhs.GetInversed();
	}


	template <typename T, MatrixMajor major>
	Vec3<T> Mat3<T, major>::operator*(const Vec3<T>& _rhs) const noexcept
	{
		return Vec3(
			e00 * _rhs.x + e01 * _rhs.y + e02 * _rhs.z,
			e10 * _rhs.x + e11 * _rhs.y + e12 * _rhs.z,
			e20 * _rhs.x + e21 * _rhs.y + e22 * _rhs.z
		);
	}


	template <typename T, MatrixMajor major>
	template <typename TIn>
	Mat3<T, major>& Mat3<T, major>::operator*=(TIn _scale) noexcept
	{
		e00 *= _scale;
		e01 *= _scale;
		e02 *= _scale;

		e10 *= _scale;
		e11 *= _scale;
		e12 *= _scale;

		e20 *= _scale;
		e21 *= _scale;
		e22 *= _scale;

		return *this;
	}

	template <typename T, MatrixMajor major>
	template <typename TIn>
	Mat3<T, major>& Mat3<T, major>::operator/=(TIn _scale)
	{
		SA_ASSERT((NotEquals0, _scale), SA.Maths, L"Unscale matrix by 0 (division by 0)!");

		e00 /= _scale;
		e01 /= _scale;
		e02 /= _scale;

		e10 /= _scale;
		e11 /= _scale;
		e12 /= _scale;

		e20 /= _scale;
		e21 /= _scale;
		e22 /= _scale;

		return *this;
	}

	template <typename T, MatrixMajor major>
	Mat3<T, major>& Mat3<T, major>::operator+=(const Mat3& _rhs) noexcept
	{
		e00 += _rhs.e00;
		e01 += _rhs.e01;
		e02 += _rhs.e02;

		e10 += _rhs.e10;
		e11 += _rhs.e11;
		e12 += _rhs.e12;

		e20 += _rhs.e20;
		e21 += _rhs.e21;
		e22 += _rhs.e22;

		return *this;
	}

	template <typename T, MatrixMajor major>
	Mat3<T, major>& Mat3<T, major>::operator-=(const Mat3& _rhs) noexcept
	{
		e00 -= _rhs.e00;
		e01 -= _rhs.e01;
		e02 -= _rhs.e02;

		e10 -= _rhs.e10;
		e11 -= _rhs.e11;
		e12 -= _rhs.e12;

		e20 -= _rhs.e20;
		e21 -= _rhs.e21;
		e22 -= _rhs.e22;

		return *this;
	}

	template <typename T, MatrixMajor major>
	Mat3<T, major>& Mat3<T, major>::operator*=(const Mat3& _rhs) noexcept
	{
		return *this = *this * _rhs;
	}

	template <typename T, MatrixMajor major>
	Mat3<T, major>& Mat3<T, major>::operator/=(const Mat3& _rhs)
	{
		return *this = *this / _rhs;
	}

//}


	template <typename TIn, typename T, MatrixMajor major>
	Mat3<T, major> operator*(TIn _lhs, const Mat3<T, major>& _rhs) noexcept
	{
		return _rhs * _lhs;
	}

	template <typename TIn, typename T, MatrixMajor major>
	Mat3<T, major> operator/(TIn _lhs, const Mat3<T, major>& _rhs)
	{
		SA_ASSERT((NotEquals0, _rhs.e00), SA.Maths, L"Inverse scale matrix e00 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e01), SA.Maths, L"Inverse scale matrix e01 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e02), SA.Maths, L"Inverse scale matrix e02 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e10), SA.Maths, L"Inverse scale matrix e10 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e11), SA.Maths, L"Inverse scale matrix e11 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e12), SA.Maths, L"Inverse scale matrix e12 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e20), SA.Maths, L"Inverse scale matrix e20 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e21), SA.Maths, L"Inverse scale matrix e21 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e22), SA.Maths, L"Inverse scale matrix e22 == 0!");


		return Mat3<T>(
			_lhs / _rhs.e00, _lhs / _rhs.e01, _lhs / _rhs.e02,
			_lhs / _rhs.e10, _lhs / _rhs.e11, _lhs / _rhs.e12,
			_lhs / _rhs.e20, _lhs / _rhs.e21, _lhs / _rhs.e22
		);
	}


#if SA_LOGGER_IMPL

	template <typename T>
	std::string ToString(const Mat3<T>& _m)
	{
		// Keep memory order (Raw / column major).
		const T* const data = _m.Data();

		return
			SA::ToString(data[0]) + ", " +
			SA::ToString(data[1]) + ", " +
			SA::ToString(data[2]) + ",\n " +

			SA::ToString(data[3]) + ", " +
			SA::ToString(data[4]) + ", " +
			SA::ToString(data[5]) + ",\n " +

			SA::ToString(data[6]) + ", " +
			SA::ToString(data[7]) + ", " +
			SA::ToString(data[8]);
	}

#endif
}
