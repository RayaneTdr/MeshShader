// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <Exceptions/Exception.hpp>

namespace SA
{
	Exception::Exception(
		BaseInfo _info,
		bool _pred,
		std::wstring _msg
	) noexcept :
		Log(
			std::move(_info.file),
			_info.line,
			std::move(_info.function),
			std::move(_msg),
			_pred ? LogLevel::AssertSuccess : LogLevel::AssertFailure,
			std::move(_info.chanName),
			std::move(_info.details),
			_info.frameNum)
	{
	}
}
