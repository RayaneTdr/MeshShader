// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_FUNCTION_NAME_GUARD
#define SAPPHIRE_LOGGER_FUNCTION_NAME_GUARD

#include <SA/Support/Compilers.hpp>

namespace SA
{
	/// \cond Internal

	#if SA_GNU || SA_CLANG && !SA_MSVC

		#define __SA_FUNC_NAME __PRETTY_FUNCTION__

	#elif SA_MSVC

		#define __SA_FUNC_NAME __FUNCSIG__

	#else

		#define __SA_FUNC_NAME __FUNCTION__

	#endif

	/// \endcond
}

#endif // GUARD
