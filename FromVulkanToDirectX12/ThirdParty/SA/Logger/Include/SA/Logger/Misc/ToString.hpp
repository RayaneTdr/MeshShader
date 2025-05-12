// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_TO_STRING_GUARD
#define SAPPHIRE_LOGGER_TO_STRING_GUARD

#include <cstdint>

#include <string>
#include <vector>

/**
*	\file ToString.hpp
*
*	\brief \b Definition of Sapphire \b ToString methods.
*
*	\ingroup Logger_Misc
*	\{
*/

namespace SA
{

//{ ToString

	/**
	*	\brief Binary ToString implementation.
	*
	*	Convert elem into bit array and print as hex values.
	* 
	*	\tparam T			Type of element.
	*	\param[in] _elem	Element to convert to string.
	* 
	*	\return	std::string from element converted in binary.
	*/
	template <typename T>
	std::string ToStringBinary(const T& _elem) noexcept;

	/// \cond Internal

	namespace Intl
	{
		/**
		*	\brief Internal Binary ToString implementation.
		* 
		*	Convert bit array into hex values.
		* 
		*	\param[in] _data	Bit array to convert.
		*	\param[in] _size	Size of the bit array.
		* 
		*	\return	string of bit array as hex values.
		*/
		std::string ToStringBinary(const char* _data, uint64_t _size) noexcept;
	}

	/// \endcond


	/**
	*	\brief ToString default implementation used to print elem.
	* 
	*	Convert basic types to string, otherwise make binary conversion.
	* 
	*	\tparam T			Type of element.
	*	\param[in] _elem	Element to convert to string.
	*
	*	\return	std::string from element converted.
	*/
	template <typename T>
	std::string ToString(const T& _elem);

	/**
	*	\brief ToString implementation used to print a pointer.
	*
	*	\tparam T			Type of the pointer.
	*	\param[in] _ptr		Pointer to convert to string.
	*
	*	\return	std::string from pointer converted.
	*/
	template <typename T>
	std::string ToString(T* _ptr);

	/**
	*	\brief ToString implementation used to print an array.
	*
	*	\tparam T			Type of the array.
	*	\param[in] _elems	Array pointer to convert to string.
	*	\param[in] _size	Size of the array.
	*
	*	\return	std::string from array converted.
	*/
	template <typename T>
	std::string ToString(const T* _elems, uint64_t _size);

	/**
	*	\brief ToString implementation used to print a vector.
	*
	*	\tparam T			Type of the vector.
	*	\param[in] _vec		Vector to convert to string.
	*
	*	\return	std::string from vector converted.
	*/
	template <typename T>
	std::string ToString(const std::vector<T>& _vec);


	/// \cond Internal

	/// ToString spec for single char.
	std::string ToString(const char& _char);

	/// ToString spec for cstr char*.
	std::string ToString(const char* _cstr);

	/// ToString spec for c++ str.
	std::string ToString(const std::string& _str) noexcept;

	/// ToString spec for c++ moved str.
	std::string ToString(std::string&& _str) noexcept;

	/// \endcond

//}


//{ ToWString

	/**
	*	\brief ToWString default implementation used to print elem.
	* 
	*	Convert basic types to wstring, otherwise make binary conversion.
	* 
	*	\tparam T			Type of element.
	*	\param[in] _elem	Element to convert to wstring.
	*
	*	\return	std::wstring from element converted.
	*/
	template <typename T>
	std::wstring ToWString(const T& _elem) noexcept;

	/**
	*	\brief ToWString implementation used to print a pointer.
	*
	*	\tparam T			Type of pointer.
	*	\param[in] _ptr		Pointer to convert to wstring.
	*
	*	\return	std::wstring from pointer converted.
	*/
	template <typename T>
	std::wstring ToWString(T* _ptr) noexcept;

	/**
	*	\brief ToWString implementation used to print an array.
	*
	*	\tparam T			Type of the array.
	*	\param[in] _elems	Array pointer to convert to wstring.
	*	\param[in] _size	Size of the array.
	*
	*	\return	std::wstring from array converted.
	*/
	template <typename T>
	std::wstring ToWString(const T* _elems, uint64_t _size);

	/**
	*	\brief ToWString implementation used to print a vector.
	*
	*	\tparam T			Type of the vector.
	*	\param[in] _vec		Vector to convert to wstring.
	*
	*	\return	std::wstring from vector converted.
	*/
	template <typename T>
	std::wstring ToWString(const std::vector<T>& _vec);

	
	/// \cond Internal

	/// ToWString spec for single char.
	std::wstring ToWString(const char& _char);

	/// ToWString spec for cstr char*.
	std::wstring ToWString(const char* _cstr);

	/// ToWString spec for single wchar.
	std::wstring ToWString(const wchar_t& _char);

	/// ToWString spec for cstr wchar*.
	std::wstring ToWString(const wchar_t* _cstr);

	/// ToWString spec for c++ str.
	std::wstring ToWString(const std::string& _str);

	/// ToWString spec for c++ wstr.
	std::wstring ToWString(const std::wstring& _str) noexcept;

	/// ToWString spec for c++ moved wstr.
	std::wstring ToWString(std::wstring&& _str) noexcept;

	/// \endcond

//}

} // namespace SA

#include <SA/Logger/Misc/ToString.inl>

/** \} */

#endif // GUARD
