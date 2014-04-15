/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/
#pragma once

#include <blamlib/Halo1/ai/action_fight.hpp>
#include <blamlib/Halo1/ai/action_flee.hpp>
#include <blamlib/Halo1/ai/actions.hpp>
#include <blamlib/Halo1/ai/actor_combat.hpp>
#include <blamlib/Halo1/ai/actor_looking.hpp>
#include <blamlib/Halo1/ai/actor_moving.hpp>
#include <blamlib/Halo1/ai/actor_perception.hpp>
#include <blamlib/Halo1/ai/actor_stimulus.hpp>
#include <blamlib/Halo1/ai/actors.hpp>
#include <blamlib/Halo1/memory/data.hpp>

namespace Yelo
{
	namespace AI
	{
		struct s_actor_datum : TStructImpl(1828)
		{
			TStructGetPtrImpl(bool,				MetaSwarm, 0x6);
			//TStructGetPtrImpl(bool,				Meta, 0x7);
			TStructGetPtrImpl(bool,				MetaActive, 0x8);
			TStructGetPtrImpl(bool,				MetaEncounterless, 0x9);
			//TStructGetPtrImpl(bool,				Meta, 0xA);

			//TStructGetPtrImpl(int16,			Meta, 0x10); // ticks
			//TStructGetPtrImpl(bool,				Meta, 0x12);
			TStructGetPtrImpl(bool,				MetaDormant, 0x13);
			//TStructGetPtrImpl(int16,			Meta, 0x14);

			TStructGetPtrImpl(datum_index,		MetaUnitIndex, 0x18);
			// 0x1C ?
			TStructGetPtrImpl(int16,			MetaSwarmUnitCount, 0x1E); // MAXIMUM_NUMBER_OF_UNITS_PER_SWARM = 16
			//TStructGetPtrImpl(int16,			MetaSwarmUnit, 0x20);
			// 0x22 ?
			TStructGetPtrImpl(datum_index,		MetaSwarmUnitIndex, 0x24);
			TStructGetPtrImpl(datum_index,		MetaSwarmCacheIndex, 0x28);
			//TStructGetPtrImpl(datum_index,		Meta, 0x2C); // an actor index
			//TStructGetPtrImpl(datum_index,		Meta, 0x30);
			TStructGetPtrImpl(datum_index,		MetaEncounterIndex, 0x34);

			TStructGetPtrImpl(int16,			MetaSquadIndex, 0x3A);
			TStructGetPtrImpl(int16,			MetaPlatoonIndex, 0x3C);
			TStructGetPtrImpl(_enum,			MetaTeam, 0x3E); // Enums::game_team

			TStructGetPtrImpl(bool,				MetaTimeslice, 0x4C);
			TStructGetPtrImpl(datum_index,		MetaFirstPropIndex, 0x50);
			// 0x54 int32
			TStructGetPtrImpl(datum_index,		MetaActorDefinitionIndex, 0x58);
			TStructGetPtrImpl(datum_index,		MetaActorVariantDefinitionIndex, 0x5C);

			//TStructGetPtrImpl(_enum,		, 0x6A);
			TStructGetPtrImpl(Enums::actor_action,		StateAction, 0x6C);

			//TStructGetPtrImpl(bool,				State, 0x8D);

			// 0x9C union state.action_data (total size: 0x84)

			TStructGetPtrImpl(bool,				StateActionDataChargeFinishedMeleeAttack, 0xA3);
			TStructGetPtrImpl(bool,				StateActionDataChargeAbortedMeleeAttack, 0xA4);

			TStructGetPtrImpl(bool,				StateActionDataChargeUnableToAdvance, 0xC5);

			//////////////////////////////////////////////////////////////////////////
			// input @ 0x120, sizeof(0xA8)
			//TStructGetPtrImpl(real_point3d,	Input, 0x120);

			TStructGetPtrImpl(bool,				InputVehiclePassenger, 0x160);
			//TStructGetPtrImpl(int32,			InputSurfaceIndex, 0x164);
			//TStructGetPtrImpl(real_vector3d,	InputPosition, 0x168);
			TStructGetPtrImpl(real_vector3d,	InputFacingVector, 0x174);
			TStructGetPtrImpl(real_vector3d,	InputAimingVector, 0x180);
			TStructGetPtrImpl(real_vector3d,	InputLookingVector, 0x18C);

			TStructGetPtrImpl(bool,				InputIsBurningToDeath, 0x1B5);
			//PAD16
			TStructGetPtrImpl(real,				InputUnitDamageBody, 0x1B8);
			TStructGetPtrImpl(real,				InputUnitDamageShield, 0x1BC);
			TStructGetPtrImpl(real,				InputUnitDamageBodyRecent, 0x1C0);
			TStructGetPtrImpl(real,				InputUnitDamageShieldRecent, 0x1C4);
			//////////////////////////////////////////////////////////////////////////

