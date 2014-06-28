/*
	Yelo: Open Sauce SDK

	See license\OpenSauce\OpenSauce for specific license information
*/
#pragma once

#include <YeloLib/tag_files/tag_groups_base_yelo.hpp>

namespace Yelo
{
	namespace Enums
	{
		enum tag_postprocess_mode : byte_enum;

		enum production_build_stage
		{
			_production_build_stage_ship,
			_production_build_stage_alpha,
			_production_build_stage_beta,
			_production_build_stage_delta,
			_production_build_stage_epsilon,
			_production_build_stage_release,
		};
	};

	namespace TagGroups
	{
		struct s_scripting_definitions;
		struct s_project_yellow_scripted_ui_widget;
		struct scenario;


		struct s_project_yellow_scenario_build_info
		{
			PAD16;
			TAG_ENUM(build_stage, Enums::production_build_stage);
			TAG_FIELD(uint32, revision);
			time_t timestamp;			BOOST_STATIC_ASSERT(sizeof(time_t) == 0x8);
			byte uuid_buffer[Enums::k_uuid_buffer_size];

			TAG_PAD(int32, 4); // 16

			bool HasUuid() const;
			void GenerateUuid();
		};

		//////////////////////////////////////////////////////////////////////////
		// scenario information
		struct s_transition_sequence_block
		{
			struct _flags {
				TAG_FLAG16(unused);
			}flags;	BOOST_STATIC_ASSERT( sizeof(_flags) == sizeof(word_flags) );
			TAG_FIELD(_enum, transition_function);
			TAG_FIELD(real, transition_period);
			TAG_FIELD(int16, next_sequence_block);
			PAD16;
		};

		/* BSP */
		struct s_scenario_information_bsp_lightmap_set
		{
			TAG_PAD(int32, 1);
			TAG_FIELD(tag_reference, standard_lightmap, 'bitm');
			TAG_FIELD(tag_reference, directional_lightmap_1, 'bitm');
			TAG_FIELD(tag_reference, directional_lightmap_2, 'bitm');
			TAG_FIELD(tag_reference, directional_lightmap_3, 'bitm');
			TAG_PAD(tag_block, 3);
		};

		struct s_scenario_information_bsp_sky_set_sky
		{
			PAD16;
			TAG_FIELD(int16, sky_index);
			TAG_FIELD(tag_reference, sky);
		};

		struct s_scenario_information_bsp_sky_set
		{
			TAG_TBLOCK(skies,				s_scenario_information_bsp_sky_set_sky);
		};

		struct s_scenario_information_bsp
		{
			TAG_FIELD(tag_reference, bsp, 'sbsp');
			TAG_TBLOCK(lightmap_sets,		s_scenario_information_bsp_lightmap_set);
			TAG_TBLOCK(sky_sets,			s_scenario_information_bsp_sky_set);
			TAG_PAD(tag_block, 3);
		};
		/* BSP */

		struct s_project_yellow_scenario_information
		{
			PAD32;
			TAG_TBLOCK(bsps, s_scenario_information_bsp);
			TAG_PAD(tag_block, 4); // 48
		};
		//////////////////////////////////////////////////////////////////////////

		// yelo for scenarios
		struct project_yellow
		{
			// internal name of the cache's Yelo tag when the user doesn't supply a definition
			static cstring k_default_name;

#if !PLATFORM_IS_EDITOR
			const 
#endif
				int16 version;	enum { k_version = 2, k_group_tag = 'yelo' };
			struct _flags {
				TAG_FLAG16(dont_fix_ui_game_globals);
				TAG_FLAG16(game_updates_ignore_player_pvs_hack);
				TAG_FLAG16(unused2);
				TAG_FLAG16(unused3);
				TAG_FLAG16(unused4);
				TAG_FLAG16(unused5);
				TAG_FLAG16(unused6);
				TAG_FLAG16(unused7);
				TAG_FLAG16(unused8);
				TAG_FLAG16(unused9);
				TAG_FLAG16(unused10);
				TAG_FLAG16(unused11);
				TAG_FLAG16(unused12);

				// Flags set at runtime
				TAG_FLAG16(invalid_version); // a yelo tag was found but it was an invalid version
				TAG_FLAG16(null_definition); // 'null_yelo' definition
				TAG_FLAG16(cache_is_protected); // cache was protected with HEK+
			}flags;	BOOST_STATIC_ASSERT( sizeof(_flags) == sizeof(word_flags) );


			/* !-- Misc --! */
			TAG_FIELD(tag_reference, yelo_globals, "gelo");
			TAG_FIELD(tag_reference, game_globals, "matg");
			TAG_FIELD(tag_reference, explicit_references, "tagc");
			TAG_TBLOCK(build_info, s_project_yellow_scenario_build_info); // 1

			TAG_PAD(int32, 10); // 40
			/* --- Misc --- */


			/* !-- UI/GUI --! */
			struct {
				TAG_TBLOCK(scripted_widgets, s_project_yellow_scripted_ui_widget); // 128

				TAG_PAD(int32, 4); // 16
			}ui;
			/* --- UI/GUI --- */


			/* !-- Physics --! */
			struct _physics {
				TAG_FIELD(real, gravity_scale, "[0,2]", "amount to scale gravity ingame");
				TAG_FIELD(real, player_speed_scale, "[0,6]", "amount to scale the player speeds");

				TAG_PAD(int32, 5); // 20

				bool IsGravityScaleValid() const;
				void ResetGravityScale();

				bool IsPlayerSpeedScaleValid() const;
				void ResetPlayerSpeedScale();
			}physics;
			/* --- Physics --- */


			/* !-- Netgame --! */
			struct {
				struct _networking_flags {
					TAG_FLAG(unused);
				}flags;	BOOST_STATIC_ASSERT( sizeof(_networking_flags) == sizeof(long_flags) );

				TAG_PAD(int32, 5); // 20
			}networking;
			/* --- Netgame --- */


			/* !-- Gameplay --! */
			struct {
				struct _gameplay_flags {
					TAG_FLAG(prohibit_multiteam_vehicles, "don't allow MTV settings for this map, even if the user enables it");
				}flags;	BOOST_STATIC_ASSERT( sizeof(_gameplay_flags) == sizeof(long_flags) );

				TAG_PAD(int32, 5); // 20
			}gameplay;
			/* !-- Gameplay --! */


			/* !-- Scripting --! */
			TAG_TBLOCK(user_scripting, s_scripting_definitions); // 1
			/* !-- Scripting --! */

			/* !-- Scenario Enhancements --! */
			TAG_TBLOCK(scenario, s_project_yellow_scenario_information); // 1
			/* !-- Scenario Enhancements --! */


			TAG_PAD(int32, 20); // 80



			bool IsNull() const;
			bool IsCacheProtected() const;

			static bool PLATFORM_API GroupPostprocess(datum_index tag_index, Enums::tag_postprocess_mode mode);
		};

#if PLATFORM_IS_EDITOR
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// 	Removes Yelo-related data so that the scenario may be opened with no conflicts in the stock HEK.
		/// </summary>
		void YeloCleanseScenario(scenario* scnr);
#endif
	};
};