// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

namespace SA
{
//{ Constants

	template <typename T>
	const Quat<T> Quat<T>::Zero{ T(0), T(0), T(0), T(0) };

	template <typename T>
	const Quat<T> Quat<T>::Identity{ T(1), T(0), T(0), T(0) };

//}

//{ Constructors

	template <typename T>
	constexpr Quat<T>::Quat(T _w, T _x, T _y, T _z) noexcept :
		w{ _w },
		x{ _x },
		y{ _y },
		z{ _z }
	{
	}

	template <typename T>
	template <typename TIn>
	constexpr Quat<T>::Quat(const Quat<TIn>& _other) noexcept :
		w{ static_cast<T>(_other.w) },
		x{ static_cast<T>(_other.x) },
		y{ static_cast<T>(_other.y) },
		z{ static_cast<T>(_other.z) }
	{
	}

	template <typename T>
	Quat<T>::Quat(Deg<T> _angle, const Vec3<T>& _axis) noexcept
	{
		const Rad<T> halfAngle = _angle / T(2.0);

		w = Maths::Cos(halfAngle);

		SA_WARN(_axis.IsNormalized(), SA.Maths.Quat, L"Axis should be normalized!");

		// Quaternion imaginary axis.
		Vec3<T>& imgAxis = ImgAxis();
		imgAxis = _axis * Maths::Sin(halfAngle);
	}

//}

//{ Equals

	template <typename T>
	constexpr bool Quat<T>::IsZero() const noexcept
	{
		return Maths::Equals0(w) && Maths::Equals0(x) && Maths::Equals0(y) && Maths::Equals0(z);
	}

	template <typename T>
	constexpr bool Quat<T>::IsIdentity() const noexcept
	{
		return Maths::Equals1(w) && Maths::Equals0(x) && Maths::Equals0(y) && Maths::Equals0(z);
	}

	template <typename T>
	constexpr bool Quat<T>::Equals(const Quat& _other, T _threshold) const noexcept
	{
		return Maths::Equals(w, _other.w, _threshold) &&
			Maths::Equals(x, _other.x, _threshold) &&
			Maths::Equals(y, _other.y, _threshold) &&
			Maths::Equals(z, _other.z, _threshold);
	}


	template <typename T>
	constexpr bool Quat<T>::operator==(const Quat<T>& _rhs) const noexcept
	{
		return Equals(_rhs);
	}

	template <typename T>
	constexpr bool Quat<T>::operator!=(const Quat<T>& _rhs) const noexcept
	{
		return !(*this == _rhs);
	}

//}

//{ Accessors

	template <typename T>
	T* Quat<T>::Data() noexcept
	{
		return &w;
	}

	template <typename T>
	const T* Quat<T>::Data() const noexcept
	{
		return &w;
	}


	template <typename T>
	T& Quat<T>::operator[](uint32_t _index)
	{
		SA_ASSERT((OutOfRange, _index, 0u, 3u), SA.Maths);

		return Data()[_index];
	}

	template <typename T>
	T Quat<T>::operator[](uint32_t _index) const
	{
		SA_ASSERT((OutOfRange, _index, 0u, 3u), SA.Maths);

		return Data()[_index];
	}

//}

//{ Length

	template <typename T>
	T Quat<T>::Length() const
	{
		return Maths::Sqrt(SqrLength());
	}

	template <typename T>
	T Quat<T>::SqrLength() const noexcept
	{
		return w * w + x * x + y * y + z * z;
	}


	template <typename T>
	Quat<T>& Quat<T>::Normalize()
	{
		SA_ASSERT((NotEquals, *this, Zero), SA.Maths.Quat, L"Normalize null quaternion!");

		const T norm = Length();

		w /= norm;
		x /= norm;
		y /= norm;
		z /= norm;

		return *this;
	}

	template <typename T>
	Quat<T> Quat<T>::GetNormalized() const
	{
		SA_ASSERT((NotEquals, *this, Zero), SA.Maths.Quat, L"Normalize null quaternion!");

		const T norm = Length();

		return Quat(
			w / norm,
			x / norm,
			y / norm,
			z / norm
		);
	}

