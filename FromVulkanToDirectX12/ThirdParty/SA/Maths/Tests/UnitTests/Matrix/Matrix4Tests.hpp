// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_UT_MATRIX4_TESTS_GUARD
#define SAPPHIRE_MATHS_UT_MATRIX4_TESTS_GUARD

#include <ostream>

#include <gtest/gtest.h>

#include <SA/Maths/Matrix/Matrix4.hpp>

namespace SA
{
	/* Must be declared in SA:: */
	template <typename T, MatrixMajor major>
	std::ostream& operator<<(std::ostream& _os, const Mat4<T, major>& _m)
	{
#if SA_LOGGER_IMPL

		return _os << ToString(_m);

#else

		// Keep memory order (Raw / column major).
		const T* const data = _m.Data();

		return _os <<
			std::to_string(data[0]) + ", " +
			std::to_string(data[1]) + ", " +
			std::to_string(data[2]) + ", " +
			std::to_string(data[3]) + ",\n" +

			std::to_string(data[4]) + ", " +
			std::to_string(data[5]) + ", " +
			std::to_string(data[6]) + ", " +
			std::to_string(data[7]) + ",\n" +

			std::to_string(data[8]) + ", " +
			std::to_string(data[9]) + ", " +
			std::to_string(data[10]) + ", " +
			std::to_string(data[11]) + ",\n" +

			std::to_string(data[12]) + ", " +
			std::to_string(data[13]) + ", " +
			std::to_string(data[14]) + ", " +
			std::to_string(data[15]);

#endif
	}
}

/// Google Test typedef helper.
#define Mat4T Mat4<typename TypeParam::T, TypeParam::major>

#define EXPECT_MAT4_NEAR(_m1, _m2, eps)\
{\
	auto m1V = (_m1);\
	auto m2V = (_m2);\
\
	EXPECT_NEAR(m1V.e00, m2V.e00, eps);\
	EXPECT_NEAR(m1V.e01, m2V.e01, eps);\
	EXPECT_NEAR(m1V.e02, m2V.e02, eps);\
	EXPECT_NEAR(m1V.e03, m2V.e03, eps);\
	EXPECT_NEAR(m1V.e10, m2V.e10, eps);\
	EXPECT_NEAR(m1V.e11, m2V.e11, eps);\
	EXPECT_NEAR(m1V.e12, m2V.e12, eps);\
	EXPECT_NEAR(m1V.e13, m2V.e13, eps);\
	EXPECT_NEAR(m1V.e20, m2V.e20, eps);\
	EXPECT_NEAR(m1V.e21, m2V.e21, eps);\
	EXPECT_NEAR(m1V.e22, m2V.e22, eps);\
	EXPECT_NEAR(m1V.e23, m2V.e23, eps);\
	EXPECT_NEAR(m1V.e30, m2V.e30, eps);\
	EXPECT_NEAR(m1V.e31, m2V.e31, eps);\
	EXPECT_NEAR(m1V.e32, m2V.e32, eps);\
	EXPECT_NEAR(m1V.e33, m2V.e33, eps);\
}

#endif // GUARD
