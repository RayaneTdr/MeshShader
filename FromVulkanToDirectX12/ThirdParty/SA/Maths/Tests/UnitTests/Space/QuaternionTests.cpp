// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include "QuaternionTests.hpp"

#include "Vector3Tests.hpp"
#include "../Angle/DegreeTests.hpp"
#include "../Angle/RadianTests.hpp"

namespace SA::UT::Quaternion
{
	template <typename T>
	class QuaternionTest : public testing::Test
	{
	};

	using TestTypes = ::testing::Types<float, double>;
	TYPED_TEST_SUITE(QuaternionTest, TestTypes);

	TYPED_TEST(QuaternionTest, Constants)
	{
		EXPECT_EQ(QuatT::Zero.w, 0);
		EXPECT_EQ(QuatT::Zero.x, 0);
		EXPECT_EQ(QuatT::Zero.y, 0);
		EXPECT_EQ(QuatT::Zero.z, 0);

		EXPECT_EQ(QuatT::Identity.w, 1);
		EXPECT_EQ(QuatT::Identity.x, 0);
		EXPECT_EQ(QuatT::Identity.y, 0);
		EXPECT_EQ(QuatT::Identity.z, 0);
	}

	TYPED_TEST(QuaternionTest, Constructors)
	{
		// Default constructor.
		const QuatT q0;
		EXPECT_EQ(q0.w, 1);
		EXPECT_EQ(q0.x, 0);
		EXPECT_EQ(q0.y, 0);
		EXPECT_EQ(q0.z, 0);


		// Value constructor.
		const TypeParam q1W = TypeParam{ 893.12 };
		const TypeParam q1X = TypeParam{ 5.23 };
		const TypeParam q1Y = TypeParam{ 9.487 };
		const TypeParam q1Z = TypeParam{ 63.25 };
		const QuatT q1(q1W, q1X, q1Y, q1Z);

		EXPECT_EQ(q1.w, q1W);
		EXPECT_EQ(q1.x, q1X);
		EXPECT_EQ(q1.y, q1Y);
		EXPECT_EQ(q1.z, q1Z);


		// Angle axis.
		const DegT q2An = 46_deg;
		const RadT q2HAn = q2An / TypeParam{ 2.0 };

		const Vec3T q2Ax = Vec3T(TypeParam{ 15.01 }, TypeParam{ 0.321 }, TypeParam{ 6.21 }).Normalize();
		const Vec3T res_q2Ax = q2Ax * Maths::Sin(q2HAn);
		const QuatT q2(q2An, q2Ax);

		EXPECT_EQ(q2.w, Maths::Cos(q2HAn));
		EXPECT_EQ(q2.x, res_q2Ax.x);
		EXPECT_EQ(q2.y, res_q2Ax.y);
		EXPECT_EQ(q2.z, res_q2Ax.z);


		// Value cast constructor.
		const int32_t q3W = 63;
		const int32_t q3X = 464;
		const int32_t q3Y = 92;
		const int32_t q3Z = 4;
		const QuatT q3(Quat<int32_t>(q3W, q3X, q3Y, q3Z));

		EXPECT_EQ(q3.w, q3W);
		EXPECT_EQ(q3.x, q3X);
		EXPECT_EQ(q3.y, q3Y);
		EXPECT_EQ(q3.z, q3Z);


		// Copy constructor.
		const QuatT q4(q1);

		EXPECT_EQ(q4.w, q1.w);
		EXPECT_EQ(q4.x, q1.x);
		EXPECT_EQ(q4.y, q1.y);
		EXPECT_EQ(q4.z, q1.z);
	}

	TYPED_TEST(QuaternionTest, Equals)
	{
		const QuatT q1(TypeParam{ 1.235 }, TypeParam{ 56.351 }, TypeParam{ 45.398 }, TypeParam{ 99.25 });
		const QuatT q2(TypeParam{ 63.2 }, TypeParam{ 145.87 }, TypeParam{ 51.32 }, TypeParam{ -48.2 });

		EXPECT_FALSE(q1.IsZero());
		EXPECT_TRUE(QuatT::Zero.IsZero());

		EXPECT_TRUE(q1.Equals(q1));
		EXPECT_FALSE(q1.Equals(q2));

		EXPECT_EQ(q1, q1);
		EXPECT_NE(q1, q2);
	}

