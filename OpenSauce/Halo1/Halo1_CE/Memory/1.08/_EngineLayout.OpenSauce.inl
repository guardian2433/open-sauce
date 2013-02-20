/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/

//////////////////////////////////////////////////////////////////////////
// YeloSettings.cpp
#if __EL_INCLUDE_FILE_ID == __EL_COMMON_YELO_SETTINGS
	ENGINE_PTR(char, g_profile_path, 0x647768, 0x5B9598); // set by -path in haloce


//////////////////////////////////////////////////////////////////////////
// Memory/FunctionInterface.cpp
#elif __EL_INCLUDE_FILE_ID == __EL_MEMORY_FUNCTION_INTERFACE
	FUNC_PTR(RENDER_SKY,												0x5148C0, FUNC_PTR_NULL);
	FUNC_PTR(RENDER_WINDOW_CALL_HOOK_RENDER_SKY,						0x50FD02, FUNC_PTR_NULL);

	FUNC_PTR(RENDER_OBJECTS,											0x5125A0, FUNC_PTR_NULL);
	FUNC_PTR(RENDER_WINDOW_CALL_HOOK_RENDER_OBJECTS,					0x50FD11, FUNC_PTR_NULL);

	FUNC_PTR(STRUCTURE_RENDER_LIGHTMAPS,								0x556300, FUNC_PTR_NULL);
	FUNC_PTR(RENDER_WINDOW_CALL_HOOK_STRUCTURE_RENDER_LIGHTMAPS,		0x50FD1B, FUNC_PTR_NULL);

	FUNC_PTR(WEATHER_PARTICLE_SYSTEMS_RENDER,							0x459610, FUNC_PTR_NULL);
	FUNC_PTR(RENDER_WINDOW_CALL_HOOK_WEATHER_PARTICLE_SYSTEMS_RENDER,	0x51009C, FUNC_PTR_NULL);

	FUNC_PTR(RENDER_UI_WIDGETS,											0x49B5F0, FUNC_PTR_NULL);
	FUNC_PTR(RENDER_WINDOW_CALL_HOOK_RENDER_UI_WIDGETS,					0x5101CD, FUNC_PTR_NULL);

	FUNC_PTR(RENDER_UI_CURSOR,											0x49A480, FUNC_PTR_NULL);
	FUNC_PTR(CALL_HOOK_RENDER_UI_CURSOR,								0x49B6C0, FUNC_PTR_NULL);

	FUNC_PTR(INTERFACE_DRAW_SCREEN,										0x4976B0, FUNC_PTR_NULL);
	FUNC_PTR(RENDER_WINDOW_CALL_HOOK_INTERFACE_DRAW_SCREEN,				0x5101C1, FUNC_PTR_NULL);

	FUNC_PTR(UPDATE_UI_WIDGETS,											0x49AFB0, FUNC_PTR_NULL);
	FUNC_PTR(CALL_HOOK_UPDATE_UI_WIDGETS,								0x4CB0A7, FUNC_PTR_NULL);


//////////////////////////////////////////////////////////////////////////
// Common/GameSystems.cpp
#elif __EL_INCLUDE_FILE_ID == __EL_COMMON_GAME_SYSTEMS
	FUNC_PTR(QUERY_EXITFLAG_REG_CALL,									0x545071, 0x4FF3A6);
	FUNC_PTR(QUERY_EXITFLAG_REG,										0x582530, 0x52ACB0);
	FUNC_PTR(RELEASE_RESOURCES_ON_EXIT_CALL,							0x545290, 0x4FF587);
	FUNC_PTR(RELEASE_RESOURCES_ON_EXIT,									0x544790, 0x4FF0D0);

	DATA_PTR(PE_DATA_SIZE,												0x215000, 0x171000);


//////////////////////////////////////////////////////////////////////////
// Common/DebugDump.cpp
#elif __EL_INCLUDE_FILE_ID == __EL_COMMON_DEBUG_DUMP
	FUNC_PTR(WINMAIN_EXCEPTION_FILTER_CALL,								0x545311, 0x4FF5DF);

	FUNC_PTR(SAVE_GAMMA_TO_REGISTRY,									0x525DD0, FUNC_PTR_NULL);
	FUNC_PTR(RELEASE_D3D_DEVICE,										0x51BD90, FUNC_PTR_NULL);
	FUNC_PTR(KILL_ALL_SOUNDS,											0x54E7A0, FUNC_PTR_NULL);
	FUNC_PTR(DEDI_CLEANUP,												FUNC_PTR_NULL, 0x503BC0);

	ENGINE_PTR(void**, VIRTUALPROTECT_LOCK,								0x6BD110, 0x6257EC);
	ENGINE_PTR(DWORD, VIRTUALPROTECT_OLD_PROTECT,						0x6BD114, 0x6257F0);

#else
	#error Undefined engine layout include for: __EL_INCLUDE_OPEN_SAUCE
#endif