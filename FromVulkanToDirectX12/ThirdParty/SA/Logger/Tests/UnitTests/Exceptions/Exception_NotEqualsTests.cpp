// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <limits>

#include <SA/Collections/Debug>

namespace SA::UT::Exc_NEq
{
	int four = 4;
	int six = 6;

	TEST(Exception, NotEquals_Success)
	{
		EXPECT_NO_THROW(SA_ASSERT((NotEquals, four, six), SA/UnitTests/Exception));
	}

	TEST(Exception, NotEquals_Failure)
	{
		EXPECT_THROW(SA_ASSERT((NotEquals, four, four), SA/UnitTests/Exception, L"Some details!"), Exception_NotEquals);
		EXPECT_THROW(SA_ASSERT((NotEquals, 4.0f, 4.0f + std::numeric_limits<float>::epsilon()), SA/UnitTests/Exception), Exception_NotEquals);
		EXPECT_THROW(SA_ASSERT((NotEquals, 4.0, 4.0 + std::numeric_limits<double>::epsilon()), SA/UnitTests/Exception), Exception_NotEquals);
	}
}
