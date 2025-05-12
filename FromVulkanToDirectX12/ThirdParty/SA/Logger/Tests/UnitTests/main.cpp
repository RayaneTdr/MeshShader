// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Collections/Debug>

int main(int argc, char** argv)
{
	SA::Debug::InitDefaultLogger();

	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
