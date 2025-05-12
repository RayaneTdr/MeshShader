// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include "Matrix3Tests.hpp"
#include "Matrix4Tests.hpp"
#include "../Space/QuaternionTests.hpp"
#include "../Space/Vector3Tests.hpp"

namespace SA::UT::Matrix3
{
	template <typename InType, MatMaj Major>
	struct TypeDef
	{
		using T = InType;
		static constexpr MatMaj major = Major;
	};

	template <typename T>
	class Matrix3Test : public testing::Test
	{
	};

	using TestTypes = testing::Types<
		TypeDef<int32_t, MatMaj::Row>, TypeDef<int32_t, MatMaj::Column>,
		TypeDef<float, MatMaj::Row>, TypeDef<float, MatMaj::Column>,
		TypeDef<double, MatMaj::Row>, TypeDef<double, MatMaj::Column>
	>;
	TYPED_TEST_SUITE(Matrix3Test, TestTypes);

	TYPED_TEST(Matrix3Test, Constants)
	{
		// Zero.
		EXPECT_EQ((Mat3T::Zero.e00), 0);
		EXPECT_EQ((Mat3T::Zero.e01), 0);
		EXPECT_EQ((Mat3T::Zero.e02), 0);
		EXPECT_EQ((Mat3T::Zero.e10), 0);
		EXPECT_EQ((Mat3T::Zero.e11), 0);
		EXPECT_EQ((Mat3T::Zero.e12), 0);
		EXPECT_EQ((Mat3T::Zero.e20), 0);
		EXPECT_EQ((Mat3T::Zero.e21), 0);
		EXPECT_EQ((Mat3T::Zero.e22), 0);

		// Identity.
		EXPECT_EQ((Mat3T::Identity.e00), 1);
		EXPECT_EQ((Mat3T::Identity.e01), 0);
		EXPECT_EQ((Mat3T::Identity.e02), 0);
		EXPECT_EQ((Mat3T::Identity.e10), 0);
		EXPECT_EQ((Mat3T::Identity.e11), 1);
		EXPECT_EQ((Mat3T::Identity.e12), 0);
		EXPECT_EQ((Mat3T::Identity.e20), 0);
		EXPECT_EQ((Mat3T::Identity.e21), 0);
		EXPECT_EQ((Mat3T::Identity.e22), 1);
	}

	TYPED_TEST(Matrix3Test, DefaultConstructors)
	{
		const Mat3T m0;
		EXPECT_EQ(m0.e00, 1);
		EXPECT_EQ(m0.e01, 0);
		EXPECT_EQ(m0.e02, 0);
		EXPECT_EQ(m0.e10, 0);
		EXPECT_EQ(m0.e11, 1);
		EXPECT_EQ(m0.e12, 0);
		EXPECT_EQ(m0.e20, 0);
		EXPECT_EQ(m0.e21, 0);
		EXPECT_EQ(m0.e22, 1);
	}

	TYPED_TEST(Matrix3Test, ValueConstructors)
	{
		using T = typename TypeParam::T;

		T m1e00 = static_cast<T>(6.314);
		T m1e01 = static_cast<T>(165.2);
		T m1e02 = static_cast<T>(4236.0);
		T m1e10 = static_cast<T>(46.25);
		T m1e11 = static_cast<T>(77.51);
		T m1e12 = static_cast<T>(16.25);
		T m1e20 = static_cast<T>(653.0);
		T m1e21 = static_cast<T>(11.21);
		T m1e22 = static_cast<T>(15.36);

		const Mat3T m1(
			m1e00, m1e01, m1e02,
			m1e10, m1e11, m1e12,
			m1e20, m1e21, m1e22
		);

		EXPECT_EQ(m1.e00, m1e00);
		EXPECT_EQ(m1.e01, m1e01);
		EXPECT_EQ(m1.e02, m1e02);
		EXPECT_EQ(m1.e10, m1e10);
		EXPECT_EQ(m1.e11, m1e11);
		EXPECT_EQ(m1.e12, m1e12);
		EXPECT_EQ(m1.e20, m1e20);
		EXPECT_EQ(m1.e21, m1e21);
		EXPECT_EQ(m1.e22, m1e22);
	}

