// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_REACH_BAD_API_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_REACH_BAD_API_GUARD

#include <SA/Logger/Exceptions/Exception.hpp>

/**
*	\file Exception_ReachBadAPI.hpp
*
*	\brief <b>ReachBadAPI Exception</b> type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace SA
{
	/// ReachBadAPI
	class Exception_ReachBadAPI : public Exception
	{
	public:
		/**
		*	\e Value Constructor.
		*
		*	\param[in] _info		Base create info.
		*	\param[in] _str			Message string.
		*/
		Exception_ReachBadAPI(
			BaseInfo _info,
			std::wstring _str
		) noexcept;
	};

	class Exception_QueryBadAPIObject : public Exception_ReachBadAPI
	{
	public:
		using Exception_ReachBadAPI::Exception_ReachBadAPI;
	};


	/// \cond Internal

	/// Define Nullptr Exception creation method.
	#define __SA_CREATE_EXCEPTION_ReachBadAPI(_baseInfo, _apiName) SA::Exception_ReachBadAPI(\
		_baseInfo,\
		L"Reach bad [" SA_WSTR(_apiName) L"] API call."\
	)

	/// Define Nullptr Exception creation method.
	#define __SA_CREATE_EXCEPTION_QueryBadAPIObject(_baseInfo, _apiName) SA::Exception_QueryBadAPIObject(\
		_baseInfo,\
		L"Query [" SA_WSTR(_apiName) L"] API handle from non-[" SA_WSTR(_apiName) L"] object!"\
	)

	/// \endcond
}

/**
*	\example Exception_ReachBadAPITests.cpp
*	Examples and Unitary Tests for Exception_ReachBadAPI.
*/


/** \} */

#endif // SAPPHIRE_LOGGER_EXCEPTION_REACH_BAD_API_GUARD