			//TStructGetPtrImpl(_enum,			, 0x1E4);
			//TStructGetPtrImpl(datum_index,		, 0x1E8); // prop_index
			//////////////////////////////////////////////////////////////////////////
			// situation @ 0x1EC, sizeof(0x7B)
			//////////////////////////////////////////////////////////////////////////

			TStructGetPtrImpl(Enums::actor_target_type,		TargetTargetType, 0x268);

			TStructGetPtrImpl(datum_index,		TargetTargetPropIndex, 0x270);

			TStructGetPtrImpl(Enums::actor_danger_zone,		DangerZoneDangerType, 0x280);

			TStructGetPtrImpl(bool,				DangerZoneNoticedDanager, 0x287);

			TStructGetPtrImpl(datum_index,		DangerZoneObjectIndex, 0x28C);

			//TStructGetPtrImpl(real,				, 0x294);

			//TStructGetPtrImpl(real_point3d,		, 0x2B0);
			//TStructGetPtrImpl(real_vector3d,	, 0x2BC);

			//TStructGetPtrImpl(real,				, 0x2D8);
			//TStructGetPtrImpl(real_point3d,	, 0x2DC);

			//////////////////////////////////////////////////////////////////////////
			// stimulus @ 0x2EC, sizeof(0x64)
			TStructGetPtrImpl(bool,				StimuliVehicleEviction, 0x2ED);

			TStructGetPtrImpl(bool,				StimuliWasSurprised, 0x2F0);

			TStructGetPtrImpl(_enum,			StimuliPanicType, 0x308);
			TStructGetPtrImpl(datum_index,		StimuliPanicPropIndex, 0x30C);

			TStructGetPtrImpl(_enum,			StimuliCombatTransition, 0x312);

			TStructGetPtrImpl(datum_index,		StimuliCombatTransitionPropIndex, 0x340);

			//////////////////////////////////////////////////////////////////////////
			// emotions @ 350, sizeof(0x68)
			//TStructGetPtrImpl(real,				, 0x354);
			//TStructGetPtrImpl(bool,				, 0x358);
			//PAD8;
			//TStructGetPtrImpl(int16,				, 0x35A);

			//TStructGetPtrImpl(bool,					, 0x363);
			TStructGetPtrImpl(int16,				EmotionsCrouchSwitchingChangeTimer, 0x364);

			//////////////////////////////////////////////////////////////////////////
			// firing_positions @ 0x3B8, sizeof( ? )
			TStructGetPtrImpl(int16,			FiringPositionsCurrentPositionIndex, 0x3B8);
			//TStructGetPtrImpl(bool,					, 0x3BA);

			//TStructGetPtrImpl(int16,			FiringPositions, 0x3C6); // a count of sorts
			// 0x3C8, array of [4] elements, struct made of 2 int16
			//TStructGetPtrImpl(bool,			FiringPositions, 0x3D8);
			//TStructGetPtrImpl(bool,			FiringPositions, 0x3D9);
			//TStructGetPtrImpl(real_vector3d,	FiringPositions, 0x3DC);

			//////////////////////////////////////////////////////////////////////////
			// orders  @ 0x3E8, sizeof(0x84)

			//TStructGetPtrImpl(int16,			Orders, 0x418);

			//TStructGetPtrImpl(int16,			Orders, 0x42C);
			//TStructGetPtrImpl(int16,			Orders, 0x42E);

			//////////////////////////////////////////////////////////////////////////
			// control
			struct s_direction_specification
			{
				// 1 = _direction_specification_prop
				_enum type;
				PAD16;
				datum_index prop_index;
				PAD32; PAD32;
			}; BOOST_STATIC_ASSERT( sizeof(s_direction_specification) == 0x10 );

			//TStructGetPtrImpl(_enum,			control.path.destination_orders, 0x46C);
			//TStructGetPtrImpl(int16,			control.path.destination_orders, 0x470);

			//TStructGetPtrImpl(datum_index,	control.path.destination_orders.ignore_target_object_index, 0x480);
			TStructGetPtrImpl(bool,				ControlPathDestinationOrdersComplete, 0x484); // true when at destination

			//TStructGetPtrImpl(int32,			control.path, 0x4A0);

			//TStructGetPtrImpl(,	control.path, 0x4A8); // 0x5C byte structure

			TStructGetPtrImpl(_enum,			ControlSecondaryLookType, 0x544);
			// 0x48 ?
			TStructGetPtrImpl(s_direction_specification,	ControlSecondaryLookDirection, 0x54C);

