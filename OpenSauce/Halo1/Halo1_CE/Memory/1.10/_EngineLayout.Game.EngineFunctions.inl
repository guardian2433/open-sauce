/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/

#if !PLATFORM_IS_DEDI
#include "Memory/1.10/Pointers/HaloCE_110_Runtime.Game.EngineFunctions.inl"
#include "Memory/1.10/Pointers/HaloCE_110_Runtime_Manual.Game.EngineFunctions.inl"
#else
#include "Memory/1.10/Pointers/HaloCE_110_Dedi.Game.EngineFunctions.inl"
#endif

ENGINE_PTR(const void*, gather_exception_data,	DUO_PTR(K_GATHER_EXCEPTION_DATA));
FUNC_PTR(GATHER_EXCEPTION,						DUO_PTR(K_GATHER_EXCEPTION));

FUNC_PTR(RASTERIZER_SET_TEXTURE_BITMAP_DATA,	K_RASTERIZER_SET_TEXTURE_BITMAP_DATA, FUNC_PTR_NULL);
FUNC_PTR(RESOLUTION_LIST_ADD_RESOLUTION,		K_RESOLUTION_LIST_ADD_RESOLUTION, FUNC_PTR_NULL);

FUNC_PTR(ANIMATION_CHOOSE_RANDOM_PERMUTATION_INTERNAL,	DUO_PTR(K_ANIMATION_CHOOSE_RANDOM_PERMUTATION_INTERNAL));

FUNC_PTR(GSMD5DIGEST,							DUO_PTR(K_GSMD5DIGEST));

FUNC_PTR(SHELL_GET_COMMAND_LINE_ARGUMENT,		DUO_PTR(K_SHELL_GET_COMMAND_LINE_ARGUMENT));

//////////////////////////////////////////////////////////////////////////
// AI
FUNC_PTR(ACTOR_DELETE,							DUO_PTR(K_ACTOR_DELETE));
FUNC_PTR(ACTOR_UPDATE,							DUO_PTR(K_ACTOR_UPDATE));
FUNC_PTR(ACTOR_CUSTOMIZE_UNIT,					DUO_PTR(K_ACTOR_CUSTOMIZE_UNIT));
FUNC_PTR(ACTOR_SET_ACTIVE,						DUO_PTR(K_ACTOR_SET_ACTIVE));
FUNC_PTR(ACTOR_SET_DORMANT,						DUO_PTR(K_ACTOR_SET_DORMANT));
FUNC_PTR(ACTOR_DELETE_PROPS,					DUO_PTR(K_ACTOR_DELETE_PROPS));
FUNC_PTR(ACTOR_FREEZE,							DUO_PTR(K_ACTOR_FREEZE));
FUNC_PTR(ACTOR_CREATE_FOR_UNIT,					DUO_PTR(K_ACTOR_CREATE_FOR_UNIT));
FUNC_PTR(ACTOR_ACTION_CHANGE,					DUO_PTR(K_ACTOR_ACTION_CHANGE));
FUNC_PTR(AI_SCRIPTING_ATTACH_FREE,				DUO_PTR(K_AI_SCRIPTING_ATTACH_FREE));