	TYPED_TEST(Matrix3Test, ValueCastConstructors)
	{
		using T = typename TypeParam::T;

		uint32_t m2e00 = 336u;
		uint32_t m2e01 = 23u;
		uint32_t m2e02 = 11u;
		uint32_t m2e10 = 98u;
		uint32_t m2e11 = 462u;
		uint32_t m2e12 = 5u;
		uint32_t m2e20 = 796u;
		uint32_t m2e21 = 11u;
		uint32_t m2e22 = 22u;

		Mat3<uint32_t, TypeParam::major> mInt(
			m2e00, m2e01, m2e02,
			m2e10, m2e11, m2e12,
			m2e20, m2e21, m2e22
		);

		const Mat3T m2(mInt);

		EXPECT_EQ(m2.e00, (T)m2e00);
		EXPECT_EQ(m2.e01, (T)m2e01);
		EXPECT_EQ(m2.e02, (T)m2e02);
		EXPECT_EQ(m2.e10, (T)m2e10);
		EXPECT_EQ(m2.e11, (T)m2e11);
		EXPECT_EQ(m2.e12, (T)m2e12);
		EXPECT_EQ(m2.e20, (T)m2e20);
		EXPECT_EQ(m2.e21, (T)m2e21);
		EXPECT_EQ(m2.e22, (T)m2e22);


		// Assignment cast operator.
		Mat3T m3;
		m3 = mInt;

		EXPECT_EQ(m2, m3);
	}

	TYPED_TEST(Matrix3Test, CopyConstructors)
	{
		using T = typename TypeParam::T;

		T m1e00 = static_cast<T>(6.314);
		T m1e01 = static_cast<T>(165.2);
		T m1e02 = static_cast<T>(4236.0);
		T m1e10 = static_cast<T>(46.25);
		T m1e11 = static_cast<T>(77.51);
		T m1e12 = static_cast<T>(16.25);
		T m1e20 = static_cast<T>(653.0);
		T m1e21 = static_cast<T>(11.21);
		T m1e22 = static_cast<T>(15.36);

		const Mat3T m1(
			m1e00, m1e01, m1e02,
			m1e10, m1e11, m1e12,
			m1e20, m1e21, m1e22
		);

		const Mat3T m3(m1);

		EXPECT_EQ(m3.e00, m1.e00);
		EXPECT_EQ(m3.e01, m1.e01);
		EXPECT_EQ(m3.e02, m1.e02);
		EXPECT_EQ(m3.e10, m1.e10);
		EXPECT_EQ(m3.e11, m1.e11);
		EXPECT_EQ(m3.e12, m1.e12);
		EXPECT_EQ(m3.e20, m1.e20);
		EXPECT_EQ(m3.e21, m1.e21);
		EXPECT_EQ(m3.e22, m1.e22);
	}

	TYPED_TEST(Matrix3Test, FromMat4Constructors)
	{
		using T = typename TypeParam::T;

		T m1e00 = static_cast<T>(6.314);
		T m1e01 = static_cast<T>(165.2);
		T m1e02 = static_cast<T>(4236.0);
		T m1e03 = static_cast<T>(99.4);
		T m1e10 = static_cast<T>(46.25);
		T m1e11 = static_cast<T>(77.51);
		T m1e12 = static_cast<T>(16.25);
		T m1e13 = static_cast<T>(78.25);
		T m1e20 = static_cast<T>(653.0);
		T m1e21 = static_cast<T>(11.21);
		T m1e22 = static_cast<T>(15.36);
		T m1e23 = static_cast<T>(9.64);
		T m1e30 = static_cast<T>(1.26);
		T m1e31 = static_cast<T>(22.32);
		T m1e32 = static_cast<T>(56.214);
		T m1e33 = static_cast<T>(32.215);

		const Mat4T m1(
			m1e00, m1e01, m1e02, m1e03,
			m1e10, m1e11, m1e12, m1e13,
			m1e20, m1e21, m1e22, m1e23,
			m1e30, m1e31, m1e32, m1e33
		);


		const Mat3T m2(m1);

		EXPECT_EQ(m2.e00, m1.e00);
		EXPECT_EQ(m2.e01, m1.e01);
		EXPECT_EQ(m2.e02, m1.e02);
		EXPECT_EQ(m2.e10, m1.e10);
		EXPECT_EQ(m2.e11, m1.e11);
		EXPECT_EQ(m2.e12, m1.e12);
		EXPECT_EQ(m2.e20, m1.e20);
		EXPECT_EQ(m2.e21, m1.e21);
		EXPECT_EQ(m2.e22, m1.e22);
	}

