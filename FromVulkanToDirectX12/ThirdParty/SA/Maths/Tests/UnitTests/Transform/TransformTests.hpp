// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#include <ostream>

#include <gtest/gtest.h>

#include <SA/Maths/Transform/Transform.hpp>

#include "../Space/Vector3Tests.hpp"
#include "../Space/QuaternionTests.hpp"

namespace SA
{
	/* Must be declared in SA:: */
	template <typename T, template <typename> typename... Args>
	std::ostream& operator<<(std::ostream& _os, const Tr<T, Args...>& _tr)
	{
#if SA_LOGGER_IMPL

		return _os << "\n\t" << ToString(_tr);

#else

		if constexpr (std::is_base_of<TrPosition<T>, Tr<T, Args...>>::value)
			_os << "\nPos: " << _tr.position;
		if constexpr (std::is_base_of<TrRotation<T>, Tr<T, Args...>>::value)
			_os << "\nRot: " << _tr.rotation;
		if constexpr (std::is_base_of<TrScale<T>, Tr<T, Args...>>::value)
			_os << "\nScale: " << _tr.scale;
		if constexpr (std::is_base_of<TrUScale<T>, Tr<T, Args...>>::value)
			_os << "\nUScale: " << _tr.uScale;

		return _os;

#endif
	}
}

/// Google Test typedef helper.
#define TrT TrPRS<TypeParam>

#define EXPECT_TR_NEAR(_tr1, _tr2, eps)\
{\
	auto tr1V = (_tr1);\
	auto tr2V = (_tr2);\
\
	if constexpr (decltype(tr1V)::template HasComponent<TrPosition>())\
	{\
		EXPECT_VEC3_NEAR(tr1V.position, tr2V.position, eps);\
	}\
	if constexpr (decltype(tr1V)::template HasComponent<TrRotation>())\
	{\
		EXPECT_QUAT_NEAR(tr1V.rotation, tr2V.rotation, eps);\
	}\
	if constexpr (decltype(tr1V)::template HasComponent<TrScale>())\
	{\
		EXPECT_VEC3_NEAR(tr1V.scale, tr2V.scale, eps);\
	}\
	if constexpr (decltype(tr1V)::template HasComponent<TrUScale>())\
	{\
		EXPECT_NEAR(tr1V.uScale, tr2V.uScale, eps);\
	}\
}