	TYPED_TEST(QuaternionTest, Length)
	{
		QuatT q1(TypeParam{ 63.21 }, TypeParam{ 12.365 }, TypeParam{ 9.155 }, TypeParam{ 22.362 });

		const TypeParam qLenSqr = q1.w * q1.w + q1.x * q1.x + q1.y * q1.y + q1.z * q1.z;
		const TypeParam qLen = Maths::Sqrt(qLenSqr);

		EXPECT_EQ(q1.Length(), qLen);
		EXPECT_EQ(q1.SqrLength(), qLenSqr);

		const QuatT nQ1 = q1.GetNormalized();
		EXPECT_EQ(nQ1.w, q1.w / qLen);
		EXPECT_EQ(nQ1.x, q1.x / qLen);
		EXPECT_EQ(nQ1.y, q1.y / qLen);
		EXPECT_EQ(nQ1.z, q1.z / qLen);

		EXPECT_TRUE(nQ1.IsNormalized());
		EXPECT_FALSE(q1.IsNormalized());

		EXPECT_NEAR(nQ1.Length(), 1.0, std::numeric_limits<TypeParam>::epsilon());

		q1.Normalize();
		EXPECT_EQ(q1, nQ1);
	}

	TYPED_TEST(QuaternionTest, Inverse)
	{
		QuatT q1 = QuatT(TypeParam{ 63.21 }, TypeParam{ 12.365 }, TypeParam{ 9.155 }, TypeParam{ 22.362 }).Normalize();
		const QuatT q2 = q1.GetInversed();

		EXPECT_EQ(q2.w, q1.w);
		EXPECT_EQ(q2.x, -q1.x);
		EXPECT_EQ(q2.y, -q1.y);
		EXPECT_EQ(q2.z, -q1.z);

		q1.Inverse();
		EXPECT_EQ(q1, q2);
	}

	TYPED_TEST(QuaternionTest, Rotate)
	{
		/**
		*	Random values from Wolfram Alpha.
		*	https://www.wolframalpha.com/input/?i=Quaternion%2848%2B36.12i-42.1j-3k%29
		*/
		const QuatT q1(
			TypeParam{ 0.65379899684951437 },
			TypeParam{ 0.49198400932684733 },
			TypeParam{ -0.57343602132006610 },
			TypeParam{ -0.040862400050191698 }
		);

		/**
		*	Random values from Wolfram Alpha.
		*	https://www.wolframalpha.com/input/?i=Quaternion%287%2B1.36i-4j-23.2k%29
		*/
		const QuatT q2(
			TypeParam{ 0.28456911695921927 },
			TypeParam{ 0.055287819843885436 },
			TypeParam{ -0.16261099422502870 },
			TypeParam{ -0.94314438937370981 }
		);

		/**
		*	Computed values from Wolfram Alpha.
		*	https://www.wolframalpha.com/input/?i=Quaternion%2848%2B36.12i-42.1j-3k%29*Quaternion%287%2B1.36i-4j-23.2k%29
		*/
		const QuatT q1mltq2(
			TypeParam{ 0.027064135033571496 },
			TypeParam{ 0.71033886691834713 },
			TypeParam{ 0.19225567792515003 },
			TypeParam{ -0.67655301421661274 }
		);
		EXPECT_EQ(q1.Rotate(q2), q1mltq2);

		/**
		*	Computed values from Wolfram Alpha.
		*	https://www.wolframalpha.com/input/?i=Quaternion%2848-36.12i42.1j3k%29*Quaternion%287%2B1.36i-4j-23.2k%29
		*/
		const QuatT q1dq2(
			TypeParam{ 0.34503787137100783 },
			TypeParam{ -0.63804462461448919 },
			TypeParam{ -0.40488548772720184 },
			TypeParam{ -0.55670069709694570 }
		);
		EXPECT_EQ(q1.UnRotate(q2), q1dq2);

		/**
		*	Random values from Wolfram Alpha.
		*	https://www.wolframalpha.com/input/?i=vector+%7B2%2C+-5%2C+4%7D
		*/
		const Vec3T axis(
			TypeParam{ 0.29814198175425533 },
			TypeParam{ -0.74535601236806759 },
			TypeParam{ 0.59628497678745696 }
		);

		/// Precomputed values.
		const Vec3T q1RAxis(
			TypeParam{ 0.010723429759060848 },
			TypeParam{ -0.92185347418970509 },
			TypeParam{ -0.38739021693709924 }
		);
		EXPECT_EQ(q1.Rotate(axis), q1RAxis);

		/// Precomputed values.
		const Vec3T q1URAxis(
			TypeParam{ 0.98459187055002440 },
			TypeParam{ -0.12279218574048728 },
			TypeParam{ 0.12450272112639649 }
		);
		EXPECT_EQ(q1.UnRotate(axis), q1URAxis);

		/// Precomputed values.
		const Vec3T q1RightAxis(
			TypeParam{ 0.33900278742950163 },
			TypeParam{ -0.61767429804632101 },
			TypeParam{ 0.70961649617805012 }
		);
		EXPECT_EQ(q1.RightVector(), q1RightAxis);

		/// Precomputed values.
		const Vec3T q1UpAxis(
			TypeParam{ -0.51081111339960539 },
			TypeParam{ 0.51256399765763738 },
			TypeParam{ 0.69018124774053136 }
		);
		EXPECT_EQ(q1.UpVector(), q1UpAxis);

		/// Precomputed values.
		const Vec3T q1ForwardAxis(
			TypeParam{ -0.79003108580769366 },
			TypeParam{ -0.59645335931504828 },
			TypeParam{ -0.14175427196141333 }
		);
		EXPECT_EQ(q1.ForwardVector(), q1ForwardAxis);
	}