	TYPED_TEST(Matrix3Test, Equals)
	{
		using T = typename TypeParam::T;

		const Mat3T m1(
			(T)6.314, (T)165.2, (T)4236.0,
			(T)46.25, (T)77.51, (T)16.25,
			(T)653.0, (T)11.21, (T)15.36
		);

		const Mat3T m2(
			(T)336.65, (T)23.6, (T)11.68,
			(T)98.55, (T)462.3, (T)5.984,
			(T)796.335, (T)11.457, (T)22.32
		);

		EXPECT_FALSE(m1.IsZero());
		EXPECT_TRUE((Mat3T::Zero.IsZero()));

		EXPECT_TRUE(m1.Equals(m1));
		EXPECT_FALSE(m1.Equals(m2));

		EXPECT_EQ(m1, m1);
		EXPECT_NE(m1, m2);
	}

	TYPED_TEST(Matrix3Test, Transpose)
	{
		using T = typename TypeParam::T;

		const Mat3T m1(
			(T)6.314, (T)165.2, (T)4236.0,
			(T)46.25, (T)77.51, (T)16.25,
			(T)653.0, (T)11.21, (T)15.36
		);

		const Mat3T m2 = m1.GetTransposed();

		EXPECT_EQ(m2.e00, m1.e00);
		EXPECT_EQ(m2.e10, m1.e01);
		EXPECT_EQ(m2.e20, m1.e02);
		EXPECT_EQ(m2.e01, m1.e10);
		EXPECT_EQ(m2.e11, m1.e11);
		EXPECT_EQ(m2.e21, m1.e12);
		EXPECT_EQ(m2.e02, m1.e20);
		EXPECT_EQ(m2.e12, m1.e21);
		EXPECT_EQ(m2.e22, m1.e22);

		// Self transpose.
		Mat3T m3 = m1;
		m3.Transpose();
		EXPECT_EQ(m3, m2);
	}

	TYPED_TEST(Matrix3Test, Inverse)
	{
		using T = typename TypeParam::T;

		/**
		*	Precomputed matrix.
		*	https://www.wolframalpha.com/input/?i=%7B%7B5.26%2C+48.25%2C+12.36%7D%2C%7B148.2%2C+12.36%2C+68.2%7D%2C%7B9.25%2C+12.3%2C+46.27%7D%7D
		*/
		const Mat3T m1(
			(T)5.26, (T)48.25, (T)12.36,
			(T)148.2, (T)12.36, (T)68.2,
			(T)9.25, (T)12.3, (T)46.27
		);

		const T det = m1.Determinant();

		if constexpr (std::is_same_v<T, int32_t>)
		{
			/**
			*	Precomputed value
			*	https://www.wolframalpha.com/input/?i=%7B%7B5%2C+48%2C+12%7D%2C%7B148%2C+12%2C+68%7D%2C%7B9%2C+12%2C+46%7D%7D
			*/
			EXPECT_EQ(det, -278712);
		}
		else
			EXPECT_NEAR(det, (T)-280708.856528, (T)0.00001);

		const Mat3T m1_inv = m1.GetInversed();

		// Precomputed matrix.
		const Mat3T m1_resInv(
			(T)0.000951031, (T)0.00741159, (T)-0.0111784,
			(T)0.0221809, (T)-0.00045973, (T)-0.0052475,
			(T)-0.00608648, (T)-0.00135947, (T)0.0252419
		);

		EXPECT_MAT3_NEAR(m1_inv, m1_resInv, (T)0.00001);

		// Self inverse.
		Mat3T m2 = m1;
		m2.Inverse();
		EXPECT_EQ(m2, m1_inv);

		// Check identity.
		if constexpr (std::is_floating_point_v<T>)
		{
			Mat3T m0 = m1 * m1_inv;
			EXPECT_MAT3_NEAR(m0, Mat4T::Identity, (T)0.00001);
		}
	}

