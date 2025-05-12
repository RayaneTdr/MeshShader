// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include "RadianTests.hpp"
#include "DegreeTests.hpp"

namespace SA::UT::Radian
{
	template <typename T>
	class RadianTest : public testing::Test
	{
	};

	using TestTypes = ::testing::Types<float, double>;
	TYPED_TEST_SUITE(RadianTest, TestTypes);

	TYPED_TEST(RadianTest, Constructors)
	{
		const RadT r1;
		EXPECT_EQ(r1.Handle(), 0);

		const TypeParam r2_val = TypeParam{ 2.56 };
		const RadT r2 = r2_val;
		EXPECT_EQ(r2.Handle(), r2_val);

		const Deg<TypeParam> d4 = TypeParam{ 180.0 };
		const RadT r4 = d4;
		EXPECT_EQ(r4.Handle(), Maths::Pi<TypeParam>);
	}

	TEST(Radian, CastConstructor)
	{
		const Radd rd1 = 4.23;
		const Radf r1 = rd1;
		EXPECT_EQ(r1.Handle(), 4.23f);

		const Radf rf2 = 6.235f;
		const Radd r2 = rf2;
		EXPECT_EQ(r2.Handle(), double{ 6.235f });
	}

	TYPED_TEST(RadianTest, Equals)
	{
		const RadT r1 = TypeParam{ 1.3 };
		const RadT r2 = TypeParam{ 4.0 };
		const RadT r3 = TypeParam{ 1.3 } + std::numeric_limits<TypeParam>::epsilon();

		EXPECT_FALSE(r1.Equals(r2));
		EXPECT_TRUE(r1.Equals(r1));
		EXPECT_TRUE(r1.Equals(r3));

		EXPECT_FALSE(r1 == r2);
		EXPECT_TRUE(r1 == r1);
		EXPECT_TRUE(r1 == r3);

		EXPECT_TRUE(r1 != r2);
		EXPECT_FALSE(r1 != r1);
		EXPECT_FALSE(r1 != r3);
	}

	TYPED_TEST(RadianTest, Clamp)
	{
		const TypeParam piT = Maths::Pi<TypeParam>;
		const TypeParam baseVal = TypeParam{ 1.26 };
		const TypeParam clampedVal = TypeParam{ 1.8815926535897933 };

		RadT r1 = baseVal;
		r1.Clamp();
		EXPECT_EQ(r1, baseVal);

		RadT r2 = piT + baseVal;
		r2.Clamp();
		EXPECT_EQ(r2, -clampedVal);

		RadT r3 = 3 * piT + baseVal;
		r3.Clamp();
		EXPECT_EQ(r3, -clampedVal);

		RadT r4 = -piT - baseVal;
		r4.Clamp();
		EXPECT_EQ(r4, clampedVal);

		RadT r5 = -3 * piT - baseVal;
		r5.Clamp();
		EXPECT_EQ(r5, clampedVal);
	}

	TYPED_TEST(RadianTest, OperatorSelfMinus)
	{
		const RadT r1 = Maths::Pi<TypeParam>;

		EXPECT_EQ(-r1, -Maths::Pi<TypeParam>);

		// Ensure correct conversion.
		const Deg<TypeParam> d1 = -r1;
		EXPECT_EQ(d1, TypeParam{ -180.0 });
	}

	TYPED_TEST(RadianTest, OperatorPlus)
	{
		const RadT r1 = Maths::PiOv2<TypeParam>;
		const RadT r2 = Maths::PiOv4<TypeParam>;

		EXPECT_EQ(r1 + r2, Maths::PiOv2<TypeParam> +Maths::PiOv4<TypeParam>);

		// Ensure correct conversion.
		const Deg<TypeParam> d1 = r1 + r2;
		EXPECT_EQ(d1, (Maths::PiOv2<TypeParam> +Maths::PiOv4<TypeParam>) * Maths::RadToDeg<TypeParam>);

		RadT r3 = r1;
		r3 += r2;
		EXPECT_EQ(r3, r1 + r2);
	}

	TYPED_TEST(RadianTest, OperatorMinus)
	{
		const RadT r1 = Maths::PiOv2<TypeParam>;
		const RadT r2 = Maths::PiOv4<TypeParam>;

		EXPECT_EQ(r1 - r2, Maths::PiOv2<TypeParam> -Maths::PiOv4<TypeParam>);

		// Ensure correct conversion.
		const Deg<TypeParam> d1 = r1 - r2;
		EXPECT_EQ(d1, (Maths::PiOv2<TypeParam> -Maths::PiOv4<TypeParam>) * Maths::RadToDeg<TypeParam>);

		RadT r3 = r1;
		r3 -= r2;
		EXPECT_EQ(r3, r1 - r2);
	}

	TYPED_TEST(RadianTest, OperatorScale)
	{
		const RadT r1 = Maths::PiOv2<TypeParam>;

		EXPECT_EQ(r1 * 2, Maths::Pi<TypeParam>);

		// Ensure correct conversion.
		const Deg<TypeParam> d1 = r1 * 2;
		EXPECT_EQ(d1, TypeParam{ 180.0 });

		RadT r3 = r1;
		r3 *= 2;
		EXPECT_EQ(r3, r1 * 2);
	}

	TYPED_TEST(RadianTest, OperatorUnScale)
	{
		const RadT r1 = Maths::Pi<TypeParam>;

		EXPECT_EQ(r1 / 2, Maths::PiOv2<TypeParam>);

		// Ensure correct conversion.
		const Deg<TypeParam> d1 = r1 / 2;
		EXPECT_EQ(d1, TypeParam{ 90.0 });

		RadT r3 = r1;
		r3 /= 2;
		EXPECT_EQ(r3, r1 / 2);
	}

	TYPED_TEST(RadianTest, OperatorCast)
	{
		const TypeParam val = TypeParam{ 92.2155 };
		const RadT r1 = val;

		EXPECT_EQ(static_cast<TypeParam>(r1), val);
	}

	TEST(Radian, Literals)
	{
		const Radf r1 = 4_rad;
		EXPECT_EQ(r1.Handle(), 4.0f);

		const Radd r2 = 1.3_rad;
		EXPECT_EQ(r2.Handle(), 1.3);
	}
}
