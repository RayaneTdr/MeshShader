// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_MATRIX4_BASE_GUARD
#define SAPPHIRE_MATHS_MATRIX4_BASE_GUARD

#include <SA/Maths/Matrix/MatrixMajor.hpp>

namespace SA
{
	/// \cond Internal

	namespace Intl
	{
		template <typename T, MatrixMajor major>
		struct Mat4_Base;

//{ Row Major

		template <typename T>
		struct Mat4_Base<T, MatrixMajor::Row>
		{
			/// Matrix components.
			T e00{ 1 }; T e01{ 0 }; T e02{ 0 }; T e03{ 0 };
			T e10{ 0 }; T e11{ 1 }; T e12{ 0 }; T e13{ 0 };
			T e20{ 0 }; T e21{ 0 }; T e22{ 1 }; T e23{ 0 };
			T e30{ 0 }; T e31{ 0 }; T e32{ 0 }; T e33{ 1 };


//{ Constructors

			/// Default constructor.
			Mat4_Base() = default;

			/// Default value constructor.
			constexpr Mat4_Base(
				T _e00, T _e01, T _e02, T _e03,
				T _e10, T _e11, T _e12, T _e13,
				T _e20, T _e21, T _e22, T _e23,
				T _e30, T _e31, T _e32, T _e33
			) noexcept;

//}
		};

//}

//{ Column Major

		template <typename T>
		struct Mat4_Base<T, MatrixMajor::Column>
		{
			/// Matrix components.
			T e00{ 1 }; T e10{ 0 }; T e20{ 0 }; T e30{ 0 };
			T e01{ 0 }; T e11{ 1 }; T e21{ 0 }; T e31{ 0 };
			T e02{ 0 }; T e12{ 0 }; T e22{ 1 }; T e32{ 0 };
			T e03{ 0 }; T e13{ 0 }; T e23{ 0 }; T e33{ 1 };

//{ Constructors

			/// Default constructor.
			Mat4_Base() = default;

			/// Default value constructor.
			constexpr Mat4_Base(
				T _e00, T _e01, T _e02, T _e03,
				T _e10, T _e11, T _e12, T _e13,
				T _e20, T _e21, T _e22, T _e23,
				T _e30, T _e31, T _e32, T _e33
			) noexcept;

//}
		};
	}

//}

	/// \endcond
}

#include <SA/Maths/Matrix/Matrix4Base.inl>

#endif // GUARD
