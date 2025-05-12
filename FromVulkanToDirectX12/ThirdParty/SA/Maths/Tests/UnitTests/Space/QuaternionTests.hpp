// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_UT_QUATERNION_TESTS_GUARD
#define SAPPHIRE_MATHS_UT_QUATERNION_TESTS_GUARD

#include <ostream>

#include <gtest/gtest.h>

#include <SA/Maths/Space/Quaternion.hpp>

namespace SA
{
	/* Must be declared in SA:: */
	template <typename T>
	std::ostream& operator<<(std::ostream& _os, const Quat<T>& _q)
	{
#if SA_LOGGER_IMPL

		return _os << ToString(_q);

#else

		return _os << "W: " + std::to_string(_q.w) +
			"\tX: " + std::to_string(_q.x) +
			"\tY: " + std::to_string(_q.y) +
			"\tZ: " + std::to_string(_q.z);

#endif
	}
}

/// Google Test typedef helper.
#define QuatT Quat<TypeParam>

#define EXPECT_QUAT_NEAR(_q1, _q2, eps)\
{\
	auto q1V = (_q1);\
	auto q2V = (_q2);\
\
	EXPECT_NEAR(q1V.w, q2V.w, eps);\
	EXPECT_NEAR(q1V.x, q2V.x, eps);\
	EXPECT_NEAR(q1V.y, q2V.y, eps);\
	EXPECT_NEAR(q1V.z, q2V.z, eps);\
}

#endif // GUARD
