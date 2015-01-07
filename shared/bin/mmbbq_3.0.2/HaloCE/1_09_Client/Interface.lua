--	Yelo: Open Sauce SDK
--		Halo 1 (CE) Edition

--	See license\OpenSauce\Halo1_CE for specific license information

HaloCEClient_Interface =
{
--////////////////////////////////////////////////////////////////////////
-- Controls.cpp
	["K_INPUT_UPDATE_HOOK"] =                          0x493A16,
	["K_SETTINGS"] =                                   0x6AD822,
	["K_CONTROL_STATE"] =                              0x64C570,
	["K_MOUSE_POSITION_STATE"] =                       0x6B4028,
	["K_INPUT_STATE_FLAGS"] =                          0x6AD592,
	
--////////////////////////////////////////////////////////////////////////
-- GameUI.cpp
	["K_HUD_SCRIPTED_GLOBALS"] =                       0x6B44C8,
	["K_HUD_MESSAGING"] =                              0x64E990,
	["K_HUD_UNIT_INTERFACE"] =                         0x6B44DC,
	["K_HUD_WEAPON_INTERFACE"] =                       0x6B44E0,
	["K_HUD_NAV_POINTS"] =                             0x64E994,
	["K_MOTION_SENSOR"] =                              0x6B44E8,
	["K_FIRST_PERSON_WEAPONS"] =                       0x64DCE8,
	["K_TEXT_BOUNDS_GLOBALS"] =                        0x67F6F4,
	["K_FONT_DRAWING_GLOBALS"] =                       0x67F708,
	["K_HUD_CHAT_GLOBALS"] =                           0x64E7A8,
	["K_HUD_CHAT_LINE_COUNT"] =                        0x6B44D4,

	["K_HUD_UPDATE"] =                                 0x4ACBA0,
	["K_HUD_UPDATE_CALL"] =                            0x45C3B2,
	["K_FIRST_PERSON_WEAPONS_UPDATE"] =                0x495350,
	["K_FIRST_PERSON_WEAPONS_UPDATE_CALL"] =           0x45C38E,

	["K_FIRST_PERSON_WEAPON_SET_STATE_HOOK"] =         0x495FE9,
	["K_RENDER_CROSSHAIRS_DISABLE_MOD"] =              0x4B62E1,
	
	["K_RENDER_WIDGET_RECURSIVE"] =                    0x49DA20,
	
	["K_RENDER_WIDGET_RECURSIVE_CALL_0"] =             0x49B5FA,
	["K_RENDER_WIDGET_RECURSIVE_CALL_1"] =             0x49B6D6,
	["K_RENDER_WIDGET_RECURSIVE_CALL_2"] =             0x49DD1E,
	["K_RENDER_WIDGET_RECURSIVE_CALL_3"] =             0x49E759,
	["K_RENDER_WIDGET_RECURSIVE_CALL_4"] =             0x49EC51,
	["K_RENDER_WIDGET_RECURSIVE_CALL_5"] =             0x49EC8F,
	
	["K_RASTERIZER_RENDER_UI_SET_SCREENPROJ_CALL_0"] = 0x520885,
	["K_RASTERIZER_RENDER_UI_SET_SCREENPROJ_CALL_1"] = 0x535057,
	["K_RASTERIZER_RENDER_UI_SET_SCREENPROJ_CALL_2"] = 0x52F829,
	
	["K_HUD_RENDER_NAV_POINTS"] =                      0x4B3190,
	["K_HUD_RENDER_NAV_POINTS_CALL"] =                 0x4ACD0D,
	["K_HUD_RENDER_NAV_POINT_ANCHOR_HALF_X"] =         0x4B2D10 + 1,
	["K_HUD_RENDER_NAV_POINT_ANCHOR_HALF_Y"] =         0x4B2D19 + 2,
	["K_HUD_ANCHOR_SCREEN_X"] =                        0x6122E0,
	["K_HUD_ANCHOR_SCREEN_Y"] =                        0x6122DC,
	["K_HUD_ANCHOR_SCREEN_HALF_X"] =                   0x612954,
	["K_HUD_ANCHOR_SCREEN_HALF_Y"] =                   0x612958,
	
	["K_HUD_RENDER_PLAYERS"] =                         0x4ADA60,
	["K_HUD_RENDER_PLAYERS_CALL"] =                    0x4ACC8E,
	
	["K_HUD_RENDER_SCOREBOARD_INGAME"] =               0x45FE60,
	["K_HUD_RENDER_SCOREBOARD_INGAME_CALL"] =          0x497A62,
	["K_HUD_RENDER_SCOREBOARD_POSTGAME"] =             0x45E2A0,
	["K_HUD_RENDER_SCOREBOARD_POSTGAME_CALL"] =        0x497A59,
	["K_HUD_POINT_ANCHOR_WIDTH"] =                     0x4AED1F + 1,
	["K_HUD_POINT_ANCHOR_HEIGHT"] =                    0x4AED51 + 1,
	["K_HUD_POINT_ANCHOR_HALF_WIDTH"] =                0x4AED71 + 1,
	["K_HUD_POINT_ANCHOR_HALF_HEIGHT"] =               0x4AED95 + 1,
	["K_HUD_POINT_DAMAGE_ANCHOR_WIDTH"] =              0x4B4B94 + 1,
	["K_HUD_POINT_DAMAGE_ANCHOR_HEIGHT"] =             0x4B4B6D + 1,
	["K_HUD_POINT_DAMAGE_ANCHOR_HALF_HEIGHT"] =        0x4B4BAB + 4,
	
	["K_HUD_POINT_DAMAGE_ANCHOR_HALF_WIDTH_PTR_0"] =   0x4B4B88 + 2,
	["K_HUD_POINT_DAMAGE_ANCHOR_HALF_WIDTH_PTR_1"] =   0x4B4B48 + 2,
		
	["K_HUD_MULTIPLAYER_ICON_CTF_X"] =                 0x4B4874,
	["K_HUD_MULTIPLAYER_ICON_CTF_Y"] =                 0x4B487B,
	["K_HUD_MULTIPLAYER_ICON_KING_X"] =                0x4B48A6,
	["K_HUD_MULTIPLAYER_ICON_ODDBALL_X"] =             0x4B48D1,
	["K_HUD_MULTIPLAYER_ICON_ODDBALL_Y"] =             0x4B48D8,
	["K_HUD_MULTIPLAYER_ICON_RACE_X"] =                0x4B4900,
	["K_HUD_MULTIPLAYER_ICON_RACE_Y"] =                0x4B4907,
	["K_HUD_MULTIPLAYER_ICON_SLAYER_X"] =              0x4B492F,
	["K_HUD_MULTIPLAYER_ICON_BACKGROUND_X"] =          0x4B49DA,
	["K_HUD_MULTIPLAYER_ICON_BACKGROUND_Y"] =          0x4B49E1,
	["K_HUD_GLOBALS"] =                                0x6B44C4,
	
--////////////////////////////////////////////////////////////////////////
-- Keystone.cpp
	["K_KEYSTONE_CHATLOG_ADD_ITEM_SEND_MESSAGE"] =     0x4AEAD0,
	["K_CHAT_LOG_NAME"] =                              0x637D64,
	["K_MAIN_WINDOW"] =                                0x6BD194,

	["K_KS_TRANSLATEACCELERATOR_CALL"] =               0x5453F2,
	["K_KS_TRANSLATEACCELERATOR"] =                    0x6BD1A0,
	["K_KS_GETWINDOW"] =                               0x6BD1A8,
	["K_KW_RELEASE"] =                                 0x6BD1B8,
	["K_KW_GETCONTROLBYID"] =                          0x6BD1BC,
	["K_KC_SENDMESSAGE"] =                             0x6BD1D8,
	
--////////////////////////////////////////////////////////////////////////
-- UIWidget.cpp
	["K_UI_WIDGET_LOAD_BY_NAME_OR_TAG"] =              0x49ABD0,
}