	TYPED_TEST(Matrix3Test, Lerp)
	{
		using T = typename TypeParam::T;

		const Mat3T m1(
			(T)2.0, (T)2.0, (T)0.0,
			(T)6.0, (T)10.0, (T)16.0,
			(T)46.0, (T)12.0, (T)70.0
		);

		const Mat3T m2(
			(T)-2.0, (T)4.0, (T)8.0,
			(T)4.0, (T)-60.0, (T)10.0,
			(T)1.0, (T)8.0, (T)-10.0
		);


		const Mat3T lerp_res05(
			(T)0.0, (T)3.0, (T)4.0,
			(T)5.0, (T)-25.0, (T)13.0,
			(T)23.5, (T)10.0, (T)30.0
		);

		EXPECT_EQ((Mat3T::Lerp(m1, m2, 0.5f)), lerp_res05);

		EXPECT_EQ((Mat3T::Lerp(m1, m2, 2.0f)), m2);


		const Mat3T ulerp_res1(
			(T)6.0, (T)0.0, (T)-8.0f,
			(T)8.0, (T)80.0, (T)22.0,
			(T)91.0, (T)16.0, (T)150.0
		);

		EXPECT_EQ((Mat3T::LerpUnclamped(m1, m2, -1.0f)), ulerp_res1);
	}

	TYPED_TEST(Matrix3Test, Transform)
	{
		using T = typename TypeParam::T;

		// Rotation.

		/**
		*	Precomputed values
		*	https://www.wolframalpha.com/input/?i=Quaternion%280.653799%2C+0.491984%2C+-0.573436%2C+-0.0408624%29
		*/
		const Quat<T> q1(
			(T)0.65379899684951437,
			(T)0.49198400932684733,
			(T)-0.57343602132006610,
			(T)-0.040862400050191698
		);

		const Mat3T mRot(
			(T)0.339003, (T)-0.510811, (T)-0.790031,
			(T)-0.617674, (T)0.512564, (T)-0.596453,
			(T)0.709616, (T)0.690181, (T)-0.141754
		);


		if constexpr (std::is_floating_point_v<T>) // No test for int types.
			EXPECT_MAT3_NEAR((Mat3T::MakeRotation(q1)), mRot, 0.000001);


		// Scale.
		const Vec3<T> vScale((T)2.215, (T)5.31, (T)996.2);

		Mat3T mScale = Mat3T::Identity;
		mScale.e00 *= vScale.x;
		mScale.e11 *= vScale.y;
		mScale.e22 *= vScale.z;
		EXPECT_EQ((Mat3T::MakeScale(vScale)), mScale);
	}

