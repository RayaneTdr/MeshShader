// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Maths/Algorithms/Sqrt.hpp>

namespace SA::UT::Sqrt
{
	template <typename T>
	class SqrtTest : public testing::Test
	{
	};

	using TestTypes = ::testing::Types<float, double>;
	TYPED_TEST_SUITE(SqrtTest, TestTypes);


	TYPED_TEST(SqrtTest, Main)
	{
		EXPECT_EQ(TypeParam{ 0.0 }, Maths::Sqrt(TypeParam{ 0.0 }));
		EXPECT_EQ(TypeParam{ 1.0 }, Maths::Sqrt(TypeParam{ 1.0 }));
		EXPECT_EQ(TypeParam{ 1.4142135623730951 }, Maths::Sqrt(TypeParam{ 2.0 }));
		EXPECT_EQ(TypeParam{ 2.0 }, Maths::Sqrt(TypeParam{ 4.0 }));
		EXPECT_EQ(TypeParam{ 5.0 }, Maths::Sqrt(TypeParam{ 25.0 }));
	}
}
