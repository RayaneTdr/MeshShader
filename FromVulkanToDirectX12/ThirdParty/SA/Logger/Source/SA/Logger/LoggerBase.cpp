// Copyright (c) 2024 Sapphire's Suite. All Rights Reserved.

#include <LoggerBase.hpp>

namespace SA
{
	LoggerBase::~LoggerBase()
	{
		ClearStreams();
	}

	void LoggerBase::Log(SA::Log _log)
	{
		ProcessLog(_log);
	}

//{ Streams

	void LoggerBase::ProcessLog(const SA::Log& _log, bool _bForce)
	{
		for (auto it = mStreams.begin(); it != mStreams.end(); ++it)
			(*it)->ProcessLog(_log, _bForce);
	}


	void LoggerBase::RegisterStream(ALogStream* _stream)
	{
		mStreams.push_back(_stream);
	}

	bool LoggerBase::UnregisterStream(ALogStream* _stream)
	{
		for (auto it = mStreams.begin(); it != mStreams.end(); ++it)
		{
			if (*it == _stream)
			{
				mStreams.erase(it);
				return true;
			}
		}

		return false;
	}


	void LoggerBase::ClearStreams(bool _bFlush)
	{
		for (auto it = mStreams.begin(); it != mStreams.end(); ++it)
		{
			if (_bFlush)
				(*it)->Flush();
			
			delete *it;
		}

		mStreams.clear();
	}


	void LoggerBase::Flush()
	{
		for (auto it = mStreams.begin(); it != mStreams.end(); ++it)
			(*it)->Flush();
	}


	void LoggerBase::EnableLogLevel(LogLevel _level)
	{
		for (auto it = mStreams.begin(); it != mStreams.end(); ++it)
			(*it)->levelFlags |= _level;
	}

	void LoggerBase::DisableLogLevel(LogLevel _level)
	{
		for (auto it = mStreams.begin(); it != mStreams.end(); ++it)
			(*it)->levelFlags &= ~_level;
	}


	void LoggerBase::EnableLogChannel(const std::wstring& _channel)
	{
		for (auto it = mStreams.begin(); it != mStreams.end(); ++it)
			(*it)->channelFilter.SetChannelEnabled(_channel, true);
	}

	void LoggerBase::DisableLogChannel(const std::wstring& _channel)
	{
		for (auto it = mStreams.begin(); it != mStreams.end(); ++it)
			(*it)->channelFilter.SetChannelEnabled(_channel, false);
	}

//}
}
