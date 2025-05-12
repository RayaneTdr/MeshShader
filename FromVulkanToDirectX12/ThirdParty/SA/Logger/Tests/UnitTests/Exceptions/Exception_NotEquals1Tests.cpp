// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace SA::UT::Exc_NEq1
{
	int one = 1;
	int two = 2;

	TEST(Exception, NotEquals1_Success)
	{
		EXPECT_NO_THROW(SA_ASSERT((NotEquals1, two), SA/UnitTests/Exception));
	}

	TEST(Exception, NotEquals1_Failure)
	{
		EXPECT_THROW(SA_ASSERT((NotEquals1, one), SA/UnitTests/Exception, L"Some details!"), Exception_NotEquals1);
	}

	TEST(Exception, NotEquals1_CatchAny)
	{
		// try catching any not equals exception.

		EXPECT_THROW(SA_ASSERT((NotEquals1, one), SA/UnitTests/Exception), Exception_NotEquals);
	}

	TEST(Exception, NotEquals1Float)
	{
		EXPECT_THROW(SA_ASSERT((NotEquals1, 1.0f + std::numeric_limits<float>::epsilon()),
			SA/UnitTests/Exception), Exception_NotEquals1);
	}

	TEST(Exception, NotEquals1Double)
	{
		EXPECT_THROW(SA_ASSERT((NotEquals1, 1.0 + std::numeric_limits<double>::epsilon()),
			SA/UnitTests/Exception), Exception_NotEquals1);
	}
}
