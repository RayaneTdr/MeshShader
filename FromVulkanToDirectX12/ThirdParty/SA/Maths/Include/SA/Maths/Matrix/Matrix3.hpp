// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_MATRIX3_GUARD
#define SAPPHIRE_MATHS_MATRIX3_GUARD

#include <limits>

#include <SA/Maths/Debug.hpp>
#include <SA/Maths/Config.hpp>

#include <SA/Maths/Matrix/Matrix3Base.hpp>

#include <SA/Maths/Algorithms/Equals.hpp>
#include <SA/Maths/Algorithms/Lerp.hpp>

#if SA_MATHS_MATRIX3_SIMD

	#include <SA/Support/Intrinsics.hpp>
	#include <SA/Support/Pragma.hpp>

#endif

/**
*	\file Matrix3.hpp
*
*	\brief <b>Matrix 3x3</b> type implementation.
*
*	\ingroup Maths
*	\{
*/


namespace SA
{
	template <typename T>
	struct Vec3;

	template <typename T>
	struct Quat;

	template <typename T, MatrixMajor major>
	struct Mat4;


	/**
	*	\brief \e Matrix 3x3 Sapphire-Maths class.
	*
	* 	must be align at 32 for intrinsics.
	* 
	*	\tparam T	Type of the matrix.
	*/

#if SA_MATHS_MATRIX3_SIMD && SA_INTRISC

	// Disable padding struct warning.
	SA_PRAGMA_SDWARN_MSVC(4324)

	template <typename T, MatrixMajor major = MatrixMajor::Default>
	struct alignas(32) Mat3 : public Intl::Mat3_Base<T, major>

#else

