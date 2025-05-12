# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

include(SA_FetchOrInclude.cmake)

# Clone Google Benchmark repository at config time and add it to ThirdParty/.
# Automatically init git submodules.
#
# USAGE:
#	SA_FetchGoogleBenchmark()
#
function(SA_FetchGoogleBenchmark)

	SA_FetchOrInclude(
		GIT_REPOSITORY	https://github.com/google/benchmark
		GIT_TAG			v1.6.0
		CMAKE_TARGET	benchmark
		REPO_FULL_NAME	"Google Benchmark"
	)

endfunction(SA_FetchGoogleBenchmark)