	template <typename T>
	bool Quat<T>::IsNormalized() const noexcept
	{
		return Maths::Equals1(SqrLength());
	}

//}

//{ Inverse

	template <typename T>
	Quat<T>& Quat<T>::Inverse() noexcept
	{
		SA_WARN(IsNormalized(), SA.Maths.Quat, L"Quaternion should be normalized!");
		
		// Inverse of normalized quaternion is conjugate.

		x = -x;
		y = -y;
		z = -z;

		return *this;
	}

	template <typename T>
	constexpr Quat<T> Quat<T>::GetInversed() const noexcept
	{
		SA_WARN(IsNormalized(), SA.Maths.Quat, L"Quaternion should be normalized!");

		// Inverse of normalized quaternion is conjugate.

		return Quat(w, -x, -y, -z);
	}

//}

//{ Angle/Axis

	template <typename T>
	Vec3<T>& Quat<T>::ImgAxis() noexcept
	{
		return reinterpret_cast<Vec3<T>&>(x);
	}

	template <typename T>
	const Vec3<T>& Quat<T>::ImgAxis() const noexcept
	{
		return reinterpret_cast<const Vec3<T>&>(x);
	}

	template <typename T>
	constexpr Deg<T> Quat<T>::GetAngle() const noexcept
	{
		return Maths::ACos(w) * 2.0f;
	}

	template <typename T>
	constexpr Vec3<T> Quat<T>::GetAxis() const noexcept
	{
		SA_WARN(IsIdentity(), SA.Maths.Quat, L"Get axis of an idendity quaternion (Vec3::Zero).");

		const Rad<T> halfAngle = Maths::ACos(w);

		return (ImgAxis() / Maths::Sin(halfAngle)).GetNormalized();
	}

//}

//{ Rotate

	template <typename T>
	Quat<T> Quat<T>::Rotate(const Quat<T>& _other) const noexcept
	{
		SA_WARN(IsNormalized(), SA.Maths.Quat, L"Quaternion should be normalized for multiplication. This quaternion is not normalized!");
		SA_WARN(_other.IsNormalized(), SA.Maths.Quat, L"Quaternion should be normalized for multiplication. Other quaternion is not normalized!");

		T resW = w * _other.w - x * _other.x - y * _other.y - z * _other.z;
		T resX = w * _other.x + x * _other.w + y * _other.z - z * _other.y;
		T resY = w * _other.y - x * _other.z + y * _other.w + z * _other.x;
		T resZ = w * _other.z + x * _other.y - y * _other.x + z * _other.w;

		return Quat(resW, resX, resY, resZ);
	}

	template <typename T>
	constexpr Vec3<T> Quat<T>::Rotate(const Vec3<T>& _vec) const noexcept
	{
		SA_WARN(IsNormalized(), SA.Maths.Quat, L"Quaternion should be normalized for multiplication. This quaternion is not normalized!");
		
		// Quaternion-vector multiplication optimization:
		// http://people.csail.mit.edu/bkph/articles/Quaternions.pdf

		// v' = q * p * q-1
		// Pure imaginary optimization:
		// v' = v + q * 2.0f * (q X v) + q * 2.0f * (q X v).
		// v' = v + q * (     A     ) + q * (      A      ).

		const Vec3<T>& imgAxis = ImgAxis();

		// Compute A = 2.0f * (q X v).
		const Vec3<T> A = T(2.0) * Vec3<T>::Cross(imgAxis, _vec);

		return _vec + (w * A) + Vec3<T>::Cross(imgAxis, A);
	}

	template <typename T>
	Quat<T> Quat<T>::UnRotate(const Quat<T>& _other) const noexcept
	{
		return GetInversed().Rotate(_other);
	}

	template <typename T>
	constexpr Vec3<T> Quat<T>::UnRotate(const Vec3<T>& _vec) const noexcept
	{
		return GetInversed().Rotate(_vec);
	}

	template <typename T>
	constexpr Vec3<T> Quat<T>::RightVector() const noexcept
	{
		return Rotate(Vec3<T>::Right);
	}

