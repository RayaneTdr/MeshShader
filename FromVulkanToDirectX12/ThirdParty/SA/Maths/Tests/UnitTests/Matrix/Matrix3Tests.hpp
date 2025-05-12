// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_UT_MATRIX3_TESTS_GUARD
#define SAPPHIRE_MATHS_UT_MATRIX3_TESTS_GUARD

#include <ostream>

#include <gtest/gtest.h>

#include <SA/Maths/Matrix/Matrix3.hpp>

namespace SA
{
	/* Must be declared in SA:: */
	template <typename T, MatrixMajor major>
	std::ostream& operator<<(std::ostream& _os, const Mat3<T, major>& _m)
	{
#if SA_LOGGER_IMPL

		return _os << ToString(_m);

#else

		// Keep memory order (Raw / column major).
		const T* const data = _m.Data();

		return _os <<
			std::to_string(data[0]) + ", " +
			std::to_string(data[1]) + ", " +
			std::to_string(data[2]) + ",\n" +

			std::to_string(data[3]) + "," +
			std::to_string(data[4]) + ", " +
			std::to_string(data[5]) + ",\n" +

			std::to_string(data[6]) + ", " +
			std::to_string(data[7]) + "," +
			std::to_string(data[8]);

#endif
	}
}

/// Google Test typedef helper.
#define Mat3T Mat3<typename TypeParam::T, TypeParam::major>

#define EXPECT_MAT3_NEAR(_m1, _m2, eps)\
{\
	auto m1V = (_m1);\
	auto m2V = (_m2);\
\
	EXPECT_NEAR(m1V.e00, m2V.e00, eps);\
	EXPECT_NEAR(m1V.e01, m2V.e01, eps);\
	EXPECT_NEAR(m1V.e02, m2V.e02, eps);\
	EXPECT_NEAR(m1V.e10, m2V.e10, eps);\
	EXPECT_NEAR(m1V.e11, m2V.e11, eps);\
	EXPECT_NEAR(m1V.e12, m2V.e12, eps);\
	EXPECT_NEAR(m1V.e20, m2V.e20, eps);\
	EXPECT_NEAR(m1V.e21, m2V.e21, eps);\
	EXPECT_NEAR(m1V.e22, m2V.e22, eps);\
}

#endif // GUARD
