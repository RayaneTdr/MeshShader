// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <Exceptions/Exception_ReachBadAPI.hpp>

namespace SA
{
	Exception_ReachBadAPI::Exception_ReachBadAPI(
		BaseInfo _info,
		std::wstring _str
	) noexcept :
		Exception(std::move(_info), false, std::move(_str))
	{
	}
}
