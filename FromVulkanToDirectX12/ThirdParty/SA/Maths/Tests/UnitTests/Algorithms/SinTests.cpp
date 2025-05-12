// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Maths/Angle/Degree.hpp>
#include <SA/Maths/Algorithms/Sin.hpp>

namespace SA::UT::Sin
{
	TEST(Sinus, SinusFloat)
	{
		EXPECT_EQ(Maths::Sin(0.0_rad), 0.0f);

		//EXPET_FLOAT_EQ(Maths::Sin<float>(Maths::Pi<float>), 0.0f);
		EXPECT_NEAR(Maths::Sin<float>(Maths::Pi<float>), 0.0f, std::numeric_limits<float>::epsilon());

		EXPECT_EQ(Maths::Sin<float>(Maths::PiOv2<float>), 1.0f);
		EXPECT_EQ(Maths::Sin<float>(-Maths::PiOv2<float>), -1.0f);

		EXPECT_FLOAT_EQ(Maths::Sin<float>(Degf{ 40 }), float{ 0.64278760968653925 });
		EXPECT_FLOAT_EQ(Maths::Sin<float>(0.69813170079773179_rad), float{ 0.64278760968653925 });
		
		EXPECT_EQ(Maths::ASin(float{ 0.64278760968653925 }), Radf(0.69813170079773179_rad));
	}

	TEST(Sinus, SinusDouble)
	{
		EXPECT_EQ(Maths::Sin(0.0_rad), 0.0);

		//EXPECT_DOUBLE_EQ(Maths::Sin<double>(Maths::Pi<double>), 0.0);
		EXPECT_NEAR(Maths::Sin<double>(Maths::Pi<double>), 0.0, std::numeric_limits<double>::epsilon());

		EXPECT_EQ(Maths::Sin<double>(Maths::PiOv2<double>), 1.0);
		EXPECT_EQ(Maths::Sin<double>(-Maths::PiOv2<double>), -1.0);

		EXPECT_EQ(Maths::Sin<double>(Degd{ 40 }), 0.64278760968653925);
		EXPECT_EQ(Maths::Sin<double>(0.69813170079773179_rad), 0.64278760968653925);
		
		EXPECT_EQ(Maths::ASin(0.64278760968653925), 0.69813170079773179_rad);
	}
}
