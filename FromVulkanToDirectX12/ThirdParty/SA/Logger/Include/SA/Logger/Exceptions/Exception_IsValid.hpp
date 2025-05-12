// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_IS_VALID_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_IS_VALID_GUARD

#include <SA/Logger/Exceptions/Exception.hpp>

/**
*	\file Exception_IsValid.hpp
*
*	\brief <b>IsValid Exception</b> type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace SA
{
	/**
	*	\brief IsValid Exception type
	* 
	*	Exception will be thrown if \e _obj->IsValid() returns false.
	*/
	class Exception_IsValid : public Exception
	{
	public:
		/**
		 * @brief \e Value constructor
		 * 
		 * @tparam T 	Object type
		 * 
		 * @param _info 	Base create info.
		 * @param _obj 		Object to check validity
		 * @param _objStr 	Object variable as a string.
		 */
		template <typename T>
		Exception_IsValid(BaseInfo _info,
			const T& _obj,
			std::wstring _objStr
		) noexcept :
			Exception(std::move(_info),
				_obj.IsValid(),
				SA::StringFormat(L"Object \'%1\' of type [%2] and value [%3] .IsValid() must return true!", _objStr, typeid(T).name(), _obj)
			)
		{
		}
	};


	/// \cond Internal

	/// Define IsValid Exception creation method.
	#define __SA_CREATE_EXCEPTION_IsValid(_baseInfo, _obj) SA::Exception_IsValid(\
		_baseInfo,\
		_obj,\
		SA_WSTR(_obj)\
	)

	/// Define IsValid Exception creation method for *this specialization.
	#define __SA_CREATE_EXCEPTION_IsThisValid(_baseInfo)\
		__SA_CREATE_EXCEPTION_IsValid(_baseInfo, *this)

	/// \endcond
}


/**
*	\example Exception_IsValidTests.cpp
*	Examples and Unitary Tests for Exception_IsValid.
*/


/** \} */

#endif // GUARD
