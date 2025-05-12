# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.



# Project

project(SA_LoggerUT)

SA_FetchGoogleTest()



# Executable

## Inputs

file(GLOB_RECURSE SA_LOGGER_UT_SOURCES "*.cpp")

## Add executable target.
add_executable(SA_LoggerUT ${SA_LOGGER_UT_SOURCES})



# Dependencies

### Add library dependencies.
target_link_libraries(SA_LoggerUT PRIVATE SA_Logger)

### Google test module dependency.
target_link_libraries(SA_LoggerUT PRIVATE gtest)



# Tests

add_test(NAME CSA_LoggerUT COMMAND SA_LoggerUT)
