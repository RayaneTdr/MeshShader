// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

namespace SA
{
//{ Constants

	template <typename T, MatrixMajor major>
	const Mat4<T, major> Mat4<T, major>::Zero
	{
		T(0), T(0), T(0), T(0),
		T(0), T(0), T(0), T(0),
		T(0), T(0), T(0), T(0),
		T(0), T(0), T(0), T(0)
	};

	template <typename T, MatrixMajor major>
	const Mat4<T, major> Mat4<T, major>::Identity
	{
		T(1), T(0), T(0), T(0),
		T(0), T(1), T(0), T(0),
		T(0), T(0), T(1), T(0),
		T(0), T(0), T(0), T(1)
	};

//}

//{ Constructors

	template <typename T, MatrixMajor major>
	template <typename TIn, MatrixMajor majorIn>
	constexpr Mat4<T, major>::Mat4(const Mat4<TIn, majorIn>& _other) noexcept :
		Intl::Mat4_Base<T, major>(
			static_cast<T>(_other.e00), static_cast<T>(_other.e01), static_cast<T>(_other.e02), static_cast<T>(_other.e03),
			static_cast<T>(_other.e10), static_cast<T>(_other.e11), static_cast<T>(_other.e12), static_cast<T>(_other.e13),
			static_cast<T>(_other.e20), static_cast<T>(_other.e21), static_cast<T>(_other.e22), static_cast<T>(_other.e23),
			static_cast<T>(_other.e30), static_cast<T>(_other.e31), static_cast<T>(_other.e32), static_cast<T>(_other.e33)
		)
	{
	}

	template <typename T, MatrixMajor major>
	template <typename TIn, MatrixMajor majorIn>
	constexpr Mat4<T, major>::Mat4(const Mat3<TIn, majorIn>& _other) noexcept :
		Intl::Mat4_Base<T, major>(
			static_cast<T>(_other.e00), static_cast<T>(_other.e01), static_cast<T>(_other.e02), T(0),
			static_cast<T>(_other.e10), static_cast<T>(_other.e11), static_cast<T>(_other.e12), T(0),
			static_cast<T>(_other.e20), static_cast<T>(_other.e21), static_cast<T>(_other.e22), T(0),
			T(0), T(0), T(0), T(1)
		)
	{
	}

//}

//{ Equals

	template <typename T, MatrixMajor major>
	constexpr bool Mat4<T, major>::IsZero() const noexcept
	{
		// Allows constexpr.

		return
			Maths::Equals0(e00) && Maths::Equals0(e01) && Maths::Equals0(e02) && Maths::Equals0(e03) &&
			Maths::Equals0(e10) && Maths::Equals0(e11) && Maths::Equals0(e12) && Maths::Equals0(e13) &&
			Maths::Equals0(e20) && Maths::Equals0(e21) && Maths::Equals0(e22) && Maths::Equals0(e23) &&
			Maths::Equals0(e30) && Maths::Equals0(e31) && Maths::Equals0(e32) && Maths::Equals0(e33);
	}

	template <typename T, MatrixMajor major>
	constexpr bool Mat4<T, major>::IsIdentity() const noexcept
	{
		// Allows constexpr.

		return
			Maths::Equals1(e00) && Maths::Equals0(e01) && Maths::Equals0(e02) && Maths::Equals0(e03) &&
			Maths::Equals0(e10) && Maths::Equals1(e11) && Maths::Equals0(e12) && Maths::Equals0(e13) &&
			Maths::Equals0(e20) && Maths::Equals0(e21) && Maths::Equals1(e22) && Maths::Equals0(e23) &&
			Maths::Equals0(e30) && Maths::Equals0(e31) && Maths::Equals0(e32) && Maths::Equals1(e33);
	}


