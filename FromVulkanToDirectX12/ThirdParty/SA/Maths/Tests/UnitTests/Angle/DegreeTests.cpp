// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include "DegreeTests.hpp"
#include "RadianTests.hpp"

namespace SA::UT::Degree
{
	#define DegT Deg<TypeParam>

	template <typename T>
	class DegreeTest : public testing::Test
	{
	};

	using TestTypes = ::testing::Types<float, double>;
	TYPED_TEST_SUITE(DegreeTest, TestTypes);

	TYPED_TEST(DegreeTest, Constructors)
	{
		// Default constructor.
		const DegT d1;
		EXPECT_EQ(d1.Handle(), 0);

		// Value constructor.
		const TypeParam d2_val = TypeParam{ 2.56 };
		const DegT d2 = d2_val;
		EXPECT_EQ(d2.Handle(), d2_val);

		// Radian constructor.
		const RadT r4 = Maths::Pi<TypeParam>;
		const DegT d4 = r4;
		EXPECT_EQ(d4.Handle(), 180);


		// Value cast constructor.
		const Deg<int> d5 = 4;
		DegT d6(d5);
		EXPECT_EQ(d6.Handle(), 4);
	}

	TYPED_TEST(DegreeTest, Equals)
	{
		const DegT d1 = TypeParam{ 1.3 };
		const DegT d2 = TypeParam{ 4.0 };
		const DegT d3 = TypeParam{ 1.3 } + std::numeric_limits<TypeParam>::epsilon();

		EXPECT_FALSE(d1.Equals(d2));
		EXPECT_TRUE(d1.Equals(d1));
		EXPECT_TRUE(d1.Equals(d3));

		EXPECT_FALSE(d1 == d2);
		EXPECT_TRUE(d1 == d1);
		EXPECT_TRUE(d1 == d3);

		EXPECT_TRUE(d1 != d2);
		EXPECT_FALSE(d1 != d1);
		EXPECT_FALSE(d1 != d3);
	}

	TYPED_TEST(DegreeTest, Clamp)
	{
		const TypeParam d1_val = TypeParam{ 10.0 };
		DegT d1 = d1_val;
		d1.Clamp();
		EXPECT_EQ(d1, d1_val);

		const TypeParam d2_val = TypeParam{ 310.0 };
		const TypeParam d2_clampedVal = TypeParam{ -50.0 };
		DegT d2 = d2_val;
		d2.Clamp();
		EXPECT_EQ(d2, d2_clampedVal);

		const TypeParam d3_val = TypeParam{ 670.0 };
		const TypeParam d3_clampedVal = TypeParam{ -50.0 };
		DegT d3 = d3_val;
		d3.Clamp();
		EXPECT_EQ(d3, d3_clampedVal);

		const TypeParam d4_val = TypeParam{ -200.0 };
		const TypeParam d4_clampedVal = TypeParam{ 160.0 };
		DegT d4 = d4_val;
		d4.Clamp();
		EXPECT_EQ(d4, d4_clampedVal);

		const TypeParam d5_val = TypeParam{ -560.0 };
		const TypeParam d5_clampedVal = TypeParam{ 160.0 };
		DegT d5 = d5_val;
		d5.Clamp();
		EXPECT_EQ(d5, d5_clampedVal);
	}

	TYPED_TEST(DegreeTest, OperatorSelfMinus)
	{
		const DegT d1 = TypeParam{ 180.0 };

		EXPECT_EQ(-d1, TypeParam{ -180.0 });

		// Ensure correct conversion.
		const RadT r1 = -d1;
		EXPECT_EQ(r1, -Maths::Pi<TypeParam>);
	}

	TYPED_TEST(DegreeTest, OperatorPlus)
	{
		const DegT d1 = TypeParam{ 160.0 };
		const DegT d2 = TypeParam{ 20.0 };

		EXPECT_EQ(d1 + d2, TypeParam{ 180.0 });

		// Ensure correct conversion.
		const RadT r1 = d1 + d2;
		EXPECT_EQ(r1, Maths::Pi<TypeParam>);

		DegT d3 = d1;
		d3 += d2;
		EXPECT_EQ(d3, d1 + d2);
	}

	TYPED_TEST(DegreeTest, OperatorMinus)
	{
		const DegT d1 = TypeParam{ 200.0 };
		const DegT d2 = TypeParam{ 20.0 };

		EXPECT_EQ(d1 - d2, TypeParam{ 180.0 });

		// Ensure correct conversion.
		const RadT r1 = d1 - d2;
		EXPECT_EQ(r1, Maths::Pi<TypeParam>);

		DegT d3 = d1;
		d3 -= d2;
		EXPECT_EQ(d3, d1 - d2);
	}

	TYPED_TEST(DegreeTest, OperatorScale)
	{
		const DegT d1 = TypeParam{ 90.0 };

		EXPECT_EQ(d1 * 2, TypeParam{ 180.0 });

		// Ensure correct conversion.
		const RadT r1 = d1 * 2;
		EXPECT_EQ(r1, Maths::Pi<TypeParam>);

		DegT d3 = d1;
		d3 *= 2;
		EXPECT_EQ(d3, d1 * 2);
	}

	TYPED_TEST(DegreeTest, OperatorUnScale)
	{
		const DegT d1 = TypeParam{ 180.0 };

		EXPECT_EQ(d1 / 2, TypeParam{ 90.0 });

		// Ensure correct conversion.
		const RadT r1 = d1 / 2;
		EXPECT_EQ(r1, Maths::PiOv2<TypeParam>);

		DegT d3 = d1;
		d3 /= 2;
		EXPECT_EQ(d3, d1 / 2);
	}

	TYPED_TEST(DegreeTest, OperatorCast)
	{
		const TypeParam val = TypeParam{ 92.2155 };
		const DegT d1 = val;

		EXPECT_EQ(static_cast<TypeParam>(d1), val);
	}

	TEST(Degree, Literals)
	{
		const Degf d1 = 4_deg;
		EXPECT_EQ(d1.Handle(), 4.0f);

		const Degd d2 = 1.3_deg;
		EXPECT_EQ(d2.Handle(), 1.3);
	}
}
