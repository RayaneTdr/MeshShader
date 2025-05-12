# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.



# Project

project(SA_MathsUT)

SA_FetchGoogleTest()



# Executable

## Inputs

file(GLOB_RECURSE SA_MATHS_UT_SOURCES "*.cpp")

## Add executable target.
add_executable(SA_MathsUT ${SA_MATHS_UT_SOURCES})



# Dependencies

### Add library dependencies.
target_link_libraries(SA_MathsUT PRIVATE SA_Maths)

### Google test module dependency.
target_link_libraries(SA_MathsUT PRIVATE gtest)



# Tests

add_test(NAME CSA_MathsUT COMMAND SA_MathsUT)
