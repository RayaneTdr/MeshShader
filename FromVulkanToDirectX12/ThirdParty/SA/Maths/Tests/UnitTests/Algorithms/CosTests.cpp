// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Maths/Angle/Degree.hpp>
#include <SA/Maths/Algorithms/Cos.hpp>

namespace SA::UT::Cos
{
	TEST(Cosinus, CosinusFloat)
	{
		EXPECT_EQ(Maths::Cos(0.0_rad), 1.0f);

		EXPECT_EQ(Maths::Cos<float>(Maths::Pi<float>), -1.0f);
		
		//EXPECT_FLOAT_EQ(Maths::Cos<float>(Maths::PiOv2<float>), 0.0);
		EXPECT_NEAR(Maths::Cos<float>(Maths::PiOv2<float>), 0.0f, std::numeric_limits<float>::epsilon());

		EXPECT_EQ(Maths::Cos<float>(Degf{ 40 }), float{ 0.76604444311897801 });
		EXPECT_EQ(Maths::Cos<float>(0.69813170079773179_rad), float{ 0.76604444311897801 });

		EXPECT_EQ(Maths::ACos(float{ 0.76604444311897801 }), Radf(0.69813170079773179_rad));
	}

	TEST(Cosinus, CosinusDouble)
	{
		EXPECT_EQ(Maths::Cos(0.0_rad), 1.0);

		//EXPECT_EQ(Maths::Cos<double>(Maths::Pi<double>), -1.0);
		EXPECT_NEAR(Maths::Cos<double>(Maths::PiOv2<double>), 0.0, std::numeric_limits<double>::epsilon());

		EXPECT_DOUBLE_EQ(Maths::Cos<double>(Degd{ 40 }), 0.76604444311897801);
		EXPECT_DOUBLE_EQ(Maths::Cos<double>(0.69813170079773179_rad), 0.76604444311897801);
		
		EXPECT_EQ(Maths::ACos(0.76604444311897801), 0.69813170079773179_rad);
	}
}
