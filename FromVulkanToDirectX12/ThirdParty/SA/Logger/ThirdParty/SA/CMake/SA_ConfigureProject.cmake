# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

include(Internal/SA_SetupConfiguration.cmake)

# Setup project with Sapphire Suite's requirements.
#
# USAGE:
#	SA_ConfigureProject(
#		<project>
#	)
#
# ARGUMENTS:
#	PROJECT
#		Name of the cmake project.
macro(SA_ConfigureProject PROJECT)

	message("[SA] ${PROJECT} Main directory: ${CMAKE_CURRENT_SOURCE_DIR}")



	# Output directories
	set(SA_BIN_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/Build/bin/${CMAKE_CXX_COMPILER_ID}_$<CONFIG>")
	message("[SA] ${PROJECT} Output directory: ${SA_BIN_OUTPUT_DIR}")

	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${SA_BIN_OUTPUT_DIR}/libs")
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${SA_BIN_OUTPUT_DIR}/libs")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${SA_BIN_OUTPUT_DIR}")



	# Organize targets (and nesting targets) in IDE.
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)

	__SA_SetupConfiguration()

endmacro(SA_ConfigureProject)
