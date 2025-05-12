// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <iostream>

#include <Streams/Console/ConsoleColor.hpp>

#include <SA/Support/API/Windows.hpp>

namespace SA
{
#if SA_WIN

	/// Windows console handle.
	static HANDLE cslHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	void SetConsoleColor(ConsoleColor _cslColor)
	{
		uint8_t attrib = 0u;

		const uint8_t fg = 0x07 & _cslColor; // fg bits only.

		switch (fg)
		{
			case ConsoleColor::None_FG:
				attrib = 7;
				break;
			case ConsoleColor::Red_FG:
				attrib = 4;
				break;
			case ConsoleColor::Green_FG:
				attrib = 2;
				break;
			case ConsoleColor::Blue_FG:
				attrib = 1;
				break;
			case ConsoleColor::Cyan_FG:
				attrib = 3;
				break;
			case ConsoleColor::Magenta_FG:
				attrib = 5;
				break;
			case ConsoleColor::Yellow_FG:
				attrib = 6;
				break;
			case ConsoleColor::Black_FG:
				attrib = 0u;
				break;
			default:
				// TODO: Debug.
				//SA_LOG(L"ConsoleColor foreground bit [" << fg << L"] not supported", Warning, Core);
				attrib = 7;
				break;
		}

		if (_cslColor & ConsoleColor::Bright_FG) // Bright foreground?
			attrib += 8u;


		const uint8_t bg = 0x70 & _cslColor; // bg bits only.

		switch (bg)
		{
			case ConsoleColor::None_BG:
				break;
			case ConsoleColor::Red_BG:
				attrib += 4u << 4u;
				break;
			case ConsoleColor::Green_BG:
				attrib += 2u << 4u;
				break;
			case ConsoleColor::Blue_BG:
				attrib += 1u << 4u;
				break;
			case ConsoleColor::Cyan_BG:
				attrib += 3u << 4u;
				break;
			case ConsoleColor::Magenta_BG:
				attrib += 5u << 4u;
				break;
			case ConsoleColor::Yellow_BG:
				attrib += 6u << 4u;
				break;
			case ConsoleColor::White_BG:
				attrib += 7u << 4u;
				break;
			default:
				// TODO: Debug.
				//SA_LOG(L"ConsoleColor background bit [" << bg << L"] not supported", Warning, Core);
				break;
		}

		if (_cslColor & ConsoleColor::Bright_BG) // Bright background?
			attrib += 8u << 4u;


		SetConsoleTextAttribute(cslHandle, attrib);
}

#else

	void SetConsoleColor(ConsoleColor _cslColor)
	{
		std::string attrib = "\033[";
		const uint8_t fg = 0x07 & _cslColor; // fg bits only.

		// Bright? Unix share fg and bg brightness.
		attrib += _cslColor & (ConsoleColor::Bright_FG | ConsoleColor::Bright_BG) ? "1;" : "0;";

		switch (fg)
		{
			case ConsoleColor::None_FG:
				attrib += "0";
				break;
			case ConsoleColor::Red_FG:
				attrib += "31";
				break;
			case ConsoleColor::Green_FG:
				attrib += "32";
				break;
			case ConsoleColor::Blue_FG:
				attrib += "34";
				break;
			case ConsoleColor::Cyan_FG:
				attrib += "36";
				break;
			case ConsoleColor::Magenta_FG:
				attrib += "35";
				break;
			case ConsoleColor::Yellow_FG:
				attrib += "33";
				break;
			case ConsoleColor::Black_FG:
				attrib += "30";
				break;
			default:
				// TODO: Debug.
				//SA_LOG(L"ConsoleColor foreground bit [" << fg << L"] not supported", Warning, Core);
				break;
		}

		uint8_t bg = 0x70 & _cslColor; // bg bits only.

		switch (bg)
		{
			case ConsoleColor::None_BG:
				break;
			case ConsoleColor::Red_BG:
				attrib += ";41";
				break;
			case ConsoleColor::Green_BG:
				attrib += ";42";
				break;
			case ConsoleColor::Blue_BG:
				attrib += ";44";
				break;
			case ConsoleColor::Cyan_BG:
				attrib += ";46";
				break;
			case ConsoleColor::Magenta_BG:
				attrib += ";45";
				break;
			case ConsoleColor::Yellow_BG:
				attrib += ";43";
				break;
			case ConsoleColor::White_BG:
				attrib += ";47";
				break;
			default:
				// TODO: Debug.
				//SA_LOG(L"ConsoleColor background bit [" << bg << L"] not supported", Warning, Core);
				break;
		}

		attrib += "m";

		std::cout << attrib;
	}

#endif

}
