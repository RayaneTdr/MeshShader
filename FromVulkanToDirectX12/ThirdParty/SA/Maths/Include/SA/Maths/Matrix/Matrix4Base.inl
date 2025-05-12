// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

namespace SA::Intl
{
	/// \cond Internal

//{ Row Major

//{ Constructors

	template <typename T>
	constexpr Mat4_Base<T, MatrixMajor::Row>::Mat4_Base(
		T _e00, T _e01, T _e02, T _e03,
		T _e10, T _e11, T _e12, T _e13,
		T _e20, T _e21, T _e22, T _e23,
		T _e30, T _e31, T _e32, T _e33
	) noexcept :
		e00{ _e00 }, e01{ _e01 }, e02{ _e02 }, e03{ _e03 },
		e10{ _e10 }, e11{ _e11 }, e12{ _e12 }, e13{ _e13 },
		e20{ _e20 }, e21{ _e21 }, e22{ _e22 }, e23{ _e23 },
		e30{ _e30 }, e31{ _e31 }, e32{ _e32 }, e33{ _e33 }
	{
	}

//}

//}

//{ Column Major

	template <typename T>
	constexpr Mat4_Base<T, MatrixMajor::Column>::Mat4_Base(
		T _e00, T _e01, T _e02, T _e03,
		T _e10, T _e11, T _e12, T _e13,
		T _e20, T _e21, T _e22, T _e23,
		T _e30, T _e31, T _e32, T _e33
	) noexcept :
		e00{ _e00 }, e10{ _e10 }, e20{ _e20 }, e30{ _e30 },
		e01{ _e01 }, e11{ _e11 }, e21{ _e21 }, e31{ _e31 },
		e02{ _e02 }, e12{ _e12 }, e22{ _e22 }, e32{ _e32 },
		e03{ _e03 }, e13{ _e13 }, e23{ _e23 }, e33{ _e33 }
	{
	}

//}

	/// \endcond
}
