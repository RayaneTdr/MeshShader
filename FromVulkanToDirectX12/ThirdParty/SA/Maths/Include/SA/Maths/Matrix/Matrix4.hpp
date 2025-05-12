// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_MATRIX4_GUARD
#define SAPPHIRE_MATHS_MATRIX4_GUARD

#include <limits>

#include <SA/Maths/Debug.hpp>
#include <SA/Maths/Config.hpp>

#include <SA/Maths/Matrix/Matrix4Base.hpp>

#include <SA/Maths/Algorithms/Lerp.hpp>
#include <SA/Maths/Algorithms/Equals.hpp>

#if SA_MATHS_MATRIX4_SIMD

	#include <SA/Support/Intrinsics.hpp>

#endif

/**
*	\file Matrix4.hpp
*
*	\brief <b>Matrix 4x4</b> type implementation.
*
*	\ingroup Maths_Matrix
*	\{
*/


namespace SA
{
	template <typename T>
	struct Vec3;

	template <typename T>
	struct Vec4;

	template <typename T>
	struct Quat;

	template <typename T, MatrixMajor major>
	struct Mat3;


	/**
	*	\brief \e Matrix 4x4 Sapphire-Maths class.
	*
	* 	must be align at 32 for intrinsics.
	* 
	*	\tparam T	Type of the matrix.
	*/

#if SA_MATHS_MATRIX4_SIMD && SA_INTRISC

	template <typename T, MatrixMajor major = MatrixMajor::Default>
	struct alignas(32) Mat4 : public Intl::Mat4_Base<T, major>

#else

