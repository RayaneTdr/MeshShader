// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <iostream>

#include <SA/Collections/Debug>

void LogCallback(SA::Log _log)
{
	// Filter: discard Info level.
	if(_log.level == SA::LogLevel::Info)
		return;

	std::wcout << SA::ToWString(_log) << std::endl;
}	

namespace MyNamespace
{
	class MyClass
	{
	public:
		int i = 0;
	};
}

namespace SA
{
	template <>
	std::string ToString(const MyNamespace::MyClass& _m)
	{
		return "MyNamespace::MyClass: " + std::to_string(_m.i);
	}
}

int main()
{
//{ Init

	// SA::Debug::logCB = LogCallback;
	// SA::Debug::InitDefaultLoggerThread;

	//SA::Logger logger;
	SA::LoggerThread logger;

	SA::ConsoleLogStream& cslStream = logger.CreateSteam<SA::ConsoleLogStream>();
	logger.CreateSteam<SA::FileLogStream>();

	SA::Debug::logger = &logger;

	cslStream.levelFlags |= SA::LogLevel::AssertSuccess;

//}

	int i = 8614;

	MyNamespace::MyClass m1;
	m1.i = 72;

	SA_LOG("efsegseg");
	SA_LOG(i, Error);
	SA_LOG(m1, Info);
	SA_LOG("efsegseg", Error, PP.SuperChan);
	SA_LOG("efsegseg", Error, PP.SuperChan, L"super dets");
	SA_LOG(L"AAAAAAAAAA", Normal, SA.TestChan, L"");
	SA_LOG(("%1 Hello %1 %2", 8, m1), Normal, SA.TestChan, L"");

	SA_LOG("Discarded message", Info);

	SA_ERROR(3 < 1, NewChan, ("Some Details! %1 is > %2", 3, 1))
	SA_WARN(3 < 1, NewChan, ("Some Details! %1 is > %2", 3, 1))


	int i2 = 4;
	int j2 = 0;
	int k2 = 6;

	std::vector<int> v = {8, 9, 3, 1};

	SA_ASSERT((OutOfRange, i2, j2, k2), SA.SuperAssertChan, L"SomeDetails!?");
	SA_ASSERT((OutOfRange, i2, j2, k2), SA.SuperAssertChan);
	SA_ASSERT((OutOfArrayRange, 1, v), SA.SuperAssertChan, ("SomeDetails %1 %2!?", i2, j2));

//{ Log RAII

	{
		SA_LOG_RAII(L"RAII 1!", Info, SA.RAIIChan);

		SA_LOG(L"Normal log!", Error);

		{
			SA_LOG_RAII("RAII 2!", Warning, SA.RAIIChan, L"After Normal and Before RAII 1");
			SA_LOG_RAII("RAII 3!", Warning, SA.RAIIChan, L"After Normal and Before RAII 1 and Before RAII 2");
		}

		logger.Flush(); // ensure correct order with LoggerThread.
	}

//}

//{ Test LogLevel Flags

	SA_LOG("This log level is enabled in console!", Warning, SA/TestChan);

	logger.Flush();

	cslStream.levelFlags &= ~SA::LogLevel::Warning;

	SA_LOG("This log level is NOT enabled in console!", Warning, SA/TestChan);

	logger.Flush();

	cslStream.levelFlags |= SA::LogLevel::Warning;

	SA_LOG("This log level is enabled AGAIN in console!", Warning, SA/TestChan);

//}

//{ Test Data Race

	for (int i = 0; i < 10; ++i)
	{
		SA_LOG("Hello, World!", Info, SA/TestChan, "Some Details!");

		SA_LOG_END_OF_FRAME();
	}

	try
	{
		SA_ASSERT((OutOfRange, 4u, 1u, 3u), SA/OtherChan);
	}
	catch (SA::Exception& _exc)
	{
		(void)_exc;
		SA_LOG("CATCH");
	}

//}

	return 0;
}
