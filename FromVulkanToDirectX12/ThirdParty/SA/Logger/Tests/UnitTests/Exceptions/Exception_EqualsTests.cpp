// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <limits>

#include <SA/Collections/Debug>

namespace SA::UT::Exc_Eq
{
	int four = 4;
	int six = 6;

	TEST(Exception, Equals_Success)
	{
		EXPECT_NO_THROW(SA_ASSERT((Equals, four, four), SA/UnitTests/Exception));
		EXPECT_NO_THROW(SA_ASSERT((Equals, 4.0f, 4.0f + std::numeric_limits<float>::epsilon()), SA/UnitTests/Exception));
		EXPECT_NO_THROW(SA_ASSERT((Equals, 4.0, 4.0 + std::numeric_limits<double>::epsilon()), SA/UnitTests/Exception));
	}

	TEST(Exception, Equals_Failure)
	{
		EXPECT_THROW(SA_ASSERT((Equals, four, six), SA/UnitTests/Exception, L"Some details!"), Exception_Equals);
	}
}
