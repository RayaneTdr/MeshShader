// Copyright (c) 2023 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_GUARD

#include <SA/Maths/Debug.hpp>

#include <SA/Maths/Transform/Functors/TransformTRSMatrixFunctor.hpp>
#include <SA/Maths/Transform/Functors/TransformRotateAxisFunctor.hpp>

/**
 * @file Transform.hpp
 * 
 * @brief \b Transform type definition
 * 
 * @ingroup Maths_Transform
 * @{ 
 */


namespace SA
{
	/**
	 * @brief \e Transform Sapphire's class.
	 * 
	 * @tparam T 		Transform type.
	 * @tparam Args 	Transform component types.
	 */
	template <typename T, template <typename> typename... Args>
	struct Tr : public Args<T>...
	{
		/// Transform type alias.
		using Type = T;


		/**
		 * @brief \e compile-time HasComponent.
		 * 
		 * @tparam Comp Transform Component type
		 * @return Wether this has 'Comp' component.
		 */
		template <template <typename> typename Comp>
		static constexpr bool HasComponent() noexcept;


	//{ Equals

		/**
		*	\brief Whether this transform is a zero transform.
		*
		*	\return True if this is a zero transform.
		*/
		bool IsZero() const noexcept;

		/**
		*	\brief Whether this transform is an identity transform.
		*
		*	\return True if this is an identity transform.
		*/
		bool IsIdentity() const noexcept;

		/**
		*	\brief \e Compare 2 transform.
		*
		*	\param[in] _other		Other transform to compare to.
		*	\param[in] _epsilon		Epsilon value for threshold comparison.
		*
		*	\return Whether this and _other are equal.
		*/
		bool Equals(const Tr& _other, T _epsilon = std::numeric_limits<T>::epsilon()) const noexcept;


		/**
		*	\brief \e Compare 2 transform equality.
		*
		*	\param[in] _rhs		Other transform to compare to.
		*
		*	\return Whether this and _rhs are equal.
		*/
		bool operator==(const Tr& _rhs) const noexcept;

		/**
		*	\brief \e Compare 2 transform inequality.
		*
		*	\param[in] _rhs		Other transform to compare to.
		*
		*	\return Whether this and _rhs are non-equal.
		*/
		bool operator!=(const Tr& _rhs) const noexcept;

	//}


	//{ Transformation

		/**
		*	\brief \e Getter of \b right vector (X axis) of this transform.
		*
		*	\return transformed right vector normalized.
		*/
		template <typename TrFunc = TrRotateAxisFunctor>
		Vec3<T> Right(TrFunc _functor = TrFunc()) const;

		/**
		*	\brief \e Getter of \b up vector (Y axis) of this transform.
		*
		*	\return transformed up vector normalized.
		*/
		template <typename TrFunc = TrRotateAxisFunctor>
		Vec3<T> Up(TrFunc _functor = TrFunc()) const;

		/**
		*	\brief \e Getter of \b forward vector (Z axis) of this transform.
		*
		*	\return transformed forward vector normalized.
		*/
		template <typename TrFunc = TrRotateAxisFunctor>
		Vec3<T> Forward(TrFunc _functor = TrFunc()) const;


		/**
		 * @brief \b Compute matrix from transform
		 * Use default TRS order application.
		 * 
		 * @return transformation matrix.
		 */
		template <typename TrFunc = TrTRSMatrixFunctor>
		Mat4<T> Matrix(TrFunc _functor = TrFunc()) const noexcept;

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
		static Tr Lerp(const Tr& _start, const Tr& _end, float _alpha) noexcept;

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
		static Tr LerpUnclamped(const Tr& _start, const Tr& _end, float _alpha) noexcept;

	//}


	//{ Operators

		/**
		*	\brief \b Multiply transform to compute transformation.
		*
		*	\param[in] _rhs		Transform to multiply.
		*
		*	\return new transform result.
		*/
		template <template <typename> typename... InArgs>
		Tr operator*(const Tr<T, InArgs...>& _rhs) const;

