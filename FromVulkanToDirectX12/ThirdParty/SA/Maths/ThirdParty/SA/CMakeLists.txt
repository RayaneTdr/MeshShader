# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

# Entrypoints

if(SA_MATHS_USE_LOGGER_OPT)

	SA_FetchModule(Logger)

### Temp required to fix MSVC C4201 in Rectangle2D.hpp
else()
#elseif(SA_MATHS_INTRINSICS_OPT)

	# Support required for intrinsics.
	SA_FetchModule(Support)

endif()
