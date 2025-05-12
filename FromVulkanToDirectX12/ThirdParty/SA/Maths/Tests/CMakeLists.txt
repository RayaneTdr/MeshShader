# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

# Entrypoints

add_subdirectory(Prototype)
add_subdirectory(UnitTests)

if(SA_MATHS_BUILD_BENCHMARK_OPT)

	add_subdirectory(Benchmark)

endif()
