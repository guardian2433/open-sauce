/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/

//////////////////////////////////////////////////////////////////////////
// DX9.cpp
#if __EL_INCLUDE_FILE_ID == __EL_RASTERIZER_DX9_DX9
	ENGINE_PTR(D3DPRESENT_PARAMETERS, Params,				0x75B780, PTR_NULL);
	ENGINE_PTR(D3DCAPS9, Caps,								0x75C0C0, PTR_NULL);
	ENGINE_DPTR(IDirect3D9, D3D,							0x6B8430, PTR_NULL);
	ENGINE_DPTR(IDirect3DDevice9, Device,					0x6B842C, PTR_NULL);
	ENGINE_DPTR(IDirectInput8, DInput8,						0x64C54C, PTR_NULL);
	ENGINE_DPTR(IDirectInputDevice8, DInput8DeviceKeyboard,	0x64C750, PTR_NULL);
	ENGINE_DPTR(IDirectInputDevice8, DInput8DeviceMouse,	0x64C754, PTR_NULL);
	ENGINE_DPTR(IDirectInputDevice8, DInput8DeviceJoysticks,0x64C798, PTR_NULL);


//////////////////////////////////////////////////////////////////////////
// GBuffer.cpp
#elif __EL_INCLUDE_FILE_ID == __EL_RASTERIZER_DX9_GBUFFER
	ENGINE_PTR(DX9::s_vsf_entry*, VSF_TABLE_START_REFERENCE,	0x533C12, PTR_NULL);

	FUNC_PTR(RENDER_OBJECT_LIST_HOOK,			0x512AE2, FUNC_PTR_NULL);
	FUNC_PTR(RENDER_OBJECT_LIST_HOOK_RETN,		0x512AEA, FUNC_PTR_NULL);

	FUNC_PTR(RENDER_OBJECT_LIST_END_HOOK,		0x512DE1, FUNC_PTR_NULL);

	FUNC_PTR(RENDER_OBJECT_OBJECT_LOD_HOOK,		0x4DA666, FUNC_PTR_NULL);
	FUNC_PTR(RENDER_OBJECT_OBJECT_LOD_HOOK_RETN,0x4DA66C, FUNC_PTR_NULL);

	FUNC_PTR(FIRST_PERSON_WEAPON_DRAW_HOOK,		0x4954D3, FUNC_PTR_NULL);
	FUNC_PTR(FIRST_PERSON_WEAPON_DRAW_HOOK_RETN,0x4954D8, FUNC_PTR_NULL);

	FUNC_PTR(COMMAND_CAMERA_SET_HOOK,			0x445778, FUNC_PTR_NULL);
	FUNC_PTR(COMMAND_CAMERA_SET_HOOK_RETN,		0x44577D, FUNC_PTR_NULL);

	FUNC_PTR(COMMAND_SWITCH_BSP_HOOK,			0x54261B, FUNC_PTR_NULL);
	FUNC_PTR(COMMAND_SWITCH_BSP_HOOK_RETN,		0x542622, FUNC_PTR_NULL);

	FUNC_PTR(COMMAND_GAME_SAVE_HOOK,			0x482907, FUNC_PTR_NULL);
	FUNC_PTR(COMMAND_GAME_SAVE_HOOK_RETN,		0x48290D, FUNC_PTR_NULL);

	FUNC_PTR(RENDER_OBJECTS_TRANSPARENT,								0x519170, FUNC_PTR_NULL);
	FUNC_PTR(RENDER_WINDOW_CALL_RENDER_OBJECTS_TRANSPARENT_HOOK,		0x510194, FUNC_PTR_NULL);
	FUNC_PTR(RENDER_WINDOW_CALL_RENDER_OBJECTS_TRANSPARENT_RETN,		0x510199, FUNC_PTR_NULL);

	FUNC_PTR(RASTERIZER_DRAW_STATIC_TRIANGLES_STATIC_VERTICES__DRAW_INDEXED_PRIMITIVE_HOOK,
												0x5201D6, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_DRAW_DYNAMIC_TRIANGLES_STATIC_VERTICES2__DRAW_INDEXED_PRIMITIVE_HOOK,
												0x51FF58, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// DX9/rasterizer_dx9_shaders_vshader9.cpp
#elif __EL_INCLUDE_FILE_ID == __EL_RASTERIZER_DX9_VSHADERS
	ENGINE_PTR(s_rasterizer_dx9_effect_collection, rasterizer_dx9_effect_collection,	0x75B740, PTR_NULL);
	ENGINE_PTR(s_effect_shader_entry, rasterizer_effect_shaders,						0x638AD8, PTR_NULL);
	ENGINE_PTR(s_vsf_entry, vsf_table,													0x639258, PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// DeviceHooks.cpp
#elif __EL_INCLUDE_FILE_ID == __EL_RASTERIZER_DX9_DEVICEHOOKS
	FUNC_PTR(RASTERIZER_D3D_CREATE_DEVICE_HOOK,											0x51ADD2, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_D3D_CREATE_DEVICE_RETN,											0x51ADD7, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_D3D_RESET_DEVICE_HOOK,											0x519B7F, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_D3D_RESET_DEVICE_RETN,											0x519B84, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_D3D_BEGIN_SCENE_CALL,											0x51B277, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_D3D_END_SCENE_CALL,												0x51BDA0, FUNC_PTR_NULL);

	FUNC_PTR(RASTERIZER_SET_WORLD_VIEW_PROJECTION_MATRIX_VERTEX_CONSTANT_CALL,			0x51CCD3, FUNC_PTR_NULL);
	FUNC_PTR(RASTERIZER_SET_MODEL_TEX_SCALE_VERTEX_CONSTANT_CALL,						0x52E2D3, FUNC_PTR_NULL);

	static void** K_RASTERIZER_SET_MODEL_SPEC_COLOR_VERTEX_CONSTANT_CALLS[] = {
		CAST_PTR(void**, 0x52E2ED), CAST_PTR(void**, 0x52BB4D)
	};
	FUNC_PTR(RASTERIZER_SET_MODEL_VERTEX_LIGHT_VERTEX_CONSTANT_CALL,					0x51CA6E, FUNC_PTR_NULL);
#else
	#error Undefined engine layout include for: __EL_INCLUDE_RASTERIZER_DX9
#endif