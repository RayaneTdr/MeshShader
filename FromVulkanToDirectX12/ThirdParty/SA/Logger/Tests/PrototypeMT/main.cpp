// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <iostream>
#include <chrono>

#include <SA/Collections/Debug>

void LoggingThread()
{
	for (int i = 0; i < 1000; ++i)
	{
		if(i == 999)
			SA_LOG(("HELLO %1", i), Warning)
		else
			SA_LOG(("HELLO %1", i));
	}
}

int main()
{
	std::chrono::time_point<std::chrono::system_clock> start, submitEnd, end;

//{ Init

	SA::LoggerThread loggerThread(4000);

	loggerThread.CreateSteam<SA::ConsoleLogStream>();
	loggerThread.CreateSteam<SA::FileLogStream>();

	SA::Debug::logger = &loggerThread;

//}

	start = std::chrono::system_clock::now();

	std::thread t1(LoggingThread);
	std::thread t2(LoggingThread);
	std::thread t3(LoggingThread);
	std::thread t4(LoggingThread);

	if (t1.joinable())
		t1.join();

	if (t2.joinable())
		t2.join();

	if (t3.joinable())
		t3.join();

	if (t4.joinable())
		t4.join();

	submitEnd = std::chrono::system_clock::now();

	loggerThread.Flush();

	end = std::chrono::system_clock::now();

	auto submitTime = submitEnd - start;
	std::cout << "Total submitted time: " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(submitTime).count() << "ms / " <<
		std::chrono::duration_cast<std::chrono::microseconds>(submitTime).count() << "μs" << std::endl;

	auto totalTime = end - start;
	std::cout << "Total elapsed time: " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(totalTime).count() << "ms / " <<
		std::chrono::duration_cast<std::chrono::microseconds>(totalTime).count() << "μs" << std::endl;

	return 0;
}
