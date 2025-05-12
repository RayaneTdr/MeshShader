// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <Exceptions/Exception_NotEquals.hpp>

namespace SA
{
	Exception_NotEquals::Exception_NotEquals(Exception_Equals&& _exc) noexcept :
		Exception(std::move(_exc))
	{
		// Replace "==" into "!="
		{
			size_t index = msg.find(L"==");

			while (index != std::wstring::npos)
			{
				msg.replace(index, 2, L"!=");
				index = msg.find(L"==");
			}

			msg.replace(msg.rfind(L"Values must be equal."), 21, L"Values must be NOT equal.");
		}

		// Reverse predicate.
		if(level == LogLevel::AssertSuccess)
			level = LogLevel::AssertFailure;
		else if(level == LogLevel::AssertFailure)
			level = LogLevel::AssertSuccess;
	}
}
