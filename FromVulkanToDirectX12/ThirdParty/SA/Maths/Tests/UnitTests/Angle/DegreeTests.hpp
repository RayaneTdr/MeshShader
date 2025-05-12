// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_UT_DEGREE_TESTS_GUARD
#define SAPPHIRE_MATHS_UT_DEGREE_TESTS_GUARD

#include <ostream>

#include <gtest/gtest.h>

#include <SA/Maths/Angle/Degree.hpp>

namespace SA
{
	/* Must be declared in SA:: */
	template <typename T>
	std::ostream& operator<<(std::ostream& _os, const Deg<T>& _d)
	{
#if SA_LOGGER_IMPL

		return _os << ToString(_d);

#else

		return _os << std::to_string(_d.Handle()) + "_deg";

#endif

	}
}

/// Google Test typedef helper.
#define DegT Deg<TypeParam>

#endif // GUARD
