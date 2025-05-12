# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

include(SA_FetchOrInclude.cmake)

# Clone a git repository from Sapphire Suite (module) at config time and add it to ThirdParty/SA/<repo_name>.
# Automatically init git submodules.
#
# USAGE:
#	SA_FetchModule(
#		<module_name>
#	)
#
# ARGUMENTS:
#	MODULE_NAME
#		Name of the Sapphire Suite's module to clone (name of the repository).
#
function(SA_FetchModule _module_name)

	set(SA_MODULE_NAME "SA_${_module_name}")

	SA_FetchOrInclude(
		GIT_REPOSITORY	https://github.com/SapphireSuite/${_module_name}
		GIT_TAG			main
		CMAKE_TARGET	${SA_MODULE_NAME}
		REPO_FULL_NAME	${SA_MODULE_NAME}
		SOURCE_DIR		"ThirdParty/SA"
	)

endfunction(SA_FetchModule)
