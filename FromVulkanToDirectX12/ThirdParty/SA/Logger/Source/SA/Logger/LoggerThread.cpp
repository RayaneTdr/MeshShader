// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <LoggerThread.hpp>

namespace SA
{
	LoggerThread::LoggerThread(uint32_t _ringBufferSize) noexcept :
		mRingBuffer(_ringBufferSize)
	{
		mThread = std::thread(&LoggerThread::ThreadLoop, this);
	}

	LoggerThread::~LoggerThread()
	{
		Flush();

		mIsRunning = false;

		if(mThread.joinable())
			mThread.join();
	}

	void LoggerThread::Log(SA::Log _log)
	{
		mRingBuffer.Push(std::move(_log));
	}

//{ Thread

	void LoggerThread::ThreadLoop()
	{
		SA::Log currLog;

		while (mIsRunning)
		{
			if(mRingBuffer.Pop(currLog, mIsRunning))
				ProcessLog(currLog);
		}
	}

//}

//{ Streams

	void LoggerThread::ProcessLog(const SA::Log& _log, bool _bForce)
	{
		std::lock_guard lk(mStreamMutex);

		LoggerBase::ProcessLog(_log, _bForce);
	}


	void LoggerThread::RegisterStream(ALogStream* _stream)
	{
		std::lock_guard lk(mStreamMutex);

		LoggerBase::RegisterStream(_stream);
	}

	bool LoggerThread::UnregisterStream(ALogStream* _stream)
	{
		std::lock_guard lk(mStreamMutex);

		return LoggerBase::UnregisterStream(_stream);
	}


	void LoggerThread::ClearStreams(bool _bFlush)
	{
		std::lock_guard lk(mStreamMutex);

		LoggerBase::ClearStreams(_bFlush);
	}


	void LoggerThread::Flush()
	{
		while(!mRingBuffer.IsEmpty())
			std::this_thread::yield();

		// Flush all.
		std::lock_guard lkStreams(mStreamMutex);

		LoggerBase::Flush();
	}


	void LoggerThread::EnableLogLevel(LogLevel _level)
	{
		std::lock_guard lk(mStreamMutex);

		LoggerBase::EnableLogLevel(_level);
	}

	void LoggerThread::DisableLogLevel(LogLevel _level)
	{
		std::lock_guard lk(mStreamMutex);

		LoggerBase::DisableLogLevel(_level);
	}


	void LoggerThread::EnableLogChannel(const std::wstring& _channel)
	{
		std::lock_guard lk(mStreamMutex);

		LoggerBase::EnableLogChannel(_channel);
	}

	void LoggerThread::DisableLogChannel(const std::wstring& _channel)
	{
		std::lock_guard lk(mStreamMutex);

		LoggerBase::DisableLogChannel(_channel);
	}

//}


//{ Frame Num

	/// Increment current registered frame number.
	void LoggerThread::IncrementFrameNum()
	{
		mFrameNum = (mFrameNum + 1) % 1000;
	}

	/// Get current registered frame number.
	uint32_t LoggerThread::GetFrameNum() const
	{
		return mFrameNum;
	}
//}
}
