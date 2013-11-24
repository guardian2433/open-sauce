/*
	Yelo: Open Sauce SDK
		Halo 1 (Editing Kit) Edition

	See license\OpenSauce\Halo1_CheApe for specific license information
*/
#pragma once

#include <YeloLib/shell/platform_yelo.hpp>
#define PLATFORM_TARGET		PLATFORM_TARGET_PC
#define PLATFORM_IS_EDITOR	TRUE
#define PLATFORM_IS_STUBBS	FALSE
#define CHEAPE_PLATFORM		CHEAPE_PLATFORM_HALO1

// PLATFORM_TYPE is defined in the vcproj build configurations
#if !defined(PLATFORM_ID)
	#if defined(PLATFORM_TYPE_GUERILLA)
		#define PLATFORM_ID PLATFORM_GUERILLA
	#elif defined(PLATFORM_TYPE_TOOL)
		#define PLATFORM_ID PLATFORM_TOOL
	#elif defined(PLATFORM_TYPE_SAPIEN)
		#define PLATFORM_ID PLATFORM_SAPIEN
	#else
		#error PLATFORM_TYPE not defined. Step 1: Bash head on keyboard. Step 2: Repeat. Are you selecting a build config that is just vanilla Debug or Release?
	#endif
#endif

// Calling convention of guerilla\tool\sapien
#define PLATFORM_API __cdecl
