// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include "Vector2Tests.hpp"

#include <SA/Maths/Space/Vector3.hpp>

namespace SA::UT::Vector2
{
	template <typename T>
	class Vector2Test : public testing::Test
	{
	};

	using TestTypes = ::testing::Types<float, double>;
	TYPED_TEST_SUITE(Vector2Test, TestTypes);

	TYPED_TEST(Vector2Test, Constants)
	{
		EXPECT_EQ(Vec2T::Zero.x, 0);
		EXPECT_EQ(Vec2T::Zero.y, 0);

		EXPECT_EQ(Vec2T::One.x, 1);
		EXPECT_EQ(Vec2T::One.y, 1);


		// X Axis.
		EXPECT_EQ(Vec2T::Right.x, 1);
		EXPECT_EQ(Vec2T::Right.y, 0);

		EXPECT_EQ(Vec2T::Left.x, -1);
		EXPECT_EQ(Vec2T::Left.y, 0);


		// Y Axis.
		EXPECT_EQ(Vec2T::Up.x, 0);
		EXPECT_EQ(Vec2T::Up.y, 1);

		EXPECT_EQ(Vec2T::Down.x, 0);
		EXPECT_EQ(Vec2T::Down.y, -1);
	}

	TYPED_TEST(Vector2Test, Constructors)
	{
		// Default constructor.
		const Vec2T v0;
		EXPECT_EQ(v0.x, 0);
		EXPECT_EQ(v0.y, 0);


		// Value constructor.
		const TypeParam v1X = TypeParam{ 5.23 };
		const TypeParam v1Y = TypeParam{ 9.487 };
		const Vec2T v1(v1X, v1Y);
		
		EXPECT_EQ(v1.x, v1X);
		EXPECT_EQ(v1.y, v1Y);


		// Scale constructor.
		const TypeParam v2S = TypeParam{ 31.285 };
		const Vec2T v2(v2S);

		EXPECT_EQ(v2.x, v2S);
		EXPECT_EQ(v2.y, v2S);


		// Value cast constructor.
		const int32_t v3X = 464;
		const int32_t v3Y = 92;
		const Vec2T v3(Vec2i(v3X, v3Y));

		EXPECT_EQ(v3.x, v3X);
		EXPECT_EQ(v3.y, v3Y);


		// Copy constructor.
		const Vec2T v4(v1);

		EXPECT_EQ(v4.x, v1.x);
		EXPECT_EQ(v4.y, v1.y);


		// From Vec3.
		const Vec3<TypeParam> v5(TypeParam{ 12.48 }, TypeParam{ 1.2358 }, TypeParam{ 4.26 });

		const Vec2T v6(v5);
		EXPECT_EQ(v6.x, v5.x);
		EXPECT_EQ(v6.y, v5.y);
	}

	TYPED_TEST(Vector2Test, Equals)
	{
		const Vec2T v1(TypeParam{ 56.351 }, TypeParam{ 45.398 });
		const Vec2T v2(TypeParam{ 145.87 }, TypeParam{ 51.32 });

		EXPECT_FALSE(v1.IsZero());
		EXPECT_TRUE(Vec2T::Zero.IsZero());

		EXPECT_TRUE(v1.Equals(v1));
		EXPECT_FALSE(v1.Equals(v2));

		EXPECT_EQ(v1, v1);
		EXPECT_NE(v1, v2);
	}

	TYPED_TEST(Vector2Test, Lenght)
	{
		Vec2T v1(TypeParam{ 12.365 }, TypeParam{ 9.155 });

		const TypeParam vLenSqr = v1.x * v1.x + v1.y * v1.y;
		const TypeParam vLen = Maths::Sqrt(vLenSqr);

		EXPECT_EQ(v1.Length(), vLen);
		EXPECT_EQ(v1.SqrLength(), vLenSqr);

		const Vec2T nV1 = v1.GetNormalized();
		EXPECT_EQ(nV1.x, v1.x / vLen);
		EXPECT_EQ(nV1.y, v1.y / vLen);

		EXPECT_TRUE(nV1.IsNormalized());
		EXPECT_FALSE(v1.IsNormalized());

		EXPECT_EQ(nV1.Length(), 1.0);

		v1.Normalize();
		EXPECT_EQ(v1, nV1);
	}

	TYPED_TEST(Vector2Test, Projection)
	{
		// Reflect
		const Vec2T v1(TypeParam{ 1.0 }, TypeParam{ 1.0f });
		const Vec2T norm(TypeParam{ -1.0 }, TypeParam{ 0.0f });
		const Vec2T refl = Vec2f(TypeParam{ -1.0 }, TypeParam{ 1.0f });

		EXPECT_EQ(v1.Reflect(norm), refl);


		// TODO: Projections.
	}

	TYPED_TEST(Vector2Test, Dot)
	{
		const Vec2T v1(TypeParam{ 5.23 }, TypeParam{ 12.36 });
		const Vec2T v2(TypeParam{ 88.25 }, TypeParam{ 94.01 });

		const TypeParam dot = v1.x * v2.x + v1.y * v2.y;
		
		EXPECT_EQ(Vec2T::Dot(v1, v2), dot);
		EXPECT_EQ(v1 | v2, dot);
	}

	TYPED_TEST(Vector2Test, Cross)
	{
		const Vec2T v1(TypeParam{ 4.26 }, TypeParam{ 463.2 });
		const Vec2T v2(TypeParam{ 63.7 }, TypeParam{ 44.11 });

		const TypeParam cross = v1.x * v2.y - v1.y * v2.x;

		EXPECT_EQ(Vec2T::Cross(v1, v2), cross);
		EXPECT_EQ(v1 ^ v2, cross);
	}