	TYPED_TEST(Matrix3Test, Operators)
	{
		using T = typename TypeParam::T;

		const Mat3T m1(
			(T)6.314, (T)165.2, (T)4236.0,
			(T)46.25, (T)77.51, (T)16.25,
			(T)653.0, (T)11.21, (T)15.36
		);

		// Minus self.
		const Mat3T mm1(
			-m1.e00, -m1.e01, -m1.e02,
			-m1.e10, -m1.e11, -m1.e12,
			-m1.e20, -m1.e21, -m1.e22
		);

		EXPECT_EQ(-m1, mm1);


		// Scale.
		T scale = (T)6.21;

		const Mat3T sm1(
			m1.e00 * scale, m1.e01 * scale, m1.e02 * scale,
			m1.e10 * scale, m1.e11 * scale, m1.e12 * scale,
			m1.e20 * scale, m1.e21 * scale, m1.e22 * scale
		);

		EXPECT_EQ(m1 * scale, sm1);
		EXPECT_EQ(scale * m1, sm1);


		// Unscale.
		const Mat3T usm1(
			m1.e00 / scale, m1.e01 / scale, m1.e02 / scale,
			m1.e10 / scale, m1.e11 / scale, m1.e12 / scale,
			m1.e20 / scale, m1.e21 / scale, m1.e22 / scale
		);
		const Mat3T susm1(
			scale / m1.e00, scale / m1.e01, scale / m1.e02,
			scale / m1.e10, scale / m1.e11, scale / m1.e12,
			scale / m1.e20, scale / m1.e21, scale / m1.e22
		);

		EXPECT_EQ(m1 / scale, usm1);
		EXPECT_EQ(scale / m1, susm1);


		// Vector transform
		const Vec3<T> v1((T)10.0412, (T)2.361, (T)12.35);

		Vec3<T> v1_res(
			m1.e00 * v1.x + m1.e01 * v1.y + m1.e02 * v1.z,
			m1.e10 * v1.x + m1.e11 * v1.y + m1.e12 * v1.z,
			m1.e20 * v1.x + m1.e21 * v1.y + m1.e22 * v1.z
		);

		EXPECT_EQ(m1 * v1, v1_res);


		// Mat3 operators
		const Mat3T m2(
			(T)336.65, (T)23.6, (T)11.68,
			(T)98.55, (T)462.3, (T)5.984,
			(T)796.335, (T)11.457, (T)22.32
		);

		const Mat3T m1pm2(
			m1.e00 + m2.e00, m1.e01 + m2.e01, m1.e02 + m2.e02,
			m1.e10 + m2.e10, m1.e11 + m2.e11, m1.e12 + m2.e12,
			m1.e20 + m2.e20, m1.e21 + m2.e21, m1.e22 + m2.e22
		);
		EXPECT_EQ(m1 + m2, m1pm2);

		const Mat3T m1mm2(
			m1.e00 - m2.e00, m1.e01 - m2.e01, m1.e02 - m2.e02,
			m1.e10 - m2.e10, m1.e11 - m2.e11, m1.e12 - m2.e12,
			m1.e20 - m2.e20, m1.e21 - m2.e21, m1.e22 - m2.e22
		);
		EXPECT_EQ(m1 - m2, m1mm2);

		/**
		*	Precomputed matrix.
		*	https://www.wolframalpha.com/input/?i=%7B%7B5.26%2C+48.25%2C+12.36%7D%2C%7B148.2%2C+12.36%2C+68.2%7D%2C%7B9.25%2C+12.3%2C+46.27%7D%7D
		*/
		const Mat3T m3(
			(T)5.26, (T)48.25, (T)12.36,
			(T)148.2, (T)12.36, (T)68.2,
			(T)9.25, (T)12.3, (T)46.27
		);

		/**
		*	Precomputed matrix.
		*	https://www.wolframalpha.com/input/?i=%7B%7B98.0%2C+1324.0%2C+3.25%7D%2C%7B63.25%2C+10.2%2C+1.25%7D%2C%7B47.2%2C+6.21%2C+614.0%7D%7D
		*/
		const Mat3T m4(
			(T)98.0, (T)1324.0, (T)3.25,
			(T)63.25, (T)10.2, (T)1.25,
			(T)47.2, (T)6.21, (T)614.0
		);

		/**
		*	Precomputed matrix.
		*	https://www.wolframalpha.com/input/?i=%7B%7B5.26%2C+48.25%2C+12.36%7D%2C%7B148.2%2C+12.36%2C+68.2%7D%2C%7B9.25%2C+12.3%2C+46.27%7D%7D*%7B%7B98.0%2C+1324.0%2C+3.25%7D%2C%7B63.25%2C+10.2%2C+1.25%7D%2C%7B47.2%2C+6.21%2C+614.0%7D%7D
		*/
		Mat3T m3multm4;
		Mat3T m3divm4;

		if constexpr (std::is_integral_v<T>)
		{
			m3multm4 = Mat3T(
				4078, 7172, 7431,
				18456, 196480, 42208,
				3800, 12312, 28283
			);

			EXPECT_EQ(m3 * m4, m3multm4);
		}
		else
		{
			m3multm4 = Mat3T(
				(T)4150.6845, (T)7533.1456, (T)7666.4475,
				(T)18524.41, (T)196766.394, (T)42371.9,
				(T)3868.419, (T)12659.796, (T)28455.217
			);

			EXPECT_MAT3_NEAR(m3 * m4, m3multm4, 0.002);

			m3divm4 = Mat3T(
				(T)0.0362558, (T)0.0121266, (T)0.0199137,
				(T)-0.00870679, (T)2.27711, (T)0.106485,
				(T)0.00834252, (T)0.0772336, (T)0.0751569
			);

			EXPECT_MAT3_NEAR(m3 / m4, m3divm4, 0.002);
		}


		// op *= scalar.
		Mat3T m5 = m1;
		m5 *= scale;
		EXPECT_EQ(m5, sm1);


		// op /= scalar.
		Mat3T m6 = m1;
		m6 /= scale;
		EXPECT_EQ(m6, usm1);


		// op += Mat.
		Mat3T m7 = m1;
		m7 += m2;
		EXPECT_EQ(m7, m1pm2);

		// op -= Mat.
		Mat3T m8 = m1;
		m8 -= m2;
		EXPECT_EQ(m8, m1mm2);


		// op *= Mat.
		Mat3T m9 = m3;
		m9 *= m4;
		EXPECT_MAT3_NEAR(m9, m3multm4, 0.002);


		// op /= Mat.
		if constexpr (std::is_floating_point_v<T>)
		{
			Mat3T m10 = m3;
			m10 /= m4;
			EXPECT_MAT3_NEAR(m10, m3divm4, 0.002);
		}
	}