	template <typename T, MatrixMajor major = MatrixMajor::Default>
	struct Mat4 : public Intl::Mat4_Base<T, major>

#endif
	{
		using Intl::Mat4_Base<T, major>::e00;
		using Intl::Mat4_Base<T, major>::e01;
		using Intl::Mat4_Base<T, major>::e02;
		using Intl::Mat4_Base<T, major>::e03;

		using Intl::Mat4_Base<T, major>::e10;
		using Intl::Mat4_Base<T, major>::e11;
		using Intl::Mat4_Base<T, major>::e12;
		using Intl::Mat4_Base<T, major>::e13;

		using Intl::Mat4_Base<T, major>::e20;
		using Intl::Mat4_Base<T, major>::e21;
		using Intl::Mat4_Base<T, major>::e22;
		using Intl::Mat4_Base<T, major>::e23;

		using Intl::Mat4_Base<T, major>::e30;
		using Intl::Mat4_Base<T, major>::e31;
		using Intl::Mat4_Base<T, major>::e32;
		using Intl::Mat4_Base<T, major>::e33;

//{ Constants

		/**
		*	\brief Zero Mat4 constant
		* 
		*	{0, 0, 0, 0}
		*	{0, 0, 0, 0}
		*	{0, 0, 0, 0}
		*	{0, 0, 0, 0}
		*/
		static const Mat4 Zero;

		/**
		*	\brief Identity Mat4 constant
		* 
		*	{1, 0, 0, 0}
		*	{0, 1, 0, 0}
		*	{0, 0, 1, 0}
		*	{0, 0, 0, 1}
		*/
		static const Mat4 Identity;

//}

//{ Constructors

		using Intl::Mat4_Base<T, major>::Mat4_Base;

		/**
		*	\brief \e Value constructor from another Mat4 type.
		*
		*	\tparam TIn			Type of the input Mat4.
		*	\tparam majorIn		Major of the input Mat4.
		*
		*	\param[in] _other	Mat4 to construct from.
		*/
		template <typename TIn, MatrixMajor majorIn>
		constexpr Mat4(const Mat4<TIn, majorIn>& _other) noexcept;

		/**
		*	\brief \e Value constructor from another Mat3 type.
		*
		*	\tparam TIn			Type of the input Mat3.
		*	\tparam majorIn		Major of the input Mat4.
		*
		*	\param[in] _other	Mat3 to construct from.
		*/
		template <typename TIn, MatrixMajor majorIn>
		constexpr Mat4(const Mat3<TIn, majorIn>& _other) noexcept;

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
		*	\param[in] _threshold	Allowed threshold to accept equality.
		*
		*	\return Whether this and _other are equal.
		*/
		constexpr bool Equals(const Mat4& _other, T _threshold = std::numeric_limits<T>::epsilon()) const noexcept;


		/**
		*	\brief \e Compare 2 matrix equality.
		*
		*	\param[in] _rhs		Other matrix to compare to.
		*
		*	\return Whether this and _rhs are equal.
		*/
		constexpr bool operator==(const Mat4& _rhs) const noexcept;

		/**
		*	\brief \e Compare 2 matrix inequality.
		*
		*	\param[in] _rhs		Other matrix to compare to.
		*
		*	\return Whether this and _rhs are non-equal.
		*/
		constexpr bool operator!=(const Mat4& _rhs) const noexcept;

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
		Mat4& Transpose() noexcept;

		/**
		*	\brief \b Transpose this matrix.
		*
		*	\return new transposed matrix.
		*/
		constexpr Mat4 GetTransposed() const noexcept;

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
		Mat4& Inverse();

		/**
		*	\brief \b Inverse this matrix.
		*
		*	\return new inversed matrix.
		*/
		Mat4 GetInversed() const;

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
		static Mat4 Lerp(const Mat4& _start, const Mat4& _end, float _alpha) noexcept;

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
		static Mat4 LerpUnclamped(const Mat4& _start, const Mat4& _end, float _alpha) noexcept;

//}

//{ Transform


		/**
		*	\brief Make <b> translation matrix </b> from vector3.
		*
		*	\param[in] _transl	Vector to translate
		*
		*	\return translation matrix.
		*/
		static Mat4 MakeTranslation(const Vec3<T>& _transl) noexcept;

		/**
		*	\brief Make <b> rotation matrix </b> from quaternion.
		*
		*	\param[in] _rot	quaternion to use for rotation.
		*
		*	\return rotation matrix.
		*/
		static Mat4 MakeRotation(const Quat<T>& _rot) noexcept;

		/**
		*	\brief Make <b> scale matrix </b> from vector3.
		*
		*	\param[in] _scale	Vector for scaling.
		*
		*	\return scale matrix.
		*/
		static Mat4 MakeScale(const Vec3<T>& _scale) noexcept;

		/**
		 *	\brief Make <b> LookAt matrix </b> from center, target and up.
		 * 
		 *	\param[in] _eye		Center (camera).
		 *	\param[in] _target	Target to look at.
		 *	\param[in] _up		Up vector (camera).
		 *
		 * 	\returns LookAt matrix.
		*/
		static Mat4 MakeLookAt(const Vec3<T>& _eye, const Vec3<T>& _target, const Vec3<T>& _up);

		/**
		 * \brief Make <b> view matrix </b> for camera.
		 * 
		 * @param _eye 			Camera's world position
		 * @param _forward 		Camera forward vector
		 * @param _up 			Camera's up vector.
		 * 
		 * @return Inverse View matrix. 
		 */
		// static Mat4 MakeView(const Vec3<T>& _eye, const Vec3<T>& _forward, const Vec3<T>& _up);

		/**
		 * \brief Make <b> inverse view matrix </b> for camera.
		 * 
		 * @param _eye 			Camera's world position
		 * @param _forward 		Camera forward vector
		 * @param _up 			Camera's up vector.
		 * 
		 * @return Inverse View matrix. 
		 */
		static Mat4 MakeInverseView(const Vec3<T>& _eye, const Vec3<T>& _forward, const Vec3<T>& _up);

		/**
		*	\brief Make <b> perspective matrix </b>.
		*
		*	\param[in] _fov			Perspective FOV.
		*	\param[in] _aspect		Aspect ratio (width/height).
		*	\param[in] _near		Near frustum.
		*	\param[in] _far			Far frustum.
		*
		*	\return perspective matrix.
		*/
		static Mat4 MakePerspective(T _fov = T(90.0), T _aspect = T(1.0), T _near = T(0.35), T _far = T(10.0)) noexcept;

//}

//{ Operators
		
		/**
		*	\brief \e Assignment operator from another Mat4 type.
		*
		*	\tparam TIn			Type of the input Mat4.
		*	\tparam majorIn		Major of the input Mat4.
		*
		*	\param[in] _rhs		Mat4 to assign from.
		*/
		template <typename TIn, MatrixMajor majorIn>
		Mat4& operator=(const Mat4<TIn, majorIn> _rhs) noexcept;

		/**
		*	\brief \e Getter of the opposite signed matrix.
		*
		*	\return new opposite signed matrix.
		*/
		constexpr Mat4 operator-() const noexcept;

		/**
		*	\brief \b Scale each matrix component by _scale.
		*
		*	\tparam TIn			Type of the input scale.
		*	\param[in] _scale	Scale value to apply on all components.
		*
		*	\return new matrix scaled.
		*/
		template<typename TIn>
		Mat4 operator*(TIn _scale) const noexcept;

		/**
		*	\brief <b> Inverse Scale </b> each matrix component by _scale.
		*
		*	\tparam TIn			Type of the input scale.
		*	\param[in] _scale	Inverse scale value to apply on all components.
		*
		*	\return new matrix inverse-scaled.
		*/
		template<typename TIn>
		Mat4 operator/(TIn _scale) const;

		/**
		*	\brief \b Add term by term matrix values.
		*
		*	\param[in] _rhs		Matrix to add.
		*
		*	\return new matrix result.
		*/
		Mat4 operator+(const Mat4& _rhs) const noexcept;

		/**
		*	\brief \b Subtract term by term matrix values.
		*
		*	\param[in] _rhs		Matrix to substract.
		*
		*	\return new matrix result.
		*/
		Mat4 operator-(const Mat4& _rhs) const noexcept;

		/**
		*	\brief \b Multiply matrices.
		*
		*	\param[in] _rhs		Matrix to multiply to.
		*
		*	\return new matrix result.
		*/
		Mat4 operator*(const Mat4& _rhs) const noexcept;

		/**
		*	\brief \b Inverse multiply matrices.
		*
		*	\param[in] _rhs		Matrix to inverse multiply to.
		*
		*	\return new matrix result.
		*/
		Mat4 operator/(const Mat4& _rhs) const;


		/**
		*	\brief transform this vector by this matrix.
		*
		*	Ignore 4th row/column component.
		*
		*	\param[in] _rhs		Vector to transform.
		*
		*	\return Transformed vector.
		*/
		Vec3<T> operator*(const Vec3<T>&_rhs) const noexcept;

		/**
		*	\brief transform this vector by this matrix.
		*
		*	\param[in] _rhs		Vector to transform.
		*
		*	\return Transformed vector.
		*/
		Vec4<T> operator*(const Vec4<T>&_rhs) const noexcept;


		/**
		*	\brief \b Scale each matrix component by _scale.
		*
		*	\tparam TIn			Type of the input scale.
		*	\param[in] _scale	Scale value to apply on all components.
		*
		*	\return self matrix scaled.
		*/
		template<typename TIn>
		Mat4& operator*=(TIn _scale) noexcept;

		/**
		*	\brief <b> Inverse Scale </b> each matrix component by _scale.
		*
		*	\tparam TIn			Type of the input scale.
		*	\param[in] _scale	Inverse scale value to apply on all components.
		*
		*	\return self matrix inverse-scaled.
		*/
		template<typename TIn>
		Mat4& operator/=(TIn _scale);

		/**
		*	\brief \b Add term by term matrix values.
		*
		*	\param[in] _rhs		Matrix to add.
		*
		*	\return self matrix result.
		*/
		Mat4& operator+=(const Mat4& _rhs) noexcept;

		/**
		*	\brief \b Subtract term by term matrix values.
		*
		*	\param[in] _rhs		Matrix to substract.
		*
		*	\return self matrix result.
		*/
		Mat4& operator-=(const Mat4& _rhs) noexcept;

		/**
		*	\brief \b Multiply matrices.
		*
		*	\param[in] _rhs		Matrix to multiply to.
		*
		*	\return self matrix result.
		*/
		Mat4& operator*=(const Mat4& _rhs) noexcept;

		/**
		*	\brief \b Inverse multiply matrices.
		*
		*	\param[in] _rhs		Matrix to inverse multiply to.
		*
		*	\return self matrix result.
		*/
		Mat4& operator/=(const Mat4& _rhs);

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

#if SA_MATHS_MATRIX4_SIMD && SA_INTRISC

	// Disable padding struct warning.
	//SA_PRAGMA_EDWARN_MSVC()

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
	Mat4<T, major> operator*(TIn _lhs, const Mat4<T, major>& _rhs) noexcept;

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
	Mat4<T, major> operator/(TIn _lhs, const Mat4<T, major>& _rhs);


#if SA_LOGGER_IMPL

	/**
	*	\brief ToString Mat4 implementation
	*
	*	Convert Mat4 as a string.
	*
	*	\tparam T		Input matrix type.
	*	\tparam major	Input matrix major.
	*
	*	\param[in] _m	Input matrix.
	*
	*	\return input matrix as a string.
	*/
	template <typename T, MatrixMajor major>
	std::string ToString(const Mat4<T, major>& _m);

#endif


//{ Aliases

	/// Alias for int32 Mat4.
	using Mat4i = Mat4<int32_t>;

	/// Alias for float Mat4.
	using Mat4f = Mat4<float>;

	/// Alias for double Mat4.
	using Mat4d = Mat4<double>;


	/// Template alias of Mat4
	template <typename T, MatrixMajor major = MatrixMajor::Default>
	using Matrix4 = Mat4<T>;

	/// Alias for int32 Matrix4.
	using Matrix4i = Matrix4<int32_t>;

	/// Alias for float Matrix4.
	using Matrix4f = Matrix4<float>;

	/// Alias for double Matrix4.
	using Matrix4d = Matrix4<double>;


	/// Alias for row major int32 Mat4.
	using RMat4i = Mat4<int32_t, MatrixMajor::Row>;

	/// Alias for row major float Mat4.
	using RMat4f = Mat4<float, MatrixMajor::Row>;

	/// Alias for row major double Mat4.
	using RMat4d = Mat4<double, MatrixMajor::Row>;


	/// Alias for column major int32 Mat4.
	using CMat4i = Mat4<int32_t, MatrixMajor::Column>;

	/// Alias for column major float Mat4.
	using CMat4f = Mat4<float, MatrixMajor::Column>;

	/// Alias for column major double Mat4.
	using CMat4d = Mat4<double, MatrixMajor::Column>;

//}

	/// \cond Internal

#if SA_MATHS_MATRIX4_SIMD && SA_INTRISC_AVX // SIMD int32

//{ Row Major

	template <>
	template <>
	RMat4i RMat4i::operator*(int32_t _scale) const noexcept;

#if SA_INTRISC_SVML
	template <>
	template <>
	RMat4i RMat4i::operator/(int32_t _scale) const;
#endif

	template <>
	RMat4i RMat4i::operator+(const RMat4i& _rhs) const noexcept;

	template <>
	RMat4i RMat4i::operator-(const RMat4i& _rhs) const noexcept;

	template <>
	RMat4i RMat4i::operator*(const RMat4i& _rhs) const noexcept;


	template <>
	Vec3<int32_t> RMat4i::operator*(const Vec3<int32_t>& _rhs) const noexcept;

	template <>
	Vec4<int32_t> RMat4i::operator*(const Vec4<int32_t>& _rhs) const noexcept;


	template <>
	template <>
	RMat4i& RMat4i::operator*=(int32_t _scale) noexcept;

#if SA_INTRISC_SVML
	template <>
	template <>
	RMat4i& RMat4i::operator/=(int32_t _scale);
#endif

	template <>
	RMat4i& RMat4i::operator+=(const RMat4i& _rhs) noexcept;

	template <>
	RMat4i& RMat4i::operator-=(const RMat4i& _rhs) noexcept;

//}

//{ Column Major

	template <>
	template <>
	CMat4i CMat4i::operator*(int32_t _scale) const noexcept;

#if SA_INTRISC_SVML
	template <>
	template <>
	CMat4i CMat4i::operator/(int32_t _scale) const;
#endif

	template <>
	CMat4i CMat4i::operator+(const CMat4i& _rhs) const noexcept;

	template <>
	CMat4i CMat4i::operator-(const CMat4i& _rhs) const noexcept;

	template <>
	CMat4i CMat4i::operator*(const CMat4i& _rhs) const noexcept;


	template <>
	Vec3<int32_t> CMat4i::operator*(const Vec3<int32_t>& _rhs) const noexcept;

	template <>
	Vec4<int32_t> CMat4i::operator*(const Vec4<int32_t>& _rhs) const noexcept;


	template <>
	template <>
	CMat4i& CMat4i::operator*=(int32_t _scale) noexcept;

#if SA_INTRISC_SVML
	template <>
	template <>
	CMat4i& CMat4i::operator/=(int32_t _scale);
#endif

	template <>
	CMat4i& CMat4i::operator+=(const CMat4i& _rhs) noexcept;

	template <>
	CMat4i& CMat4i::operator-=(const CMat4i& _rhs) noexcept;

//}

#endif

#if SA_MATHS_MATRIX4_SIMD && SA_INTRISC_SSE // SIMD float

//{ Row Major

	template <>
	float RMat4f::Determinant() const noexcept;

	template <>
	RMat4f RMat4f::GetInversed() const;


	template <>
	RMat4f RMat4f::MakeRotation(const Quat<float>& _rot) noexcept;


	template <>
	template <>
	RMat4f RMat4f::operator*(float _scale) const noexcept;

	template <>
	template <>
	RMat4f RMat4f::operator/(float _scale) const;

	template <>
	RMat4f RMat4f::operator+(const RMat4f& _rhs) const noexcept;

	template <>
	RMat4f RMat4f::operator-(const RMat4f& _rhs) const noexcept;

	template <>
	RMat4f RMat4f::operator*(const RMat4f& _rhs) const noexcept;


	template <>
	Vec3<float> RMat4f::operator*(const Vec3<float>& _rhs) const noexcept;

	template <>
	Vec4<float> RMat4f::operator*(const Vec4<float>& _rhs) const noexcept;


	template <>
	template <>
	RMat4f& RMat4f::operator*=(float _scale) noexcept;

	template <>
	template <>
	RMat4f& RMat4f::operator/=(float _scale);

	template <>
	RMat4f& RMat4f::operator+=(const RMat4f& _rhs) noexcept;

	template <>
	RMat4f& RMat4f::operator-=(const RMat4f& _rhs) noexcept;


	template <>
	RMat4f operator/(float _lhs, const RMat4f& _rhs);

//}

//{ Column Major

	template <>
	float CMat4f::Determinant() const noexcept;

	template <>
	CMat4f CMat4f::GetInversed() const;


	template <>
	CMat4f CMat4f::MakeRotation(const Quat<float>& _rot) noexcept;


	template <>
	template <>
	CMat4f CMat4f::operator*(float _scale) const noexcept;

	template <>
	template <>
	CMat4f CMat4f::operator/(float _scale) const;

	template <>
	CMat4f CMat4f::operator+(const CMat4f& _rhs) const noexcept;

	template <>
	CMat4f CMat4f::operator-(const CMat4f& _rhs) const noexcept;

	template <>
	CMat4f CMat4f::operator*(const CMat4f& _rhs) const noexcept;


	template <>
	Vec3<float> CMat4f::operator*(const Vec3<float>& _rhs) const noexcept;

	template <>
	Vec4<float> CMat4f::operator*(const Vec4<float>& _rhs) const noexcept;


	template <>
	template <>
	CMat4f& CMat4f::operator*=(float _scale) noexcept;

	template <>
	template <>
	CMat4f& CMat4f::operator/=(float _scale);

	template <>
	CMat4f& CMat4f::operator+=(const CMat4f& _rhs) noexcept;

	template <>
	CMat4f& CMat4f::operator-=(const CMat4f& _rhs) noexcept;


	template <>
	CMat4f operator/(float _lhs, const CMat4f& _rhs);

//}

#endif

#if SA_MATHS_MATRIX4_SIMD && SA_INTRISC_AVX // SIMD double

//{ Row Major

	template <>
	double RMat4d::Determinant() const noexcept;

	template <>
	RMat4d RMat4d::GetInversed() const;


	template <>
	RMat4d RMat4d::MakeRotation(const Quat<double>& _rot) noexcept;


	template <>
	template <>
	RMat4d RMat4d::operator*(double _scale) const noexcept;

	template <>
	template <>
	RMat4d RMat4d::operator/(double _scale) const;

	template <>
	RMat4d RMat4d::operator+(const RMat4d& _rhs) const noexcept;

	template <>
	RMat4d RMat4d::operator-(const RMat4d& _rhs) const noexcept;

	template <>
	RMat4d RMat4d::operator*(const RMat4d& _rhs) const noexcept;


	template <>
	Vec3<double> RMat4d::operator*(const Vec3<double>& _rhs) const noexcept;

	template <>
	Vec4<double> RMat4d::operator*(const Vec4<double>& _rhs) const noexcept;


	template <>
	template <>
	RMat4d& RMat4d::operator*=(double _scale) noexcept;

	template <>
	template <>
	RMat4d& RMat4d::operator/=(double _scale);

	template <>
	RMat4d& RMat4d::operator+=(const RMat4d& _rhs) noexcept;

	template <>
	RMat4d& RMat4d::operator-=(const RMat4d& _rhs) noexcept;


	template <>
	RMat4d operator/(double _lhs, const RMat4d& _rhs);

//}

//{ Column Major

	template <>
	double CMat4d::Determinant() const noexcept;

	template <>
	CMat4d CMat4d::GetInversed() const;


	template <>
	CMat4d CMat4d::MakeRotation(const Quat<double>& _rot) noexcept;


	template <>
	template <>
	CMat4d CMat4d::operator*(double _scale) const noexcept;

	template <>
	template <>
	CMat4d CMat4d::operator/(double _scale) const;

	template <>
	CMat4d CMat4d::operator+(const CMat4d& _rhs) const noexcept;

	template <>
	CMat4d CMat4d::operator-(const CMat4d& _rhs) const noexcept;

	template <>
	CMat4d CMat4d::operator*(const CMat4d& _rhs) const noexcept;


	template <>
	Vec3<double> CMat4d::operator*(const Vec3<double>& _rhs) const noexcept;

	template <>
	Vec4<double> CMat4d::operator*(const Vec4<double>& _rhs) const noexcept;


	template <>
	template <>
	CMat4d& CMat4d::operator*=(double _scale) noexcept;

	template <>
	template <>
	CMat4d& CMat4d::operator/=(double _scale);

	template <>
	CMat4d& CMat4d::operator+=(const CMat4d& _rhs) noexcept;

	template <>
	CMat4d& CMat4d::operator-=(const CMat4d& _rhs) noexcept;


	template <>
	CMat4d operator/(double _lhs, const CMat4d& _rhs);

//}

#endif

	/// \endcond
}

/**
*	\example Matrix4Tests.cpp
*	Examples and Unitary Tests for Mat4.
*/


/** \} */

#include <SA/Maths/Matrix/Matrix4.inl>

#endif // GUARD