	template <typename T, MatrixMajor major = MatrixMajor::Default>
	struct Mat3 : public Intl::Mat3_Base<T, major>

#endif
	{
		using Intl::Mat3_Base<T, major>::e00;
		using Intl::Mat3_Base<T, major>::e01;
		using Intl::Mat3_Base<T, major>::e02;

		using Intl::Mat3_Base<T, major>::e10;
		using Intl::Mat3_Base<T, major>::e11;
		using Intl::Mat3_Base<T, major>::e12;

		using Intl::Mat3_Base<T, major>::e20;
		using Intl::Mat3_Base<T, major>::e21;
		using Intl::Mat3_Base<T, major>::e22;


//{ Constants

		/**
		*	\brief Zero Mat3 constant
		* 
		*	{0, 0, 0}
		*	{0, 0, 0}
		*	{0, 0, 0}
		*/
		static const Mat3 Zero;

		/**
		*	\brief Identity Mat3 constant
		* 
		*	{1, 0, 0}
		*	{0, 1, 0}
		*	{0, 0, 1}
		*/
		static const Mat3 Identity;

//}

//{ Constructors

		using Intl::Mat3_Base<T, major>::Mat3_Base;

		/**
		*	\brief \e Value constructor from another Mat3 type.
		*
		*	\tparam TIn			Type of the input Mat3.
		*	\tparam majorIn		Major of the input Mat3.
		*
		*	\param[in] _other	Mat3 to construct from.
		*/
		template <typename TIn, MatrixMajor majorIn>
		constexpr Mat3(const Mat3<TIn, majorIn>& _other) noexcept;

		/**
		*	\brief \e Value constructor from another Mat4 type.
		*
		*	\tparam TIn			Type of the input Mat4.
		*	\tparam majorIn		Major of the input Mat3.
		*
		*	\param[in] _other	Mat4 to construct from.
		*/
		template <typename TIn, MatrixMajor majorIn>
		constexpr Mat3(const Mat4<TIn, majorIn>& _other) noexcept;

//}

//{ Equals

		/**
		*	\brief Whether this matrix is a zero matrix.
		*
		*	\return True if this is a zero matrix.
		*/
		constexpr bool IsZero() const noexcept;

		/**
		*	\brief Whether this matrix is an identity matrix.
		*
		*	\return True if this is an identity matrix.
		*/
		constexpr bool IsIdentity() const noexcept;


		/**
		*	\brief \e Compare 2 Matrix.
		*
		*	\param[in] _other		Other matrix to compare to.
		*	\param[in] _epsilon		Epsilon value for threshold comparison.
		*
		*	\return Whether this and _other are equal.
		*/
		constexpr bool Equals(const Mat3& _other, T _epsilon = std::numeric_limits<T>::epsilon()) const noexcept;


		/**
		*	\brief \e Compare 2 matrix equality.
		*
		*	\param[in] _rhs		Other matrix to compare to.
		*
		*	\return Whether this and _rhs are equal.
		*/
		constexpr bool operator==(const Mat3& _rhs) const noexcept;

		/**
		*	\brief \e Compare 2 matrix inequality.
		*
		*	\param[in] _rhs		Other matrix to compare to.
		*
		*	\return Whether this and _rhs are non-equal.
		*/
		constexpr bool operator!=(const Mat3& _rhs) const noexcept;
//}

//{ Accessors

		/**
		*	\brief \e Getter of matrix data
		*
		*	\return this matrix as a T*.
		*/
		T* Data() noexcept;

		/**
		*	\brief <em> Const Getter </em> of matrix data
		*
		*	\return this matrix as a const T*.
		*/
		const T* Data() const noexcept;


		/**
		*	\brief \e Getter of Value at index.
		*
		*	\param[in] _index		Index to access.
		*
		*	\return element at index.
		*/
		T& At(uint32_t _index);

		/**
		*	\brief <em> Const Getter </em> of Value at index.
		*
		*	\param[in] _index		Index to access.
		*
		*	\return element at index.
		*/
		const T& At(uint32_t _index) const;

		/**
		*	\brief \e Getter of Value at (x;y).
		*
		*	\param[in] _x		row index.
		*	\param[in] _y		column index.
		*
		*	\return element at index.
		*/
		T& At(uint32_t _x, uint32_t _y);

		/**
		*	\brief <em> Const Getter </em> of Value at (x;y).
		*
		*	\param[in] _x		row index.
		*	\param[in] _y		column index.
		*
		*	\return element at index.
		*/
		const T& At(uint32_t _x, uint32_t _y) const;


		/**
		*	\brief \e Access operator by index.
		*
		*	\param[in] _index	Index to access.
		*
		*	\return T value at index.
		*/
		T& operator[](uint32_t _index);

		/**
		*	\brief <em> Const Access </em> operator by index.
		*
		*	\param[in] _index	Index to access.
		*
		*	\return T value at index.
		*/
		const T& operator[](uint32_t _index) const;
//}

//{ Transpose

		/**
		*	\brief \b Transpose this matrix.
		*
		*	\return self transposed matrix.
		*/
		Mat3& Transpose() noexcept;

		/**
		*	\brief \b Transpose this matrix.
		*
		*	\return new transposed matrix.
		*/
		constexpr Mat3 GetTransposed() const noexcept;

//}

//{ Inverse

		/**
		*	\brief \e Compute the determinant of the matrix.
		*
		*	\return Determinant of this matrix.
		*/
		T Determinant() const noexcept;

		/**
		*	\brief \b Inverse this matrix.
		*
		*	\return self inversed matrix.
		*/
		Mat3& Inverse();

		/**
		*	\brief \b Inverse this matrix.
		*
		*	\return new inversed matrix.
		*/
		Mat3 GetInversed() const;
	
//}

//{ Lerp

		/**
		*	\brief <b> Clamped Lerp </b> from _start to _end at _alpha.
		*
		*	Reference: https://en.wikipedia.org/wiki/Linear_interpolation
		*
		*	\param _start	Starting point of the lerp.
		*	\param _end		Ending point of the lerp.
		*	\param _alpha	Alpha of the lerp.
		*
		*	\return interpolation between _start and _end. return _start when _alpha == 0.0f and _end when _alpha == 1.0f.
		*/
		static Mat3 Lerp(const Mat3& _start, const Mat3& _end, float _alpha) noexcept;

		/**
		*	\brief <b> Unclamped Lerp </b> from _start to _end at _alpha.
		*
		*	Reference: https://en.wikipedia.org/wiki/Linear_interpolation
		*
		*	\param _start	Starting point of the lerp.
		*	\param _end		Ending point of the lerp.
		*	\param _alpha	Alpha of the lerp.
		*
		*	\return interpolation between _start and _end. return _start when _alpha == 0.0f and _end when _alpha == 1.0f.
		*/
		static Mat3 LerpUnclamped(const Mat3& _start, const Mat3& _end, float _alpha) noexcept;

//}

//{ Transform

		/**
		*	\brief Make <b> rotation matrix </b> from quaternion.
		*
		*	\param[in] _rot	quaternion to use for rotation.
		*
		*	\return rotation matrix.
		*/
		static Mat3 MakeRotation(const Quat<T>& _rot) noexcept;

		/**
		*	\brief Make <b> scale matrix </b> from vector3.
		*
		*	\param[in] _scale	Vector for scaling.
		*
		*	\return scale matrix.
		*/
		static Mat3 MakeScale(const Vec3<T>& _scale) noexcept;

//}

//{ Operators
		
		/**
		*	\brief \e Assignment operator from another Mat3 type.
		*
		*	\tparam TIn			Type of the input Mat3.
		*	\tparam majorIn		Major of the input Mat3.
		*
		*	\param[in] _rhs		Mat3 to assign from.
		*/
		template <typename TIn, MatrixMajor majorIn>
		Mat3& operator=(const Mat3<TIn, majorIn> _rhs) noexcept;

		/**
		*	\brief \e Getter of the opposite signed matrix.
		*
		*	\return new opposite signed matrix.
		*/
		constexpr Mat3 operator-() const noexcept;

		/**
		*	\brief \b Scale each matrix component by _scale.
		*
		*	\tparam TIn			Type of the input scale.
		* 
		*	\param[in] _scale	Scale value to apply on all components.
		*
		*	\return new matrix scaled.
		*/
		template <typename TIn>
		Mat3 operator*(TIn _scale) const noexcept;

		/**
		*	\brief <b> Inverse Scale </b> each matrix component by _scale.
		*
		*	\tparam TIn			Type of the input scale.
		* 
		*	\param[in] _scale	Inverse scale value to apply on all components.
		*
		*	\return new matrix inverse-scaled.
		*/
		template <typename TIn>
		Mat3 operator/(TIn _scale) const;

		/**
		*	\brief \b Add term by term matrix values.
		*
		*	\param[in] _rhs		Matrix to add.
		*
		*	\return new matrix result.
		*/
		Mat3 operator+(const Mat3& _rhs) const noexcept;

		/**
		*	\brief \b Subtract term by term matrix values.
		*
		*	\param[in] _rhs		Matrix to substract.
		*
		*	\return new matrix result.
		*/
		Mat3 operator-(const Mat3& _rhs) const noexcept;

		/**
		*	\brief \b Multiply matrices.
		*
		*	\param[in] _rhs		Matrix to multiply to.
		*
		*	\return new matrix result.
		*/
		Mat3 operator*(const Mat3& _rhs) const noexcept;

		/**
		*	\brief \b Inverse multiply matrices.
		*
		*	\param[in] _rhs		Matrix to inverse multiply to.
		*
		*	\return new matrix result.
		*/
		Mat3 operator/(const Mat3& _rhs) const;


		/**
		*	\brief transform this vector by this matrix.
		*
		*	\param[in] _rhs		Vector to transform.
		*
		*	\return Transformed vector.
		*/
		Vec3<T> operator*(const Vec3<T>&_rhs) const noexcept;


		/**
		*	\brief \b Scale each matrix component by _scale.
		*
		*	\tparam TIn			Type of the input scale.
		*
		*	\param[in] _scale	Scale value to apply on all components.
		*
		*	\return self matrix scaled.
		*/
		template <typename TIn>
		Mat3& operator*=(TIn _scale) noexcept;

		/**
		*	\brief <b> Inverse Scale </b> each matrix component by _scale.
		*
		*	\tparam TIn			Type of the input scale.
		* 
		*	\param[in] _scale	Inverse scale value to apply on all components.
		*
		*	\return self matrix inverse-scaled.
		*/
		template <typename TIn>
		Mat3& operator/=(TIn _scale);

		/**
		*	\brief \b Add term by term matrix values.
		*
		*	\param[in] _rhs		Matrix to add.
		*
		*	\return self matrix result.
		*/
		Mat3& operator+=(const Mat3& _rhs) noexcept;

		/**
		*	\brief \b Subtract term by term matrix values.
		*
		*	\param[in] _rhs		Matrix to substract.
		*
		*	\return self matrix result.
		*/
		Mat3& operator-=(const Mat3& _rhs) noexcept;

		/**
		*	\brief \b Multiply matrices.
		*
		*	\param[in] _rhs		Matrix to multiply to.
		*
		*	\return self matrix result.
		*/
		Mat3& operator*=(const Mat3& _rhs) noexcept;

		/**
		*	\brief \b Inverse multiply matrices.
		*
		*	\param[in] _rhs		Matrix to inverse multiply to.
		*
		*	\return self matrix result.
		*/
		Mat3& operator/=(const Mat3& _rhs);

//}


#if SA_LOGGING

		/**
		*	\brief ToString implementation
		*
		*	Convert this matrix as a string.
		*	Print element in memoro order.
		*
		*	\return this as a string.
		*/
		std::string ToString() const noexcept;

#endif
	};

#if SA_MATHS_MATRIX3_SIMD && SA_INTRISC

