# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

# Configure a target from Sapphire Suite's config.
# Set standard to C11/C++20
# Add public module proprocessor: <UPPER_MODULE_NAME>_IMPL (ex: SA_LOGGER_IMPL).
#
# USAGE:
#	SA_ConfigureTarget(
#		<target>
#		LINK	<link_opt>
#	)
#
# ARGUMENTS:
#	TARGET
#		Name of the target to configure.
#
#	LINK
#		Target link option (PUBLIC | PRIVATE | INTERFACE).
#		Default is PUBLIC.
function(SA_ConfigureTarget _target)

 #{ Args

	cmake_parse_arguments(
		PARGS
		""
		"LINK"
		""
		${ARGN}
	)

	# Default PUBLIC.
	if(NOT PARGS_LINK)
		set(PARGS_LINK PUBLIC)
	endif()

 #}


	# Standard
	target_compile_features(${_target} ${PARGS_LINK} c_std_11)
	target_compile_features(${_target} ${PARGS_LINK} cxx_std_20)


	# Set project configuration compile & link options.
	if(NOT ${PARGS_LINK} STREQUAL "INTERFACE")
		target_compile_options(${_target} PUBLIC ${SA_COMPILE_PUBLIC_OPTIONS})
		target_compile_options(${_target} PRIVATE ${SA_COMPILE_PRIVATE_OPTIONS})
		
		target_link_options(${_target} PUBLIC ${SA_LINK_PUBLIC_OPTIONS})
		target_link_options(${_target} PRIVATE ${SA_LINK_PRIVATE_OPTIONS})
	endif()


	# Module implementation preprocessor.
	string(TOUPPER ${_target} SA_UPPER_TARGET)
	target_compile_definitions(${_target} ${PARGS_LINK} ${SA_UPPER_TARGET}_IMPL)


	# CI option preprocessor.
	if(SA_CI)
		target_compile_definitions(${_target} ${PARGS_LINK} SA_CI)
	endif()

endfunction(SA_ConfigureTarget)