		/**
		*	\brief \b Divide transform to compute inverse-transformation.
		*
		*	\param[in] _rhs		Transform to divide.
		*
		*	\return new transform result.
		*/
		template <template <typename> typename... InArgs>
		Tr operator/(const Tr<T, InArgs...>& _rhs) const;

		/**
		*	\brief \b Multiply transform to compute transformation.
		*
		*	\param[in] _rhs		Transform to multiply.
		*
		*	\return self transform result.
		*/
		template <template <typename> typename... InArgs>
		Tr& operator*=(const Tr<T, InArgs...>& _rhs);

		/**
		*	\brief \b Divide transform to compute inverse-transformation.
		*
		*	\param[in] _rhs		Transform to divide.
		*
		*	\return self transform result.
		*/
		template <template <typename> typename... InArgs>
		Tr& operator/=(const Tr<T, InArgs...>& _rhs);

	//}


	//{ Cast

		/**
		*	\brief \e Cast operator into other Transf type.
		*
		*	\tparam TOut		Type of the casted transform.
		*	\tparam ArgsOut		Args Type of the casted transform.
		*
		*	\return \e Casted result.
		*/
		template <typename TOut, template <typename> typename... ArgsOut>
		operator Tr<TOut, ArgsOut...>() const noexcept;

	//}

	private:

	//{ Packed

		template <typename CurrT, typename... PArgs>
		bool IsZeroPacked() const noexcept;

		template <typename CurrT, typename... PArgs>
		bool IsIdentityPacked() const noexcept;

		template <typename CurrT, typename... PArgs>
		bool EqualsPacked(const Tr& _other, T _epsilon) const noexcept;


		template <typename CurrT, typename... PArgs>
		void LerpUnclampedPacked(const Tr& _start, const Tr& _end, float _alpha) noexcept;


		template <typename TrIn, typename CurrT, typename... PArgs>
		void MultiplyPacked(const Tr& _lhs, const TrIn& _rhs) noexcept;

		template <typename TrIn, typename CurrT, typename... PArgs>
		void DividePacked(const Tr& _lhs, const TrIn& _rhs) noexcept;

	//}


	#if SA_LOGGER_IMPL

		template <typename CurrT, typename... PArgs>
		std::string ToStringPacked() const noexcept;

	public:

		std::string ToString() const noexcept;

	#endif
	};


#if SA_LOGGER_IMPL

	/**
	*	\brief ToString Transform implementation
	*
	*	Convert Transform as a string.
	*
	*	\tparam T		Input Transform type.
	*	\tparam Args	Input Transform component types.
	*
	*	\param[in] _tr	Input Transform.
	*
	*	\return input transform as a string.
	*/
	template <typename T, template <typename> typename... Args>
	std::string ToString(const Tr<T, Args...>& _tr) { return _tr.ToString(); }

#endif


//{ Aliases

//{ Tr aliases

	/// Alias for Position Tranf.
	template <typename T>
	using TrP = Tr<T, TrPosition>;

	/// Alias for Rotation Tranf.
	template <typename T>
	using TrR = Tr<T, TrRotation>;

	/// Alias for Scale Tranf.
	template <typename T>
	using TrS = Tr<T, TrScale>;

	/// Alias for UScale Tranf.
	template <typename T>
	using TrUS = Tr<T, TrUScale>;

	/// Alias for Position Rotation Tranf.
	template <typename T>
	using TrPR = Tr<T, TrPosition, TrRotation>;

	/// Alias for Position Rotation Scale Tranf.
	template <typename T>
	using TrPRS = Tr<T, TrPosition, TrRotation, TrScale>;

	/// Alias for Position Rotation UScale Tranf.
	template <typename T>
	using TrPRUS = Tr<T, TrPosition, TrRotation, TrUScale>;

//{ Float

	/// Alias for Position Tranf float.
	using TrPf = Tr<float, TrPosition>;

	/// Alias for Rotation Tranf float.
	using TrRf = Tr<float, TrRotation>;

	/// Alias for Scale Tranf float.
	using TrSf = Tr<float, TrScale>;

	/// Alias for UScale Tranf float.
	using TrUSf = Tr<float, TrUScale>;