	template <typename T>
	constexpr Vec3<T> Quat<T>::UpVector() const noexcept
	{
		return Rotate(Vec3<T>::Up);
	}

	template <typename T>
	constexpr Vec3<T> Quat<T>::ForwardVector() const noexcept
	{
		return Rotate(Vec3<T>::Forward);
	}

//}

//{ Euler

	template <typename T>
	Vec3<Deg<T>> Quat<T>::ToEuler() const noexcept
	{
		/**
		*	Pitch, Yaw, Roll principle applied to SA-Maths coordinates system.
		* 
		*	Pitch: X-Axis.
		*	Origin at the center of gravity and is directed to the right.
		*	A positive pitching motion raises the nose of the aircraft and lowers the tail.
		* 
		*	Yaw: -1 * Y-Axis.
		*	Origin at the center of gravity and is directed towards the bottom of the aircraft.
		*	A positive yawing motion moves the nose of the aircraft to the right.
		* 
		*	Roll: Z-Axis.
		*	Origin at the center of gravity and is directed forward, parallel to the fuselage reference line.
		*	A positive rolling motion lifts the left wing and lowers the right wing.
		* 
		*	Source: https://en.wikipedia.org/wiki/Aircraft_principal_axes
		*/

		/**
		*	Pitch, Yaw, Roll formula  applied to SA-Maths coordinates system.
		*	Source: https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles
		*/

		Vec3<Deg<T>> result;

		// Pitch - X axis
		{
			T cosPitch = 1 - 2 * (x * x + y * y);
			const T sinPitch = 2 * (w * x + y * z);

			// Handle floating-point precision.
			if (Maths::Equals0(cosPitch))
				cosPitch = 0.0f;


			result.x = Maths::ATan2(sinPitch, cosPitch);
		}


		// Yaw - Y axis
		{
			T sinYaw = 2 * (w * y - z * x);

			// Handle floating-point precision.
			if (Maths::Equals1(sinYaw))
				sinYaw = 1.0f;


			if (std::abs(sinYaw) > 1) // 90 degrees if out of range.
				result.y = std::copysign(Maths::PiOv4<T> * Maths::RadToDeg<T>, sinYaw);
			else
				result.y = Maths::ASin(sinYaw);
		}


		// Roll - Z axis
		{
			T cosRoll = 1 - 2 * (y * y + z * z);
			const T sinRoll = 2 * (w * z + x * y);

			// Handle floating-point precision.
			if (Maths::Equals0(cosRoll))
				cosRoll = 0.0f;


			result.z = Maths::ATan2(sinRoll, cosRoll);
		}

		return result;
	}

	template <typename T>
	Quat<T> Quat<T>::FromEuler(const Vec3<Deg<T>>& _angles) noexcept
	{
		/**
		*	Pitch, Yaw, Roll principle applied to SA-Maths coordinates system.
		* 
		*	Pitch: X-Axis.
		*	Origin at the center of gravity and is directed to the right.
		*	A positive pitching motion raises the nose of the aircraft and lowers the tail.
		* 
		*	Yaw: -1 * Y-Axis.
		*	Origin at the center of gravity and is directed towards the bottom of the aircraft.
		*	A positive yawing motion moves the nose of the aircraft to the right.
		* 
		*	Roll: Z-Axis.
		*	Origin at the center of gravity and is directed forward, parallel to the fuselage reference line.
		*	A positive rolling motion lifts the left wing and lowers the right wing.
		* 
		*	Source: https://en.wikipedia.org/wiki/Aircraft_principal_axes
		*/

		/**
		*	Pitch, Yaw, Roll formula  applied to SA-Maths coordinates system.
		*	Source: https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles
		*/

		Vec3<Rad<T>> halfRadAngles = Vec3<T>(_angles) * T{ 0.5 } *Maths::DegToRad<T>;

		const T cosPitch = Maths::Cos(halfRadAngles.x);
		const T sinPitch = Maths::Sin(halfRadAngles.x);

		const T cosYaw = Maths::Cos(halfRadAngles.y);
		const T sinYaw = Maths::Sin(halfRadAngles.y);

		const T cosRoll = Maths::Cos(halfRadAngles.z);
		const T sinRoll = Maths::Sin(halfRadAngles.z);

		return Quat(
			cosPitch * cosYaw * cosRoll + sinPitch * sinYaw * sinRoll,
			sinPitch * cosYaw * cosRoll - cosPitch * sinYaw * sinRoll,
			cosPitch * sinYaw * cosRoll + sinPitch * cosYaw * sinRoll,
			cosPitch * cosYaw * sinRoll - sinPitch * sinYaw * cosRoll
		);
	}

//}

//{ Dot

