// Copyright (c) 2023 Sapphire Development Team. All Rights Reserved.

namespace SA
{
	template <typename T, template <typename> typename... Args>
	template <template <typename> typename Comp>
	constexpr bool Tr<T, Args...>::HasComponent() noexcept
	{
		return std::is_base_of<Comp<T>, Tr<T, Args...>>::value;
	}

//{ Equals

	template <typename T, template <typename> typename... Args>
	template <typename CurrT, typename... PArgs>
	bool Tr<T, Args...>::IsZeroPacked() const noexcept
	{
		bool bPack = true;

		if constexpr(sizeof...(PArgs) != 0)
			bPack = IsZeroPacked<PArgs...>();

		return bPack && CurrT::IsZero();
	}

	template <typename T, template <typename> typename... Args>
	template <typename CurrT, typename... PArgs>
	bool Tr<T, Args...>::IsIdentityPacked() const noexcept
	{
		bool bPack = true;

		if constexpr(sizeof...(PArgs) != 0)
			bPack = IsIdentityPacked<PArgs...>();

		return bPack && CurrT::IsIdentity();
	}

	template <typename T, template <typename> typename... Args>
	template <typename CurrT, typename... PArgs>
	bool Tr<T, Args...>::EqualsPacked(const Tr& _other, T _epsilon) const noexcept
	{
		bool bPack = true;

		if constexpr(sizeof...(PArgs) != 0)
			bPack = EqualsPacked<PArgs...>(_other, _epsilon);

		return bPack && CurrT::Equals(_other, _epsilon);
	}


	template <typename T, template <typename> typename... Args>
	bool Tr<T, Args...>::IsZero() const noexcept
	{
		return IsZeroPacked<Args<T>...>();
	}

	template <typename T, template <typename> typename... Args>
	bool Tr<T, Args...>::IsIdentity() const noexcept
	{
		return IsIdentityPacked<Args<T>...>();
	}


	template <typename T, template <typename> typename... Args>
	bool Tr<T, Args...>::Equals(const Tr& _other, T _epsilon) const noexcept
	{
		return EqualsPacked<Args<T>...>(_other, _epsilon);
	}


	template <typename T, template <typename> typename... Args>
	bool Tr<T, Args...>::operator==(const Tr& _rhs) const noexcept
	{
		return Equals(_rhs);
	}

	template <typename T, template <typename> typename... Args>
	bool Tr<T, Args...>::operator!=(const Tr& _rhs) const noexcept
	{
		return !(*this == _rhs);
	}

//}


//{ Transformation

	template <typename T, template <typename> typename... Args>
	template <typename TrFunc>
	Vec3<T> Tr<T, Args...>::Right(TrFunc _functor) const
	{
		return _functor(*this, Vec3<T>::Right);
	}

	template <typename T, template <typename> typename... Args>
	template <typename TrFunc>
	Vec3<T> Tr<T, Args...>::Up(TrFunc _functor) const
	{
		return _functor(*this, Vec3<T>::Up);
	}

	template <typename T, template <typename> typename... Args>
	template <typename TrFunc>
	Vec3<T> Tr<T, Args...>::Forward(TrFunc _functor) const
	{
		return _functor(*this, Vec3<T>::Forward);
	}


	template <typename T, template <typename> typename... Args>
	template <typename TrFunc>
	Mat4<T> Tr<T, Args...>::Matrix(TrFunc _functor) const noexcept
	{
		return _functor(*this);
	}

//}


//{ Lerp

	template <typename T, template <typename> typename... Args>
	template <typename CurrT, typename... PArgs>
	void Tr<T, Args...>::LerpUnclampedPacked(const Tr& _start, const Tr& _end, float _alpha) noexcept
	{
		((CurrT&)*this) = CurrT::LerpUnclamped(_start, _end, _alpha);

		if constexpr(sizeof...(PArgs) != 0)
			LerpUnclampedPacked<PArgs...>(_start, _end, _alpha);
	}


	template <typename T, template <typename> typename... Args>
	Tr<T, Args...> Tr<T, Args...>::Lerp(const Tr& _start, const Tr& _end, float _alpha) noexcept
	{
		SA_WARN(_alpha >= 0.0f && _alpha <= 1.0f, SA.Maths, (L"Alpha[%1] clamped to range [0, 1]! Use LerpUnclamped if intended instead.", _alpha));

		return LerpUnclamped(_start, _end, std::clamp(_alpha, 0.0f, 1.0f));
	}

