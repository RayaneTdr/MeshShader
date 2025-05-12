// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <iostream>

#include <Streams/Console/ConsoleLogStream.hpp>

#include <SA/Support/API/Windows.hpp>

namespace SA
{
#if SA_WIN
	/// Windows console handle.
	static HANDLE cslHandle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

	void ConsoleLogStream::Flush()
	{
#if SA_WIN
		FlushConsoleInputBuffer(cslHandle);
#else
		std::wcout.flush();
#endif
	}

	void ConsoleLogStream::Output(const Log& _log)
	{
		theme.SetConsoleColorFromLevel(_log.level);

#if SA_WIN
		std::wstring msg = ToWString(_log) + L'\n';
		WriteConsoleW(cslHandle, msg.data(), static_cast<DWORD>(msg.size()), 0, NULL);
#else
		std::wcout << ToWString(_log) << L'\n';
#endif

		SA::SetConsoleColor(CslColor::Reset);
	}
}
