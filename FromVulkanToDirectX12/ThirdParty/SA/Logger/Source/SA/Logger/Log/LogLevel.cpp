// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <Log/LogLevel.hpp>

#include <SA/Support/Algorithms/BitScanForward.hpp>

namespace SA
{
	std::string ToString(LogLevel _lvl) noexcept
	{
		static constexpr const char* const names[]{
			"Unknown",
			"Normal",
			"Info",
			"Warning",
			"Error",
			"AssertSuccess",
			"AssertFailure"
		};

		return names[BitScanForward(static_cast<uint32_t>(_lvl)) + 1u];
	}

	std::wstring ToWString(LogLevel _lvl) noexcept
	{
		static constexpr const wchar_t* const names[]{
			L"Unknown", 
			L"Normal",
			L"Info",
			L"Warning",
			L"Error", 
			L"AssertSuccess",
			L"AssertFailure"
		};

		return names[BitScanForward(static_cast<uint32_t>(_lvl)) + 1u];
	}
}
