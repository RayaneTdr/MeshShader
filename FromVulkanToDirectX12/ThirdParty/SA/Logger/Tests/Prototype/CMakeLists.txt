# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.



# Project

project(SA_LoggerProto)



# Executable

## Add executable target.
add_executable(SA_LoggerProto "main.cpp")



# Dependencies

### Add library dependencies.
target_link_libraries(SA_LoggerProto PRIVATE SA_Logger)



# Tests

add_test(NAME CSA_LoggerProto COMMAND SA_LoggerProto)