	template <typename T, MatrixMajor major>
	constexpr bool Mat4<T, major>::Equals(const Mat4& _other, T _threshold) const noexcept
	{
		// Allows constexpr.

		return
			Maths::Equals(e00, _other.e00, _threshold) &&
			Maths::Equals(e01, _other.e01, _threshold) &&
			Maths::Equals(e02, _other.e02, _threshold) &&
			Maths::Equals(e03, _other.e03, _threshold) &&
			Maths::Equals(e10, _other.e10, _threshold) &&
			Maths::Equals(e11, _other.e11, _threshold) &&
			Maths::Equals(e12, _other.e12, _threshold) &&
			Maths::Equals(e13, _other.e13, _threshold) &&
			Maths::Equals(e20, _other.e20, _threshold) &&
			Maths::Equals(e21, _other.e21, _threshold) &&
			Maths::Equals(e22, _other.e22, _threshold) &&
			Maths::Equals(e23, _other.e23, _threshold) &&
			Maths::Equals(e30, _other.e30, _threshold) &&
			Maths::Equals(e31, _other.e31, _threshold) &&
			Maths::Equals(e32, _other.e32, _threshold) &&
			Maths::Equals(e33, _other.e33, _threshold);
	}


	template <typename T, MatrixMajor major>
	constexpr bool Mat4<T, major>::operator==(const Mat4& _rhs) const noexcept
	{
		return Equals(_rhs);
	}

	template <typename T, MatrixMajor major>
	constexpr bool Mat4<T, major>::operator!=(const Mat4& _rhs) const noexcept
	{
		return !(*this == _rhs);
	}

//}

//{ Accessors

	template <typename T, MatrixMajor major>
	T* Mat4<T, major>::Data() noexcept
	{
		return &e00;
	}

	template <typename T, MatrixMajor major>
	const T* Mat4<T, major>::Data() const noexcept
	{
		return &e00;
	}


	template <typename T, MatrixMajor major>
	T& Mat4<T, major>::At(uint32_t _index)
	{
		SA_ASSERT((OutOfRange, _index, 0u, 15u), SA.Maths);

		return Data()[_index];

	}

	template <typename T, MatrixMajor major>
	const T& Mat4<T, major>::At(uint32_t _index) const
	{
		SA_ASSERT((OutOfRange, _index, 0u, 15u), SA.Maths);

		return Data()[_index];
	}

	template <typename T, MatrixMajor major>
	T& Mat4<T, major>::At(uint32_t _x, uint32_t _y)
	{
		SA_ASSERT((OutOfRange, _x, 0u, 4u), SA.Maths);
		SA_ASSERT((OutOfRange, _y, 0u, 4u), SA.Maths);

		return Data()[_x * 4u + _y];
	}

	template <typename T, MatrixMajor major>
	const T& Mat4<T, major>::At(uint32_t _x, uint32_t _y) const
	{
		SA_ASSERT((OutOfRange, _x, 0u, 4u), SA.Maths);
		SA_ASSERT((OutOfRange, _y, 0u, 4u), SA.Maths);

		return Data()[_x * 4u + _y];
	}


	template <typename T, MatrixMajor major>
	T& Mat4<T, major>::operator[](uint32_t _index)
	{
		return At(_index);
	}

	template <typename T, MatrixMajor major>
	const T& Mat4<T, major>::operator[](uint32_t _index) const
	{
		return At(_index);
	}

//}

//{ Transpose

	template <typename T, MatrixMajor major>
	Mat4<T, major>& Mat4<T, major>::Transpose() noexcept
	{
		std::swap(e01, e10);
		std::swap(e02, e20);
		std::swap(e03, e30);

		std::swap(e12, e21);
		std::swap(e13, e31);

		std::swap(e23, e32);

		return *this;
	}

	template <typename T, MatrixMajor major>
	constexpr Mat4<T, major> Mat4<T, major>::GetTransposed() const noexcept
	{
		// Allows constexpr.

		return Mat4(
			e00, e10, e20, e30,
			e01, e11, e21, e31,
			e02, e12, e22, e32,
			e03, e13, e23, e33
		);
	}

//}

//{ Inverse

	template <typename T, MatrixMajor major>
	T Mat4<T, major>::Determinant() const noexcept
	{
		const T det22_33_23_32 = e22 * e33 - e23 * e32;
		const T det12_33_13_32 = e12 * e33 - e13 * e32;
		const T det12_23_13_22 = e12 * e23 - e13 * e22;
		const T det02_33_03_32 = e02 * e33 - e03 * e32;
		const T det02_23_03_22 = e02 * e23 - e03 * e22;
		const T det02_13_03_12 = e02 * e13 - e03 * e12;

		return
			e00 * (e11 * det22_33_23_32 - e21 * det12_33_13_32 + e31 * det12_23_13_22) -
			e10 * (e01 * det22_33_23_32 - e21 * det02_33_03_32 + e31 * det02_23_03_22) +
			e20 * (e01 * det12_33_13_32 - e11 * det02_33_03_32 + e31 * det02_13_03_12) -
			e30 * (e01 * det12_23_13_22 - e11 * det02_23_03_22 + e21 * det02_13_03_12);
	}