HaloCEClient_Interface_Index =
{
	[1] = "K_INPUT_UPDATE_HOOK",
	[2] = "K_SETTINGS",
	[3] = "K_CONTROL_STATE",
	[4] = "K_MOUSE_POSITION_STATE",
	[5] = "K_INPUT_STATE_FLAGS",
	[6] = "K_HUD_SCRIPTED_GLOBALS",
	[7] = "K_HUD_MESSAGING",
	[8] = "K_HUD_UNIT_INTERFACE",
	[9] = "K_HUD_WEAPON_INTERFACE",
	[10] = "K_HUD_NAV_POINTS",
	[11] = "K_MOTION_SENSOR",
	[12] = "K_FIRST_PERSON_WEAPONS",
	[13] = "K_TEXT_BOUNDS_GLOBALS",
	[14] = "K_FONT_DRAWING_GLOBALS",
	[15] = "K_HUD_CHAT_GLOBALS",
	[16] = "K_HUD_CHAT_LINE_COUNT",
	[17] = "K_HUD_UPDATE",
	[18] = "K_HUD_UPDATE_CALL",
	[19] = "K_FIRST_PERSON_WEAPONS_UPDATE",
	[20] = "K_FIRST_PERSON_WEAPONS_UPDATE_CALL",
	[21] = "K_FIRST_PERSON_WEAPON_SET_STATE_HOOK",
	[22] = "K_RENDER_CROSSHAIRS_DISABLE_MOD",
	[23] = "K_RENDER_WIDGET_RECURSIVE",
	[24] = "K_RENDER_WIDGET_RECURSIVE_CALL_0",
	[25] = "K_RENDER_WIDGET_RECURSIVE_CALL_1",
	[26] = "K_RENDER_WIDGET_RECURSIVE_CALL_2",
	[27] = "K_RENDER_WIDGET_RECURSIVE_CALL_3",
	[28] = "K_RENDER_WIDGET_RECURSIVE_CALL_4",
	[29] = "K_RENDER_WIDGET_RECURSIVE_CALL_5",
	[30] = "K_RASTERIZER_RENDER_UI_SET_SCREENPROJ_CALL_0",
	[31] = "K_RASTERIZER_RENDER_UI_SET_SCREENPROJ_CALL_1",
	[32] = "K_RASTERIZER_RENDER_UI_SET_SCREENPROJ_CALL_2",
	[33] = "K_HUD_RENDER_NAV_POINTS",
	[34] = "K_HUD_RENDER_NAV_POINTS_CALL",
	[35] = "K_HUD_RENDER_NAV_POINT_ANCHOR_HALF_X",
	[36] = "K_HUD_RENDER_NAV_POINT_ANCHOR_HALF_Y",
	[37] = "K_HUD_ANCHOR_SCREEN_X",
	[38] = "K_HUD_ANCHOR_SCREEN_Y",
	[39] = "K_HUD_ANCHOR_SCREEN_HALF_X",
	[40] = "K_HUD_ANCHOR_SCREEN_HALF_Y",
	[41] = "K_HUD_RENDER_PLAYERS",
	[42] = "K_HUD_RENDER_PLAYERS_CALL",
	[43] = "K_HUD_RENDER_SCOREBOARD_INGAME",
	[44] = "K_HUD_RENDER_SCOREBOARD_INGAME_CALL",
	[45] = "K_HUD_RENDER_SCOREBOARD_POSTGAME",
	[46] = "K_HUD_RENDER_SCOREBOARD_POSTGAME_CALL",
	[47] = "K_HUD_POINT_ANCHOR_WIDTH",
	[48] = "K_HUD_POINT_ANCHOR_HEIGHT",
	[49] = "K_HUD_POINT_ANCHOR_HALF_WIDTH",
	[50] = "K_HUD_POINT_ANCHOR_HALF_HEIGHT",
	[51] = "K_HUD_POINT_DAMAGE_ANCHOR_WIDTH",
	[52] = "K_HUD_POINT_DAMAGE_ANCHOR_HEIGHT",
	[53] = "K_HUD_POINT_DAMAGE_ANCHOR_HALF_HEIGHT",
	[54] = "K_HUD_POINT_DAMAGE_ANCHOR_HALF_WIDTH_PTR_0",
	[55] = "K_HUD_POINT_DAMAGE_ANCHOR_HALF_WIDTH_PTR_1",
	[56] = "K_HUD_MULTIPLAYER_ICON_CTF_X",
	[57] = "K_HUD_MULTIPLAYER_ICON_CTF_Y",
	[58] = "K_HUD_MULTIPLAYER_ICON_KING_X",
	[59] = "K_HUD_MULTIPLAYER_ICON_ODDBALL_X",
	[60] = "K_HUD_MULTIPLAYER_ICON_ODDBALL_Y",
	[61] = "K_HUD_MULTIPLAYER_ICON_RACE_X",
	[62] = "K_HUD_MULTIPLAYER_ICON_RACE_Y",
	[63] = "K_HUD_MULTIPLAYER_ICON_SLAYER_X",
	[64] = "K_HUD_MULTIPLAYER_ICON_BACKGROUND_X",
	[65] = "K_HUD_MULTIPLAYER_ICON_BACKGROUND_Y",
	[66] = "K_HUD_GLOBALS",
	[67] = "K_KEYSTONE_CHATLOG_ADD_ITEM_SEND_MESSAGE",
	[68] = "K_CHAT_LOG_NAME",
	[69] = "K_MAIN_WINDOW",
	[70] = "K_KS_TRANSLATEACCELERATOR_CALL",
	[71] = "K_KS_TRANSLATEACCELERATOR",
	[72] = "K_KS_GETWINDOW",
	[73] = "K_KW_RELEASE",
	[74] = "K_KW_GETCONTROLBYID",
	[75] = "K_KC_SENDMESSAGE",
	[76] = "K_UI_WIDGET_LOAD_BY_NAME_OR_TAG",
}