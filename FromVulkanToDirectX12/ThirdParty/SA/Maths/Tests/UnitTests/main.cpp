// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <gtest/gtest.h>

#include <SA/Maths/Debug.hpp>

int main(int argc, char** argv)
{
#if SA_LOGGER_IMPL

	SA::Debug::InitDefaultLogger();

#endif

	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
