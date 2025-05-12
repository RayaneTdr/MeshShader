# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

# Add *public* sources and include directory to a target (using target_sources and target_include_directories).
#
# USAGE:
#	SA_TargetPublicSources(
#		<target>
#		SRC_DIR				<public_src_dir>
#		INCL_DIR			<public_include_dir>
#	)
#
# ARGUMENTS:
#	TARGET
#		Name of the cmake target.
#
#	SRC_DIR
#		Public source folder.
#		Default is "Include/SA/<module_name>".
#
#	INCL_DIR
#		Public include directory.
#		Path used from outside target to access include directory.
#		Default is "Include"
function(SA_TargetPublicSources _target)
	
  #{ Args

	cmake_parse_arguments(
		PARGS
		""
		"SRC_DIR;INCL_DIR"
		""
		${ARGN}
	)


	# Remove SA_ from target name to get folder name.
	string(REPLACE "SA_" "" MODULE_NAME ${_target})


	# Default "Include/SA/<module_name>".
	if(NOT PARGS_SRC_DIR)
		set(PARGS_SRC_DIR "Include/SA/${MODULE_NAME}")
	endif()


	# Default "Include".
	if(NOT PARGS_INCL_DIR)
		set(PARGS_INCL_DIR Include)
	endif()

  #}

	file(GLOB_RECURSE SA_SOURCES_PUBLIC "${PARGS_SRC_DIR}/*.hpp")
	message(VERBOSE "[SA] ${_target} public sources: ${SA_SOURCES_PUBLIC}")

	source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/${PARGS_SRC_DIR}" PREFIX Public FILES ${SA_SOURCES_PUBLIC})
	target_sources(${_target} PUBLIC ${SA_SOURCES_PUBLIC})


	## Include directories
	if(NOT "${PARGS_INCL_DIR}" STREQUAL "OFF")

		# Public include directory (access from project's outside).
		target_include_directories(${_target} PUBLIC ${PARGS_INCL_DIR})
	
	endif()

	# Private include directory (access from project's inside).
	target_include_directories(${_target} PRIVATE ${PARGS_SRC_DIR})

endfunction(SA_TargetPublicSources)



# Add *private* sources and include directory to a target (using target_sources and target_include_directories).
#
# USAGE:
#	SA_TargetPrivateSources(
#		<target>
#		SRC_DIR		<private_src_dir>
#	)
#
# ARGUMENTS:
#	TARGET
#		Name of the cmake target.
#
#	SRC_DIR
#		Private source folder.
#		Default is "Source/SA/<module_name>".
function(SA_TargetPrivateSources _target)
	
  #{ Args

	cmake_parse_arguments(
		PARGS
		""
		"SRC_DIR"
		""
		${ARGN}
	)


	# Remove SA_ from target name to get folder name.
	string(REPLACE "SA_" "" MODULE_NAME ${_target})


	# Default "Source/SA/<module_name>".
	if(NOT PARGS_SRC_DIR)
		set(PARGS_SRC_DIR "Source/SA/${MODULE_NAME}")
	endif()

  #}

	file(GLOB_RECURSE SA_SOURCES_PRIVATE "${PARGS_SRC_DIR}/*.hpp" "${PARGS_SRC_DIR}/*.cpp")
	message(VERBOSE "[SA] ${_target} private sources: ${SA_SOURCES_PRIVATE}")

	source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/${PARGS_SRC_DIR}" PREFIX Private FILES ${SA_SOURCES_PRIVATE})
	target_sources(${_target} PRIVATE ${SA_SOURCES_PRIVATE})

endfunction(SA_TargetPrivateSources)



# Add *interface* sources and include directory to a target (using target_sources and target_include_directories).
#
# USAGE:
#	SA_TargetInterfaceSources(
#		<target>
#		SRC_DIR				<interface_src_folder>
#		INCL_DIR			<public_include_dir>
#	)
#
# ARGUMENTS:
#	TARGET
#		Name of the cmake target.
#
#	SRC_DIR
#		Interface source folder.
#		Default is "Include/SA/<module_name>".
#
#	INCL_DIR
#		Interface include directory.
#		Path used from outside target to access include directory.
#		Default is "Include"
function(SA_TargetInterfaceSources _target)
	
  #{ Args

	cmake_parse_arguments(
		PARGS
		""
		"SRC_DIR;INCL_DIR"
		""
		${ARGN}
	)


	# Remove SA_ from target name to get folder name.
	string(REPLACE "SA_" "" MODULE_NAME ${_target})


	# Default "Include/SA/<module_name>".
	if(NOT PARGS_SRC_DIR)
		set(PARGS_SRC_DIR "Include/SA/${MODULE_NAME}")
	endif()


	# Default "Include".
	if(NOT PARGS_INCL_DIR)
		set(PARGS_INCL_DIR Include)
	endif()

  #}

	file(GLOB_RECURSE SA_SOURCES_INTERFACE "${PARGS_SRC_DIR}/*.hpp")
	message(VERBOSE "[SA] ${_target} interface sources: ${SA_SOURCES_INTERFACE}")

	source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/${PARGS_SRC_DIR}" PREFIX Public FILES ${SA_SOURCES_INTERFACE})
	target_sources(${_target} INTERFACE ${SA_SOURCES_INTERFACE})


	## Include directories
	if(NOT "${PARGS_INCL_DIR}" STREQUAL "OFF")

		# Interface include directory (access from project's outside).
		target_include_directories(${_target} INTERFACE ${PARGS_INCL_DIR})

	endif()

endfunction(SA_TargetInterfaceSources)


# Add sources and include directories to a target (using target_sources and target_include_directories).
#
# USAGE:
#	SA_TargetSources(
#		<target>
#		PUBLIC_SRC_DIR		<public_folder>
#		PUBLIC_INCL_DIR		<public_folder>
#		PRIVATE_SRC_DIR		<private_folder>
#	)
#
# ARGUMENTS:
#	TARGET
#		Name of the cmake target.
#
#	PUBLIC_SRC_DIR
#		Public source directory.
#		Default is "Include/SA/<module_name>".
#
#	PUBLIC_INCL_DIR
#		Public include directory.
#		Default is "Include/"
#
#	PRIVATE_SRC_DIR
#		Private source directory.
#		Default is "Source/SA/<module_name>".
function(SA_TargetSources _target)
	
  #{ Args

	cmake_parse_arguments(
		PARGS
		""
		"PUBLIC_SRC_DIR;PUBLIC_INCL_DIR;PRIVATE_SRC_DIR"
		""
		${ARGN}
	)

  #}

	SA_TargetPublicSources(${_target} SRC_DIR ${PARGS_PUBLIC_SRC_DIR} INCL_DIR ${PARGS_PUBLIC_INCL_DIR})
	SA_TargetPrivateSources(${_target} SRC_DIR ${PARGS_PRIVATE_SRC_DIR})

endfunction(SA_TargetSources)
