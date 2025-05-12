// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace SA::UT::Exc_NEq0
{
	int zero = 0;
	int one = 1;

	TEST(Exception, NotEquals0_Success)
	{
		EXPECT_NO_THROW(SA_ASSERT((NotEquals0, one), SA/UnitTests/Exception));
	}

	TEST(Exception, NotEquals0_Failure)
	{
		EXPECT_THROW(SA_ASSERT((NotEquals0, zero), SA/UnitTests/Exception, L"Some details!"), Exception_NotEquals0);
	}

	TEST(Exception, NotEquals0_CatchAny)
	{
		// try catching any not equals exception.

		EXPECT_THROW(SA_ASSERT((NotEquals0, zero), SA/UnitTests/Exception), Exception_NotEquals0);
	}

	TEST(Exception, NotEquals0Float)
	{
		EXPECT_THROW(SA_ASSERT((NotEquals0, std::numeric_limits<float>::epsilon()),
			SA/UnitTests/Exception), Exception_NotEquals0);
	}

	TEST(Exception, NotEquals0Double)
	{
		EXPECT_THROW(SA_ASSERT((NotEquals0, std::numeric_limits<double>::epsilon()),
			SA/UnitTests/Exception), Exception_NotEquals0);
	}
}
