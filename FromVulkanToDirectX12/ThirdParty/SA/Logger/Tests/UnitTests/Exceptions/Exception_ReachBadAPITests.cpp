// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace SA::UT::Exc_ReachBadAPI
{
	TEST(Exception, ReachBadAPI)
	{
		EXPECT_THROW(SA_THROW((ReachBadAPI, MyAPI), SA.UnitTests.Exception), Exception_ReachBadAPI);
		EXPECT_THROW(SA_THROW((QueryBadAPIObject, MyAPI), SA.UnitTests.Exception), Exception_QueryBadAPIObject);
	}
}