	template <typename T, MatrixMajor major>
	Mat4<T, major>& Mat4<T, major>::Inverse()
	{
		return *this = GetInversed();
	}

	template <typename T, MatrixMajor major>
	Mat4<T, major> Mat4<T, major>::GetInversed() const
	{
		const T det = Determinant();

		SA_ASSERT((NotEquals0, det), SA.Maths, L"Determinant must be != 0 to compute inverse matrix");

		Mat4 result;

		const T _01x12 = e01 * e12;
		const T _01x13 = e01 * e13;
		const T _01x22 = e01 * e22;
		const T _01x23 = e01 * e23;
		const T _01x32 = e01 * e32;
		const T _01x33 = e01 * e33;

		const T _02x11 = e02 * e11;
		const T _02x13 = e02 * e13;
		const T _02x21 = e02 * e21;
		const T _02x23 = e02 * e23;
		const T _02x31 = e02 * e31;
		const T _02x33 = e02 * e33;

		const T _03x11 = e03 * e11;
		const T _03x12 = e03 * e12;
		const T _03x21 = e03 * e21;
		const T _03x22 = e03 * e22;
		const T _03x31 = e03 * e31;
		const T _03x32 = e03 * e32;

		const T _11x22 = e11 * e22;
		const T _11x23 = e11 * e23;
		const T _11x32 = e11 * e32;
		const T _11x33 = e11 * e33;

		const T _12x21 = e12 * e21;
		const T _12x23 = e12 * e23;
		const T _12x31 = e12 * e31;
		const T _12x33 = e12 * e33;

		const T _13x21 = e13 * e21;
		const T _13x22 = e13 * e22;
		const T _13x31 = e13 * e31;
		const T _13x32 = e13 * e32;

		const T _21x32 = e21 * e32;
		const T _21x33 = e21 * e33;

		const T _22x31 = e22 * e31;
		const T _22x33 = e22 * e33;

		const T _23x31 = e23 * e31;
		const T _23x32 = e23 * e32;

		// Row 0.
		result.e00 =
			e11 * _22x33 -
			e11 * _23x32 -
			e21 * _12x33 +
			e21 * _13x32 +
			e31 * _12x23 -
			e31 * _13x22;

		result.e01 =
			-e01 * _22x33 +
			e01 * _23x32 +
			e21 * _02x33 -
			e21 * _03x32 -
			e31 * _02x23 +
			e31 * _03x22;

		result.e02 =
			e01 * _12x33 -
			e01 * _13x32 -
			e11 * _02x33 +
			e11 * _03x32 +
			e31 * _02x13 -
			e31 * _03x12;

		result.e03 =
			-e01 * _12x23 +
			e01 * _13x22 +
			e11 * _02x23 -
			e11 * _03x22 -
			e21 * _02x13 +
			e21 * _03x12;


		// Row 1
		result.e10 =
			-e10 * _22x33 +
			e10 * _23x32 +
			e20 * _12x33 -
			e20 * _13x32 -
			e30 * _12x23 +
			e30 * _13x22;

		result.e11 =
			e00 * _22x33 -
			e00 * _23x32 -
			e20 * _02x33 +
			e20 * _03x32 +
			e30 * _02x23 -
			e30 * _03x22;

		result.e12 =
			-e00 * _12x33 +
			e00 * _13x32 +
			e10 * _02x33 -
			e10 * _03x32 -
			e30 * _02x13 +
			e30 * _03x12;

		result.e13 =
			e00 * _12x23 -
			e00 * _13x22 -
			e10 * _02x23 +
			e10 * _03x22 +
			e20 * _02x13 -
			e20 * _03x12;


		// Row 2.
		result.e20 =
			e10 * _21x33 -
			e10 * _23x31 -
			e20 * _11x33 +
			e20 * _13x31 +
			e30 * _11x23 -
			e30 * _13x21;

		result.e21 =
			-e00 * _21x33 +
			e00 * _23x31 +
			e20 * _01x33 -
			e20 * _03x31 -
			e30 * _01x23 +
			e30 * _03x21;

		result.e22 =
			e00 * _11x33 -
			e00 * _13x31 -
			e10 * _01x33 +
			e10 * _03x31 +
			e30 * _01x13 -
			e30 * _03x11;

		result.e23 =
			-e00 * _11x23 +
			e00 * _13x21 +
			e10 * _01x23 -
			e10 * _03x21 -
			e20 * _01x13 +
			e20 * _03x11;


		// Row 3.
		result.e30 =
			-e10 * _21x32 +
			e10 * _22x31 +
			e20 * _11x32 -
			e20 * _12x31 -
			e30 * _11x22 +
			e30 * _12x21;

		result.e31 =
			e00 * _21x32 -
			e00 * _22x31 -
			e20 * _01x32 +
			e20 * _02x31 +
			e30 * _01x22 -
			e30 * _02x21;

		result.e32 =
			-e00 * _11x32 +
			e00 * _12x31 +
			e10 * _01x32 -
			e10 * _02x31 -
			e30 * _01x12 +
			e30 * _02x11;

		result.e33 =
			e00 * _11x22 -
			e00 * _12x21 -
			e10 * _01x22 +
			e10 * _02x21 +
			e20 * _01x12 -
			e20 * _02x11;


		result /= det;

		return result;
	}

//}
	
//{ Lerp