	TEST(Matrix3, Majors)
	{
		float e00 = 6.314f;
		float e01 = 165.2f;
		float e02 = 4236.0f;
		float e10 = 46.25f;
		float e11 = 77.51f;
		float e12 = 16.25f;
		float e20 = 653.0f;
		float e21 = 11.21f;
		float e22 = 15.36f;

		const Mat3<float, MatrixMajor::Row> m1(
			e00, e01, e02,
			e10, e11, e12,
			e20, e21, e22
		);
		const Mat3<float, MatrixMajor::Column> m2(
			e00, e01, e02,
			e10, e11, e12,
			e20, e21, e22
		);

		// Same value for same name.
		EXPECT_EQ(m1.e00, m2.e00);
		EXPECT_EQ(m1.e01, m2.e01);
		EXPECT_EQ(m1.e02, m2.e02);
		EXPECT_EQ(m1.e10, m2.e10);
		EXPECT_EQ(m1.e11, m2.e11);
		EXPECT_EQ(m1.e12, m2.e12);
		EXPECT_EQ(m1.e20, m2.e20);
		EXPECT_EQ(m1.e21, m2.e21);
		EXPECT_EQ(m1.e22, m2.e22);


		// Auto conversion.
		const Mat3<float, MatrixMajor::Column> cm1 = m1;
		const Mat3<float, MatrixMajor::Row> rm2 = m2;

		EXPECT_EQ(cm1, m2);
		EXPECT_EQ(rm2, m1);


		// Different memory.
		const float* const dm1 = m1.Data();
		const float* const dm2 = m2.Data();

		EXPECT_EQ(dm1[0], dm2[0]);
		EXPECT_EQ(dm1[1], dm2[3]);
		EXPECT_EQ(dm1[2], dm2[6]);

		EXPECT_EQ(dm1[3], dm2[1]);
		EXPECT_EQ(dm1[4], dm2[4]);
		EXPECT_EQ(dm1[5], dm2[7]);

		EXPECT_EQ(dm1[6], dm2[2]);
		EXPECT_EQ(dm1[7], dm2[5]);
		EXPECT_EQ(dm1[8], dm2[8]);
	}

