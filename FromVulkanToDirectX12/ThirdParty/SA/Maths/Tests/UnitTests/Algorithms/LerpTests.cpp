// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Maths/Algorithms/Lerp.hpp>

namespace SA::UT::Lerp
{
	template <typename T>
	class LerpTest : public testing::Test
	{
	};

	using TestTypes = ::testing::Types<float, double>;
	TYPED_TEST_SUITE(LerpTest, TestTypes);

	TYPED_TEST(LerpTest, Lerp)
	{
		EXPECT_EQ(Maths::Lerp(TypeParam{ 1.0 }, TypeParam{ 5.0 }, 0.0f), TypeParam{  1.0f });
		EXPECT_EQ(Maths::Lerp(TypeParam{ 1.0 }, TypeParam{ 5.0 }, 1.0f), TypeParam{ 5.0f });
		EXPECT_EQ(Maths::Lerp(TypeParam{ 1.0 }, TypeParam{ 5.0 }, 0.5f), TypeParam{ 3.0f });

		EXPECT_EQ(Maths::Lerp(TypeParam{ 1.0 }, TypeParam{ 5.0 }, -1.0f), TypeParam{ 1.0f });
		EXPECT_EQ(Maths::Lerp(TypeParam{ 1.0 }, TypeParam{ 5.0 }, 2.0f), TypeParam{ 5.0f });
	}

	TYPED_TEST(LerpTest, LerpUnclamped)
	{
		EXPECT_EQ(Maths::LerpUnclamped(TypeParam{ 1.0 }, TypeParam{ 5.0 }, 0.0f), TypeParam{ 1.0 });
		EXPECT_EQ(Maths::LerpUnclamped(TypeParam{ 1.0 }, TypeParam{ 5.0 }, 1.0f), TypeParam{ 5.0 });
		EXPECT_EQ(Maths::LerpUnclamped(TypeParam{ 1.0 }, TypeParam{ 5.0 }, 0.5f), TypeParam{ 3.0 });
		EXPECT_EQ(Maths::LerpUnclamped(TypeParam{ 1.0 }, TypeParam{ 5.0 }, -1.0f), TypeParam{ -3.0 });
		EXPECT_EQ(Maths::LerpUnclamped(TypeParam{ 1.0 }, TypeParam{ 5.0 }, 2.0f), TypeParam{ 9.0 });
	}

	TYPED_TEST(LerpTest, SLerp)
	{
		// TODO: Implement.
	}

	TYPED_TEST(LerpTest, SLerpUnclamped)
	{
		// TODO: Implement.
	}
}
