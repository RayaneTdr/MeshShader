// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_OUT_OF_ARRAY_RANGE_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_OUT_OF_ARRAY_RANGE_GUARD

#include <SA/Logger/Exceptions/Exception_OutOfRange.hpp>

/**
*	\file Exception_OutOfArrayRange.hpp
*
*	\brief <b>OutOfRange Array Exception</b> type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace SA
{
	/**
	*	\brief OutOfArrayRange Exception type
	* 
	*	Exception will be thrown if curr is out of [0u;_array.size()[ range.
	*/
	class Exception_OutOfArrayRange : public Exception_OutOfRange
	{
	public:
		/**
		*	\e Value with bound Constructor.
		* 
		*	\param[in] _info			Base create info.
		*	\param[in] _currIndex		Index used for access.
		*	\param[in] _currIndexStr	Index variable used for access, as a wstring.
		*	\param[in] _array			Array to check bounds with.
		*	\param[in] _arrayName		Array variable to access, as a wstring.
		*	\param[in] _minBound		Optionnal array min bound
		*	\param[in] _maxBound		optionnal array max bound
		*/
		template <typename U>
		Exception_OutOfArrayRange(BaseInfo _info,
			uint32_t _currIndex,
			std::wstring _currIndexStr,
			const U& _array,
			std::wstring _arrayName = L"",
			uint32_t _minBound = 0,
			uint32_t _maxBound = uint32_t(-1)
		) noexcept :
			Exception_OutOfRange(std::move(_info),
				_currIndex,
				_minBound < static_cast<uint32_t>(_array.size()) ? _minBound : static_cast<uint32_t>(_array.size()) - 1,
				_maxBound < static_cast<uint32_t>(_array.size()) ? _maxBound : static_cast<uint32_t>(_array.size()) - 1,
				L"")
		{
			// Post initialization to use min/max bounds variables.
			msg = L"Index \'" + _currIndexStr + L"\' [" + ToWString(_currIndex) + L"] must be in array \'" + _arrayName +
				L"\' range [" + ToWString(minBound) + L';' + ToWString(maxBound) + L']';
		}
	};


	/// \cond Internal

	/// Define OutOfRange Exception creation method.
	#define __SA_CREATE_EXCEPTION_OutOfArrayRange(_baseInfo, _currIndex, _array, ...) SA::Exception_OutOfArrayRange(\
		_baseInfo,\
		_currIndex,\
		SA_WSTR(_currIndex),\
		_array,\
		SA_WSTR(_array),\
		##__VA_ARGS__\
	)

	/// \endcond
}


/**
*	\example Exception_OutOfArrayRangeTests.cpp
*	Examples and Unitary Tests for Exception_OutOfArrayRange.
*/


/** \} */

#endif // GUARD