	TEST(Matrix3, AccessorsRow)
	{
		// Test non-const access.
		Mat3<float, MatMaj::Row> m1(
			6.314f, 165.2f, 4236.0f,
			46.25f, 77.51f, 16.25f,
			653.0f, 11.21f, 15.36f
		);

		EXPECT_EQ(m1[0], m1.e00);
		EXPECT_EQ(m1[1], m1.e01);
		EXPECT_EQ(m1[2], m1.e02);
		EXPECT_EQ(m1[3], m1.e10);
		EXPECT_EQ(m1[4], m1.e11);
		EXPECT_EQ(m1[5], m1.e12);
		EXPECT_EQ(m1[6], m1.e20);
		EXPECT_EQ(m1[7], m1.e21);
		EXPECT_EQ(m1[8], m1.e22);

		EXPECT_EQ(m1.At(0), m1.e00);
		EXPECT_EQ(m1.At(1), m1.e01);
		EXPECT_EQ(m1.At(2), m1.e02);
		EXPECT_EQ(m1.At(3), m1.e10);
		EXPECT_EQ(m1.At(4), m1.e11);
		EXPECT_EQ(m1.At(5), m1.e12);
		EXPECT_EQ(m1.At(6), m1.e20);
		EXPECT_EQ(m1.At(7), m1.e21);
		EXPECT_EQ(m1.At(8), m1.e22);

		EXPECT_EQ(m1.At(0, 0), m1.e00);
		EXPECT_EQ(m1.At(0, 1), m1.e01);
		EXPECT_EQ(m1.At(0, 2), m1.e02);
		EXPECT_EQ(m1.At(1, 0), m1.e10);
		EXPECT_EQ(m1.At(1, 1), m1.e11);
		EXPECT_EQ(m1.At(1, 2), m1.e12);
		EXPECT_EQ(m1.At(2, 0), m1.e20);
		EXPECT_EQ(m1.At(2, 1), m1.e21);
		EXPECT_EQ(m1.At(2, 2), m1.e22);

		EXPECT_EQ(m1.Data(), &m1.e00);

		// Const.

		const Mat3<float, MatMaj::Row>& cm1 = m1;

		EXPECT_EQ(cm1[0], cm1.e00);
		EXPECT_EQ(cm1[1], cm1.e01);
		EXPECT_EQ(cm1[2], cm1.e02);
		EXPECT_EQ(cm1[3], cm1.e10);
		EXPECT_EQ(cm1[4], cm1.e11);
		EXPECT_EQ(cm1[5], cm1.e12);
		EXPECT_EQ(cm1[6], cm1.e20);
		EXPECT_EQ(cm1[7], cm1.e21);
		EXPECT_EQ(cm1[8], cm1.e22);

		EXPECT_EQ(cm1.At(0), cm1.e00);
		EXPECT_EQ(cm1.At(1), cm1.e01);
		EXPECT_EQ(cm1.At(2), cm1.e02);
		EXPECT_EQ(cm1.At(3), cm1.e10);
		EXPECT_EQ(cm1.At(4), cm1.e11);
		EXPECT_EQ(cm1.At(5), cm1.e12);
		EXPECT_EQ(cm1.At(6), cm1.e20);
		EXPECT_EQ(cm1.At(7), cm1.e21);
		EXPECT_EQ(cm1.At(8), cm1.e22);

		EXPECT_EQ(cm1.At(0, 0), cm1.e00);
		EXPECT_EQ(cm1.At(0, 1), cm1.e01);
		EXPECT_EQ(cm1.At(0, 2), cm1.e02);
		EXPECT_EQ(cm1.At(1, 0), cm1.e10);
		EXPECT_EQ(cm1.At(1, 1), cm1.e11);
		EXPECT_EQ(cm1.At(1, 2), cm1.e12);
		EXPECT_EQ(cm1.At(2, 0), cm1.e20);
		EXPECT_EQ(cm1.At(2, 1), cm1.e21);
		EXPECT_EQ(cm1.At(2, 2), cm1.e22);

		EXPECT_EQ(cm1.Data(), &cm1.e00);
	}

