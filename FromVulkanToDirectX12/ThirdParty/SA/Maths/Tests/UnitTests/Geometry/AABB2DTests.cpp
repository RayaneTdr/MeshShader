// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include "AABB2DTests.hpp"

#include <SA/Maths/Geometry/AABB3D.hpp>

namespace SA::UT::AABB2
{
	template <typename T>
	class AABB2DTest : public testing::Test
	{
	};

	using TestTypes = ::testing::Types<float, double>;
	TYPED_TEST_SUITE(AABB2DTest, TestTypes);


	TYPED_TEST(AABB2DTest, Constructors)
	{
		// Default constructor.
		AABB2DT b0;
		EXPECT_EQ(b0.min, Vec2T::Zero);
		EXPECT_EQ(b0.max, Vec2T::Zero);

		// Value constructor.
		const Vec2T b1Min(TypeParam{ 5.23 }, TypeParam{ 34.98 });
		const Vec2T b1Max(TypeParam{ 6.25 }, TypeParam{ 44.21 });

		const AABB2DT b1(b1Min, b1Max);
		EXPECT_EQ(b1.min, b1Min);
		EXPECT_EQ(b1.max, b1Max);


		// From AABB3D
		AABB3D<TypeParam> aabb3D(
			Vec3<TypeParam>(TypeParam{ 5.23 }, TypeParam{ 6.25 }, TypeParam{ 4.21 }),
			Vec3<TypeParam>(TypeParam{ 7.254 }, TypeParam{ 11.24 }, TypeParam{ 7.554 })
		);
		AABB2DT b2 = aabb3D;
		EXPECT_EQ(b2.min, Vec2T(aabb3D.min));
		EXPECT_EQ(b2.max, Vec2T(aabb3D.max));
	}

	TYPED_TEST(AABB2DTest, Equals)
	{
		const AABB2DT b0(
			Vec2T(TypeParam{ 5.23 }, TypeParam{ 34.98 }),
			Vec2T(TypeParam{ 54.25 }, TypeParam{ 68.21 })
		);

		const AABB2DT b1(
			Vec2T(TypeParam{ 7.23 }, TypeParam{ 37.24 }),
			Vec2T(TypeParam{ 30.25 }, TypeParam{ 40.0 })
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

	TYPED_TEST(AABB2DTest, CollisionX)
	{
		// Reference for test.
		const AABB2DT b0(
			Vec2T(TypeParam{ 5.23 }, TypeParam{ 34.98 }),
			Vec2T(TypeParam{ 54.25 }, TypeParam{ 68.21 })
		);


		// No Collision < min.
		const AABB2DT b1(
			Vec2T(TypeParam{ 0.23 }, TypeParam{ 34.98 }),
			Vec2T(TypeParam{ 4.25 }, TypeParam{ 68.21 })
		);

		EXPECT_FALSE(b0.IsCollidingX(b1));


		// No Collision > max.
		const AABB2DT b2(
			Vec2T(TypeParam{ 58.4 }, TypeParam{ 34.98 }),
			Vec2T(TypeParam{ 69.4 }, TypeParam{ 68.21 })
		);

		EXPECT_FALSE(b0.IsCollidingX(b2));


		// Collision.
		const AABB2DT b3(
			Vec2T(TypeParam{ 7.48 }, TypeParam{ 34.98 }),
			Vec2T(TypeParam{ 69.4 }, TypeParam{ 68.21 })
		);

		EXPECT_TRUE(b0.IsCollidingX(b3));
	}

	TYPED_TEST(AABB2DTest, CollisionY)
	{
		// Reference for test.
		const AABB2DT b0(
			Vec2T(TypeParam{ 5.23 }, TypeParam{ 34.98 }),
			Vec2T(TypeParam{ 54.25 }, TypeParam{ 68.21 })
		);


		// No Collision < min.
		const AABB2DT b1(
			Vec2T(TypeParam{ 5.23 }, TypeParam{ 3.42 }),
			Vec2T(TypeParam{ 54.25 }, TypeParam{ 32.4 })
		);

		EXPECT_FALSE(b0.IsCollidingY(b1));


		// No Collision > max.
		const AABB2DT b2(
			Vec2T(TypeParam{ 5.23 }, TypeParam{ 79.2 }),
			Vec2T(TypeParam{ 54.25 }, TypeParam{ 81.24 })
		);

		EXPECT_FALSE(b0.IsCollidingY(b2));


		// Collision.
		const AABB2DT b3(
			Vec2T(TypeParam{ 5.23 }, TypeParam{ 37.98 }),
			Vec2T(TypeParam{ 54.25 }, TypeParam{ 49.21 })
		);

		EXPECT_TRUE(b0.IsCollidingY(b3));
	}

	TYPED_TEST(AABB2DTest, Collision)
	{
		// Reference for test.
		const AABB2DT b0(
			Vec2T(TypeParam{ 5.23 }, TypeParam{ 34.98 }),
			Vec2T(TypeParam{ 54.25 }, TypeParam{ 68.21 })
		);

		// No collision.
		const AABB2DT b1(
			Vec2T(TypeParam{ 1.23 }, TypeParam{ 2.24 }),
			Vec2T(TypeParam{ 4.25 }, TypeParam{ 10.0 })
		);

		EXPECT_FALSE(b0.IsColliding(b1));


		// Collision X only.
		const AABB2DT b2(
			Vec2T(TypeParam{ 7.23 }, TypeParam{ 2.24 }),
			Vec2T(TypeParam{ 30.25 }, TypeParam{ 10.0 })
		);

		EXPECT_TRUE(b0.IsColliding(b2));


		// Collision Y only.
		const AABB2DT b3(
			Vec2T(TypeParam{ 1.23 }, TypeParam{ 37.24 }),
			Vec2T(TypeParam{ 4.25 }, TypeParam{ 40.0 })
		);

		EXPECT_TRUE(b0.IsColliding(b3));


		// Collision X Y.
		const AABB2DT b4(
			Vec2T(TypeParam{ 7.23 }, TypeParam{ 37.24 }),
			Vec2T(TypeParam{ 30.25 }, TypeParam{ 40.0 })
		);

		EXPECT_TRUE(b0.IsColliding(b4));
	}

	TYPED_TEST(AABB2DTest, Geometry)
	{
		const AABB2DT b0(
			Vec2T(TypeParam{ 5 }, TypeParam{ 7 }),
			Vec2T(TypeParam{ 8 }, TypeParam{ 15 })
		);

		EXPECT_EQ(b0.Width(), 3);
		EXPECT_EQ(b0.Height(), 8);
		EXPECT_EQ(b0.Center(), Vec2T(TypeParam{ 6.5 }, TypeParam{ 11 }));
		EXPECT_EQ(b0.Area(), 24);
	}

	TYPED_TEST(AABB2DTest, Merge)
	{
		const AABB2DT b0(
			Vec2T(TypeParam{ 5 }, TypeParam{ 7 }),
			Vec2T(TypeParam{ 8 }, TypeParam{ 15 })
		);

		const AABB2DT b1(
			Vec2T(TypeParam{ 7 }, TypeParam{ 4 }),
			Vec2T(TypeParam{ 12 }, TypeParam{ 14 })
		);

		const AABB2DT merged = AABB2DT::Merge(b0, b1);
		const AABB2DT cmerged(b0, b1);

		EXPECT_EQ(merged.min, Vec2T(TypeParam{ 5 }, TypeParam{ 4 }));
		EXPECT_EQ(merged.max, Vec2T(TypeParam{ 12 }, TypeParam{ 15 }));
		EXPECT_EQ(cmerged, merged);
	}
}