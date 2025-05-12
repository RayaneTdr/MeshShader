// Copyright (c) 2024 Sapphire's Suite. All Rights Reserved.

namespace SA
{
	template <typename ExcepT>
	void LoggerBase::Assert(ExcepT _exc)
	{
		if(_exc.level == LogLevel::AssertFailure)
		{
			Flush();

			// Force instant process.
			ProcessLog(_exc, true);

			throw std::forward<ExcepT>(_exc);
		}
		else
		{
			// Simple log.
			Log(std::forward<ExcepT>(_exc));
		}
	}

//{ Streams

	template <typename StreamT, typename... Args>
	StreamT& LoggerBase::CreateSteam(Args&&... _args)
	{
		StreamT* const stream = new StreamT(std::forward<Args>(_args)...);

		RegisterStream(stream);

		return *stream;
	}

	template <typename StreamT>
	bool LoggerBase::DestroyStream(StreamT& _stream, bool _bFlush)
	{
		StreamT* const streamPtr = &_stream;

		const bool bUnregisted = UnregisterSteam(streamPtr);

		if (bUnregisted)
		{
			if (_bFlush)
				streamPtr->Flush();

			delete streamPtr;
		}

		return bUnregisted;
	}

//}
}
