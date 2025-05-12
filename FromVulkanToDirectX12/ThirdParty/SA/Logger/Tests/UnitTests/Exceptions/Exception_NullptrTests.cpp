// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace SA::UT::Exc_Nullptr
{
	TEST(Exception, Nullptr_Success)
	{
		int i = 5;
		EXPECT_NO_THROW(SA_ASSERT((Nullptr, &i), SA/UnitTests/Exception));
	}

	TEST(Exception, Nullptr_Failure)
	{
		EXPECT_THROW(SA_ASSERT((Nullptr, (int*)nullptr), SA/UnitTests/Exception), Exception_Nullptr);
	}
}
