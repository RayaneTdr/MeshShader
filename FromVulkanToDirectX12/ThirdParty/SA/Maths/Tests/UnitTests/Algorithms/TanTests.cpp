// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Maths/Angle/Degree.hpp>
#include <SA/Maths/Algorithms/Tan.hpp>

namespace SA::UT::Tan
{
	TEST(Tangent, TangentFloat)
	{
		//EXPECT_EQ(Maths::Tan<float>(Maths::Pi<float>), 0.0f);
		EXPECT_NEAR(Maths::Tan<float>(Maths::Pi<float>), 0.0f, std::numeric_limits<float>::epsilon());
		
		EXPECT_FLOAT_EQ(Maths::Tan<float>(Maths::PiOv3<float>), float{ 1.7320508075688767 });
		EXPECT_FLOAT_EQ(Maths::Tan<float>(-Maths::PiOv6<float>), float{ -0.57735026918962573 });
		EXPECT_FLOAT_EQ(Maths::Tan<float>(40_deg), float{ 0.83909963117727993 });
		EXPECT_FLOAT_EQ(Maths::Tan<float>(0.69813170079773179_rad), float{ 0.83909963117727993 });

		EXPECT_EQ(Maths::ATan(float{ 0.83909963117727993 }), Radf(0.69813170079773179_rad));

		EXPECT_EQ(Maths::ATan2(1.215f, 6.25f), float{ 0.19200519160533092 });
	}

	TEST(Tangent, TangentDouble)
	{
		//EXPECT_EQ(Maths::Tan<double>(Maths::Pi<double>), 0.0);
		EXPECT_NEAR(Maths::Tan<double>(Maths::Pi<double>), 0.0, std::numeric_limits<double>::epsilon());

		EXPECT_EQ(Maths::Tan<double>(Maths::PiOv3<double>), 1.7320508075688767);
		EXPECT_DOUBLE_EQ(Maths::Tan<double>(-Maths::PiOv6<double>), -0.57735026918962573);
		EXPECT_DOUBLE_EQ(Maths::Tan<double>(40_deg), 0.83909963117727993);
		EXPECT_DOUBLE_EQ(Maths::Tan<double>(0.69813170079773179_rad), 0.83909963117727993);
		
		EXPECT_EQ(Maths::ATan(0.83909963117727993), 0.69813170079773179_rad);

		EXPECT_EQ(Maths::ATan2(1.215, 6.25), 0.19200519160533092);
	}
}