	template <typename T>
	T Quat<T>::Dot(const Quat<T>& _lhs, const Quat& _rhs) noexcept
	{
		return _lhs.w * _rhs.w +
			_lhs.x * _rhs.x +
			_lhs.y * _rhs.y +
			_lhs.z * _rhs.z;
	}

//}

//{ Lerp

	template <typename T>
	Quat<T> Quat<T>::Lerp(const Quat& _start, const Quat& _end, float _alpha)
	{
		SA_WARN(_start.IsNormalized(), SA.Maths.Quat, L"_start quaternion should be normalized!");
		SA_WARN(_end.IsNormalized(), SA.Maths.Quat, L"_end quaternion should be normalized!");

		return Maths::Lerp(_start, _end, _alpha).GetNormalized();
	}

	template <typename T>
	Quat<T> Quat<T>::LerpUnclamped(const Quat& _start, const Quat& _end, float _alpha)
	{
		SA_WARN(_start.IsNormalized(), SA.Maths.Quat, L"_start quaternion should be normalized!");
		SA_WARN(_end.IsNormalized(), SA.Maths.Quat, L"_end quaternion should be normalized!");

		return Maths::LerpUnclamped(_start, _end, _alpha).GetNormalized();
	}

	template <typename T>
	Quat<T> Quat<T>::SLerp(const Quat& _start, const Quat& _end, float _alpha)
	{
		SA_WARN(_start.IsNormalized(), SA.Maths.Quat, L"_start quaternion should be normalized!");
		SA_WARN(_end.IsNormalized(), SA.Maths.Quat, L"_end quaternion should be normalized!");

		return Maths::SLerp(_start, _end, _alpha).GetNormalized();
	}

	template <typename T>
	Quat<T> Quat<T>::SLerpUnclamped(const Quat& _start, const Quat& _end, float _alpha)
	{
		SA_WARN(_start.IsNormalized(), SA.Maths.Quat, L"_start quaternion should be normalized!");
		SA_WARN(_end.IsNormalized(), SA.Maths.Quat, L"_end quaternion should be normalized!");

		return Maths::SLerpUnclamped(_start, _end, _alpha).GetNormalized();
	}

//}

//{ Operators

	template <typename T>
	constexpr Quat<T> Quat<T>::operator-() const noexcept
	{
		return Quat(-w, -x, -y, -z);
	}

	template <typename T>
	Quat<T> Quat<T>::operator*(T _scale) const noexcept
	{
		return Quat(
			w * _scale,
			x * _scale,
			y * _scale,
			z * _scale
		);
	}

	template <typename T>
	Quat<T> Quat<T>::operator/(T _scale) const
	{
		SA_ASSERT((NotEquals0, _scale), SA.Maths.Quat, L"Unscale quaternion by 0 (division by 0)!");

		return Quat(
			w / _scale,
			x / _scale,
			y / _scale,
			z / _scale
		);
	}

	template <typename T>
	Quat<T> Quat<T>::operator+(const Quat<T>& _rhs) const noexcept
	{
		return Quat(
			w + _rhs.w,
			x + _rhs.x,
			y + _rhs.y,
			z + _rhs.z
		);
	}

	template <typename T>
	Quat<T> Quat<T>::operator-(const Quat<T>& _rhs) const noexcept
	{
		return Quat(
			w - _rhs.w,
			x - _rhs.x,
			y - _rhs.y,
			z - _rhs.z
		);
	}