	/// Alias for Position Rotation Tranf float.
	using TrPRf = Tr<float, TrPosition, TrRotation>;

	/// Alias for Position Rotation Scale Tranf float.
	using TrPRSf = Tr<float, TrPosition, TrRotation, TrScale>;

	/// Alias for Position Rotation UScale Tranf float.
	using TrPRUSf = Tr<float, TrPosition, TrRotation, TrUScale>;

//}


//{ Double

	/// Alias for Position Tranf double.
	using TrPd = Tr<double, TrPosition>;

	/// Alias for Rotation Tranf double.
	using TrRd = Tr<double, TrRotation>;

	/// Alias for Scale Tranf double.
	using TrSd = Tr<double, TrScale>;

	/// Alias for UScale Tranf double.
	using TrUSd = Tr<double, TrUScale>;

	/// Alias for Position Rotation Tranf double.
	using TrPRd = Tr<double, TrPosition, TrRotation>;

	/// Alias for Position Rotation Scale Tranf double.
	using TrPRSd = Tr<double, TrPosition, TrRotation, TrScale>;

	/// Alias for Position Rotation UScale Tranf double.
	using TrPRUSd = Tr<double, TrPosition, TrRotation, TrUScale>;

//}

//}


//{ Transform aliases

	/// Template alias of Tr
	template <typename T, template <typename> typename... Args>
	using Transform = Tr<T, Args...>;

	/// Alias for Position Transform.
	template <typename T>
	using TransformP = Transform<T, TrPosition>;

	/// Alias for Rotation Transform.
	template <typename T>
	using TransformR = Transform<T, TrRotation>;

	/// Alias for Scale Transform.
	template <typename T>
	using TransformS = Transform<T, TrScale>;

	/// Alias for UScale Transform.
	template <typename T>
	using TransformUS = Transform<T, TrUScale>;

	/// Alias for Position Rotation Transform.
	template <typename T>
	using TransformPR = Transform<T, TrPosition, TrRotation>;

	/// Alias for Position Rotation Scale Transform.
	template <typename T>
	using TransformPRS = Transform<T, TrPosition, TrRotation, TrScale>;

	/// Alias for Position Rotation UScale Transform.
	template <typename T>
	using TransformPRUS = Transform<T, TrPosition, TrRotation, TrUScale>;

//{ Float

	/// Alias for Position Transform float.
	using TransformPf = Transform<float, TrPosition>;

	/// Alias for Rotation Transform float.
	using TransformRf = Transform<float, TrRotation>;

	/// Alias for Scale Transform float.
	using TransformSf = Transform<float, TrScale>;

	/// Alias for UScale Transform float.
	using TransformUSf = Transform<float, TrUScale>;

	/// Alias for Position Rotation Transform float.
	using TransformPRf = Transform<float, TrPosition, TrRotation>;

	/// Alias for Position Rotation Scale Transform float.
	using TransformPRSf = Transform<float, TrPosition, TrRotation, TrScale>;

	/// Alias for Position Rotation UScale Transform float.
	using TransformPRUSf = Transform<float, TrPosition, TrRotation, TrUScale>;

//}


//{ Double

	/// Alias for Position Transform double.
	using TransformPd = Transform<double, TrPosition>;

	/// Alias for Rotation Transform double.
	using TransformRd = Transform<double, TrRotation>;

	/// Alias for Scale Transform double.
	using TransformSd = Transform<double, TrScale>;

	/// Alias for UScale Transform double.
	using TransformUSd = Transform<double, TrUScale>;

	/// Alias for Position Rotation Transform double.
	using TransformPRd = Transform<double, TrPosition, TrRotation>;

	/// Alias for Position Rotation Scale Transform double.
	using TransformPRSd = Transform<double, TrPosition, TrRotation, TrScale>;

	/// Alias for Position Rotation UScale Transform double.
	using TransformPRUSd = Transform<double, TrPosition, TrRotation, TrUScale>;

//}

//}

//}

}

/**
*	@example TransformTests.cpp
*	Examples and Unitary Tests for Transform.
*/

/** @} */

#include <SA/Maths/Transform/Transform.inl>

#endif // GUARD
