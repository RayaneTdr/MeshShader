// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <Log/LogRAII.hpp>

#include <SA/Logger/Logger.hpp>

namespace SA
{
	LogRAII::LogRAII(Log&& _log) : mHandle{std::move(_log)}
	{
	}

	LogRAII::~LogRAII()
	{
		__SA_LOGGER(std::move(mHandle));
	}
}