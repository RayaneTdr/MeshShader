// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace SA::UT::Exc_Eq0
{
	int zero = 0;
	int one = 1;

	TEST(Exception, Equals0_Success)
	{
		EXPECT_NO_THROW(SA_ASSERT((Equals0, zero), SA/UnitTests/Exception));
	}

	TEST(Exception, Equals0_Failure)
	{
		EXPECT_THROW(SA_ASSERT((Equals0, one), SA/UnitTests/Exception, L"Some details!"), Exception_Equals0);
	}

	TEST(Exception, Equals0_CatchAny)
	{
		// try catching any equals exception.

		EXPECT_THROW(SA_ASSERT((Equals0, one), SA/UnitTests/Exception), Exception_Equals);
	}

	TEST(Exception, Equals0Float)
	{
		EXPECT_NO_THROW(SA_ASSERT((Equals0, std::numeric_limits<float>::epsilon()), SA/UnitTests/Exception));
	}

	TEST(Exception, Equals0Double)
	{
		EXPECT_NO_THROW(SA_ASSERT((Equals0, std::numeric_limits<double>::epsilon()), SA/UnitTests/Exception));
	}
}