	TYPED_TEST(Vector2Test, Angle)
	{
		const Vec2T v1(TypeParam{ -2.0 }, TypeParam{ 1.0 });
		const Vec2T v2(TypeParam{ 1.0 }, TypeParam{ 2.0 });

		EXPECT_EQ(Vec2T::Angle(v1, v2), Deg<TypeParam>(-90.0));
		EXPECT_EQ(Vec2T::AngleUnsigned(v1, v2), Deg<TypeParam>(90.0));
	}

	TYPED_TEST(Vector2Test, Dist)
	{
		const Vec2T v1(TypeParam{ 45.21 }, TypeParam{ -98.25 });
		const Vec2T v2(TypeParam{ 9.25 }, TypeParam{ 1.265 });

		EXPECT_EQ(Vec2T::Dist(v1, v2), (v1 - v2).Length());
		EXPECT_EQ(Vec2T::SqrDist(v1, v2), (v1 - v2).SqrLength());
	}

	TYPED_TEST(Vector2Test, Dir)
	{
		const Vec2T v1(TypeParam{ -23.65 }, TypeParam{ -11.25 });
		const Vec2T v2(TypeParam{ 400.2 }, TypeParam{ -28.82 });
		const Vec2T vDir = v2 - v1;

		EXPECT_EQ(Vec2T::Dir(v1, v2), vDir);
		EXPECT_EQ(Vec2T::DirN(v1, v2), vDir.GetNormalized());
	}

	TYPED_TEST(Vector2Test, Lerp)
	{
		const Vec2T v1(TypeParam{ 2.0 }, TypeParam{ 2.0 });
		const Vec2T v2(TypeParam{ -2.0 }, TypeParam{ 4.0 });

		const Vec2T lerp_res05(TypeParam{ 0.0 }, TypeParam{ 3.0 });
		EXPECT_EQ(Vec2T::Lerp(v1, v2, 0.5f), lerp_res05);

		EXPECT_EQ(Vec2T::Lerp(v1, v2, 2.0f), v2);


		const Vec2T ulerp_res1(TypeParam{ 6.0 }, TypeParam{ 0.0 });
		EXPECT_EQ(Vec2T::LerpUnclamped(v1, v2, -1.0f), ulerp_res1);
	}

	TYPED_TEST(Vector2Test, SLerp)
	{
		const Vec2T v1(TypeParam{ 2.0 }, TypeParam{ 2.0 });
		const Vec2T v2(TypeParam{ -2.0 }, TypeParam{ 2.0 });

		const Vec2T slerp = Vec2T::SLerp(v1, v2, 0.5f);
		const Vec2T slerp_res05(TypeParam{ 0.0 }, v1.Length());

		EXPECT_VEC2_NEAR(slerp, slerp_res05, 0.000001);
	}

	TYPED_TEST(Vector2Test, Operators)
	{
		const Vec2T v1(TypeParam{ 1.25 }, TypeParam{ 100.3 });

		const Vec2T mv1(-v1.x, -v1.y);
		EXPECT_EQ(-v1, mv1);

		// Scalar Scale.
		const TypeParam scale = TypeParam{ -45.264 };
		const Vec2T sv1(v1.x * scale, v1.y * scale);
		EXPECT_EQ(v1 * scale, sv1);
		EXPECT_EQ(scale * v1, sv1);

		const Vec2T usv1(v1.x / scale, v1.y / scale);
		const Vec2T susv1(scale / v1.x, scale / v1.y);
		EXPECT_EQ(v1 / scale, usv1);
		EXPECT_EQ(scale / v1, susv1);


		// Vec2 operators.
		const Vec2T v2(TypeParam{ 89.25 }, TypeParam{ -44.25 });

		const Vec2T v1pv2(v1.x + v2.x, v1.y + v2.y);
		EXPECT_EQ(v1 + v2, v1pv2);

		const Vec2T v1mv2(v1.x - v2.x, v1.y - v2.y);
		EXPECT_EQ(v1 - v2, v1mv2);

		const Vec2T v1mltv2(v1.x * v2.x, v1.y * v2.y);
		EXPECT_EQ(v1 * v2, v1mltv2);

		const Vec2T v1dv2(v1.x / v2.x, v1.y / v2.y);
		EXPECT_EQ(v1 / v2, v1dv2);


		// op *= scalar.
		Vec2T v3 = v1;
		v3 *= scale;
		EXPECT_EQ(v3, sv1);


		// op /= scalar.
		Vec2T v4 = v1;
		v4 /= scale;
		EXPECT_EQ(v4, usv1);


		// op += Vec2.
		Vec2T v5 = v1;
		v5 += v2;
		EXPECT_EQ(v5, v1pv2);

		// op -= Vec2.
		Vec2T v6 = v1;
		v6 -= v2;
		EXPECT_EQ(v6, v1mv2);


		// op *= Vec2.
		Vec2T v7 = v1;
		v7 *= v2;
		EXPECT_EQ(v7, v1mltv2);


		// op /= Vec2.
		Vec2T v8 = v1;
		v8 /= v2;
		EXPECT_EQ(v8, v1dv2);
	}

	TYPED_TEST(Vector2Test, Accessors)
	{
		const Vec2T v1(TypeParam{ 92.25 }, TypeParam{ 7.26 });

		EXPECT_EQ(v1[0], v1.x);
		EXPECT_EQ(v1[1], v1.y);

		EXPECT_EQ(v1.Data(), &v1.x);
		EXPECT_EQ(const_cast<Vec2T&>(v1).Data(), &v1.x);
	}
}
