// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_UT_RADIAN_TESTS_GUARD
#define SAPPHIRE_MATHS_UT_RADIAN_TESTS_GUARD

#include <ostream>

#include <gtest/gtest.h>

#include <SA/Maths/Angle/Radian.hpp>

namespace SA
{
	/* Must be declared in SA:: */
	template <typename T>
	std::ostream& operator<<(std::ostream& _os, const Rad<T>& _r)
	{
#if SA_LOGGER_IMPL

		return _os << ToString(_r);

#else

		return _os << std::to_string(_r.Handle()) + "_rad";

#endif
	}
}

/// Google Test typedef helper.
#define RadT Rad<TypeParam>

#endif // GUARD