			TStructGetPtrImpl(bool,				ControlIdleMajorActive, 0x55C);
			// 0x55D ?
			//TStructGetPtrImpl(bool,				Control, 0x55E);
			TStructGetPtrImpl(bool,				ControlIdleMinorActive, 0x55F);
			//TStructGetPtrImpl(int32,	Control, 0x560); // timer. secondary look?
			TStructGetPtrImpl(int32,	ControlIdleMajorTimer, 0x564);
			TStructGetPtrImpl(int32,	ControlIdleMinorTimer, 0x568);
			TStructGetPtrImpl(s_direction_specification,	ControlIdleMajorDirection, 0x56C);
			TStructGetPtrImpl(s_direction_specification,	ControlIdleMinorDirection, 0x57C);

			//TStructGetPtrImpl(bool,				Control, 0x591);
			//PAD24
			//TStructGetPtrImpl(real,				Control, 0x594);

			TStructGetPtrImpl(real_vector3d,	ControlDesiredFacingVector, 0x5A4);
			TStructGetPtrImpl(real_vector3d,	ControlDesiredAimingVector, 0x5B0);
			TStructGetPtrImpl(real_vector3d,	ControlDesiredLookingVector, 0x5BC);
			// 0x5C8, 0x10 byte structure

			TStructGetPtrImpl(_enum,			ControlFireState, 0x5F2);

			TStructGetPtrImpl(Enums::actor_fire_target,		ControlCurrentFireTargetType, 0x60C);
			//////////////////////////////////////////////////////////////////////////
			// _actor_fire_target_prop
			TStructGetPtrImpl(datum_index,		ControlCurrentFireTargetPropIndex, 0x610);
			//////////////////////////////////////////////////////////////////////////
			// _actor_fire_target_manual_point
			//TStructGetPtrImpl(real_point3d,		ControlCurrentFireTargetManualPoint?, 0x610);
			//TStructGetPtrImpl(int32,				Control, 0x61C);

			//TStructGetPtrImpl(bool,				Control, 0x621);
			//TStructGetPtrImpl(bool,				Control, 0x622);
			//TStructGetPtrImpl(bool,				Control, 0x623);
			//TStructGetPtrImpl(sbyte,				Control, 0x624);
			//TStructGetPtrImpl(int16,				Control, 0x626);

			//TStructGetPtrImpl(real_vector3d,	Control, 0x62C);

			//TStructGetPtrImpl(real,				Control, 0x638);

			TStructGetPtrImpl(real_vector3d,	ControlBurstAimVector, 0x68C);

			TStructGetPtrImpl(word_flags,		ControlDataFlags, 0x6D0); // unit_control_flags
			// PAD16?
			TStructGetPtrImpl(int16,			ControlPersistentControlTicks, 0x6D4);
			// PAD16?
			TStructGetPtrImpl(long_flags,		ControlPersistentControlFlags, 0x6D8);

			TStructGetPtrImpl(Enums::actor_movement_state,			ControlMovementState, 0x6DC);
			TStructGetPtrImpl(real_vector3d,	ControlDataThrottle, 0x6E0);

			//TStructGetPtrImpl(int16,			ControlAnimation, 0x6EC);
			TStructGetPtrImpl(real_vector2d,	ControlAnimationFacing, 0x6F0);
			TStructGetPtrImpl(_enum,			ControlDataAimingType, 0x6F8); // 0=alert, 1=casual, casted to byte then set to ctrl_data's aiming_speed
			// PAD24
			TStructGetPtrImpl(real_vector3d,	ControlDataFacingVector, 0x6FC);
			TStructGetPtrImpl(real_vector3d,	ControlDataAimingVector, 0x708);
			TStructGetPtrImpl(real_vector3d,	ControlDataLookingVector, 0x714);
			TStructGetPtrImpl(real,				ControlDataPrimaryTrigger, 0x720);
		};
		typedef Memory::DataArray<	s_actor_datum, 
									256>
			actor_data_t;


		struct s_swarm_datum : Memory::s_datum_base
		{
			int16 unit_count;			// 0x2
			datum_index actor_index;	// 0x4
			UNKNOWN_TYPE(int16);		// 0x8
			PAD16;
			UNKNOWN_TYPE(real_vector3d);// 0xC
			datum_index unit_indices[Enums::k_maximum_number_of_units_per_swarm];
			datum_index component_indices[Enums::k_maximum_number_of_units_per_swarm];
		}; BOOST_STATIC_ASSERT( sizeof(s_swarm_datum) == 0x98 );
		typedef Memory::DataArray<	s_swarm_datum, 
									Enums::k_maximum_number_of_active_swarms> 
			swarm_data_t;

		struct s_swarm_component_datum : TStructImpl(64)
		{
		};
		typedef Memory::DataArray<	s_swarm_component_datum, 
									256>
			swarm_component_data_t;


		actor_data_t&					Actors();

		swarm_data_t&					Swarms();
		swarm_component_data_t&			SwarmComponents();
	};
};