	TEST(Matrix3, AccessorsColumn)
	{
		// Test non-const access.
		Mat3<float, MatMaj::Column> m1(
			6.314f, 165.2f, 4236.0f,
			46.25f, 77.51f, 16.25f,
			653.0f, 11.21f, 15.36f
		);

		EXPECT_EQ(m1[0], m1.e00);
		EXPECT_EQ(m1[1], m1.e10);
		EXPECT_EQ(m1[2], m1.e20);
		EXPECT_EQ(m1[3], m1.e01);
		EXPECT_EQ(m1[4], m1.e11);
		EXPECT_EQ(m1[5], m1.e21);
		EXPECT_EQ(m1[6], m1.e02);
		EXPECT_EQ(m1[7], m1.e12);
		EXPECT_EQ(m1[8], m1.e22);

		EXPECT_EQ(m1.At(0), m1.e00);
		EXPECT_EQ(m1.At(1), m1.e10);
		EXPECT_EQ(m1.At(2), m1.e20);
		EXPECT_EQ(m1.At(3), m1.e01);
		EXPECT_EQ(m1.At(4), m1.e11);
		EXPECT_EQ(m1.At(5), m1.e21);
		EXPECT_EQ(m1.At(6), m1.e02);
		EXPECT_EQ(m1.At(7), m1.e12);
		EXPECT_EQ(m1.At(8), m1.e22);

		EXPECT_EQ(m1.At(0, 0), m1.e00);
		EXPECT_EQ(m1.At(0, 1), m1.e10);
		EXPECT_EQ(m1.At(0, 2), m1.e20);
		EXPECT_EQ(m1.At(1, 0), m1.e01);
		EXPECT_EQ(m1.At(1, 1), m1.e11);
		EXPECT_EQ(m1.At(1, 2), m1.e21);
		EXPECT_EQ(m1.At(2, 0), m1.e02);
		EXPECT_EQ(m1.At(2, 1), m1.e12);
		EXPECT_EQ(m1.At(2, 2), m1.e22);

		EXPECT_EQ(m1.Data(), &m1.e00);


		const Mat3<float, MatMaj::Column>& cm1 = m1;

		EXPECT_EQ(cm1[0], cm1.e00);
		EXPECT_EQ(cm1[1], cm1.e10);
		EXPECT_EQ(cm1[2], cm1.e20);
		EXPECT_EQ(cm1[3], cm1.e01);
		EXPECT_EQ(cm1[4], cm1.e11);
		EXPECT_EQ(cm1[5], cm1.e21);
		EXPECT_EQ(cm1[6], cm1.e02);
		EXPECT_EQ(cm1[7], cm1.e12);
		EXPECT_EQ(cm1[8], cm1.e22);

		EXPECT_EQ(cm1.At(0), cm1.e00);
		EXPECT_EQ(cm1.At(1), cm1.e10);
		EXPECT_EQ(cm1.At(2), cm1.e20);
		EXPECT_EQ(cm1.At(3), cm1.e01);
		EXPECT_EQ(cm1.At(4), cm1.e11);
		EXPECT_EQ(cm1.At(5), cm1.e21);
		EXPECT_EQ(cm1.At(6), cm1.e02);
		EXPECT_EQ(cm1.At(7), cm1.e12);
		EXPECT_EQ(cm1.At(8), cm1.e22);

		EXPECT_EQ(cm1.At(0, 0), cm1.e00);
		EXPECT_EQ(cm1.At(0, 1), cm1.e10);
		EXPECT_EQ(cm1.At(0, 2), cm1.e20);
		EXPECT_EQ(cm1.At(1, 0), cm1.e01);
		EXPECT_EQ(cm1.At(1, 1), cm1.e11);
		EXPECT_EQ(cm1.At(1, 2), cm1.e21);
		EXPECT_EQ(cm1.At(2, 0), cm1.e02);
		EXPECT_EQ(cm1.At(2, 1), cm1.e12);
		EXPECT_EQ(cm1.At(2, 2), cm1.e22);

		EXPECT_EQ(cm1.Data(), &cm1.e00);
	}
}
