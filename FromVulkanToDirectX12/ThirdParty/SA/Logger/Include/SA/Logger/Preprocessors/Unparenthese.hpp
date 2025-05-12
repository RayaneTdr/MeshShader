// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_UNPARENTHESES_GUARD
#define SAPPHIRE_LOGGER_UNPARENTHESES_GUARD

namespace SA
{
	/// \cond Internal

	/**
	 * Optional macro argument parentheses: remove "only if" parentheses.
	 * 
	 * Sources:
	 * https://stackoverflow.com/a/62984543
	 * https://www.mikeash.com/pyblog/friday-qa-2015-03-20-preprocessor-abuse-and-optional-parentheses.html
	*/

	#define __SA_EXTRACT(...) __SA_EXTRACT __VA_ARGS__
	#define __SA_NOTHING__SA_EXTRACT
	#define __SA_PASTE(_x, ...) _x ## __VA_ARGS__
	#define __SA_EVAL_PASTE(_x, ...) __SA_PASTE(_x, __VA_ARGS__)
	#define __SA_UNPARENT(_x) __SA_EVAL_PASTE(__SA_NOTHING, __SA_EXTRACT _x)

	/// \endcond
}

#endif // GUARD