	TYPED_TEST(QuaternionTest, Euler)
	{
		// Pi/2 angle on X Axis.
		const QuatT q1(90.0_deg, Vec3T::Right);
		const Vec3T res_eul1(90, 0, 0);
		const Vec3<DegT> eul1 = q1.ToEuler();
		EXPECT_EQ(Vec3T(eul1), res_eul1);
		EXPECT_EQ(QuatT::FromEuler(eul1), q1);


		// Pi/2 angle on Y Axis.
		const QuatT q2(90.0_deg, Vec3T::Up);
		const Vec3T res_eul2(0, 90, 0);
		const Vec3<DegT> eul2 = q2.ToEuler();
		EXPECT_VEC3_NEAR(Vec3T(eul2), res_eul2, 0.00001);
		EXPECT_EQ(QuatT::FromEuler(eul2), q2);


		// Pi/2 angle on Z Axis.
		const QuatT q3(90.0_deg, Vec3T::Forward);
		const Vec3T res_eul3(0, 0, 90);
		const Vec3<DegT> eul3 = q3.ToEuler();
		EXPECT_EQ(Vec3T(eul3), res_eul3);
		EXPECT_EQ(QuatT::FromEuler(eul3), q3);


		// Pi/2 angle on XY Axis.
		const QuatT q4(90.0_deg, Vec3T(1, 1, 0).Normalize());
		const Vec3T res_eul4(90, 45, 45);
		const Vec3<DegT> eul4 = q4.ToEuler();
		EXPECT_VEC3_NEAR(Vec3T(eul4), res_eul4, 0.00001);
		EXPECT_EQ(QuatT::FromEuler(eul4), q4);


		// Pi/2 angle on XZ Axis.
		const QuatT q5(90.0_deg, Vec3T(1, 0, 1).Normalize());
		const Vec3T res_eul5(54.75f, -30.0f, 54.75f);
		const Vec3<DegT> eul5 = q5.ToEuler();
		EXPECT_VEC3_NEAR(Vec3T(eul5), res_eul5, 0.015);
		EXPECT_QUAT_NEAR(QuatT::FromEuler(eul5), q5, 0.000001);


		// Pi/2 angle on YZ Axis.
		const QuatT q6(90.0_deg, Vec3T(0, 1, 1).Normalize());
		const Vec3T res_eul6(45, 45, 90);
		const Vec3<DegT> eul6 = q6.ToEuler();
		EXPECT_VEC3_NEAR(Vec3T(eul6), res_eul6, 0.00001);
		EXPECT_EQ(QuatT::FromEuler(eul6), q6);


		// Pi/2 angle on XYZ Axis.
		const QuatT q7(90.0_deg, Vec3T(1, 1, 1).Normalize());
		const Vec3T res_eul7(70, 14, 70);
		const Vec3<DegT> eul7 = q7.ToEuler();
		EXPECT_VEC3_NEAR(Vec3T(eul7), res_eul7, 0.15);
		EXPECT_EQ(QuatT::FromEuler(eul7), q7);


		// random angle on random axis.
		const QuatT q8(145.264_deg, Vec3T(3.656f, 1.15f, 7.36f).Normalize());
		const Vec3T res_eul8 = Vec3T(37.84f, -39.26f, 127.20f);
		const Vec3<DegT> eul8 = q8.ToEuler();
		EXPECT_VEC3_NEAR(Vec3T(eul8), res_eul8, 0.01);
		EXPECT_QUAT_NEAR(QuatT::FromEuler(eul8), q8, 0.000001);
	}

