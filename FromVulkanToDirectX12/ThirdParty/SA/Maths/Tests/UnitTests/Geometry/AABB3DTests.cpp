// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include "AABB3DTests.hpp"

#include <SA/Maths/Geometry/AABB2D.hpp>

namespace SA::UT::AABB3
{
	template <typename T>
	class AABB3DTest : public testing::Test
	{
	};

	using TestTypes = ::testing::Types<float, double>;
	TYPED_TEST_SUITE(AABB3DTest, TestTypes);


	TYPED_TEST(AABB3DTest, Constructors)
	{
		// Default constructor.
		AABB3DT b0;
		EXPECT_EQ(b0.min, Vec3T::Zero);
		EXPECT_EQ(b0.max, Vec3T::Zero);

		// Value constructor.
		const Vec3T b1Min(TypeParam{ 5.23 }, TypeParam{ 34.98 }, TypeParam{ 5.24 });
		const Vec3T b1Max(TypeParam{ 6.25 }, TypeParam{ 44.21 }, TypeParam{ 77.62 });

		const AABB3DT b1(b1Min, b1Max);
		EXPECT_EQ(b1.min, b1Min);
		EXPECT_EQ(b1.max, b1Max);


		// From AABB2D
		AABB2D<TypeParam> aabb2D(
			Vec2<TypeParam>(TypeParam{ 5.23 }, TypeParam{ 6.25 }),
			Vec2<TypeParam>(TypeParam{ 7.254 }, TypeParam{ 11.24 })
		);
		AABB3DT b2 = aabb2D;
		EXPECT_EQ(b2.min, Vec3T(aabb2D.min));
		EXPECT_EQ(b2.max, Vec3T(aabb2D.max));
	}

	TYPED_TEST(AABB3DTest, Equals)
	{
		const AABB3DT b0(
			Vec3T(TypeParam{ 5.23 }, TypeParam{ 34.98 }, TypeParam{ 3.24 }),
			Vec3T(TypeParam{ 54.25 }, TypeParam{ 68.21 }, TypeParam{ 44.25 })
		);

		const AABB3DT b1(
			Vec3T(TypeParam{ 7.23 }, TypeParam{ 37.24 }, TypeParam{ 1.25 }),
			Vec3T(TypeParam{ 30.25 }, TypeParam{ 40.0 }, TypeParam{ 9.24 })
		);

		EXPECT_TRUE(b0.Equals(b0));
		EXPECT_FALSE(b0.Equals(b1));

		EXPECT_TRUE(b0 == b0);
		EXPECT_FALSE(b0 != b0);
		EXPECT_EQ(b0, b0);

		EXPECT_FALSE(b0 == b1);
		EXPECT_TRUE(b0 != b1);
		EXPECT_NE(b0, b1);
	}

	TYPED_TEST(AABB3DTest, CollisionX)
	{
		// Reference for test.
		const AABB3DT b0(
			Vec3T(TypeParam{ 5.23 }, TypeParam{ 34.98 }, TypeParam{ 3.211 }),
			Vec3T(TypeParam{ 54.25 }, TypeParam{ 68.21 }, TypeParam{ 63.21 })
		);


		// No Collision < min.
		const AABB3DT b1(
			Vec3T(TypeParam{ 0.23 }, TypeParam{ 34.98 }, TypeParam{ 3.211 }),
			Vec3T(TypeParam{ 4.25 }, TypeParam{ 68.21 }, TypeParam{ 63.21 })
		);

		EXPECT_FALSE(b0.IsCollidingX(b1));


		// No Collision > max.
		const AABB3DT b2(
			Vec3T(TypeParam{ 58.4 }, TypeParam{ 34.98 }, TypeParam{ 3.211 }),
			Vec3T(TypeParam{ 69.4 }, TypeParam{ 68.21 }, TypeParam{ 63.21 })
		);

		EXPECT_FALSE(b0.IsCollidingX(b2));


		// Collision.
		const AABB3DT b3(
			Vec3T(TypeParam{ 7.48 }, TypeParam{ 34.98 }, TypeParam{ 3.211 }),
			Vec3T(TypeParam{ 69.4 }, TypeParam{ 68.21 }, TypeParam{ 63.21 })
		);

		EXPECT_TRUE(b0.IsCollidingX(b3));
	}

	TYPED_TEST(AABB3DTest, CollisionY)
	{
		// Reference for test.
		const AABB3DT b0(
			Vec3T(TypeParam{ 5.23 }, TypeParam{ 34.98 }, TypeParam{ 3.211 }),
			Vec3T(TypeParam{ 54.25 }, TypeParam{ 68.21 }, TypeParam{ 63.21 })
		);


		// No Collision < min.
		const AABB3DT b1(
			Vec3T(TypeParam{ 5.23 }, TypeParam{ 3.42 }, TypeParam{ 3.211 }),
			Vec3T(TypeParam{ 54.25 }, TypeParam{ 32.4 }, TypeParam{ 63.21 })
		);

		EXPECT_FALSE(b0.IsCollidingY(b1));


		// No Collision > max.
		const AABB3DT b2(
			Vec3T(TypeParam{ 5.23 }, TypeParam{ 79.2 }, TypeParam{ 3.211 }),
			Vec3T(TypeParam{ 54.25 }, TypeParam{ 81.24 }, TypeParam{ 63.21 })
		);

		EXPECT_FALSE(b0.IsCollidingY(b2));


		// Collision.
		const AABB3DT b3(
			Vec3T(TypeParam{ 5.23 }, TypeParam{ 37.98 }, TypeParam{ 3.211 }),
			Vec3T(TypeParam{ 54.25 }, TypeParam{ 49.21 }, TypeParam{ 63.21 })
		);

		EXPECT_TRUE(b0.IsCollidingY(b3));
	}

