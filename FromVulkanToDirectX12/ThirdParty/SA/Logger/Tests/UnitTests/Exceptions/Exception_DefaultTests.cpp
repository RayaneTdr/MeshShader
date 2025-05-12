// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace SA::UT::Exc_Default
{
	bool SuccessFunction() { return true; }
	bool FailureFunction() { return false; }

	TEST(Exception, Default_Success)
	{
		EXPECT_NO_THROW(SA_ASSERT((Default, SuccessFunction()), SA/UnitTests/Exception));
		EXPECT_NO_THROW(SA_ASSERT((Default, SuccessFunction()), SA/UnitTests/Exception,
		("Details about Function %1", "SuccessFunction")));
	}

	TEST(Exception, Default_Failure)
	{
		EXPECT_THROW(SA_ASSERT((Default, FailureFunction()), SA/UnitTests/Exception), Exception_Default);
		EXPECT_THROW(SA_ASSERT((Default, FailureFunction()), SA/UnitTests/Exception,
		("Details about Function %1", "FailureFunction")), Exception_Default);
	}
}
