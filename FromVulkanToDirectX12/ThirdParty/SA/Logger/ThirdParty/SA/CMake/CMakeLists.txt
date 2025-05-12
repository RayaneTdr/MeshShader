# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

if(NOT SA_CMAKE_MODULE_GUARD)

set(SA_CMAKE_MODULE_GUARD true PARENT_SCOPE)

include(SA_ConfigureProject.cmake)
include(SA_ConfigureTarget.cmake)
include(SA_FetchOrInclude.cmake)
include(SA_FetchModule.cmake)
include(SA_FetchGoogleTest.cmake)
include(SA_FetchGoogleBenchmark.cmake)
include(SA_SetIntrinsicsFlags.cmake)
include(SA_SetRTTIFlags.cmake)
include(SA_TargetSources.cmake)

endif()
