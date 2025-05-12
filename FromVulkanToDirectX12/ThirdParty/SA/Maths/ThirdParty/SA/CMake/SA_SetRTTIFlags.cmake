# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

# Set compilation RTTI flags for target.
#
# USAGE:
#	SA_SetRTTIFlags(
#		<target>
#		LINK		<link_opt>
#	)
#
# ARGUMENTS:
#	TARGET
#		Name of the target to set RTTI flags.
#
#	LINK
#		Target link option (PUBLIC | PRIVATE | INTERFACE).
#		Default is PUBLIC.
#
#	TOGGLE
#		Toggle flag (ON | OFF).
#		Default is ON.
function(SA_SetRTTIFlags _target)

  #{ Args

	cmake_parse_arguments(
		PARGS
		""
		"LINK;TOGGLE"
		""
		${ARGN}
	)


	# Default PUBLIC.
	if(NOT PARGS_LINK)
		set(PARGS_LINK PUBLIC)
	endif()


	# Default ON.
	if(NOT PARGS_TOGGLE)
		set(PARGS_TOGGLE "ON")
	endif()

  #}


	if(${PARGS_TOGGLE} STREQUAL ON)

		set(MSVC_FLAG /GR)

		set(GCC_CLANG_FLAG -frtti)

	elseif(${PARGS_TOGGLE} STREQUAL OFF)

		set(MSVC_FLAG /GR-)

		set(GCC_CLANG_FLAG -fno-rtti)

	else()

		message(FATAL_ERROR "TOGGLE must be either ON or OFF")

	endif()


	if(MSVC)

		target_compile_options(${_target} ${PARGS_LINK} ${MSVC_FLAG})

	else()

		target_compile_options(${_target} ${PARGS_LINK} ${GCC_CLANG_FLAG})

	endif()

endfunction(SA_SetRTTIFlags)