	TYPED_TEST(QuaternionTest, Dot)
	{
		const QuatT q1(TypeParam{ 66.25 }, TypeParam{ 5.23 }, TypeParam{ 12.36 }, TypeParam{ -96.31 });
		const QuatT q2(TypeParam{ -7.21 }, TypeParam{ 88.25 }, TypeParam{ 94.01 }, TypeParam{ 1.265 });

		const TypeParam dot = q1.w * q2.w + q1.x * q2.x + q1.y * q2.y + q1.z * q2.z;

		EXPECT_EQ(QuatT::Dot(q1, q2), dot);
		EXPECT_EQ(q1 | q2, dot);
	}

	TYPED_TEST(QuaternionTest, Lerp)
	{
		/**
		*	Random values from Wolfram Alpha.
		*	https://www.wolframalpha.com/input/?i=Quaternion%2848%2C36.12%2C-42.1%2C-3%29
		*/
		const QuatT q1(TypeParam{ 0.653799 }, TypeParam{ 0.491984 }, TypeParam{ -0.573436 }, TypeParam{ -0.0408624 });

		/**
		*	Random values from Wolfram Alpha.
		*	https://www.wolframalpha.com/input/?i=Quaternion%287%2B1.36i-4j-23.2k%29
		*/
		const QuatT q2(TypeParam{ 0.2845691 }, TypeParam{ 0.05528782 }, TypeParam{ -0.162611 }, TypeParam{ -0.9431444 });

		// Precomputed value.
		const QuatT lerp_res05(TypeParam{ 0.5721251 }, TypeParam{ 0.3336728 }, TypeParam{ -0.4487695 }, TypeParam{ -0.5999511 });
		EXPECT_QUAT_NEAR(QuatT::Lerp(q1, q2, 0.5f), lerp_res05, 0.000001);

		EXPECT_QUAT_NEAR(QuatT::Lerp(q1, q2, 2.0f), q2, 0.000001);


		// Precomputed value.
		const QuatT ulerp_res1(TypeParam{ 0.5377033 }, TypeParam{ 0.4881137 }, TypeParam{ -0.517327 }, TypeParam{ 0.4527616 });
		EXPECT_QUAT_NEAR(QuatT::LerpUnclamped(q1, q2, -1.0f), ulerp_res1, 0.000001);

		// Precomputed value.
		const QuatT slerp_res05(TypeParam{ 0.5721251 }, TypeParam{ 0.3336728 }, TypeParam{ -0.4487695 }, TypeParam{ -0.5999511 });
		EXPECT_QUAT_NEAR(QuatT::SLerp(q1, q2, 0.5f), slerp_res05, 0.000001);
	}

