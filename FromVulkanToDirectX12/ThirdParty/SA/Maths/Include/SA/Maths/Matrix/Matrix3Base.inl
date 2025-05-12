// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

namespace SA::Intl
{
	/// \cond Internal

//{ Row Major

//{ Construcors

	template <typename T>
	constexpr Mat3_Base<T, MatrixMajor::Row>::Mat3_Base(
		T _e00, T _e01, T _e02,
		T _e10, T _e11, T _e12,
		T _e20, T _e21, T _e22
	) noexcept :
		e00{ _e00 }, e01{ _e01 }, e02{ _e02 },
		e10{ _e10 }, e11{ _e11 }, e12{ _e12 },
		e20{ _e20 }, e21{ _e21 }, e22{ _e22 }
	{
	}

//}

//}

//{ Column Major

	template <typename T>
	constexpr Mat3_Base<T, MatrixMajor::Column>::Mat3_Base(
		T _e00, T _e01, T _e02,
		T _e10, T _e11, T _e12,
		T _e20, T _e21, T _e22
	) noexcept :
		e00{ _e00 }, e10{ _e10 }, e20{ _e20 },
		e01{ _e01 }, e11{ _e11 }, e21{ _e21 },
		e02{ _e02 }, e12{ _e12 }, e22{ _e22 }
	{
	}

//}

//}

	///\endcond
}
