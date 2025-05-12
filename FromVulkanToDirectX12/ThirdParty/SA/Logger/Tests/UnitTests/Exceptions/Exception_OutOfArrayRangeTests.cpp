// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

#include <array>
#include <vector>
#include <list>

namespace SA::UT::Exc_OOAR
{
	TEST(Exception, OutOfArrayRange_Success)
	{
		const std::array<float, 6> tab{ 1.2f, 3.36f, 45.2f, 78.21f, 6.3f, 11.2f };

		EXPECT_NO_THROW(SA_ASSERT((OutOfArrayRange, 0, tab), SA/UnitTests/Exception));
		EXPECT_NO_THROW(SA_ASSERT((OutOfArrayRange, 1, tab), SA/UnitTests/Exception));
		EXPECT_NO_THROW(SA_ASSERT((OutOfArrayRange, 5, tab), SA/UnitTests/Exception));
		EXPECT_NO_THROW(SA_ASSERT((OutOfArrayRange, 2, tab, 1, 4), SA/UnitTests/Exception));


		const std::vector<float> v{ 1.2f, 3.36f, 45.2f, 78.21f, 6.3f, 11.2f };

		EXPECT_NO_THROW(SA_ASSERT((OutOfArrayRange, 0, v), SA/UnitTests/Exception));
		EXPECT_NO_THROW(SA_ASSERT((OutOfArrayRange, 3, v), SA/UnitTests/Exception));
		EXPECT_NO_THROW(SA_ASSERT((OutOfArrayRange, 5, v), SA/UnitTests/Exception));
		EXPECT_NO_THROW(SA_ASSERT((OutOfArrayRange, 2, v, 1, 4), SA/UnitTests/Exception));


		const std::list<float> l{ 1.2f, 3.36f, 45.2f, 78.21f, 6.3f, 11.2f };

		EXPECT_NO_THROW(SA_ASSERT((OutOfArrayRange, 0, l), SA/UnitTests/Exception));
		EXPECT_NO_THROW(SA_ASSERT((OutOfArrayRange, 2, l), SA/UnitTests/Exception));
		EXPECT_NO_THROW(SA_ASSERT((OutOfArrayRange, 5, l), SA/UnitTests/Exception));
		EXPECT_NO_THROW(SA_ASSERT((OutOfArrayRange, 2, l, 1, 4), SA/UnitTests/Exception));
	}

	TEST(Exception, OutOfArrayRange_Failure)
	{
		const std::vector<float> v{ 1.2f, 3.36f, 45.2f, 78.21f, 6.3f, 11.2f };

		EXPECT_THROW(SA_ASSERT((OutOfArrayRange, 6, v), SA/UnitTests/Exception), Exception_OutOfRange);
		EXPECT_THROW(SA_ASSERT((OutOfArrayRange, 5, v, 1, 4), SA/UnitTests/Exception), Exception_OutOfRange);

		try
		{
			SA_ASSERT((OutOfArrayRange, 5, v, 1, 4), SA/UnitTests/Exception);
		}
		catch (Exception_OutOfRange& _exc)
		{
			EXPECT_EQ(_exc.currIndex, 5u);
			EXPECT_EQ(_exc.minBound, 1u);
			EXPECT_EQ(_exc.maxBound, 4u);
		}


		EXPECT_THROW(SA_ASSERT((OutOfArrayRange, 10, v), SA/UnitTests/Exception), Exception_OutOfRange);

		try
		{
			SA_ASSERT((OutOfArrayRange, 10, v), SA/UnitTests/Exception);
		}
		catch (Exception_OutOfRange& _exc)
		{
			EXPECT_EQ(_exc.currIndex, 10u);
			EXPECT_EQ(_exc.minBound, 0u);
			EXPECT_EQ(_exc.maxBound, 5u);
		}

		const std::vector<float> v1;
		EXPECT_THROW(SA_ASSERT((OutOfArrayRange, 0, v1), SA/UnitTests/Exception), Exception_OutOfRange);
	}
}
