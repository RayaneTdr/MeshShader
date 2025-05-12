# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.



# Project

project(SA_LoggerProtoMT)



# Executable

## Add executable target.
add_executable(SA_LoggerProtoMT "main.cpp")



# Dependencies

### Add library dependencies.
target_link_libraries(SA_LoggerProtoMT PRIVATE SA_Logger)



# Tests

add_test(NAME CSA_LoggerProtoMT COMMAND SA_LoggerProto)
