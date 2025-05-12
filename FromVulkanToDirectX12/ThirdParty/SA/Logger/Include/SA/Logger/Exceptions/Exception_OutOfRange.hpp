// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_OUT_OF_RANGE_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_OUT_OF_RANGE_GUARD

#include <SA/Logger/Exceptions/Exception.hpp>

/**
*	\file Exception_OutOfRange.hpp
*
*	\brief <b>OutOfRange Exception</b> type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace SA
{
	/**
	*	\brief OutOfRange Exception type
	* 
	*	Exception will be thrown if curr is out of [min;max] range.
	*/
	class Exception_OutOfRange : public Exception
	{
	public:
		/// Index used for access.
		uint32_t currIndex = 0u;

		/// Minimum bound included.
		uint32_t minBound = 0u;

		/// Maximum bound included.
		uint32_t maxBound = 1u;

		/**
		*	\e Value Message Constructor.
		* 
		*	\param[in] _info		Base create info.
		*	\param[in] _currIndex	Index used for access.
		*	\param[in] _minBound	Minimum bound allowed.
		*	\param[in] _maxBound	Maximum bound allowed.
		*	\param[in] _msg			Message to display on assertion.
		*/
		Exception_OutOfRange(
			BaseInfo _info,
			uint32_t _currIndex,
			uint32_t _minBound,
			uint32_t _maxBound,
			std::wstring _msg
		) noexcept;


		/**
		*	\e Full \e Value Constructor.
		* 
		*	\param[in] _info			Base create info.
		*	\param[in] _currIndex		Index used for access.
		*	\param[in] _currIndexStr	Index variable used for access, as a wstring.
		*	\param[in] _minBound		Minimum bound allowed.
		*	\param[in] _minBoundStr		Min bound variable used for access, as a wstring.
		*	\param[in] _maxBound		Maximum bound allowed.
		*	\param[in] _maxBoundStr		Max bound variable used for access, as a wstring.
		*/
		Exception_OutOfRange(
			BaseInfo _info,
			uint32_t _currIndex,
			std::wstring _currIndexStr,
			uint32_t _minBound,
			std::wstring _minBoundStr,
			uint32_t _maxBound,
			std::wstring _maxBoundStr
		) noexcept;
	};
	

	/// \cond Internal

	/// Define OutOfRange Exception creation method.
	#define __SA_CREATE_EXCEPTION_OutOfRange(_baseInfo, _currIndex, _minBound, _maxBound) SA::Exception_OutOfRange(\
		_baseInfo,\
		_currIndex,\
		SA_WSTR(_currIndex),\
		_minBound,\
		SA_WSTR(_minBound),\
		_maxBound,\
		SA_WSTR(_maxBound)\
	)

	/// \endcond
}

/**
*	\example Exception_OutOfRangeTests.cpp
*	Examples and Unitary Tests for Exception_OutOfRange.
*/


/** \} */

#endif // GUARD