	// Disable padding struct warning.
	SA_PRAGMA_EDWARN_MSVC()

#endif


	/**
	*	\brief \b Scale each matrix components by _lhs.
	*
	*	\tparam TIn			Type of the input scale.
	* 
	*	\param[in] _lhs		Scale value to apply on all components.
	*	\param[in] _rhs		Matrix to scale.
	*
	*	\return new matrix scaled.
	*/
	template <typename TIn, typename T, MatrixMajor major>
	Mat3<T, major> operator*(TIn _lhs, const Mat3<T, major>& _rhs) noexcept;

	/**
	*	\brief <b> Inverse Scale </b> each matrix components by _lhs.
	*
	*	\tparam TIn			Type of the input scale.
	* 
	*	\param[in] _lhs		Inverse scale value to apply on all components.
	*	\param[in] _rhs		Matrix to scale.
	*
	*	\return new matrix inverse-scaled.
	*/
	template <typename TIn, typename T, MatrixMajor major>
	Mat3<T, major> operator/(TIn _lhs, const Mat3<T, major>& _rhs);


#if SA_LOGGER_IMPL

	/**
	*	\brief ToString Mat3 implementation
	*
	*	Convert Mat3 as a string.
	*
	*	\tparam T		Input matrix type.
	*
	*	\param[in] _m	Input matrix.
	*
	*	\return input matrix as a string.
	*/
	template <typename T>
	std::string ToString(const Mat3<T>& _m);

#endif


//{ Aliases

