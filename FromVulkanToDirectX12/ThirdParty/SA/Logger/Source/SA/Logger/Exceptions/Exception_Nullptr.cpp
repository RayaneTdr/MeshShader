// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <Exceptions/Exception_Nullptr.hpp>

namespace SA
{
	Exception_Nullptr::Exception_Nullptr(
		BaseInfo _info,
		bool _pred,
		std::wstring _predStr
	) noexcept :
		Exception(std::move(_info), _pred, _predStr + L" must be not null!")
	{
	}
}