	template <typename T, MatrixMajor major>
	Mat4<T, major> Mat4<T, major>::Lerp(const Mat4& _start, const Mat4& _end, float _alpha) noexcept
	{
		return Maths::Lerp(_start, _end, _alpha);
	}

	template <typename T, MatrixMajor major>
	Mat4<T, major> Mat4<T, major>::LerpUnclamped(const Mat4& _start, const Mat4& _end, float _alpha) noexcept
	{
		return Maths::LerpUnclamped(_start, _end, _alpha);
	}

//}

//{ Transform

	template <typename T, MatrixMajor major>
	Mat4<T, major> Mat4<T, major>::MakeTranslation(const Vec3<T>& _transl) noexcept
	{
		Mat4 res = Mat4::Identity;

		res.e03 = _transl.x;
		res.e13 = _transl.y;
		res.e23 = _transl.z;

		return res;
	}

	template <typename T, MatrixMajor major>
	Mat4<T, major> Mat4<T, major>::MakeRotation(const Quat<T>& _rotation) noexcept
	{
		SA_WARN(_rotation.IsNormalized(), SA.Maths, L"Quaternion should be normalized!");

		// Sources: https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation

		const T XW2 = T(2) * _rotation.x * _rotation.w;
		const T XX2 = T(2) * _rotation.x * _rotation.x;
		const T XY2 = T(2) * _rotation.x * _rotation.y;
		const T XZ2 = T(2) * _rotation.x * _rotation.z;

		const T YW2 = T(2) * _rotation.y * _rotation.w;
		const T YY2 = T(2) * _rotation.y * _rotation.y;
		const T YZ2 = T(2) * _rotation.y * _rotation.z;

		const T ZW2 = T(2) * _rotation.z * _rotation.w;
		const T ZZ2 = T(2) * _rotation.z * _rotation.z;

		return Mat4(
			T(1) - YY2 - ZZ2, XY2 - ZW2, XZ2 + YW2, T(0),
			XY2 + ZW2, T(1) - XX2 - ZZ2, YZ2 - XW2, T(0),
			XZ2 - YW2, YZ2 + XW2, T(1) - XX2 - YY2, T(0),
			T(0), T(0), T(0), T(1)
		);
	}

	template <typename T, MatrixMajor major>
	Mat4<T, major> Mat4<T, major>::MakeScale(const Vec3<T>& _scale) noexcept
	{
		Mat4 result = Mat4::Identity;

		result.e00 = _scale.x;
		result.e11 = _scale.y;
		result.e22 = _scale.z;

		return result;
	}


