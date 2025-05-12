// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

namespace SA::UT::Exc_OOR
{
	TEST(Exception, OutOfRange_Success)
	{
		SA_ASSERT((OutOfRange, 4, 0, 6), SA/UnitTests/Exception);

		EXPECT_NO_THROW(SA_ASSERT((OutOfRange, 4, 0, 6), SA/UnitTests/Exception));
		EXPECT_NO_THROW(SA_ASSERT((OutOfRange, 6, 0, 6), SA/UnitTests/Exception));
	}

	TEST(Exception, OutOfRange_Failure)
	{
		EXPECT_THROW(SA_ASSERT((OutOfRange, 2, 4, 6), SA/UnitTests/Exception), Exception_OutOfRange);

		try
		{
			SA_ASSERT((OutOfRange, 2, 4, 6), SA/UnitTests/Exception);
		}
		catch (Exception_OutOfRange& _exc)
		{
			EXPECT_EQ(_exc.currIndex, 2u);
			EXPECT_EQ(_exc.minBound, 4u);
			EXPECT_EQ(_exc.maxBound, 6u);
		}


		EXPECT_THROW(SA_ASSERT((OutOfRange, 10, 0, 6), SA/UnitTests/Exception), Exception_OutOfRange);

		try
		{
			SA_ASSERT((OutOfRange, 10, 0, 6), SA/UnitTests/Exception);
		}
		catch (Exception_OutOfRange& _exc)
		{
			EXPECT_EQ(_exc.currIndex, 10u);
			EXPECT_EQ(_exc.minBound, 0u);
			EXPECT_EQ(_exc.maxBound, 6u);
		}
	}
}
