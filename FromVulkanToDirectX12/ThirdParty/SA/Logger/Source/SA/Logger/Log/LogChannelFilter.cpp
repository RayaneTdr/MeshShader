// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <Log/LogChannelFilter.hpp>

namespace SA
{
	static const std::wstring separators = L"./_-\\|";

	bool LogChannelFilter::IsSingleChannelEnabled(const std::wstring& _chanName) const
	{
		auto it = mChannels.find(_chanName);

		return it != mChannels.cend() ? it->second : true;
	}

	bool LogChannelFilter::IsChannelEnabled(const std::wstring& _chanName, size_t _offset) const
	{
		const size_t fIndex = _chanName.find_first_of(separators, _offset);

		if (fIndex == std::wstring::npos)
			return IsSingleChannelEnabled(_chanName);

		return IsSingleChannelEnabled(_chanName.substr(0u, fIndex)) && IsChannelEnabled(_chanName, fIndex + 1);
	}

	void LogChannelFilter::SetChannelEnabled(const std::wstring& _chanName, bool _bEnabled)
	{
		mChannels[_chanName] = _bEnabled;
	}
}
