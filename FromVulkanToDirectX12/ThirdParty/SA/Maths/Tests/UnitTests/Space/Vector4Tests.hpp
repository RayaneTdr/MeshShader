// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_UT_VECTOR4_TESTS_GUARD
#define SAPPHIRE_MATHS_UT_VECTOR4_TESTS_GUARD

#include <ostream>

#include <gtest/gtest.h>

#include <SA/Maths/Space/Vector4.hpp>

namespace SA
{
	/* Must be declared in SA:: */
	template <typename T>
	std::ostream& operator<<(std::ostream& _os, const Vec4<T>& _v)
	{
#if SA_LOGGER_IMPL

		return _os << ToString(_v);

#else

		return _os << "X: " + std::to_string(_v.x) +
			"\tY: " + std::to_string(_v.y) +
			"\tZ: " + std::to_string(_v.z) +
			"\tW: " + std::to_string(_v.w);

#endif
	}
}

/// Google Test typedef helper.
#define Vec4T Vec4<TypeParam>

#define EXPECT_VEC4_NEAR(_v1, _v2, eps)\
{\
	auto v1V = (_v1);\
	auto v2V = (_v2);\
\
	EXPECT_NEAR(v1V.x, v2V.x, eps);\
	EXPECT_NEAR(v1V.y, v2V.y, eps);\
	EXPECT_NEAR(v1V.z, v2V.z, eps);\
	EXPECT_NEAR(v1V.w, v2V.w, eps);\
}

#endif // GUARD
