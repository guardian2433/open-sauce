/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/


//////////////////////////////////////////////////////////////////////////
// Rasterizer.cpp
#if __EL_INCLUDE_FILE_ID == __EL_RASTERIZER_RASTERIZER
	namespace Rasterizer
	{
		static real_matrix3x4** K_VSH_CONSTANTS__NODEMATRICES_REFERENCES[] = {
			CAST_PTR(real_matrix3x4**, 0x51C733), CAST_PTR(real_matrix3x4**, 0x52A4BF), CAST_PTR(real_matrix3x4**, 0x52A516), 
			CAST_PTR(real_matrix3x4**, 0x52A56E), CAST_PTR(real_matrix3x4**, 0x52A5CC), CAST_PTR(real_matrix3x4**, 0x52A66B)
		};
		static void** K_VSH_CONSTANTS__NODEMATRICES_REFERENCES_PLUS_8[] = {
			CAST_PTR(void**, 0x51C6AA), 
		};
		static uint16* K_RASTERIZER_GLOBALS_MAXIMUM_NODES_PER_MODEL_WRITE_VALUES[] = {
			CAST_PTR(uint16*, 0x51AEF1), 
		};

		ENGINE_PTR(s_rasterizer_config, rasterizer_config,					0x6BDE18, PTR_NULL);
		ENGINE_PTR(s_rasterizer_globals, rasterizer_globals,				0x637CF8, PTR_NULL);
		ENGINE_PTR(s_rasterizer_debug_options, rasterizer_debug_data,		0x6249C0, PTR_NULL);
		ENGINE_PTR(s_rasterizer_frame_parameters, rasterizer_frame_params,	0x75C210, PTR_NULL);

		FUNC_PTR(RASTERIZER_DISPOSE,									0x51C140, FUNC_PTR_NULL);
		FUNC_PTR(RASTERIZER_DISPOSE_CALL_FROM_RASTERIZER,				0x51B110, FUNC_PTR_NULL);
		FUNC_PTR(RASTERIZER_DISPOSE_CALL_FROM_SHELL,					0x544809, FUNC_PTR_NULL);
		

		static void** K_RENDERED_TRIANGLE_ARRAY_UPGRADE_ADDRESS_LIST[] = {
			CAST_PTR(void**, 0x50FE3E), CAST_PTR(void**, 0x50FF9C), CAST_PTR(void**, 0x50FFDE), 
			CAST_PTR(void**, 0x510017), CAST_PTR(void**, 0x510049), CAST_PTR(void**, 0x510073), 
			CAST_PTR(void**, 0x5100AE), CAST_PTR(void**, 0x5101BF), CAST_PTR(void**, 0x5101E0), 
			CAST_PTR(void**, 0x556240), CAST_PTR(void**, 0x55637C), CAST_PTR(void**, 0x556466), 
			CAST_PTR(void**, 0x556546),
		};
		static uint16* K_MAXIMUM_RENDERED_TRIANGLES_UPGRADE_ADDRESS_LIST[] = {
			CAST_PTR(uint16*, 0x557387), CAST_PTR(uint16*, 0x5573F7),
			CAST_PTR(uint16*, 0x55745A), CAST_PTR(uint16*, 0x557577),
		};

		ENGINE_PTR(DWORD, RASTERIZER_DYNAMIC_GEOMETRY_INITIALIZE__CreateIndexBuffer_Length_ARG, 0x51F6C1+1, PTR_NULL);

		ENGINE_PTR(DWORD, RASTERIZER_DEVICE_ADAPTER_INDEX,				0x6B8438, PTR_NULL);
		ENGINE_PTR(char, RESOLUTION_LIST_COUNT,							0x4BE38C, PTR_NULL);
		ENGINE_PTR(void**, RESOLUTION_LIST_STRING_NULL_REFERENCE,		0x4BE3CB, PTR_NULL);

		FUNC_PTR(RESOLUTION_LIST_SETUP_RESOLUTIONS_CALL,				0x4BE2EF, FUNC_PTR_NULL);

		static void** K_RESOLUTION_LIST_X_REFERENCES[] = {
			CAST_PTR(void**, 0x4BE2DA), CAST_PTR(void**, 0x4BE302), CAST_PTR(void**, 0x4BE3AC),
			CAST_PTR(void**, 0x4BE57C), CAST_PTR(void**, 0x4BE967)
		};
		static void** K_RESOLUTION_LIST_Y_REFERENCES[] = {
			CAST_PTR(void**, 0x4BE36A), CAST_PTR(void**, 0x4BE3B2), CAST_PTR(void**, 0x4BE4CC),
			CAST_PTR(void**, 0x4BE4FE), CAST_PTR(void**, 0x4BE97B)
		};
		static void** K_RESOLUTION_LIST_STRING_REFERENCES[] = {
			CAST_PTR(void**, 0x4BE3A6), CAST_PTR(void**, 0x4BEC2C)
		};

		static void** K_RESOLUTION_LIST_REFRESH_COUNT_REFERENCES[] = {
			CAST_PTR(void**, 0x4BE3BD), CAST_PTR(void**, 0x4BE3E1), CAST_PTR(void**, 0x4BE404),
			CAST_PTR(void**, 0x4BE425), CAST_PTR(void**, 0x4BE536), CAST_PTR(void**, 0x4BE58E),
			CAST_PTR(void**, 0x4BE9AB), CAST_PTR(void**, 0x4BEC58), CAST_PTR(void**, 0x4BEC5E)
		};
		static void** K_RESOLUTION_LIST_REFRESH_RATE_REFERENCES[] = {
			CAST_PTR(void**, 0x4BE31B), CAST_PTR(void**, 0x4BE3D3), CAST_PTR(void**, 0x4BE3FE),
			CAST_PTR(void**, 0x4BE431), CAST_PTR(void**, 0x4BE546), CAST_PTR(void**, 0x4BE9BC),
			CAST_PTR(void**, 0x4BEC9A),
		};

		ENGINE_PTR(byte, NVIDIA_USE_BASIC_CAMO_TOGGLE,					0x51ABB8, PTR_NULL);

		static char** K_SCREENSHOT_FOLDER_REFERENCES[] = {
			CAST_PTR(char**, 0x4CD8BC), CAST_PTR(char**, 0x4CD8D3)
		};
	};
	namespace Render
	{
		ENGINE_PTR(s_render_window, render_window,						0x6B4C20, PTR_NULL);
		ENGINE_PTR(s_render_globals, render_globals,					0x75E100, PTR_NULL);
		ENGINE_PTR(s_render_target, global_render_targets,				0x638A20, PTR_NULL);
		ENGINE_PTR(s_structure_render_globals, structure_render_globals,0x67EAB8, PTR_NULL);

		FUNC_PTR(RENDER_WINDOW_REFLECTION_CALL,							0x50FA10, FUNC_PTR_NULL);
		FUNC_PTR(RENDER_WINDOW_FUNC,									0x50FC50, FUNC_PTR_NULL);
		FUNC_PTR(RENDER_WINDOW_REFLECTION_CALL_RETN,					0x50FA15, FUNC_PTR_NULL);

		FUNC_PTR(RENDER_WINDOW_END_HOOK,								0x51BD98, FUNC_PTR_NULL);
	};

