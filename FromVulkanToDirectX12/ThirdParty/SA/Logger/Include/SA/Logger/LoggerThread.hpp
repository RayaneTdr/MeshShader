// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_LOGGER_THREAD_GUARD
#define SAPPHIRE_LOGGER_LOGGER_THREAD_GUARD

#include <SA/Logger/LoggerBase.hpp>

#include <SA/Logger/Misc/RingBuffer.hpp>

#include <mutex>
#include <thread>

/**
*	\file LoggerThread.hpp
*
*	\brief \e Multithread <b>Lock-free Logger</b> class implementation.
*
*	\ingroup Logger
*	\{
*/

namespace SA
{
	/**
	*	\brief Multithread logger class.
	* 
	*	Create one thread for log output.
	*	Push logs in thread-safe queue.
	*/
	class LoggerThread : public LoggerBase
	{
		/**
		* \brief Current atomic registered frame number.
		* Use IncrementFrameNum() or SA_LOG_END_OF_FRAME() at the end of the frame to track frame number.
		*/
		std::atomic<uint32_t> mFrameNum = 0u;

	//{ Thread

		/// Logger thread.
		std::thread mThread;

		/// Current running state.
		std::atomic<bool> mIsRunning = true;

		/// FIFO Ring buffer
		RingBuffer<SA::Log> mRingBuffer;

		void ThreadLoop();

	//}

	//{ Streams
	
		/// Output stream mutex operations.
		std::mutex mStreamMutex;

		void ProcessLog(const SA::Log& _log, bool _bForce = false) override final;

		void RegisterStream(ALogStream* _stream) override final;
		bool UnregisterStream(ALogStream* _stream) override final;

	//}

	public:
		/// Default Constructor.
		LoggerThread(uint32_t _ringBufferSize = 32) noexcept;

		/**
		*	Thread-safe destructor.
		*	Flush all remaining logs in streams before join.
		*/
		~LoggerThread();

		void Log(SA::Log _log) override final;

	//{ Streams

		void ClearStreams(bool _bFlush = true) override final;


		void Flush() override final;


		void EnableLogLevel(LogLevel _level) override final;

		void DisableLogLevel(LogLevel _level) override final;


		void EnableLogChannel(const std::wstring& _channel) override final;

		void DisableLogChannel(const std::wstring& _channel) override final;

	//}


	//{ Frame Num

		/// Increment current registered frame number.
		void IncrementFrameNum() override final;

		/// Get current registered frame number.
		uint32_t GetFrameNum() const override final;
	//}
	};
}


/** \}*/

#endif // GUARD
