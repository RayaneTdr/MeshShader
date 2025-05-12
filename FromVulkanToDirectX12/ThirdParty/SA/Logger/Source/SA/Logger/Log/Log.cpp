// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <Log/Log.hpp>

namespace SA
{
	Log::Log(
		std::wstring _file,
		uint32_t _line,
		std::string _function,
		std::wstring _msg,
		LogLevel _level,
		std::wstring _chanName,
		std::wstring _details,
		uint32_t _frameNum,
		std::string _backtrace
	) noexcept :
		file{ std::move(_file) },
		line{ _line },
		function{ std::move(_function) },
		msg{ std::move(_msg) },
		level{_level },
		chanName{ std::move(_chanName) },
		details{ std::move(_details) },
		frameNum{ _frameNum },
		backtrace{ std::move(_backtrace) },
		date{ DateTime::Now() }
	{
	}

	std::wstring ToWString(const Log& _log)
	{
		std::wstring str;

		// Output date.
		str += L'[' + SA::ToWString(_log.date.hour) +
			L':' + SA::ToWString(_log.date.minute) +
			L':' + SA::ToWString(_log.date.second) + L']';

		// Output FrameNum.
		str += L'[' + SA::ToWString(_log.frameNum) + L"] ";

		// Output level and channel.
		str += L'{' + SA::ToWString(_log.level) + L" - " + _log.chanName + L'}';

		// Output location.
		str += L'\t' + _log.file + L':' + SA::ToWString(_log.line) + L" - " + SA::ToWString(_log.function) + L'\n';

		// Output message.
		str += L"Msg:\t" + _log.msg + L'\n';

		if (!_log.details.empty())
			str += L"Dets:\t" + _log.details + L'\n';

		if(!_log.backtrace.empty())
			str += L"Backtrace:\t" + SA::ToWString(_log.backtrace) + L'\n';

		return str;
	}
}
