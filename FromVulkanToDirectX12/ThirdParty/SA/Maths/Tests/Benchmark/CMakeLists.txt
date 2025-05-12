# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.



# Project

project(SA_MathsBenchmark)


SA_FetchGoogleBenchmark()



# Executable

## Inputs

file(GLOB_RECURSE SA_MATHS_BENCHMARK_SOURCES "*.cpp")

## Add executable target.
add_executable(SA_MathsBenchmark ${SA_MATHS_BENCHMARK_SOURCES})



# Dependencies

### Add library dependencies.
target_link_libraries(SA_MathsBenchmark PRIVATE SA_Maths)

### Google test module dependency.
target_link_libraries(SA_MathsBenchmark PRIVATE benchmark::benchmark)
