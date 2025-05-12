// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Maths/Algorithms/Equals.hpp>

namespace SA::UT::Equals
{
	template <typename T>
	class EqualsTest : public testing::Test
	{
	};

	using TestTypes = ::testing::Types<float, double, int32_t, uint32_t>;
	TYPED_TEST_SUITE(EqualsTest, TestTypes);

	TYPED_TEST(EqualsTest, Equals)
	{
		const TypeParam defaultVal = static_cast<TypeParam>(1.26);
		const TypeParam epsilon = std::numeric_limits<TypeParam>::epsilon();

		EXPECT_TRUE(Maths::Equals(defaultVal, defaultVal));
		EXPECT_TRUE(Maths::Equals(defaultVal, defaultVal + epsilon));

		// float / double test only.
		if constexpr (std::is_floating_point_v<TypeParam>)
		{
			EXPECT_FALSE(Maths::Equals(defaultVal, defaultVal + 2 * epsilon));
		}
		
		EXPECT_TRUE(Maths::Equals(defaultVal, defaultVal + 1, TypeParam{ 1 }));
		EXPECT_FALSE(Maths::Equals(defaultVal, defaultVal + 1, epsilon));
	}
}
