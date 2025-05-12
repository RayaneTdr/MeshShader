# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

# Internal helper macro to setup configurations for MSVC.
macro(__SA_SetupConfiguration_MSVC)

	#set(CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo;AddrSan")
	#set(CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo;AddrSan;ThreadSan;MemorySan") # Not supported yet.

	# /MP: Build with multiple processes.
	# /W[0, 1, 2, 3, 4]: Set compiler warning level.
	# /GR-: Disable RTTI generation.
	# /Zi: Generate debug info in .pdb.
	# /Zo: Enhanced debugging information for optimized code in non-debug.
	# /O[d, 1, 2, 3]: Code optimization level (d = disabled).
	# /Oy-: Disable frame pointer omission.

	#set(CMAKE_CXX_FLAGS_DEBUG 			"/Zi")
	#set(CMAKE_CXX_FLAGS_RELEASE			"/O2 -DNDEBUG")
	#set(CMAKE_CXX_FLAGS_RELWITHDEBINFO	"/Zi /Zo /O2 -DNDEBUG")
	set(CMAKE_CXX_FLAGS_ADDRSAN			"/Zi /Zo /O1")
	set(CMAKE_CXX_FLAGS_THREADSAN		"/Zi /Zo /O1")
	set(CMAKE_CXX_FLAGS_MEMORYSAN		"/Zi /Zo /O1")


	# set(CMAKE_EXE_LINKER_FLAGS_DEBUG)
	# set(CMAKE_EXE_LINKER_FLAGS_RELEASE)
	# set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO)
	set(CMAKE_EXE_LINKER_FLAGS_ADDRSAN "/DEBUG /INCREMENTAL:NO")
	set(CMAKE_EXE_LINKER_FLAGS_THREADSAN "/DEBUG /INCREMENTAL:NO")
	set(CMAKE_EXE_LINKER_FLAGS_MEMORYSAN "/DEBUG /INCREMENTAL:NO")


	set(SA_COMPILE_PUBLIC_OPTIONS
		
		$<$<CONFIG:Debug>:>
		$<$<CONFIG:Release>:>
		$<$<CONFIG:RelWithDebInfo>:>
		$<$<CONFIG:AddrSan>:>
		$<$<CONFIG:ThreadSan>:>
		$<$<CONFIG:MemorySan>:>
	)

	set(SA_COMPILE_PRIVATE_OPTIONS
		/MP /W4 #[[/GR-]]
		$<$<CONFIG:Debug>:>
		$<$<CONFIG:Release>:>
		$<$<CONFIG:RelWithDebInfo>:>
		$<$<CONFIG:AddrSan>: 		/fsanitize=address #[[/fsanitize=undefined]] #[[/fsanitize=leak]] /Oy-> # undefined and leak Not supported yet.
	#	$<$<CONFIG:ThreadSan>: 		/fsanitize=thread /Oy-> 	# Not supported yet.
	#	$<$<CONFIG:MemorySan>: 		/fsanitize=memory /Oy-> 	# Not supported yet.
	)


	set(SA_LINK_PUBLIC_OPTIONS
		
		$<$<CONFIG:Debug>:>
		$<$<CONFIG:Release>:>
		$<$<CONFIG:RelWithDebInfo>:>
		$<$<CONFIG:AddrSan>:>
		$<$<CONFIG:ThreadSan>:>
		$<$<CONFIG:MemorySan>:>
	)

	set(SA_LINK_PRIVATE_OPTIONS
		
		$<$<CONFIG:Debug>:>
		$<$<CONFIG:Release>:>
		$<$<CONFIG:RelWithDebInfo>:>
		$<$<CONFIG:AddrSan>: clang_rt.asan_dynamic-x86_64.lib clang_rt.asan_dynamic_runtime_thunk-x86_64.lib clang_rt.ubsan_standalone_cxx-x86_64.lib>
		$<$<CONFIG:ThreadSan>:>
		$<$<CONFIG:MemorySan>:>
	)

endmacro(__SA_SetupConfiguration_MSVC)
