// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <Preprocessors/LogMacro.hpp>

#include <iostream>

#include <Logger.hpp>
#include <LoggerThread.hpp>

#include <Streams/File/FileLogStream.hpp>
#include <Streams/Console/ConsoleLogStream.hpp>

namespace SA
{
	namespace Debug
	{
		LoggerBase* logger = nullptr;
		void (*logCB)(SA::Log) = Intl::DefaultLogCallback;
		
		
		void InitDefaultLogger()
		{
			static Logger defaultLogger;

			defaultLogger.CreateSteam<ConsoleLogStream>();
			defaultLogger.CreateSteam<FileLogStream>();

			SA::Debug::logger = &defaultLogger;
		}

		void InitDefaultLoggerThread()
		{
			static LoggerThread defaultLoggerThread;

			defaultLoggerThread.CreateSteam<ConsoleLogStream>();
			defaultLoggerThread.CreateSteam<FileLogStream>();

			SA::Debug::logger = &defaultLoggerThread;
		}


		namespace Intl
		{
			void DefaultLogCallback(SA::Log _log)
			{
				std::wcout << SA::ToWString(_log) << std::endl;
			}
		}
	}
}