#elif __EL_INCLUDE_FILE_ID == __EL_RASTERIZER_LIGHTMAPS
	namespace Render { namespace Lightmaps
	{
		FUNC_PTR(BSP_LIGHTMAP_INDEX_HOOK,							0x5568DA, FUNC_PTR_NULL);
		FUNC_PTR(BSP_LIGHTMAP_INDEX_RETN,							0x5568E0, FUNC_PTR_NULL);
		FUNC_PTR(SET_LIGHTMAP_SAMPLER_CALL,							0x522F6C, FUNC_PTR_NULL);
		FUNC_PTR(OBJECT_RENDER_CACHE_LIGHTMAP_TAG_INDEX_HOOK,		0x4F6304, FUNC_PTR_NULL);
		FUNC_PTR(OBJECT_RENDER_CACHE_LIGHTMAP_TAG_INDEX_RETN,		0x4F630A, FUNC_PTR_NULL);
	};};

#elif __EL_INCLUDE_FILE_ID == __EL_RASTERIZER_SKY
	namespace Render { namespace Sky
	{
		FUNC_PTR(FOG_ATMOSPHERIC_SKY_TAG_INDEX_HOOK, 0x54205F, FUNC_PTR_NULL);
		FUNC_PTR(FOG_ATMOSPHERIC_SKY_TAG_INDEX_RETN, 0x542066, FUNC_PTR_NULL);
		FUNC_PTR(FOG_PLANAR_SKY_TAG_INDEX_HOOK, 0x558DBC, FUNC_PTR_NULL);
		FUNC_PTR(FOG_PLANAR_SKY_TAG_INDEX_RETN, 0x558DC2, FUNC_PTR_NULL);
		FUNC_PTR(RENDER_SKY_SKY_TAG_INDEX_HOOK, 0x51492E, FUNC_PTR_NULL);
		FUNC_PTR(RENDER_SKY_SKY_TAG_INDEX_RETN, 0x514935, FUNC_PTR_NULL);
		FUNC_PTR(VISIBLE_SKY_ENABLE_SKY_TAG_INDEX_HOOK, 0x556F60, FUNC_PTR_NULL);
		FUNC_PTR(VISIBLE_SKY_ENABLE_SKY_TAG_INDEX_RETN, 0x556F6A, FUNC_PTR_NULL);
	};};

#else
	#error Undefined engine layout include for: __EL_INCLUDE_RASTERIZER
#endif