	TYPED_TEST(AABB3DTest, CollisionZ)
	{
		// Reference for test.
		const AABB3DT b0(
			Vec3T(TypeParam{ 5.23 }, TypeParam{ 34.98 }, TypeParam{ 3.211 }),
			Vec3T(TypeParam{ 54.25 }, TypeParam{ 68.21 }, TypeParam{ 63.21 })
		);


		// No Collision < min.
		const AABB3DT b1(
			Vec3T(TypeParam{ 5.23 }, TypeParam{ 34.98 }, TypeParam{ -2.21 }),
			Vec3T(TypeParam{ 54.25 }, TypeParam{ 68.21 }, TypeParam{ 2.25 })
		);

		EXPECT_FALSE(b0.IsCollidingZ(b1));


		// No Collision > max.
		const AABB3DT b2(
			Vec3T(TypeParam{ 5.23 }, TypeParam{ 34.98 }, TypeParam{ 68.24 }),
			Vec3T(TypeParam{ 54.25 }, TypeParam{ 68.21 }, TypeParam{ 215.2 })
		);

		EXPECT_FALSE(b0.IsCollidingZ(b2));


		// Collision.
		const AABB3DT b3(
			Vec3T(TypeParam{ 5.23 }, TypeParam{ 34.98 }, TypeParam{ 6.211 }),
			Vec3T(TypeParam{ 54.25 }, TypeParam{ 68.21 }, TypeParam{ 96.21 })
		);

		EXPECT_TRUE(b0.IsCollidingZ(b3));
	}

	TYPED_TEST(AABB3DTest, Collision)
	{
		// Reference for test.
		const AABB3DT b0(
			Vec3T(TypeParam{ 5.23 }, TypeParam{ 34.98 }, TypeParam{ 3.211 }),
			Vec3T(TypeParam{ 54.25 }, TypeParam{ 68.21 }, TypeParam{ 63.21 })
		);

		// No collision.
		const AABB3DT b1(
			Vec3T(TypeParam{ 1.23 }, TypeParam{ 2.24 }, TypeParam{ -2.41 }),
			Vec3T(TypeParam{ 4.25 }, TypeParam{ 10.0 }, TypeParam{ -1.2 })
		);

		EXPECT_FALSE(b0.IsColliding(b1));


		// Collision X only.
		const AABB3DT b2(
			Vec3T(TypeParam{ 7.23 }, TypeParam{ 2.24 }, TypeParam{ -2.41 }),
			Vec3T(TypeParam{ 30.25 }, TypeParam{ 10.0 }, TypeParam{ -1.2 })
		);

		EXPECT_TRUE(b0.IsColliding(b2));


		// Collision Y only.
		const AABB3DT b3(
			Vec3T(TypeParam{ 1.23 }, TypeParam{ 37.24 }, TypeParam{ -2.41 }),
			Vec3T(TypeParam{ 4.25 }, TypeParam{ 40.0 }, TypeParam{ -1.2 })
		);

		EXPECT_TRUE(b0.IsColliding(b3));
		

		// Collision Z only.
		const AABB3DT b4(
			Vec3T(TypeParam{ 1.23 }, TypeParam{ 2.24 }, TypeParam{ 7.25 }),
			Vec3T(TypeParam{ 4.25 }, TypeParam{ 10.0 }, TypeParam{ 46.2 })
		);

		EXPECT_TRUE(b0.IsColliding(b4));


		// Collision X Y Z.
		const AABB3DT b5(
			Vec3T(TypeParam{ 7.23 }, TypeParam{ 37.24 }, TypeParam{ 7.25 }),
			Vec3T(TypeParam{ 30.25 }, TypeParam{ 40.0 }, TypeParam{ 46.2 })
		);

		EXPECT_TRUE(b0.IsColliding(b5));
	}

	TYPED_TEST(AABB3DTest, Geometry)
	{
		const AABB3DT b0(
			Vec3T(TypeParam{ 5 }, TypeParam{ 7 }, TypeParam{ 9 }),
			Vec3T(TypeParam{ 8 }, TypeParam{ 15 }, TypeParam{ 21 })
		);

		EXPECT_EQ(b0.Width(), 3);
		EXPECT_EQ(b0.Height(), 8);
		EXPECT_EQ(b0.Depth(), 12);
		EXPECT_EQ(b0.Center(), Vec3T(TypeParam{ 6.5 }, TypeParam{ 11 }, TypeParam{ 15 }));
		EXPECT_EQ(b0.Area(), 288);
	}

	TYPED_TEST(AABB3DTest, Merge)
	{
		const AABB3DT b0(
			Vec3T(TypeParam{ 5 }, TypeParam{ 7 }, TypeParam{ -9 }),
			Vec3T(TypeParam{ 8 }, TypeParam{ 15 }, TypeParam{ 21 })
		);

		const AABB3DT b1(
			Vec3T(TypeParam{ 7 }, TypeParam{ 4 }, TypeParam{ 10 }),
			Vec3T(TypeParam{ 12 }, TypeParam{ 14 }, TypeParam{ 70 })
		);

		const AABB3DT merged = AABB3DT::Merge(b0, b1);
		const AABB3DT cmerged(b0, b1);

		EXPECT_EQ(merged.min, Vec3T(TypeParam{ 5 }, TypeParam{ 4 }, TypeParam{ -9 }));
		EXPECT_EQ(merged.max, Vec3T(TypeParam{ 12 }, TypeParam{ 15 }, TypeParam{ 70 }));
		EXPECT_EQ(cmerged, merged);
	}
}