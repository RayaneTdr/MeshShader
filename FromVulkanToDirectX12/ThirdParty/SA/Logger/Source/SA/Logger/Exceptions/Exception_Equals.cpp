// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <Exceptions/Exception_Equals.hpp>

#include <limits>

namespace SA
{
	/// \cond Internal

	namespace Intl
	{
		template <typename T>
		bool NearlyEquals(T _lhs, T _rhs) noexcept
		{
			return (_lhs < _rhs ? _rhs - _lhs : _lhs - _rhs) <= std::numeric_limits<T>::epsilon();
		}
	}

	/// \endcond


	Exception_Equals::Exception_Equals(
		BaseInfo _info,
		float _lhs,
		float _rhs,
		std::wstring _predStr
	) noexcept :
		Exception(std::move(_info),
			Intl::NearlyEquals(_lhs, _rhs),
			std::move(_predStr) + L" => { " + ToWString(_lhs) + L"f == " + ToWString(_rhs)+ L"f }: Values must be equal.")
	{
	}

	Exception_Equals::Exception_Equals(
		BaseInfo _info,
		double _lhs,
		double _rhs,
		std::wstring _predStr
	) noexcept :
		Exception(std::move(_info),
			Intl::NearlyEquals(_lhs, _rhs),
			std::move(_predStr) + L" => { " + ToWString(_lhs) + L"d == " + ToWString(_rhs)+ L"d }: Values must be equal.")
	{
	}
}
