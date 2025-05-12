# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

# Internal helper macro to setup configurations for GCC and Clang.
macro(__SA_SetupConfiguration_GCC_Clang)

	#set(CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo;AddrSan;ThreadSan;MemorySan")

	# -Wall: Enable all compiler warnings.
	# -Wextra: Enable compiler extra warnings.
	# -fno-rtti: Disable RTTI generation.
	# -g: Generate debug info.
	# -O[0, 1, 2, 3]: Code optimization level (d = disabled).
	# -fsanitize=undefined: Track undefined behaviors.
	
	#set(CMAKE_CXX_FLAGS_DEBUG 			"-g")
	#set(CMAKE_CXX_FLAGS_RELEASE 		"-O3 -DNDEBUG")
	#set(CMAKE_CXX_FLAGS_RELWITHDEBINFO	"-g -O2 -DNDEBUG")
	set(CMAKE_CXX_FLAGS_ADDRSAN 		"-g -O1")
	set(CMAKE_CXX_FLAGS_THREADSAN 		"-g -O1")
	set(CMAKE_CXX_FLAGS_MEMORYSAN 		"-g -O1")

	set(SA_COMPILE_PUBLIC_OPTIONS
		
		$<$<CONFIG:Debug>:>
		$<$<CONFIG:Release>:>
		$<$<CONFIG:RelWithDebInfo>:>
		$<$<CONFIG:AddrSan>:>
		$<$<CONFIG:ThreadSan>:>
		$<$<CONFIG:MemorySan>:>
	)

	set(SA_COMPILE_PRIVATE_OPTIONS
		-Wall -Wextra #[[-fno-rtti]]
		$<$<CONFIG:Debug>:>
		$<$<CONFIG:Release>:>
		$<$<CONFIG:RelWithDebInfo>:>
		$<$<CONFIG:AddrSan>: 		-fsanitize=address -fsanitize=undefined -fsanitize=leak -fno-omit-frame-pointer>
		$<$<CONFIG:ThreadSan>: 		-fsanitize=thread -fno-omit-frame-pointer>
		$<$<CONFIG:MemorySan>: 		-fsanitize=memory -fno-omit-frame-pointer>
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
		$<$<CONFIG:AddrSan>: 		-fsanitize=address -fsanitize=undefined -fsanitize=leak>
		$<$<CONFIG:ThreadSan>: 		-fsanitize=thread>
		$<$<CONFIG:MemorySan>: 		-fsanitize=memory>
	)

endmacro(__SA_SetupConfiguration_GCC_Clang)
