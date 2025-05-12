# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

include(Internal/SA_SetupConfiguration_MSVC.cmake)
include(Internal/SA_SetupConfiguration_GCC_Clang.cmake)

# Internal helper macro to setup configurations.
macro(__SA_SetupConfiguration)

	if(MSVC)
		__SA_SetupConfiguration_MSVC()
	else()
		__SA_SetupConfiguration_GCC_Clang()
	endif()

endmacro(__SA_SetupConfiguration)