	TYPED_TEST(QuaternionTest, Operators)
	{
		const QuatT q1(TypeParam{ 66.25 }, TypeParam{ 5.23 }, TypeParam{ 12.36 }, TypeParam{ -96.31 });

		const QuatT mq1(-q1.w, -q1.x, -q1.y, -q1.z);
		EXPECT_EQ(-q1, mq1);

		// Scalar Scale.
		TypeParam scale = TypeParam{ 56.21 };
		const QuatT sq1(q1.w * scale, q1.x * scale, q1.y * scale, q1.z * scale);
		EXPECT_EQ(q1 * scale, sq1);
		EXPECT_EQ(scale * q1, sq1);

		const QuatT usq1(q1.w / scale, q1.x / scale, q1.y / scale, q1.z / scale);
		const QuatT susq1(scale / q1.w, scale / q1.x, scale / q1.y, scale / q1.z);
		EXPECT_EQ(q1 / scale, usq1);
		EXPECT_EQ(scale / q1, susq1);


		// Quat operators.
		const QuatT q2(TypeParam{ 44.21 }, TypeParam{ -54.21}, TypeParam{ 2.32}, TypeParam{ 100.31 });

		const QuatT q1pq2(q1.w + q2.w, q1.x + q2.x, q1.y + q2.y, q1.z + q2.z);
		EXPECT_EQ(q1 + q2, q1pq2);

		const QuatT q1mq2(q1.w - q2.w, q1.x - q2.x, q1.y - q2.y, q1.z - q2.z);
		EXPECT_EQ(q1 - q2, q1mq2);


		/**
		*	Random values from Wolfram Alpha.
		*	https://www.wolframalpha.com/input/?i=Quaternion%2848%2C36.12%2C-42.1%2C-3%29
		*/
		const QuatT qmlt1(
			TypeParam{ 0.65379899684951437 },
			TypeParam{ 0.49198400932684733 },
			TypeParam{ -0.57343602132006610 },
			TypeParam{ -0.040862400050191698 }
		);

		/**
		*	Random values from Wolfram Alpha.
		*	https://www.wolframalpha.com/input/?i=Quaternion%287%2B1.36i-4j-23.2k%29
		*/
		const QuatT qmlt2(
			TypeParam{ 0.28456911695921927 },
			TypeParam{ 0.055287819843885436 },
			TypeParam{ - 0.16261099422502870 },
			TypeParam{ -0.94314438937370981 }
		);

		/**
		*	Computed values from Wolfram Alpha.
		*	https://www.wolframalpha.com/input/?i=Quaternion%2848%2B36.12i-42.1j-3k%29*Quaternion%287%2B1.36i-4j-23.2k%29
		*/
		const QuatT q1mltq2(
			TypeParam{ 0.027064135033571489 },
			TypeParam{ 0.71033886691834713 },
			TypeParam{ 0.19225567792515003 },
			TypeParam{ -0.67655301421661285 }
		);
		EXPECT_EQ(qmlt1 * qmlt2, q1mltq2);

		/**
		*	Computed values from Wolfram Alpha.
		*	https://www.wolframalpha.com/input/?i=Quaternion%280.653799+%2B+0.491984i+-+0.573436j+-+0.0408624k%29+*+Quaternion%280.0115685+-+0.0022476i+%2B+0.00661059j+%2B+0.0383414k%29
		*/
		const QuatT q1dq2(
			TypeParam{ 0.34503787137100789 },
			TypeParam{ -0.43033195673395258 },
			TypeParam{ -0.51862004236446857 },
			TypeParam{ 0.65329666001837794 }
		);
		EXPECT_EQ(qmlt1 / qmlt2, q1dq2);

		// op *= scalar.
		QuatT q3 = q1;
		q3 *= scale;
		EXPECT_EQ(q3, sq1);


		// op /= scalar.
		QuatT q4 = q1;
		q4 /= scale;
		EXPECT_EQ(q4, usq1);


		// op += Quat.
		QuatT q5 = q1;
		q5 += q2;
		EXPECT_EQ(q5, q1pq2);

		// op -= Quat.
		QuatT q6 = q1;
		q6 -= q2;
		EXPECT_EQ(q6, q1mq2);


		// op *= Quat.
		QuatT q7 = qmlt1;
		q7 *= qmlt2;
		EXPECT_EQ(q7, q1mltq2);


		// op /= Quat.
		QuatT q8 = qmlt1;
		q8 /= qmlt2;
		EXPECT_EQ(q8, q1dq2);
	}

	TYPED_TEST(QuaternionTest, Accessors)
	{
		const QuatT q1(TypeParam{ 66.321 }, TypeParam{ 92.25 }, TypeParam{ 7.26 }, TypeParam{ -66.31 });

		EXPECT_EQ(q1[0], q1.w);
		EXPECT_EQ(q1[1], q1.x);
		EXPECT_EQ(q1[2], q1.y);
		EXPECT_EQ(q1[3], q1.z);

		EXPECT_EQ(q1.Data(), &q1.w);
		EXPECT_EQ(const_cast<QuatT&>(q1).Data(), &q1.w);
	}
}