	template <typename T, MatrixMajor major>
	Mat4<T, major> Mat4<T, major>::MakeLookAt(const Vec3<T>& _eye, const Vec3<T>& _target, const Vec3<T>& _up)
	{
		const Vec3<T> forward = (_target - _eye).Normalize();

		return MakeInverseView(_eye, forward, _up);
	}

	/*
	template <typename T, MatrixMajor major>
	Mat4<T, major> Mat4<T, major>::MakeView(const Vec3<T>& _eye, const Vec3<T>& _forward, const Vec3<T>& _up)
	{
		const Vec3<T> right = Vec3<T>::Cross(_up, _forward).Normalize();

		return Mat4(
			right.x, _up.x, _forward.x, _eye.x,
			right.y, _up.y, _forward.y, _eye.y,
			right.z, _up.z, _forward.z, _eye.z,
			T(0), T(0), T(0) , T(1)
		);
	}
	*/

	template <typename T, MatrixMajor major>
	Mat4<T, major> Mat4<T, major>::MakeInverseView(const Vec3<T>& _eye, const Vec3<T>& _forward, const Vec3<T>& _up)
	{
		const Vec3<T> right = Vec3<T>::Cross(_up, _forward).Normalize();

		const Vec3<T> translation = Vec3(
			Vec3<T>::Dot(_eye, right),
			Vec3<T>::Dot(_eye, _up),
			Vec3<T>::Dot(_eye, _forward)
		);

		return Mat4(
			right.x,	right.y,	right.z,	-translation.x,
			_up.x,		_up.y,		_up.z,		-translation.y,
			_forward.x,	_forward.y,	_forward.z,	-translation.z,
			T(0),		 T(0),		T(0),		T(1)
		);
	}


	template <typename T, MatrixMajor major>
	Mat4<T, major> Mat4<T, major>::MakePerspective(T _fov, T _aspect, T _near, T _far) noexcept
	{
		const T focalLength = T(1) / std::tan(Maths::DegToRad<T> * _fov / T(2));

		/**
		*	Vulkan/DX12 matrix
		*	Sources: https://youtu.be/U0_ONQQ5ZNM
		*	https://computergraphics.stackexchange.com/questions/12448/vulkan-perspective-matrix-vs-opengl-perspective-matrix
		*/

		return Mat4(
			focalLength / _aspect,	0,					0,									0,
			0,						focalLength,		0,									0,
			0,						0,					_far / (_far - _near),				-(_far * _near) / (_far - _near),
			0,						0,					1,									0
		);
	}

//}

//{ Operators

	template <typename T, MatrixMajor major>
	template <typename TIn, MatrixMajor majorIn>
	Mat4<T, major>& Mat4<T, major>::operator=(const Mat4<TIn, majorIn> _rhs) noexcept
	{
		e00 = static_cast<T>(_rhs.e00);
		e01 = static_cast<T>(_rhs.e01);
		e02 = static_cast<T>(_rhs.e02);
		e03 = static_cast<T>(_rhs.e03);

		e10 = static_cast<T>(_rhs.e10);
		e11 = static_cast<T>(_rhs.e11);
		e12 = static_cast<T>(_rhs.e12);
		e13 = static_cast<T>(_rhs.e13);

		e20 = static_cast<T>(_rhs.e20);
		e21 = static_cast<T>(_rhs.e21);
		e22 = static_cast<T>(_rhs.e22);
		e23 = static_cast<T>(_rhs.e23);

		e30 = static_cast<T>(_rhs.e30);
		e31 = static_cast<T>(_rhs.e31);
		e32 = static_cast<T>(_rhs.e32);
		e33 = static_cast<T>(_rhs.e33);

		return *this;
	}

	template <typename T, MatrixMajor major>
	constexpr Mat4<T, major> Mat4<T, major>::operator-() const noexcept
	{
		// Allows constexpr.

		return Mat4(
			-e00, -e01, -e02, -e03,
			-e10, -e11, -e12, -e13,
			-e20, -e21, -e22, -e23,
			-e30, -e31, -e32, -e33
		);
	}

