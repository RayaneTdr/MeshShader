# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

cmake_minimum_required(VERSION 3.16)

# Sapphire Suite's CMake tools.
add_subdirectory(ThirdParty/SA/CMake)



# Project

project(SA_Logger)
SA_ConfigureProject(SA_Logger)



# Library

add_library(SA_Logger STATIC)
SA_ConfigureTarget(SA_Logger)
SA_TargetSources(SA_Logger)

### Link dependencies.
target_link_libraries(SA_Logger PUBLIC SA_Support)

### Thread
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(SA_Logger PUBLIC Threads::Threads)

### Advanced MSVC preprocessor required for Core::Debug
### https://docs.microsoft.com/en-us/cpp/preprocessor/preprocessor-experimental-overview
if("${CMAKE_CXX_COMPILER_ID}" MATCHES "MSVC")
	if(${MSVC_TOOLSET_VERSION} LESS 142)
		target_compile_options(SA_Logger PUBLIC /experimental:preprocessor)
	else()
		target_compile_options(SA_Logger PUBLIC /Zc:preprocessor)
	endif()
endif()



# Options

## Add SA_Logger's tests to build tree.
option(SA_LOGGER_BUILD_TESTS_OPT "Should build SA_Logger tests" OFF)


## SA_Logger should log even in release.
option(SA_LOG_RELEASE_OPT "Should log in release" ON)

if(SA_LOG_RELEASE_OPT)
	target_compile_definitions(SA_Logger PUBLIC SA_LOG_RELEASE_OPT)
endif()



# Entrypoints

add_subdirectory(ThirdParty)

if(SA_LOGGER_BUILD_TESTS_OPT)

	### Enable testing for this directory and below.
	enable_testing()

	add_subdirectory(Tests)
endif()
