# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

include(SA_FetchOrInclude.cmake)

# Clone GoogleTest repository at config time and add it to ThirdParty/.
# Automatically init git submodules.
#
# USAGE:
#	SA_FetchGoogleTest()
#
function(SA_FetchGoogleTest)

	SA_FetchOrInclude(
		GIT_REPOSITORY	https://github.com/google/googletest
		GIT_TAG			release-1.11.0
		CMAKE_TARGET	gtest
		REPO_FULL_NAME	"Google Test"
	)

endfunction(SA_FetchGoogleTest)