	template <typename T, MatrixMajor major>
	template<typename TIn>
	Mat4<T, major> Mat4<T, major>::operator*(TIn _scale) const noexcept
	{
		return Mat4(
			(T)(e00 * _scale), (T)(e01 * _scale), (T)(e02 * _scale), (T)(e03 * _scale),
			(T)(e10 * _scale), (T)(e11 * _scale), (T)(e12 * _scale), (T)(e13 * _scale),
			(T)(e20 * _scale), (T)(e21 * _scale), (T)(e22 * _scale), (T)(e23 * _scale),
			(T)(e30 * _scale), (T)(e31 * _scale), (T)(e32 * _scale), (T)(e33 * _scale)
		);
	}

	template <typename T, MatrixMajor major>
	template<typename TIn>
	Mat4<T, major> Mat4<T, major>::operator/(TIn _scale) const
	{
		SA_ASSERT((NotEquals0, _scale), SA.Maths, L"Unscale matrix by 0 (division by 0)!");

		return Mat4(
			(T)(e00 / _scale), (T)(e01 / _scale), (T)(e02 / _scale), (T)(e03 / _scale),
			(T)(e10 / _scale), (T)(e11 / _scale), (T)(e12 / _scale), (T)(e13 / _scale),
			(T)(e20 / _scale), (T)(e21 / _scale), (T)(e22 / _scale), (T)(e23 / _scale),
			(T)(e30 / _scale), (T)(e31 / _scale), (T)(e32 / _scale), (T)(e33 / _scale)
		);
	}

	template <typename T, MatrixMajor major>
	Mat4<T, major> Mat4<T, major>::operator+(const Mat4& _rhs) const noexcept
	{
		return Mat4(
			e00 + _rhs.e00, e01 + _rhs.e01, e02 + _rhs.e02, e03 + _rhs.e03,
			e10 + _rhs.e10, e11 + _rhs.e11, e12 + _rhs.e12, e13 + _rhs.e13,
			e20 + _rhs.e20, e21 + _rhs.e21, e22 + _rhs.e22, e23 + _rhs.e23,
			e30 + _rhs.e30, e31 + _rhs.e31, e32 + _rhs.e32, e33 + _rhs.e33
		);
	}

	template <typename T, MatrixMajor major>
	Mat4<T, major> Mat4<T, major>::operator-(const Mat4& _rhs) const noexcept
	{
		return Mat4(
			e00 - _rhs.e00, e01 - _rhs.e01, e02 - _rhs.e02, e03 - _rhs.e03,
			e10 - _rhs.e10, e11 - _rhs.e11, e12 - _rhs.e12, e13 - _rhs.e13,
			e20 - _rhs.e20, e21 - _rhs.e21, e22 - _rhs.e22, e23 - _rhs.e23,
			e30 - _rhs.e30, e31 - _rhs.e31, e32 - _rhs.e32, e33 - _rhs.e33
		);
	}

	template <typename T, MatrixMajor major>
	Mat4<T, major> Mat4<T, major>::operator*(const Mat4& _rhs) const noexcept
	{
		return Mat4(
			e00 * _rhs.e00 + e01 * _rhs.e10 + e02 * _rhs.e20 + e03 * _rhs.e30,
			e00 * _rhs.e01 + e01 * _rhs.e11 + e02 * _rhs.e21 + e03 * _rhs.e31,
			e00 * _rhs.e02 + e01 * _rhs.e12 + e02 * _rhs.e22 + e03 * _rhs.e32,
			e00 * _rhs.e03 + e01 * _rhs.e13 + e02 * _rhs.e23 + e03 * _rhs.e33,

			e10 * _rhs.e00 + e11 * _rhs.e10 + e12 * _rhs.e20 + e13 * _rhs.e30,
			e10 * _rhs.e01 + e11 * _rhs.e11 + e12 * _rhs.e21 + e13 * _rhs.e31,
			e10 * _rhs.e02 + e11 * _rhs.e12 + e12 * _rhs.e22 + e13 * _rhs.e32,
			e10 * _rhs.e03 + e11 * _rhs.e13 + e12 * _rhs.e23 + e13 * _rhs.e33,

			e20 * _rhs.e00 + e21 * _rhs.e10 + e22 * _rhs.e20 + e23 * _rhs.e30,
			e20 * _rhs.e01 + e21 * _rhs.e11 + e22 * _rhs.e21 + e23 * _rhs.e31,
			e20 * _rhs.e02 + e21 * _rhs.e12 + e22 * _rhs.e22 + e23 * _rhs.e32,
			e20 * _rhs.e03 + e21 * _rhs.e13 + e22 * _rhs.e23 + e23 * _rhs.e33,

			e30 * _rhs.e00 + e31 * _rhs.e10 + e32 * _rhs.e20 + e33 * _rhs.e30,
			e30 * _rhs.e01 + e31 * _rhs.e11 + e32 * _rhs.e21 + e33 * _rhs.e31,
			e30 * _rhs.e02 + e31 * _rhs.e12 + e32 * _rhs.e22 + e33 * _rhs.e32,
			e30 * _rhs.e03 + e31 * _rhs.e13 + e32 * _rhs.e23 + e33 * _rhs.e33
		);
	}

