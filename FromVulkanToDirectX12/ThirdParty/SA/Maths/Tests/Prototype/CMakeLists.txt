# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.



# Project

project(SA_MathsProto)



# Executable

## Add executable target.
add_executable(SA_MathsProto "main.cpp")



# Dependencies

### Add library dependencies.
target_link_libraries(SA_MathsProto PRIVATE SA_Maths)



# Tests

add_test(NAME CSA_MathsProto COMMAND SA_MathsProto)