	/// Alias for int32 Mat3.
	using Mat3i = Mat3<int32_t>;

	/// Alias for float Mat3.
	using Mat3f = Mat3<float>;

	/// Alias for double Mat3.
	using Mat3d = Mat3<double>;


	/// Template alias of Mat3
	template <typename T, MatrixMajor major = MatrixMajor::Default>
	using Matrix3 = Mat3<T, major>;

	/// Alias for int32 Matrix3.
	using Matrix3i = Matrix3<int32_t>;

	/// Alias for float Matrix3.
	using Matrix3f = Matrix3<float>;

	/// Alias for double Matrix3.
	using Matrix3d = Matrix3<double>;


	/// Alias for row major int32 Mat3.
	using RMat3i = Mat3<int32_t, MatrixMajor::Row>;

	/// Alias for row major float Mat3.
	using RMat3f = Mat3<float, MatrixMajor::Row>;

	/// Alias for row major double Mat3.
	using RMat3d = Mat3<double, MatrixMajor::Row>;


	/// Alias for column major int32 Mat3.
	using CMat3i = Mat3<int32_t, MatrixMajor::Column>;

	/// Alias for column major float Mat3.
	using CMat3f = Mat3<float, MatrixMajor::Column>;

	/// Alias for column major double Mat3.
	using CMat3d = Mat3<double, MatrixMajor::Column>;

//}

