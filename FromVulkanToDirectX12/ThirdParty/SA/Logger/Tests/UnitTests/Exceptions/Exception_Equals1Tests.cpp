// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace SA::UT::Exc_Eq1
{
	int one = 1;
	int two = 2;

	TEST(Exception, Equals1_Success)
	{
		EXPECT_NO_THROW(SA_ASSERT((Equals1, one), SA/UnitTests/Exception));
	}

	TEST(Exception, Equals1_Failure)
	{
		EXPECT_THROW(SA_ASSERT((Equals1, two), SA/UnitTests/Exception, L"Some details!"), Exception_Equals1);
	}

	TEST(Exception, Equals1_CatchAny)
	{
		// try catching any equals exception.

		EXPECT_THROW(SA_ASSERT((Equals1, two), SA/UnitTests/Exception), Exception_Equals);
	}

	TEST(Exception, Equals1Float)
	{
		EXPECT_NO_THROW(SA_ASSERT((Equals1, 1.0f + std::numeric_limits<float>::epsilon()), SA/UnitTests/Exception));
	}

	TEST(Exception, Equals1Double)
	{
		EXPECT_NO_THROW(SA_ASSERT((Equals1, 1.0 + std::numeric_limits<double>::epsilon()), SA/UnitTests/Exception));
	}
}
