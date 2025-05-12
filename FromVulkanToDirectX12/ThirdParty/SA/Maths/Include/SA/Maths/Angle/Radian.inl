// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

namespace SA
{
	template <typename T>
	constexpr Rad<T>::Rad(T _rad) noexcept : mHandle{ _rad }
	{
	}

	template <typename T>
	template <typename TIn>
	constexpr Rad<T>::Rad(Rad<TIn> _other) noexcept : mHandle{ static_cast<T>(_other.Handle()) }
	{
	}

	template <typename T>
	template <typename TIn>
	constexpr Rad<T>::Rad(Deg<TIn> _deg) noexcept : mHandle{ static_cast<T>(_deg.Handle() * Maths::DegToRad<T>) }
	{
	}


	template <typename T>
	constexpr T Rad<T>::Handle() const noexcept
	{
		return mHandle;
	}

	template <typename T>
	constexpr bool Rad<T>::Equals(Rad<T> _other, T _epsilon) const noexcept
	{
		return Maths::Equals(mHandle, _other.mHandle, _epsilon);
	}


	template <typename T>
	void Rad<T>::Clamp() noexcept
	{
		mHandle = std::fmod(mHandle, Maths::PiX2<T>);

		if (mHandle < -Maths::Pi<T>)
			mHandle += Maths::PiX2<T>;
		else if (mHandle > Maths::Pi<T>)
			mHandle -= Maths::PiX2<T>;
	}


	template <typename T>
	constexpr Rad<T> Rad<T>::operator-() const noexcept
	{
		return -mHandle;
	}

	template <typename T>
	constexpr Rad<T> Rad<T>::operator+(Rad _rhs) const noexcept
	{
		return mHandle + _rhs.mHandle;
	}

	template <typename T>
	constexpr Rad<T> Rad<T>::operator-(Rad _rhs) const noexcept
	{
		return mHandle - _rhs.mHandle;
	}

	template <typename T>
	constexpr Rad<T> Rad<T>::operator*(T _scale) const noexcept
	{
		return Rad(mHandle * _scale);
	}

	template <typename T>
	Rad<T> Rad<T>::operator/(T _scale) const
	{
		SA_ASSERT((NotEquals0, _scale), SA.Maths.Rad, L"Unscale Rad by 0 (division by 0).");

		return Rad(mHandle / _scale);
	}


	template <typename T>
	Rad<T>& Rad<T>::operator+=(Rad _rhs) noexcept
	{
		mHandle += _rhs.mHandle;

		return *this;
	}

	template <typename T>
	Rad<T>& Rad<T>::operator-=(Rad _rhs) noexcept
	{
		mHandle -= _rhs.mHandle;

		return *this;
	}

	template <typename T>
	Rad<T>& Rad<T>::operator*=(T _scale) noexcept
	{
		mHandle *= _scale;

		return *this;
	}

	template <typename T>
	Rad<T>& Rad<T>::operator/=(T _scale)
	{
		SA_ASSERT((NotEquals0, _scale), SA.Maths.Rad, L"Unscale Rad by 0 (division by 0).");

		mHandle /= _scale;

		return *this;
	}


	template <typename T>
	constexpr bool Rad<T>::operator==(Rad<T> _rhs) const noexcept
	{
		return Equals(_rhs);
	}

	template <typename T>
	constexpr bool Rad<T>::operator!=(Rad<T> _rhs) const noexcept
	{
		return !Equals(_rhs);
	}


	template <typename T>
	constexpr Rad<T>::operator T() const noexcept
	{
		return mHandle;
	}


#if SA_LOGGER_IMPL

	template <typename T>
	std::string ToString(const Rad<T>& _r)
	{
		return std::to_string(_r.Handle()) + "_rad";
	}

#endif


	constexpr Radf operator""_rad(unsigned long long _lit) noexcept
	{
		return Radf(static_cast<float>(_lit));
	}

	constexpr Radd operator""_rad(long double _lit) noexcept
	{
		return Radd(static_cast<double>(_lit));
	}
}
