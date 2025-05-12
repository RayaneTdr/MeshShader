// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <Logger.hpp>

namespace SA
{
//{ Frame Num

	void Logger::IncrementFrameNum()
	{
		mFrameNum = (mFrameNum + 1) % 1000;
	}

	uint32_t Logger::GetFrameNum() const
	{
		return mFrameNum;
	}

//}
}
