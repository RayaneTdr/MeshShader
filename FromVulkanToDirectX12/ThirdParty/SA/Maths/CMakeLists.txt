# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

cmake_minimum_required(VERSION 3.16)

# Sapphire Suite's CMake tools.
add_subdirectory(ThirdParty/SA/CMake)



# Project

project(SA_Maths)
SA_ConfigureProject(SA_Maths)



# Library

add_library(SA_Maths STATIC)

SA_ConfigureTarget(SA_Maths)
SA_TargetSources(SA_Maths)

### Temp required to fix MSVC C4201 in Rectangle2D.hpp
target_link_libraries(SA_Maths PUBLIC SA_Support)



# Option

## Add SA_Maths's use SA_Logger.
option(SA_MATHS_USE_LOGGER_OPT "Should compile and use SA_Logger" OFF)

if(SA_MATHS_USE_LOGGER_OPT)
	target_link_libraries(SA_Maths PUBLIC SA_Logger)
endif()


## Add SA_Maths's intrinsics implementation.
option(SA_MATHS_INTRINSICS_OPT "Should build using intrinsics" OFF)

if(SA_MATHS_INTRINSICS_OPT)
	#target_link_libraries(SA_Maths PUBLIC SA_Support)
	target_compile_definitions(SA_Maths PUBLIC SA_MATHS_INTRINSICS_OPT)
	SA_SetIntrinsicsFlags(SA_Maths)
endif()


## Add SA_Maths's tests to build tree.
option(SA_MATHS_BUILD_TESTS_OPT "Should build SA_Maths tests" OFF)


## Add SA_Maths's benchmark to build tree.
option(SA_MATHS_BUILD_BENCHMARK_OPT "Should build SA_Maths benchmark" OFF)



# Entrypoints

add_subdirectory(ThirdParty)

if(SA_MATHS_BUILD_TESTS_OPT)

	### Enable testing for this directory and below.
	enable_testing()

	add_subdirectory(Tests)
endif()