	template <typename T>
	Quat<T> Quat<T>::operator*(const Quat& _rhs) const noexcept
	{
		return Rotate(_rhs);
	}

	template <typename T>
	constexpr Vec3<T> Quat<T>::operator*(const Vec3<T>& _rhs) const noexcept
	{
		return Rotate(_rhs);
	}

	template <typename T>
	Quat<T> Quat<T>::operator/(const Quat& _rhs) const noexcept
	{
		return Rotate(_rhs.GetInversed());
	}

	template <typename T>
	constexpr Vec3<T> Quat<T>::operator/(const Vec3<T>& _rhs) const noexcept
	{
		return UnRotate(_rhs);
	}

	template <typename T>
	constexpr T Quat<T>::operator|(const Quat& _rhs) const noexcept
	{
		return Dot(*this, _rhs);
	}

	template <typename T>
	Quat<T>& Quat<T>::operator*=(T _scale) noexcept
	{
		w *= _scale;
		x *= _scale;
		y *= _scale;
		z *= _scale;

		return *this;
	}

	template <typename T>
	Quat<T>& Quat<T>::operator/=(T _scale)
	{
		SA_ASSERT((NotEquals0, _scale), SA.Maths.Quat, L"Unscale quaternion by 0 (division by 0)!");

		w /= _scale;
		x /= _scale;
		y /= _scale;
		z /= _scale;

		return *this;
	}

	template <typename T>
	Quat<T>& Quat<T>::operator+=(const Quat<T>& _rhs) noexcept
	{
		w += _rhs.w;
		x += _rhs.x;
		y += _rhs.y;
		z += _rhs.z;

		return *this;
	}

	template <typename T>
	Quat<T>& Quat<T>::operator-=(const Quat<T>& _rhs) noexcept
	{
		w -= _rhs.w;
		x -= _rhs.x;
		y -= _rhs.y;
		z -= _rhs.z;

		return *this;
	}

	template <typename T>
	Quat<T>& Quat<T>::operator*=(const Quat& _rhs) noexcept
	{
		return *this = Rotate(_rhs);
	}

	template <typename T>
	Quat<T>& Quat<T>::operator/=(const Quat& _rhs) noexcept
	{
		return *this = Rotate(_rhs.GetInversed());
	}

//}


	template <typename T>
	constexpr Quat<T> operator*(typename std::remove_cv<T>::type _lhs, const Quat<T>& _rhs) noexcept
	{
		return _rhs * _lhs;
	}

	template <typename T>
	Quat<T> operator/(typename std::remove_cv<T>::type _lhs, const Quat<T>& _rhs)
	{
		SA_ASSERT((NotEquals0, _rhs.w), SA.Maths.Quat, L"Inverse scale W by 0!");
		SA_ASSERT((NotEquals0, _rhs.x), SA.Maths.Quat, L"Inverse scale X Axis by 0!");
		SA_ASSERT((NotEquals0, _rhs.y), SA.Maths.Quat, L"Inverse scale Y Axis by 0!");
		SA_ASSERT((NotEquals0, _rhs.z), SA.Maths.Quat, L"Inverse scale Z Axis by 0!");

		return Quat<T>(
			_lhs / _rhs.w,
			_lhs / _rhs.x,
			_lhs / _rhs.y,
			_lhs / _rhs.z
		);
	}

	template <typename T>
	constexpr Vec3<T> operator*(const Vec3<T>& _lhs, const Quat<T>& _rhs) noexcept
	{
		return _rhs * _lhs;
	}

	template <typename T>
	constexpr Vec3<T> operator/(const Vec3<T>& _lhs, const Quat<T>& _rhs) noexcept
	{
		return _rhs / _lhs;
	}


#if SA_LOGGER_IMPL

	template <typename T>
	std::string ToString(const Quat<T>& _q)
	{
		return "W: " + SA::ToString(_q.w) +
			"\tX: " + SA::ToString(_q.x) +
			"\tY: " + SA::ToString(_q.y) +
			"\tZ: " + SA::ToString(_q.z);
	}

#endif
}