	template <typename T, MatrixMajor major>
	Mat4<T, major> Mat4<T, major>::operator/(const Mat4& _rhs) const
	{
		return *this * _rhs.GetInversed();
	}


	template <typename T, MatrixMajor major>
	Vec3<T> Mat4<T, major>::operator*(const Vec3<T>& _rhs) const noexcept
	{
		return Vec3<T>(
			e00 * _rhs.x + e01 * _rhs.y + e02 * _rhs.z,
			e10 * _rhs.x + e11 * _rhs.y + e12 * _rhs.z,
			e20 * _rhs.x + e21 * _rhs.y + e22 * _rhs.z
		);
	}

	template <typename T, MatrixMajor major>
	Vec4<T> Mat4<T, major>::operator*(const Vec4<T>& _rhs) const noexcept
	{
		return Vec4<T>(
			e00 * _rhs.x + e01 * _rhs.y + e02 * _rhs.z + e03 * _rhs.w,
			e10 * _rhs.x + e11 * _rhs.y + e12 * _rhs.z + e13 * _rhs.w,
			e20 * _rhs.x + e21 * _rhs.y + e22 * _rhs.z + e23 * _rhs.w,
			e30 * _rhs.x + e31 * _rhs.y + e32 * _rhs.z + e33 * _rhs.w
		);
	}


	template <typename T, MatrixMajor major>
	template<typename TIn>
	Mat4<T, major>& Mat4<T, major>::operator*=(TIn _scale) noexcept
	{
		e00 *= _scale;
		e01 *= _scale;
		e02 *= _scale;
		e03 *= _scale;

		e10 *= _scale;
		e11 *= _scale;
		e12 *= _scale;
		e13 *= _scale;

		e20 *= _scale;
		e21 *= _scale;
		e22 *= _scale;
		e23 *= _scale;

		e30 *= _scale;
		e31 *= _scale;
		e32 *= _scale;
		e33 *= _scale;

		return *this;
	}

	template <typename T, MatrixMajor major>
	template<typename TIn>
	Mat4<T, major>& Mat4<T, major>::operator/=(TIn _scale)
	{
		SA_ASSERT((NotEquals0, _scale), SA.Maths, L"Unscale matrix by 0 (division by 0)!");

		e00 /= _scale;
		e01 /= _scale;
		e02 /= _scale;
		e03 /= _scale;

		e10 /= _scale;
		e11 /= _scale;
		e12 /= _scale;
		e13 /= _scale;

		e20 /= _scale;
		e21 /= _scale;
		e22 /= _scale;
		e23 /= _scale;

		e30 /= _scale;
		e31 /= _scale;
		e32 /= _scale;
		e33 /= _scale;

		return *this;
	}

	template <typename T, MatrixMajor major>
	Mat4<T, major>& Mat4<T, major>::operator+=(const Mat4& _rhs) noexcept
	{
		e00 += _rhs.e00;
		e01 += _rhs.e01;
		e02 += _rhs.e02;
		e03 += _rhs.e03;

		e10 += _rhs.e10;
		e11 += _rhs.e11;
		e12 += _rhs.e12;
		e13 += _rhs.e13;

		e20 += _rhs.e20;
		e21 += _rhs.e21;
		e22 += _rhs.e22;
		e23 += _rhs.e23;

		e30 += _rhs.e30;
		e31 += _rhs.e31;
		e32 += _rhs.e32;
		e33 += _rhs.e33;

		return *this;
	}