	/// \cond Internal

#if SA_MATHS_MATRIX3_SIMD && SA_INTRISC_AVX // SIMD int32

//{ Row Major

	template <>
	template <>
	RMat3i RMat3i::operator*(int32_t _scale) const noexcept;

#if SA_INTRISC_SVML
	template <>
	template <>
	RMat3i RMat3i::operator/(int32_t _scale) const;
#endif

	template <>
	RMat3i RMat3i::operator+(const RMat3i& _rhs) const noexcept;

	template <>
	RMat3i RMat3i::operator-(const RMat3i& _rhs) const noexcept;

	template <>
	RMat3i RMat3i::operator*(const RMat3i& _rhs) const noexcept;


	template <>
	Vec3<int32_t> RMat3i::operator*(const Vec3<int32_t>& _rhs) const noexcept;


	template <>
	template <>
	RMat3i& RMat3i::operator*=(int32_t _scale) noexcept;

#if SA_INTRISC_SVML
	template <>
	template <>
	RMat3i& RMat3i::operator/=(int32_t _scale);
#endif

	template <>
	RMat3i& RMat3i::operator+=(const RMat3i& _rhs) noexcept;

	template <>
	RMat3i& RMat3i::operator-=(const RMat3i& _rhs) noexcept;

//}

//{ Column Major

	template <>
	template <>
	CMat3i CMat3i::operator*(int32_t _scale) const noexcept;

#if SA_INTRISC_SVML
	template <>
	template <>
	CMat3i CMat3i::operator/(int32_t _scale) const;
#endif

	template <>
	CMat3i CMat3i::operator+(const CMat3i& _rhs) const noexcept;

	template <>
	CMat3i CMat3i::operator-(const CMat3i& _rhs) const noexcept;

	template <>
	CMat3i CMat3i::operator*(const CMat3i& _rhs) const noexcept;


	template <>
	Vec3<int32_t> CMat3i::operator*(const Vec3<int32_t>& _rhs) const noexcept;


	template <>
	template <>
	CMat3i& CMat3i::operator*=(int32_t _scale) noexcept;

#if SA_INTRISC_SVML
	template <>
	template <>
	CMat3i& CMat3i::operator/=(int32_t _scale);
#endif

	template <>
	CMat3i& CMat3i::operator+=(const CMat3i& _rhs) noexcept;

	template <>
	CMat3i& CMat3i::operator-=(const CMat3i& _rhs) noexcept;

//}

#endif

#if SA_MATHS_MATRIX3_SIMD && SA_INTRISC_SSE // SIMD float

//{ Row Major

	template <>
	float RMat3f::Determinant() const noexcept;

	template <>
	RMat3f RMat3f::GetInversed() const;


	template <>
	RMat3f RMat3f::MakeRotation(const Quat<float>& _rot) noexcept;


	template <>
	template <>
	RMat3f RMat3f::operator*(float _scale) const noexcept;

	template <>
	template <>
	RMat3f RMat3f::operator/(float _scale) const;

	template <>
	RMat3f RMat3f::operator+(const RMat3f& _rhs) const noexcept;

	template <>
	RMat3f RMat3f::operator-(const RMat3f& _rhs) const noexcept;

	template <>
	RMat3f RMat3f::operator*(const RMat3f& _rhs) const noexcept;


	template <>
	Vec3<float> RMat3f::operator*(const Vec3<float>& _rhs) const noexcept;


	template <>
	template <>
	RMat3f& RMat3f::operator*=(float _scale) noexcept;

	template <>
	template <>
	RMat3f& RMat3f::operator/=(float _scale);

	template <>
	RMat3f& RMat3f::operator+=(const RMat3f& _rhs) noexcept;

	template <>
	RMat3f& RMat3f::operator-=(const RMat3f& _rhs) noexcept;


	template <>
	Mat3f operator/(float _lhs, const Mat3f& _rhs);

//}

//{ Column Major

	template <>
	float CMat3f::Determinant() const noexcept;

	template <>
	CMat3f CMat3f::GetInversed() const;


	template <>
	CMat3f CMat3f::MakeRotation(const Quat<float>& _rot) noexcept;


