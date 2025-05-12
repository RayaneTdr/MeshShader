// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include "Vector4Tests.hpp"

#include <SA/Maths/Space/Vector2.hpp>
#include <SA/Maths/Space/Vector3.hpp>

namespace SA::UT::Vector4
{
	template <typename T>
	class Vector4Test : public testing::Test
	{
	};

	using TestTypes = ::testing::Types<float, double>;
	TYPED_TEST_SUITE(Vector4Test, TestTypes);

	TYPED_TEST(Vector4Test, Constructors)
	{
		// Default constructor.
		const Vec4T v0;
		EXPECT_EQ(v0.x, 0);
		EXPECT_EQ(v0.y, 0);
		EXPECT_EQ(v0.z, 0);
		EXPECT_EQ(v0.w, 0);


		// Value constructor.
		const TypeParam v1X = TypeParam{ 5.23 };
		const TypeParam v1Y = TypeParam{ 9.487 };
		const TypeParam v1Z = TypeParam{ 63.25 };
		const TypeParam v1W = TypeParam{ 99.21 };
		const Vec4T v1(v1X, v1Y, v1Z, v1W);

		EXPECT_EQ(v1.x, v1X);
		EXPECT_EQ(v1.y, v1Y);
		EXPECT_EQ(v1.z, v1Z);
		EXPECT_EQ(v1.w, v1W);


		// Scale constructor.
		const TypeParam v2S = TypeParam{ 31.285 };
		const Vec4T v2_scale(v2S);

		EXPECT_EQ(v2_scale.x, v2S);
		EXPECT_EQ(v2_scale.y, v2S);
		EXPECT_EQ(v2_scale.z, v2S);
		EXPECT_EQ(v2_scale.w, v2S);


		// Value cast constructor.
		const int32_t v3X = 464;
		const int32_t v3Y = 92;
		const int32_t v3Z = 4;
		const int32_t v3W = 89;
		const Vec4T v3(Vec4i(v3X, v3Y, v3Z, v3W));

		EXPECT_EQ(v3.x, v3X);
		EXPECT_EQ(v3.y, v3Y);
		EXPECT_EQ(v3.z, v3Z);
		EXPECT_EQ(v3.w, v3W);


		// Copy constructor.
		const Vec4T v4(v1);

		EXPECT_EQ(v4.x, v1.x);
		EXPECT_EQ(v4.y, v1.y);
		EXPECT_EQ(v4.z, v1.z);
		EXPECT_EQ(v4.w, v1.w);


		// From Vec2.
		const Vec2<TypeParam> v5(TypeParam{ 12.48 }, TypeParam{ 1.2358 });

		const TypeParam v6Z = TypeParam{ 4.26 };
		const TypeParam v6W = TypeParam{ 6.324 };
		const Vec4T v6(v5, v6Z, v6W);
		EXPECT_EQ(v6.x, v5.x);
		EXPECT_EQ(v6.y, v5.y);
		EXPECT_EQ(v6.z, v6Z);
		EXPECT_EQ(v6.w, v6W);


		// From 2 Vec2.
		const Vec2<TypeParam> v7(TypeParam{ 3.221 }, TypeParam{ 896.3 });
		const Vec4T v8(v5, v7);
		EXPECT_EQ(v8.x, v5.x);
		EXPECT_EQ(v8.y, v5.y);
		EXPECT_EQ(v8.z, v7.x);
		EXPECT_EQ(v8.w, v7.y);


		// From Vec3.
		const Vec3<TypeParam> v9(TypeParam{ 996.32 }, TypeParam{ 23.21 }, TypeParam{ 1.236 });

		const TypeParam v9W = TypeParam{ 7.154 };
		const Vec4T v10(v9, v9W);
		EXPECT_EQ(v10.x, v9.x);
		EXPECT_EQ(v10.y, v9.y);
		EXPECT_EQ(v10.z, v9.z);
		EXPECT_EQ(v10.w, v9W);
	}

	TYPED_TEST(Vector4Test, Equals)
	{
		const Vec4T v1(TypeParam{ 56.351 }, TypeParam{ 45.398 }, TypeParam{ 99.25 }, TypeParam{ -63.14 });
		const Vec4T v2(TypeParam{ 145.87 }, TypeParam{ 51.32 }, TypeParam{ -48.2 }, TypeParam{ 10.32 });

		EXPECT_FALSE(v1.IsZero());
		EXPECT_TRUE(Vec4T().IsZero());
		//EXPECT_TRUE(Vec4f::Zero.IsZero());

		EXPECT_TRUE(v1.Equals(v1));
		EXPECT_FALSE(v1.Equals(v2));

		EXPECT_EQ(v1, v1);
		EXPECT_NE(v1, v2);
	}

	TYPED_TEST(Vector4Test, Accessors)
	{
		const Vec4T v1(TypeParam{ 92.25 }, TypeParam{ 7.26 }, TypeParam{ -66.31 }, TypeParam{ 3.21 });

		EXPECT_EQ(v1[0], v1.x);
		EXPECT_EQ(v1[1], v1.y);
		EXPECT_EQ(v1[2], v1.z);
		EXPECT_EQ(v1[3], v1.w);

		EXPECT_EQ(v1.Data(), &v1.x);
		EXPECT_EQ(const_cast<Vec4T&>(v1).Data(), &v1.x);
	}
}
