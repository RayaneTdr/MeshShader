// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <Streams/Console/ConsoleColorTheme.hpp>

#include <SA/Support/Algorithms/BitScanForward.hpp>

namespace SA
{
	const uint8_t* ConsoleColorTheme::Data() const
	{
		return &normal;
	}

	void ConsoleColorTheme::SetConsoleColorFromLevel(LogLevel _lvl) const
	{
		const uint8_t* const data = Data();

		const uint32_t levelBit = BitScanForward(static_cast<uint32_t>(_lvl));

		const CslColor color = static_cast<CslColor>(data[levelBit]);

		SA::SetConsoleColor(color);
	}
}
