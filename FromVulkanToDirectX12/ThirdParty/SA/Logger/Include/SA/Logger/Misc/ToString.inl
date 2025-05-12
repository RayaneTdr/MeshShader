// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

namespace SA
{
//{ ToString

	template <typename T>
	std::string ToStringBinary(const T& _elem) noexcept
	{
		return Intl::ToStringBinary(reinterpret_cast<const char*>(&_elem), sizeof(T));
	}


	template <typename T>
	std::string ToString(const T& _elem)
	{
		if constexpr (std::is_arithmetic<T>::value)
			return std::to_string(_elem);
		else
			return ToStringBinary(_elem);
	}

	template <typename T>
	std::string ToString(T* _ptr)
	{
		return "0x" + std::to_string(reinterpret_cast<uint64_t>(_ptr));
	}

	template <typename T>
	std::string ToString(const T* _elems, uint64_t _size)
	{
		std::string res = "{ ";

		for (uint32_t i = 0; i < _size; ++i)
			res += ToString(_elems[i]) + " | ";

		res[res.size() - 2] = ' ';
		res[res.size() - 1] = '}';

		return res;
	}

	template <typename T>
	std::string ToString(const std::vector<T>& _vec)
	{
		return ToString(_vec.data(), _vec.size());
	}

//}


//{ ToWString

	template <typename T>
	std::wstring ToWString(const T& _elem) noexcept
	{
		if constexpr (std::is_arithmetic<T>::value)
			return std::to_wstring(_elem);
		else
			return ToWString(ToString(_elem));
	}

	template <typename T>
	std::wstring ToWString(T* _ptr) noexcept
	{
		return L"0x" + std::to_wstring(reinterpret_cast<uint64_t>(_ptr));
	}

	template <typename T>
	std::wstring ToWString(const T* _elems, uint64_t _size)
	{
		std::wstring res = L"{ ";

		for (uint32_t i = 0; i < _size; ++i)
			res += ToWString(_elems[i]) + L", ";

		res[res.size() - 2] = L' ';
		res[res.size() - 1] = L'}';

		return res;
	}

	template <typename T>
	std::wstring ToWString(const std::vector<T>& _vec)
	{
		return ToWString(_vec.data(), _vec.size());
	}

//}
}
