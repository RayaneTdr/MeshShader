// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_AABB3D_TESTS_GUARD
#define SAPPHIRE_MATHS_AABB3D_TESTS_GUARD

#include "../Space/Vector3Tests.hpp"

#include <SA/Maths/Geometry/AABB3D.hpp>

namespace SA
{
	/* Must be declared in SA:: */
	template <typename T>
	std::ostream& operator<<(std::ostream& _os, const AABB3D<T>& _aabb)
	{
#if SA_LOGGER_IMPL

		return _os << ToString(_aabb);

#else

		return _os << "Min {" << _aabb.min << "}\tMax {" << _aabb.max << '}';

#endif
	}
}


/// Google Test typedef helper.
#define AABB3DT AABB3D<TypeParam>

#define EXPECT_AABB3D_NEAR(_aabb1, _aabb2, eps)\
{\
	auto aabb1V = (_aabb1);\
	auto aabb2V = (_aabb1);\
\
	EXPECT_VEC3_NEAR(aabb1V.min, aabb2V.min, eps);\
	EXPECT_VEC3_NEAR(aabb1V.max, aabb2V.max, eps);\
}

#endif // GUARD