//////////////////////////////////////////////////////////////////////////
// Cache
FUNC_PTR(CACHE_FILE_READ_REQUEST,					DUO_PTR(K_CACHE_FILE_READ_REQUEST));
FUNC_PTR(SOUND_CACHE_SOUND_REQUEST,					K_SOUND_CACHE_SOUND_REQUEST, FUNC_PTR_NULL);
FUNC_PTR(TEXTURE_CACHE_BITMAP_GET_HARDWARE_FORMAT,	K_TEXTURE_CACHE_BITMAP_GET_HARDWARE_FORMAT, FUNC_PTR_NULL);
FUNC_PTR(PHYSICAL_MEMORY_MAP_PREDICT_RESOURCES,		K_PHYSICAL_MEMORY_MAP_PREDICT_RESOURCES, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Camera
FUNC_PTR(DIRECTOR_DESIRED_PERSPECTIVE,			K_DIRECTOR_DESIRED_PERSPECTIVE, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Console
FUNC_PTR(CONSOLE_PROCESS_COMMAND,				DUO_PTR(K_CONSOLE_PROCESS_COMMAND));
FUNC_PTR(CONSOLE_PRINTF,						DUO_PTR(K_CONSOLE_PRINTF));
FUNC_PTR(CONSOLE_RESPONSE_PRINTF,				DUO_PTR(K_CONSOLE_RESPONSE_PRINTF));
FUNC_PTR(CONSOLE_WARNING,						DUO_PTR(K_CONSOLE_WARNING));

//////////////////////////////////////////////////////////////////////////
// Cheats
FUNC_PTR(CHEAT_ALL_WEAPONS,						DUO_PTR(K_CHEAT_ALL_WEAPONS));
FUNC_PTR(CHEAT_SPAWN_WARTHOG,					DUO_PTR(K_CHEAT_SPAWN_WARTHOG));
FUNC_PTR(CHEAT_TELEPORT_TO_CAMERA,				DUO_PTR(K_CHEAT_TELEPORT_TO_CAMERA));
FUNC_PTR(CHEAT_ACTIVE_CAMOFLAGE,				DUO_PTR(K_CHEAT_ACTIVE_CAMOFLAGE));
FUNC_PTR(CHEAT_ACTIVE_CAMOFLAGE_LOCAL_PLAYER,	DUO_PTR(K_CHEAT_ACTIVE_CAMOFLAGE_LOCAL_PLAYER));
FUNC_PTR(CHEAT_PLAYER_INDEX,					DUO_PTR(K_CHEAT_PLAYER_INDEX));
FUNC_PTR(DIRECTOR_SAVE_CAMERA,					K_DIRECTOR_SAVE_CAMERA, FUNC_PTR_NULL);
FUNC_PTR(DIRECTOR_LOAD_CAMERA,					K_DIRECTOR_LOAD_CAMERA, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Effects
FUNC_PTR(EFFECT_NEW_ON_OBJECT_MARKER,			DUO_PTR(K_EFFECT_NEW_ON_OBJECT_MARKER));

//////////////////////////////////////////////////////////////////////////
// Game
FUNC_PTR(SCENARIO_SWITCH_STRUCTURE_BSP,			DUO_PTR(K_SCENARIO_SWITCH_STRUCTURE_BSP));
FUNC_PTR(BINK_PLAYBACK_START,					K_BINK_PLAYBACK_START, FUNC_PTR_NULL);
FUNC_PTR(GAME_ENGINE_RASTERIZE_MESSAGE,			K_GAME_ENGINE_RASTERIZE_MESSAGE, FUNC_PTR_NULL);
FUNC_PTR(GAME_TEAM_IS_ENEMY,					DUO_PTR(K_GAME_TEAM_IS_ENEMY));
FUNC_PTR(GAME_ENGINE_PLAY_MULTIPLAYER_SOUND,	DUO_PTR(K_GAME_ENGINE_PLAY_MULTIPLAYER_SOUND));

//////////////////////////////////////////////////////////////////////////
// HS
FUNC_PTR(OBJECT_LIST_ADD,						DUO_PTR(K_OBJECT_LIST_ADD));

//////////////////////////////////////////////////////////////////////////
// Input
FUNC_PTR(INPUT_KEY_IS_DOWN,						K_INPUT_KEY_IS_DOWN, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Interface
FUNC_PTR(KEYSTONE_CHAT_LOG_ADD_STRING,			K_KEYSTONE_CHAT_LOG_ADD_STRING, FUNC_PTR_NULL); // I forget if the dedicated has a chat log equivalent...
FUNC_PTR(HUD_PRINT_MESSAGE,						DUO_PTR(K_HUD_PRINT_MESSAGE));
FUNC_PTR(HUD_GET_ITEM_MESSAGE,					DUO_PTR(K_HUD_GET_ITEM_MESSAGE));
FUNC_PTR(HUD_DRAW_METER,						K_HUD_DRAW_METER, FUNC_PTR_NULL);
FUNC_PTR(HUD_DRAW_NUMBERS,						K_HUD_DRAW_NUMBERS, FUNC_PTR_NULL);
FUNC_PTR(HUD_DRAW_STATIC_ELEMENT,				K_HUD_DRAW_STATIC_ELEMENT, FUNC_PTR_NULL);
FUNC_PTR(HUD_DRAW_BITMAP,						K_HUD_DRAW_BITMAP, FUNC_PTR_NULL);
FUNC_PTR(MAINMENU_LOAD,							K_MAINMENU_LOAD, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Items
FUNC_PTR(WEAPON_PREVENTS_MELEE_ATTACK,				DUO_PTR(K_WEAPON_PREVENTS_MELEE_ATTACK));
FUNC_PTR(WEAPON_PREVENTS_GRENADE_THROWING,			DUO_PTR(K_WEAPON_PREVENTS_GRENADE_THROWING));
FUNC_PTR(WEAPON_STOP_RELOAD,						DUO_PTR(K_WEAPON_STOP_RELOAD));
FUNC_PTR(FIRST_PERSON_WEAPON_MESSAGE_FROM_UNIT,		DUO_PTR(K_FIRST_PERSON_WEAPON_MESSAGE_FROM_UNIT));
FUNC_PTR(WEAPON_GET_FIRST_PERSON_ANIMATION_TIME,	DUO_PTR(K_WEAPON_GET_FIRST_PERSON_ANIMATION_TIME));

//////////////////////////////////////////////////////////////////////////
// Math
FUNC_PTR(PERIODIC_FUNCTION_EVALUATE,			DUO_PTR(K_PERIODIC_FUNCTION_EVALUATE));
FUNC_PTR(TRANSITION_FUNCTION_EVALUATE,			DUO_PTR(K_TRANSITION_FUNCTION_EVALUATE));

//////////////////////////////////////////////////////////////////////////
// Memory
FUNC_PTR(DATA_NEW,								DUO_PTR(K_DATA_NEW));
FUNC_PTR(DATUM_NEW_AT_INDEX,					DUO_PTR(K_DATUM_NEW_AT_INDEX));
FUNC_PTR(DATUM_NEW,								DUO_PTR(K_DATUM_NEW));
FUNC_PTR(DATUM_DELETE,							DUO_PTR(K_DATUM_DELETE));
FUNC_PTR(DATA_DELETE_ALL,						DUO_PTR(K_DATA_DELETE_ALL));
FUNC_PTR(DATA_ITERATOR_NEXT,					DUO_PTR(K_DATA_ITERATOR_NEXT));
FUNC_PTR(DATA_NEXT_INDEX,						DUO_PTR(K_DATA_NEXT_INDEX));
FUNC_PTR(DATUM_TRY_AND_GET,						DUO_PTR(K_DATUM_TRY_AND_GET));
FUNC_PTR(DATUM_INITIALIZE,						DUO_PTR(K_DATUM_INITIALIZE));

//////////////////////////////////////////////////////////////////////////
// Models
FUNC_PTR(MODEL_FIND_MARKER,						DUO_PTR(K_MODEL_FIND_MARKER));

//////////////////////////////////////////////////////////////////////////
// Networking
FUNC_PTR(HUD_CHAT_TO_NETWORK,					DUO_PTR(K_HUD_CHAT_TO_NETWORK));
FUNC_PTR(INDEX_RESOLUTION_TABLE_TRANSLATE,		DUO_PTR(K_INDEX_RESOLUTION_TABLE_TRANSLATE));
FUNC_PTR(MAIN_CONNECT,							DUO_PTR(K_MAIN_CONNECT));

//////////////////////////////////////////////////////////////////////////
// Objects
FUNC_PTR(HS_OBJECT_ORIENT,						DUO_PTR(K_HS_OBJECT_ORIENT));

FUNC_PTR(OBJECT_HEADER_BLOCK_ALLOCATE,			DUO_PTR(K_OBJECT_HEADER_BLOCK_ALLOCATE));
FUNC_PTR(OBJECT_ITERATOR_NEXT,					DUO_PTR(K_OBJECT_ITERATOR_NEXT));

FUNC_PTR(OBJECT_PLACEMENT_DATA_NEW,				DUO_PTR(K_OBJECT_PLACEMENT_DATA_NEW));
FUNC_PTR(OBJECT_NEW,							DUO_PTR(K_OBJECT_NEW));
FUNC_PTR(OBJECT_NEW_WITH_ROLE,					DUO_PTR(K_OBJECT_NEW_WITH_ROLE));
FUNC_PTR(OBJECT_DELETE_TO_NETWORK,				DUO_PTR(K_OBJECT_DELETE_TO_NETWORK));
FUNC_PTR(OBJECT_DELETE,							DUO_PTR(K_OBJECT_DELETE));
FUNC_PTR(OBJECT_ATTACH_TO_MARKER,				DUO_PTR(K_OBJECT_ATTACH_TO_MARKER));
FUNC_PTR(OBJECT_DETACH,							DUO_PTR(K_OBJECT_DETACH));
FUNC_PTR(OBJECTS_FIND_IN_SPHERE,				DUO_PTR(K_OBJECTS_FIND_IN_SPHERE));
FUNC_PTR(OBJECT_START_INTERPOLATION,			DUO_PTR(K_OBJECT_START_INTERPOLATION));
FUNC_PTR(OBJECT_RESET,							DUO_PTR(K_OBJECT_RESET));
FUNC_PTR(OBJECT_RECONNECT_TO_MAP,				DUO_PTR(K_OBJECT_RECONNECT_TO_MAP));
FUNC_PTR(OBJECT_DISCONNECT_FROM_MAP,			DUO_PTR(K_OBJECT_DISCONNECT_FROM_MAP));
FUNC_PTR(OBJECT_GET_ORIGIN,						DUO_PTR(K_OBJECT_GET_ORIGIN));
FUNC_PTR(OBJECT_GET_ORIENTATION,				DUO_PTR(K_OBJECT_GET_ORIENTATION));
FUNC_PTR(OBJECT_GET_LOCATION,					DUO_PTR(K_OBJECT_GET_LOCATION));
FUNC_PTR(OBJECT_SET_POSITION,					DUO_PTR(K_OBJECT_SET_POSITION));
FUNC_PTR(OBJECT_SET_POSITION_NETWORK,			DUO_PTR(K_OBJECT_SET_POSITION_NETWORK));
FUNC_PTR(OBJECT_RESTORE_BODY,					DUO_PTR(K_OBJECT_RESTORE_BODY));
FUNC_PTR(OBJECT_DEPLETE_BODY,					DUO_PTR(K_OBJECT_DEPLETE_BODY));
FUNC_PTR(OBJECT_DEPLETE_SHIELD,					DUO_PTR(K_OBJECT_DEPLETE_SHIELD));
FUNC_PTR(OBJECT_DOUBLE_CHARGE_SHIELD,			DUO_PTR(K_OBJECT_DOUBLE_CHARGE_SHIELD));
FUNC_PTR(OBJECT_CAUSE_DAMAGE,					DUO_PTR(K_OBJECT_CAUSE_DAMAGE));
FUNC_PTR(OBJECT_DEFINITION_PREDICT,				DUO_PTR(K_OBJECT_DEFINITION_PREDICT));
FUNC_PTR(OBJECT_SET_SCALE,						DUO_PTR(K_OBJECT_SET_SCALE));
FUNC_PTR(OBJECT_GET_LEVEL_OF_DETAIL_PIXELS,		K_OBJECT_GET_LEVEL_OF_DETAIL_PIXELS, FUNC_PTR_NULL);
FUNC_PTR(OBJECT_RENDER_STATE_REFRESH,			K_OBJECT_RENDER_STATE_REFRESH, FUNC_PTR_NULL);
FUNC_PTR(OBJECTS_UPDATE,						DUO_PTR(K_OBJECTS_UPDATE));
FUNC_PTR(OBJECT_UPDATE,							DUO_PTR(K_OBJECT_UPDATE));
FUNC_PTR(OBJECT_GET_MARKER_BY_NAME,				DUO_PTR(K_OBJECT_GET_MARKER_BY_NAME));
FUNC_PTR(OBJECT_DESTROY,						DUO_PTR(K_OBJECT_DESTROY));

//////////////////////////////////////////////////////////////////////////
// Units
FUNC_PTR(UNIT_UPDATE,							DUO_PTR(K_UNIT_UPDATE));
FUNC_PTR(UNIT_GET_CAMERA_POSITION,				K_UNIT_GET_CAMERA_POSITION, FUNC_PTR_NULL);
FUNC_PTR(UNIT_SET_ANIMATION,					DUO_PTR(K_UNIT_SET_ANIMATION));
FUNC_PTR(UNIT_ANIMATION_START_ACTION,			DUO_PTR(K_UNIT_ANIMATION_START_ACTION));
FUNC_PTR(UNIT_GET_CUSTOM_ANIMATION_TIME,		DUO_PTR(K_UNIT_GET_CUSTOM_ANIMATION_TIME));
FUNC_PTR(UNIT_CAN_ENTER_SEAT,					DUO_PTR(K_UNIT_CAN_ENTER_SEAT));
FUNC_PTR(UNIT_ENTER_SEAT,						DUO_PTR(K_UNIT_ENTER_SEAT));
FUNC_PTR(UNIT_EXIT_VEHICLE,						DUO_PTR(K_UNIT_EXIT_VEHICLE));
FUNC_PTR(UNIT_OPEN,								DUO_PTR(K_UNIT_OPEN));
FUNC_PTR(UNIT_CLOSE,							DUO_PTR(K_UNIT_CLOSE));
FUNC_PTR(UNIT_FIND_NEARBY_SEAT,					DUO_PTR(K_UNIT_FIND_NEARBY_SEAT));
FUNC_PTR(UNIT_EXIT_SEAT_END,					DUO_PTR(K_UNIT_EXIT_SEAT_END));
FUNC_PTR(UNIT_CAN_SEE_POINT,					DUO_PTR(K_UNIT_CAN_SEE_POINT));
FUNC_PTR(UNIT_TRY_AND_EXIT_SEAT,				DUO_PTR(K_UNIT_TRY_AND_EXIT_SEAT));
FUNC_PTR(UNIT_DETACH_FROM_PARENT,				DUO_PTR(K_UNIT_DETACH_FROM_PARENT));
FUNC_PTR(UNIT_START_USER_ANIMATION,				DUO_PTR(K_UNIT_START_USER_ANIMATION));
FUNC_PTR(UNIT_DROP_CURRENT_WEAPON,				DUO_PTR(K_UNIT_DROP_CURRENT_WEAPON));
FUNC_PTR(UNIT_DAMAGE_AFTERMATH,					DUO_PTR(K_UNIT_DAMAGE_AFTERMATH));
FUNC_PTR(UNIT_SCRIPTING_SET_CURRENT_VITALITY,	DUO_PTR(K_UNIT_SCRIPTING_SET_CURRENT_VITALITY));
FUNC_PTR(UNIT_ANIMATION_SET_STATE,				DUO_PTR(K_UNIT_ANIMATION_SET_STATE));
FUNC_PTR(UNIT_INVENTORY_GET_WEAPON,				DUO_PTR(K_UNIT_INVENTORY_GET_WEAPON));
FUNC_PTR(UNIT_THROW_GRENADE_RELEASE,			DUO_PTR(K_UNIT_THROW_GRENADE_RELEASE));
FUNC_PTR(UNIT_CAUSE_PLAYER_MELEE_DAMAGE,		DUO_PTR(K_UNIT_CAUSE_PLAYER_MELEE_DAMAGE));
FUNC_PTR(UNIT_SET_ACTIVELY_CONTROLLED,			DUO_PTR(K_UNIT_SET_ACTIVELY_CONTROLLED));
FUNC_PTR(UNIT_READY_DESIRED_WEAPON,				DUO_PTR(K_UNIT_READY_DESIRED_WEAPON));

//////////////////////////////////////////////////////////////////////////
// Physics
FUNC_PTR(COLLISION_TEST_VECTOR,					DUO_PTR(K_COLLISION_TEST_VECTOR));

//////////////////////////////////////////////////////////////////////////
// Players
FUNC_PTR(PLAYER_INDEX_FROM_UNIT_INDEX,			DUO_PTR(K_PLAYER_INDEX_FROM_UNIT_INDEX));
FUNC_PTR(PLAYER_TELEPORT,						DUO_PTR(K_PLAYER_TELEPORT));
FUNC_PTR(PLAYER_OVER_SHIELD_SCREEN_EFFECT,		K_PLAYER_OVER_SHIELD_SCREEN_EFFECT, FUNC_PTR_NULL);
FUNC_PTR(PLAYER_CAMO_SCREEN_EFFECT,				K_PLAYER_CAMO_SCREEN_EFFECT, FUNC_PTR_NULL);
FUNC_PTR(PLAYER_HEALTH_PACK_SCREEN_EFFECT,		K_PLAYER_HEALTH_PACK_SCREEN_EFFECT, FUNC_PTR_NULL);
FUNC_PTR(FIND_CLOSEST_PLAYER_INDEX,				K_FIND_CLOSEST_PLAYER_INDEX, FUNC_PTR_NULL);
FUNC_PTR(PLAYER_EXAMINE_NEARBY_VEHICLE,			DUO_PTR(K_PLAYER_EXAMINE_NEARBY_VEHICLE));
FUNC_PTR(PLAYER_SET_ACTION_RESULT,				DUO_PTR(K_PLAYER_SET_ACTION_RESULT));
FUNC_PTR(PLAYER_SET_ACTION_RESULT_TO_NETWORK,	DUO_PTR(K_PLAYER_SET_ACTION_RESULT_TO_NETWORK));
FUNC_PTR(PLAYER_CONTROL_GET_UNIT_CAMERA_INFO,	K_PLAYER_CONTROL_GET_UNIT_CAMERA_INFO, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Render
FUNC_PTR(RENDER_FRAME,							K_RENDER_FRAME, FUNC_PTR_NULL);
FUNC_PTR(RENDER_WINDOW,							K_RENDER_WINDOW, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Scenario
FUNC_PTR(SCENARIO_TRIGGER_VOLUME_TEST_POINT,	DUO_PTR(K_SCENARIO_TRIGGER_VOLUME_TEST_POINT));

//////////////////////////////////////////////////////////////////////////
// TagGroups
FUNC_PTR(TAG_LOADED,							DUO_PTR(K_TAG_LOADED));
FUNC_PTR(TAG_ITERATOR_NEXT,						DUO_PTR(K_TAG_ITERATOR_NEXT));
FUNC_PTR(UNICODE_STRING_LIST_GET_STRING,		DUO_PTR(K_UNICODE_STRING_LIST_GET_STRING));