	template <>
	template <>
	CMat3f CMat3f::operator*(float _scale) const noexcept;

	template <>
	template <>
	CMat3f CMat3f::operator/(float _scale) const;

	template <>
	CMat3f CMat3f::operator+(const CMat3f& _rhs) const noexcept;

	template <>
	CMat3f CMat3f::operator-(const CMat3f& _rhs) const noexcept;

	template <>
	CMat3f CMat3f::operator*(const CMat3f& _rhs) const noexcept;


	template <>
	Vec3<float> CMat3f::operator*(const Vec3<float>& _rhs) const noexcept;


	template <>
	template <>
	CMat3f& CMat3f::operator*=(float _scale) noexcept;

	template <>
	template <>
	CMat3f& CMat3f::operator/=(float _scale);

	template <>
	CMat3f& CMat3f::operator+=(const CMat3f& _rhs) noexcept;

	template <>
	CMat3f& CMat3f::operator-=(const CMat3f& _rhs) noexcept;


	template <>
	CMat3f operator/(float _lhs, const CMat3f& _rhs);

//}

#endif

#if SA_MATHS_MATRIX3_SIMD && SA_INTRISC_AVX // SIMD double

//{ Row Major

	template <>
	double RMat3d::Determinant() const noexcept;

	template <>
	RMat3d RMat3d::GetInversed() const;


	template <>
	RMat3d RMat3d::MakeRotation(const Quat<double>& _rot) noexcept;


	template <>
	template <>
	RMat3d RMat3d::operator*(double _scale) const noexcept;

	template <>
	template <>
	RMat3d RMat3d::operator/(double _scale) const;

	template <>
	RMat3d RMat3d::operator+(const RMat3d& _rhs) const noexcept;

	template <>
	RMat3d RMat3d::operator-(const RMat3d& _rhs) const noexcept;

	template <>
	RMat3d RMat3d::operator*(const RMat3d& _rhs) const noexcept;


	template <>
	Vec3<double> RMat3d::operator*(const Vec3<double>& _rhs) const noexcept;


	template <>
	template <>
	RMat3d& RMat3d::operator*=(double _scale) noexcept;

	template <>
	template <>
	RMat3d& RMat3d::operator/=(double _scale);

	template <>
	RMat3d& RMat3d::operator+=(const RMat3d& _rhs) noexcept;

	template <>
	RMat3d& RMat3d::operator-=(const RMat3d& _rhs) noexcept;


	template <>
	RMat3d operator/(double _lhs, const RMat3d& _rhs);

//}

//{ Column Major

	template <>
	double CMat3d::Determinant() const noexcept;

	template <>
	CMat3d CMat3d::GetInversed() const;


	template <>
	CMat3d CMat3d::MakeRotation(const Quat<double>& _rot) noexcept;


	template <>
	template <>
	CMat3d CMat3d::operator*(double _scale) const noexcept;

	template <>
	template <>
	CMat3d CMat3d::operator/(double _scale) const;

	template <>
	CMat3d CMat3d::operator+(const CMat3d& _rhs) const noexcept;

	template <>
	CMat3d CMat3d::operator-(const CMat3d& _rhs) const noexcept;

	template <>
	CMat3d CMat3d::operator*(const CMat3d& _rhs) const noexcept;


	template <>
	Vec3<double> CMat3d::operator*(const Vec3<double>& _rhs) const noexcept;


	template <>
	template <>
	CMat3d& CMat3d::operator*=(double _scale) noexcept;

	template <>
	template <>
	CMat3d& CMat3d::operator/=(double _scale);

	template <>
	CMat3d& CMat3d::operator+=(const CMat3d& _rhs) noexcept;

	template <>
	CMat3d& CMat3d::operator-=(const CMat3d& _rhs) noexcept;


	template <>
	CMat3d operator/(double _lhs, const CMat3d& _rhs);

//}

#endif

	/// \endcond
}

/**
*	\example Matrix3Tests.cpp
*	Examples and Unitary Tests for Mat3.
*/


/** \} */

#include <SA/Maths/Matrix/Matrix3.inl>

#endif // GUARD
