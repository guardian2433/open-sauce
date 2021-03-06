--	Yelo: Open Sauce SDK
--		Halo 1 (CE) Edition

--	See license\OpenSauce\Halo1_CE for specific license information

HaloCEClient_Objects =
{
--////////////////////////////////////////////////////////////////////////
-- Objects.cpp
	["K_OBJECT_TYPE_DEFINITIONS"] =                                               0x6376A4,
	["K_WIDGET_TYPE_DEFINITIONS"] =                                               0x6376D8,
	["K_WIDGETS"] =                                                               0x7FB398,
	["K_FLAGS"] =                                                                 0x7FB3A8,
	["K_ANTENNAS"] =                                                              0x7FB3AC,
	["K_GLOW"] =                                                                  0x7FB3A0,
	["K_GLOW_PARTICLES"] =                                                        0x7FB3A4,
	["K_LIGHT_VOLUMES"] =                                                         0x653CC0,
	["K_LIGHTNINGS"] =                                                            0x653CC4,
	["K_CACHED_OBJECT_RENDER_STATES"] =                                           0x75E0EC,
	["K_UNIT_GLOBALS"] =                                                          0x68A8F0,
	["K_DEVICE_GROUPS"] =                                                         0x815DB0,
	["K_OBJECT_HEADER"] =                                                         0x7FB3B0,
	["K_OBJECTS_POOL"] =                                                          0x653C04,
	["K_OBJECT_GLOBALS"] =                                                        0x653C0C,
	["K_OBJECT_NAME_LIST"] =                                                      0x653C08,
	["K_COLLIDEABLE_OBJECT"] =                                                    0x7FB3D0,
	["K_CLUSTER_COLLIDEABLE_OBJECT_REFERENCE"] =                                  0x7FB3D4,
	["K_COLLIDEABLE_OBJECT_CLUSTER_REFERENCE"] =                                  0x7FB3D8,
	["K_NONCOLLIDEABLE_OBJECT"] =                                                 0x7FB3C0,
	["K_CLUSTER_NONCOLLIDEABLE_OBJECT_REFERENCE"] =                               0x7FB3C4,
	["K_NONCOLLIDEABLE_OBJECT_CLUSTER_REFERENCE"] =                               0x7FB3C8,
	["K_OBJECT_MEMORY_POOL_ALLOCATION_SIZE"] =                                    0x4F875D + 0x30,

	["K_OBJECT_TYPES_PLACE_ALL_MOD_VEHI_REMAP"] =                                 0x4F7833 + 0x30,
	["K_OBJECTS_UPDATE__OBJECT_IN_PLAYER_PVS_NOP1"] =                             0x4F8B84 + 0x30,
	["K_OBJECTS_UPDATE__OBJECT_IN_PLAYER_PVS_NOP2"] =                             0x4F8C1A + 0x30,
	["K_OBJECTS_UPDATE_CALL"] =                                                   0x45C3A8,
	["K_OBJECTS_UPDATE_HOOK"] =                                                   0x4F8D6E,
	["K_OBJECTS_GARBAGE_COLLECTION"] =                                            0x4FD8F0,
	["K_OBJECT_DAMAGE_OBJECT_BODY_HOOK"] =                                        0x4F34AA,
	["K_BIPED_UPDATE_MOVING_HOOK"] =                                              0x561B96,
	["K_BIPED_JUMP_MOD_STUN_PENALTY_FIELD_REF"] =                                 0x56283E + 0x30,
	["K_OBJECT_DEPLETE_BODY_KILL_CHILD_HOOK"] =                                   0x4F1783,
	["K_OBJECT_DEPLETE_BODY_KILL_CHILD_RETN"] =                                   0x4F178A,

	["K_OBJECT_DAMAGE_AFTERMATH__CALC_ACCEL_HOOK"] =                              0x4F39EB + 0x30,
	["K_OBJECT_DAMAGE_AFTERMATH__CALC_ACCEL_HOOK_RETURN"] =                       0x4F3A22 + 0x30,

	["K_OBJECT_DAMAGE_AFTERMATH__UNIT_VALIDATE_INST_ACCEL_HOOK"] =                0x4F3B08 + 0x30,
	["K_OBJECT_DAMAGE_AFTERMATH__UNIT_VALIDATE_INST_ACCEL_HOOK_RETURN"] =         0x4F3B1B + 0x30,
	["K_OBJECT_DAMAGE_AFTERMATH__UNIT_VALIDATE_INST_ACCEL_HOOK_RETURN_INVALID"] = 0x4F3B88 + 0x30,
	
	["K_MAXIMUM_RENDERED_OBJECTS_REF_32BIT_0"] =                                  0x45B60C + 1 + 0x10,
	["K_MAXIMUM_RENDERED_OBJECTS_REF_32BIT_1"] =                                  0x512755 + 1 + 0x30,
	
	["K_MAXIMUM_RENDERED_OBJECTS_REF_16BIT_0"] =                                  0x5127BF + 7 + 0x30,
	
	["K_RENDER_OBJECT_GLOBALS__RENDERED_OBJECTS_REF_0"] =                         0x512613 + 3 + 0x30,
	["K_RENDER_OBJECT_GLOBALS__RENDERED_OBJECTS_REF_1"] =                         0x51275A + 1 + 0x30,
	["K_RENDER_OBJECT_GLOBALS__RENDERED_OBJECTS_REF_2"] =                         0x51279E + 3 + 0x30,
	["K_RENDER_OBJECT_GLOBALS__RENDERED_OBJECTS_REF_3"] =                         0x5127F3 + 3 + 0x30,
		
	["K_OBJECT_NEW_SET_SHADOW_FLAG_HOOK"] =                                       0x4F934A,
	["K_OBJECT_NEW_SET_SHADOW_FLAG_RETN"] =                                       0x4F9357,
	
	["K_OBJECT_DISABLE_SHADOW_CAST_OVERRIDE_0"] =                                 0x44C21A,
	["K_OBJECT_DISABLE_SHADOW_CAST_OVERRIDE_1"] =                                 0x4FE4FA,
	["K_OBJECT_DISABLE_SHADOW_CAST_OVERRIDE_2"] =                                 0x552269,
	
	["K_FIRST_PERSON_WEAPON_RENDER_UPDATE"] =                                     0x4953D0,
	["K_RENDER_WINDOW_CALL_HOOK_FIRST_PERSON_WEAPON_RENDER_UPDATE"] =             0x50FD37,
		
--////////////////////////////////////////////////////////////////////////
-- Units.cpp
	["K_UNIT_ZOOM_LEVEL_OFFSET_REF_0"] =                                          0x459F81 + 0x10,
	["K_UNIT_ZOOM_LEVEL_OFFSET_REF_1"] =                                          0x55D7A9 + 0x30,
	["K_UNIT_ZOOM_LEVEL_OFFSET_REF_2"] =                                          0x565CD9 + 0x30,
	["K_UNIT_ZOOM_LEVEL_OFFSET_REF_3"] =                                          0x5667AD + 0x30,
	["K_UNIT_ZOOM_LEVEL_OFFSET_REF_4"] =                                          0x5667BB + 0x30,
	["K_UNIT_ZOOM_LEVEL_OFFSET_REF_5"] =                                          0x566849 + 0x30,
	["K_UNIT_ZOOM_LEVEL_OFFSET_REF_6"] =                                          0x566D52 + 0x30,
	["K_UNIT_ZOOM_LEVEL_OFFSET_REF_7"] =                                          0x5694EA + 0x30,
	["K_UNIT_ZOOM_LEVEL_OFFSET_REF_8"] =                                          0x569556 + 0x30,
	["K_UNIT_ZOOM_LEVEL_OFFSET_REF_9"] =                                          0x56964E + 0x30,
	
	["K_UNIT_DESIRED_ZOOM_LEVEL_OFFSET_REF_0"] =                                  0x473DE1 + 0x10,
	["K_UNIT_DESIRED_ZOOM_LEVEL_OFFSET_REF_1"] =                                  0x55EDD4 + 0x30,
	["K_UNIT_DESIRED_ZOOM_LEVEL_OFFSET_REF_2"] =                                  0x565CDF + 0x30,
	["K_UNIT_DESIRED_ZOOM_LEVEL_OFFSET_REF_3"] =                                  0x5667A7 + 0x30,
	["K_UNIT_DESIRED_ZOOM_LEVEL_OFFSET_REF_4"] =                                  0x567562 + 0x30,
	["K_UNIT_DESIRED_ZOOM_LEVEL_OFFSET_REF_5"] =                                  0x56955D + 0x30,
	
	["K_NUMBER_OF_UNIT_GRENADE_TYPES_REF_0"] =                                    0x476B4A + 1 + 0x10,
	["K_NUMBER_OF_UNIT_GRENADE_TYPES_REF_1"] =                                    0x47F2FC + 1 + 0x10,
	["K_NUMBER_OF_UNIT_GRENADE_TYPES_REF_2"] =                                    0x4B51F9 + 1 + 0x30,
	["K_NUMBER_OF_UNIT_GRENADE_TYPES_REF_3"] =                                    0x566774 + 1 + 0x30,
	["K_NUMBER_OF_UNIT_GRENADE_TYPES_REF_4"] =                                    0x4B665C + 1 + 0x30,
	["K_NUMBER_OF_UNIT_GRENADE_TYPES_REF_5"] =                                    0x572CA6 + 4 + 0x30,

	["K_MAXIMUM_UNIT_GRENADE_INDEX_REF_0"] =                                      0x474BF4 + 2 + 0x10,
	["K_MAXIMUM_UNIT_GRENADE_INDEX_REF_1"] =                                      0x56D703 + 1 + 0x30,
	["K_MAXIMUM_UNIT_GRENADE_INDEX_REF_2"] =                                      0x56D70F + 3 + 0x30,
	
	["K_ACTOR_DIED_UNIT_GRENADE_COUNT_MOD"] =                                     0x428D35,
	["K_PLAYER_ADD_EQUIPMENT_UNIT_GRENADE_COUNT_MOD"] =                           0x476AC7 + 0x10,
	["K_BIPED_NEW_FROM_NETWORK_UNIT_GRENADE_COUNT_MOD"] =                         0x55EE1A + 0x30,
	["K_BIPED_UPDATE_BASELINE_UNIT_GRENADE_COUNT_MOD1"] =                         0x55EEB6 + 0x30,
	["K_BIPED_UPDATE_BASELINE_UNIT_GRENADE_COUNT_MOD2"] =                         0x55EED4 + 0x30,
	["K_BIPED_BUILD_UPDATE_DELTA_UNIT_GRENADE_COUNT_MOD1"] =                      0x55EFDF + 0x30,
	["K_BIPED_BUILD_UPDATE_DELTA_UNIT_GRENADE_COUNT_MOD2"] =                      0x55EFF5 + 0x30,
	["K_BIPED_PROCESS_UPDATE_DELTA_UNIT_GRENADE_COUNT_MOD"] =                     0x55F1A6 + 0x30,
	["K_BIPED_UPDATE_CHECK_PARENT_UNIT_TYPE"] =                                   0x55CBCA + 0x30,
	["K_UNIT_DAMAGE_AFTERMATH_CALL"] =                                            0x4F3C57,
	
--////////////////////////////////////////////////////////////////////////
-- Units.SeatBoarding
	["K_UNIT_CAN_ENTER_SEAT_HOOK"] =                                              0x56A340,
	
--////////////////////////////////////////////////////////////////////////
-- Units.SeatDamage
	["K_BIPED_SEATED_MELEE_HOOK"] =                                               0x55D892,
	["K_BIPED_SEATED_MELEE_RETN"] =                                               0x55D899,
	["K_UNIT_THROW_GRENADE_RELEASE_HOOK"] =                                       0x5690B3,
	["K_WEAPON_PREVENTS_GRENADE_THROWING_HOOK"] =                                 0x571E61,
	["K_WEAPON_PREVENTS_GRENADE_THROWING_RETN"] =                                 0x571E66,
	
--////////////////////////////////////////////////////////////////////////
-- Units.Animations
	["K_ANIMATION_STATE_DEFINED_KEYFRAME_HOOK"] =                                 0x56908F,
	["K_ANIMATION_STATE_DEFINED_KEYFRAME_STOCK_RETN"] =                           0x569096,
	["K_ANIMATION_STATE_DEFINED_KEYFRAME_SKIP_RETN"] =                            0x5692B7,

	["K_ANIMATION_STATE_FINAL_KEYFRAME_HOOK"] =                                   0x5690E4,
	["K_ANIMATION_STATE_FINAL_KEYFRAME_STOCK_RETN"] =                             0x5690EB,
	["K_ANIMATION_STATE_FINAL_KEYFRAME_SKIP_RETN"] =                              0x5692A4,
	
	["K_UNIT_ANIMATION_STATE_INTERRUPTABLE_CALL_0"] =                             0x569010,
	["K_UNIT_ANIMATION_STATE_INTERRUPTABLE_CALL_1"] =                             0x56936C,
	["K_UNIT_ANIMATION_STATE_INTERRUPTABLE_CALL_2"] =                             0x56AC38,
	
	["K_UNIT_ANIMATION_BUSY_CALL_0"] =                                            0x40B5EA,
	["K_UNIT_ANIMATION_BUSY_CALL_1"] =                                            0x4343A8,
	["K_UNIT_ANIMATION_BUSY_CALL_2"] =                                            0x55D045,
	["K_UNIT_ANIMATION_BUSY_CALL_3"] =                                            0x5666FF,
	["K_UNIT_ANIMATION_BUSY_CALL_4"] =                                            0x56675B,
	["K_UNIT_ANIMATION_BUSY_CALL_5"] =                                            0x566D56,
	["K_UNIT_ANIMATION_BUSY_CALL_6"] =                                            0x56B788,
	["K_UNIT_ANIMATION_BUSY_CALL_7"] =                                            0x56EE6B,
	["K_UNIT_ANIMATION_BUSY_CALL_8"] =                                            0x56F7D5,
	["K_UNIT_ANIMATION_BUSY_CALL_9"] =                                            0x570239,
		
	["K_UNIT_ANIMATION_STATE_LOOPS_CALL"] =                                       0x5692AA,
	["K_UNIT_ANIMATION_WEAPON_IK_CALL"] =                                         0x567FEE,
	["K_UNIT_ANIMATION_VEHICLE_IK_CALL"] =                                        0x567F86
}
HaloCEClient_Objects_Index =
{
	[1] = "K_OBJECT_TYPE_DEFINITIONS",
	[2] = "K_WIDGET_TYPE_DEFINITIONS",
	[3] = "K_WIDGETS",
	[4] = "K_FLAGS",
	[5] = "K_ANTENNAS",
	[6] = "K_GLOW",
	[7] = "K_GLOW_PARTICLES",
	[8] = "K_LIGHT_VOLUMES",
	[9] = "K_LIGHTNINGS",
	[10] = "K_CACHED_OBJECT_RENDER_STATES",
	[11] = "K_UNIT_GLOBALS",
	[12] = "K_DEVICE_GROUPS",
	[13] = "K_OBJECT_HEADER",
	[14] = "K_OBJECTS_POOL",
	[15] = "K_OBJECT_GLOBALS",
	[16] = "K_OBJECT_NAME_LIST",
	[17] = "K_COLLIDEABLE_OBJECT",
	[18] = "K_CLUSTER_COLLIDEABLE_OBJECT_REFERENCE",
	[19] = "K_COLLIDEABLE_OBJECT_CLUSTER_REFERENCE",
	[20] = "K_NONCOLLIDEABLE_OBJECT",
	[21] = "K_CLUSTER_NONCOLLIDEABLE_OBJECT_REFERENCE",
	[22] = "K_NONCOLLIDEABLE_OBJECT_CLUSTER_REFERENCE",
	[23] = "K_OBJECT_MEMORY_POOL_ALLOCATION_SIZE",
	[24] = "K_OBJECT_TYPES_PLACE_ALL_MOD_VEHI_REMAP",
	[25] = "K_OBJECTS_UPDATE__OBJECT_IN_PLAYER_PVS_NOP1",
	[26] = "K_OBJECTS_UPDATE__OBJECT_IN_PLAYER_PVS_NOP2",
	[27] = "K_OBJECTS_UPDATE_CALL",
	[28] = "K_OBJECTS_UPDATE_HOOK",
	[29] = "K_OBJECTS_GARBAGE_COLLECTION",
	[30] = "K_OBJECT_DAMAGE_OBJECT_BODY_HOOK",
	[31] = "K_BIPED_UPDATE_MOVING_HOOK",
	[32] = "K_BIPED_JUMP_MOD_STUN_PENALTY_FIELD_REF",
	[33] = "K_OBJECT_DEPLETE_BODY_KILL_CHILD_HOOK",
	[34] = "K_OBJECT_DEPLETE_BODY_KILL_CHILD_RETN",
	[35] = "K_OBJECT_DAMAGE_AFTERMATH__CALC_ACCEL_HOOK",
	[36] = "K_OBJECT_DAMAGE_AFTERMATH__CALC_ACCEL_HOOK_RETURN",
	[37] = "K_OBJECT_DAMAGE_AFTERMATH__UNIT_VALIDATE_INST_ACCEL_HOOK",
	[38] = "K_OBJECT_DAMAGE_AFTERMATH__UNIT_VALIDATE_INST_ACCEL_HOOK_RETURN",
	[39] = "K_OBJECT_DAMAGE_AFTERMATH__UNIT_VALIDATE_INST_ACCEL_HOOK_RETURN_INVALID",
	[40] = "K_MAXIMUM_RENDERED_OBJECTS_REF_32BIT_0",
	[41] = "K_MAXIMUM_RENDERED_OBJECTS_REF_32BIT_1",
	[42] = "K_MAXIMUM_RENDERED_OBJECTS_REF_16BIT_0",
	[43] = "K_RENDER_OBJECT_GLOBALS__RENDERED_OBJECTS_REF_0",
	[44] = "K_RENDER_OBJECT_GLOBALS__RENDERED_OBJECTS_REF_1",
	[45] = "K_RENDER_OBJECT_GLOBALS__RENDERED_OBJECTS_REF_2",
	[46] = "K_RENDER_OBJECT_GLOBALS__RENDERED_OBJECTS_REF_3",
	[47] = "K_OBJECT_NEW_SET_SHADOW_FLAG_HOOK",
	[48] = "K_OBJECT_NEW_SET_SHADOW_FLAG_RETN",
	[49] = "K_OBJECT_DISABLE_SHADOW_CAST_OVERRIDE_0",
	[50] = "K_OBJECT_DISABLE_SHADOW_CAST_OVERRIDE_1",
	[51] = "K_OBJECT_DISABLE_SHADOW_CAST_OVERRIDE_2",
	[52] = "K_FIRST_PERSON_WEAPON_RENDER_UPDATE",
	[53] = "K_RENDER_WINDOW_CALL_HOOK_FIRST_PERSON_WEAPON_RENDER_UPDATE",
	[54] = "K_UNIT_ZOOM_LEVEL_OFFSET_REF_0",
	[55] = "K_UNIT_ZOOM_LEVEL_OFFSET_REF_1",
	[56] = "K_UNIT_ZOOM_LEVEL_OFFSET_REF_2",
	[57] = "K_UNIT_ZOOM_LEVEL_OFFSET_REF_3",
	[58] = "K_UNIT_ZOOM_LEVEL_OFFSET_REF_4",
	[59] = "K_UNIT_ZOOM_LEVEL_OFFSET_REF_5",
	[60] = "K_UNIT_ZOOM_LEVEL_OFFSET_REF_6",
	[61] = "K_UNIT_ZOOM_LEVEL_OFFSET_REF_7",
	[62] = "K_UNIT_ZOOM_LEVEL_OFFSET_REF_8",
	[63] = "K_UNIT_ZOOM_LEVEL_OFFSET_REF_9",
	[64] = "K_UNIT_DESIRED_ZOOM_LEVEL_OFFSET_REF_0",
	[65] = "K_UNIT_DESIRED_ZOOM_LEVEL_OFFSET_REF_1",
	[66] = "K_UNIT_DESIRED_ZOOM_LEVEL_OFFSET_REF_2",
	[67] = "K_UNIT_DESIRED_ZOOM_LEVEL_OFFSET_REF_3",
	[68] = "K_UNIT_DESIRED_ZOOM_LEVEL_OFFSET_REF_4",
	[69] = "K_UNIT_DESIRED_ZOOM_LEVEL_OFFSET_REF_5",
	[70] = "K_NUMBER_OF_UNIT_GRENADE_TYPES_REF_0",
	[71] = "K_NUMBER_OF_UNIT_GRENADE_TYPES_REF_1",
	[72] = "K_NUMBER_OF_UNIT_GRENADE_TYPES_REF_2",
	[73] = "K_NUMBER_OF_UNIT_GRENADE_TYPES_REF_3",
	[74] = "K_NUMBER_OF_UNIT_GRENADE_TYPES_REF_4",
	[75] = "K_NUMBER_OF_UNIT_GRENADE_TYPES_REF_5",
	[76] = "K_MAXIMUM_UNIT_GRENADE_INDEX_REF_0",
	[77] = "K_MAXIMUM_UNIT_GRENADE_INDEX_REF_1",
	[78] = "K_MAXIMUM_UNIT_GRENADE_INDEX_REF_2",
	[79] = "K_ACTOR_DIED_UNIT_GRENADE_COUNT_MOD",
	[80] = "K_PLAYER_ADD_EQUIPMENT_UNIT_GRENADE_COUNT_MOD",
	[81] = "K_BIPED_NEW_FROM_NETWORK_UNIT_GRENADE_COUNT_MOD",
	[82] = "K_BIPED_UPDATE_BASELINE_UNIT_GRENADE_COUNT_MOD1",
	[83] = "K_BIPED_UPDATE_BASELINE_UNIT_GRENADE_COUNT_MOD2",
	[84] = "K_BIPED_BUILD_UPDATE_DELTA_UNIT_GRENADE_COUNT_MOD1",
	[85] = "K_BIPED_BUILD_UPDATE_DELTA_UNIT_GRENADE_COUNT_MOD2",
	[86] = "K_BIPED_PROCESS_UPDATE_DELTA_UNIT_GRENADE_COUNT_MOD",
	[87] = "K_BIPED_UPDATE_CHECK_PARENT_UNIT_TYPE",
	[88] = "K_UNIT_DAMAGE_AFTERMATH_CALL",
	[89] = "K_UNIT_CAN_ENTER_SEAT_HOOK",
	[90] = "K_BIPED_SEATED_MELEE_HOOK",
	[91] = "K_BIPED_SEATED_MELEE_RETN",
	[92] = "K_UNIT_THROW_GRENADE_RELEASE_HOOK",
	[93] = "K_WEAPON_PREVENTS_GRENADE_THROWING_HOOK",
	[94] = "K_WEAPON_PREVENTS_GRENADE_THROWING_RETN",
	[95] = "K_ANIMATION_STATE_DEFINED_KEYFRAME_HOOK",
	[96] = "K_ANIMATION_STATE_DEFINED_KEYFRAME_STOCK_RETN",
	[97] = "K_ANIMATION_STATE_DEFINED_KEYFRAME_SKIP_RETN",
	[98] = "K_ANIMATION_STATE_FINAL_KEYFRAME_HOOK",
	[99] = "K_ANIMATION_STATE_FINAL_KEYFRAME_STOCK_RETN",
	[100] = "K_ANIMATION_STATE_FINAL_KEYFRAME_SKIP_RETN",
	[101] = "K_UNIT_ANIMATION_STATE_INTERRUPTABLE_CALL_0",
	[102] = "K_UNIT_ANIMATION_STATE_INTERRUPTABLE_CALL_1",
	[103] = "K_UNIT_ANIMATION_STATE_INTERRUPTABLE_CALL_2",
	[104] = "K_UNIT_ANIMATION_BUSY_CALL_0",
	[105] = "K_UNIT_ANIMATION_BUSY_CALL_1",
	[106] = "K_UNIT_ANIMATION_BUSY_CALL_2",
	[107] = "K_UNIT_ANIMATION_BUSY_CALL_3",
	[108] = "K_UNIT_ANIMATION_BUSY_CALL_4",
	[109] = "K_UNIT_ANIMATION_BUSY_CALL_5",
	[110] = "K_UNIT_ANIMATION_BUSY_CALL_6",
	[111] = "K_UNIT_ANIMATION_BUSY_CALL_7",
	[112] = "K_UNIT_ANIMATION_BUSY_CALL_8",
	[113] = "K_UNIT_ANIMATION_BUSY_CALL_9",
	[114] = "K_UNIT_ANIMATION_STATE_LOOPS_CALL",
	[115] = "K_UNIT_ANIMATION_WEAPON_IK_CALL",
	[116] = "K_UNIT_ANIMATION_VEHICLE_IK_CALL",
}