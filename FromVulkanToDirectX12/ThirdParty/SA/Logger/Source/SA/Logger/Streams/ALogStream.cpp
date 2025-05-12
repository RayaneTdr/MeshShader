// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <Streams/ALogStream.hpp>

namespace SA
{
	void ALogStream::ProcessLog(const Log& _log, bool _bForce)
	{
		const bool bLevelEnabled = levelFlags & _log.level;
		const bool bChannelEnabled = channelFilter.IsChannelEnabled(_log.chanName);

		if (_bForce || (bLevelEnabled && bChannelEnabled))
			Output(_log);
	}

	void ALogStream::Flush()
	{
		/* Implementation in children */
	}


	ALogStream& ALogStream::operator<<(const Log& _log)
	{
		ProcessLog(_log);

		return *this;
	}
}