	template <typename T, MatrixMajor major>
	Mat4<T, major>& Mat4<T, major>::operator-=(const Mat4& _rhs) noexcept
	{
		e00 -= _rhs.e00;
		e01 -= _rhs.e01;
		e02 -= _rhs.e02;
		e03 -= _rhs.e03;

		e10 -= _rhs.e10;
		e11 -= _rhs.e11;
		e12 -= _rhs.e12;
		e13 -= _rhs.e13;

		e20 -= _rhs.e20;
		e21 -= _rhs.e21;
		e22 -= _rhs.e22;
		e23 -= _rhs.e23;

		e30 -= _rhs.e30;
		e31 -= _rhs.e31;
		e32 -= _rhs.e32;
		e33 -= _rhs.e33;

		return *this;
	}

	template <typename T, MatrixMajor major>
	Mat4<T, major>& Mat4<T, major>::operator*=(const Mat4& _rhs) noexcept
	{
		return *this = *this * _rhs;
	}

	template <typename T, MatrixMajor major>
	Mat4<T, major>& Mat4<T, major>::operator/=(const Mat4& _rhs)
	{
		return *this = *this / _rhs;
	}

//}


	template <typename TIn, typename T, MatrixMajor major>
	Mat4<T, major> operator*(TIn _lhs, const Mat4<T, major>& _rhs) noexcept
	{
		return _rhs * _lhs;
	}

	template <typename TIn, typename T, MatrixMajor major>
	Mat4<T, major> operator/(TIn _lhs, const Mat4<T, major>& _rhs)
	{
		SA_ASSERT((NotEquals0, _rhs.e00), SA.Maths, L"Inverse scale matrix e00 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e01), SA.Maths, L"Inverse scale matrix e01 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e02), SA.Maths, L"Inverse scale matrix e02 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e03), SA.Maths, L"Inverse scale matrix e03 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e10), SA.Maths, L"Inverse scale matrix e10 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e11), SA.Maths, L"Inverse scale matrix e11 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e12), SA.Maths, L"Inverse scale matrix e12 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e13), SA.Maths, L"Inverse scale matrix e13 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e20), SA.Maths, L"Inverse scale matrix e20 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e21), SA.Maths, L"Inverse scale matrix e21 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e22), SA.Maths, L"Inverse scale matrix e22 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e23), SA.Maths, L"Inverse scale matrix e23 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e30), SA.Maths, L"Inverse scale matrix e30 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e31), SA.Maths, L"Inverse scale matrix e31 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e32), SA.Maths, L"Inverse scale matrix e32 == 0!");
		SA_ASSERT((NotEquals0, _rhs.e33), SA.Maths, L"Inverse scale matrix e33 == 0!");

		return Mat4<T, major>(
			_lhs / _rhs.e00, _lhs / _rhs.e01, _lhs / _rhs.e02, _lhs / _rhs.e03,
			_lhs / _rhs.e10, _lhs / _rhs.e11, _lhs / _rhs.e12, _lhs / _rhs.e13,
			_lhs / _rhs.e20, _lhs / _rhs.e21, _lhs / _rhs.e22, _lhs / _rhs.e23,
			_lhs / _rhs.e30, _lhs / _rhs.e31, _lhs / _rhs.e32, _lhs / _rhs.e33
		);
	}


#if SA_LOGGER_IMPL

	template <typename T, MatrixMajor major>
	std::string ToString(const Mat4<T, major>& _m)
	{
		// Keep memory order (Raw / column major).
		const T* const data = _m.Data();

		return
			SA::ToString(data[0]) + ", " +
			SA::ToString(data[1]) + ", " +
			SA::ToString(data[2]) + ", " +
			SA::ToString(data[3]) + ",\n" +

			SA::ToString(data[4]) + ", " +
			SA::ToString(data[5]) + ", " +
			SA::ToString(data[6]) + ", " +
			SA::ToString(data[7]) + ",\n" +

			SA::ToString(data[8]) + ", " +
			SA::ToString(data[9]) + ", " +
			SA::ToString(data[10]) + ", " +
			SA::ToString(data[11]) + ",\n" +

			SA::ToString(data[12]) + ", " +
			SA::ToString(data[13]) + ", " +
			SA::ToString(data[14]) + ", " +
			SA::ToString(data[15]);
	}

#endif
}