	template <typename T, template <typename> typename... Args>
	Tr<T, Args...> Tr<T, Args...>::LerpUnclamped(const Tr& _start, const Tr& _end, float _alpha) noexcept
	{
		Tr res;

		res.LerpUnclampedPacked<Args<T>...>(_start, _end, _alpha);

		return res;
	}

//}


//{ Operators

	template <typename T, template <typename> typename... Args>
	template <typename TrIn, typename CurrT, typename... PArgs>
	void Tr<T, Args...>::MultiplyPacked(const Tr& _lhs, const TrIn& _rhs) noexcept
	{
		((CurrT&)*this) = CurrT::Multiply(_lhs, _rhs);

		if constexpr(sizeof...(PArgs) != 0)
			MultiplyPacked<TrIn, PArgs...>(_lhs, _rhs);
	}

	template <typename T, template <typename> typename... Args>
	template <typename TrIn, typename CurrT, typename... PArgs>
	void Tr<T, Args...>::DividePacked(const Tr& _lhs, const TrIn& _rhs) noexcept
	{
		((CurrT&)*this) = CurrT::Divide(_lhs, _rhs);

		if constexpr(sizeof...(PArgs) != 0)
			DividePacked<TrIn, PArgs...>(_lhs, _rhs);
	}


	template <typename T, template <typename> typename... Args>
	template <template <typename> typename... InArgs>
	Tr<T, Args...> Tr<T, Args...>::operator*(const Tr<T, InArgs...>& _rhs) const
	{
		Tr res;

		res.MultiplyPacked<Tr<T, InArgs...>, Args<T>...>(*this, _rhs);

		return res;
	}
	
	template <typename T, template <typename> typename... Args>
	template <template <typename> typename... InArgs>
	Tr<T, Args...> Tr<T, Args...>::operator/(const Tr<T, InArgs...>& _rhs) const
	{
		Tr res;

		res.DividePacked<Tr<T, InArgs...>, Args<T>...>(*this, _rhs);

		return res;
	}


	template <typename T, template <typename> typename... Args>
	template <template <typename> typename... InArgs>
	Tr<T, Args...>& Tr<T, Args...>::operator*=(const Tr<T, InArgs...>& _rhs)
	{
		return *this = *this * _rhs;
	}

	template <typename T, template <typename> typename... Args>
	template <template <typename> typename... InArgs>
	Tr<T, Args...>& Tr<T, Args...>::operator/=(const Tr<T, InArgs...>& _rhs)
	{
		return *this = *this / _rhs;
	}

//}


//{ Cast

	namespace Intl
	{
		template <typename ThisTrT, typename OutTrT, template <typename> typename CurrT, template <typename> typename... PArgs>
		struct TrTypeCaster
		{
			template <typename ThisT, typename OutT>
			void ApplyCurr(const ThisT& _thisTr, OutT& _outTr)
			{
				if constexpr (std::is_base_of<CurrT<OutTrT>, OutT>::value)
					(CurrT<OutTrT>&)_outTr = (const CurrT<ThisTrT>&)_thisTr;

				if constexpr (sizeof...(PArgs) != 0)
					TrTypeCaster<ThisTrT, OutTrT, PArgs...>().ApplyCurr(_thisTr, _outTr);
			}
		};
	}

	template <typename T, template <typename> typename... Args>
	template <typename TOut, template <typename> typename... ArgsOut>
	Tr<T, Args...>::operator Tr<TOut, ArgsOut...>() const noexcept
	{
		Tr<TOut, ArgsOut...> res;

		Intl::TrTypeCaster<T, TOut, Args...>().ApplyCurr(*this, res);

		return res;
	}

//}


#if SA_LOGGER_IMPL

	template <typename T, template <typename> typename... Args>
	template <typename CurrT, typename... PArgs>
	std::string Tr<T, Args...>::ToStringPacked() const noexcept
	{
		std::string res = CurrT::ToString();

		if constexpr (sizeof...(PArgs) != 0)
		{
			res += "\n\t";
			res += ToStringPacked<PArgs...>();
		}

		return res;
	}

	template <typename T, template <typename> typename... Args>
	std::string Tr<T, Args...>::ToString() const noexcept
	{
		return ToStringPacked<Args<T>...>();
	}


#endif

}
