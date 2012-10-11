/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/
#pragma once

#include <blamlib/Halo1/cache/physical_memory_map.hpp>

namespace Yelo
{
	namespace Enums
	{
		enum {
			k_game_state_allocation_size =			0x00440000,

			// Default address of the game state in memory
			k_game_state_base_address =				k_physical_memory_base_address,
			// Max amount of memory addressable by the game state. After this comes tag memory
			k_game_state_cpu_size =					k_game_state_allocation_size,
		};
	};

	namespace GameState
	{
		struct s_yelo_header_data
		{
			PAD8; // since the unused 32 bytes in s_header_data is more than likely a tag_string, we don't want to touch what is actually the first char (we want it to stay zero)
			struct {
				bool initialized : 1;
				bool game_state_upgrades_on : 1;
			}flags;									// 0x01
			struct {
				byte major;							// 0x2
				byte minor;							// 0x3
				uint16 build;						// 0x4
			}version;
			PAD16;									// 0x6
		}; BOOST_STATIC_ASSERT( sizeof(s_yelo_header_data) <= 0x20 );
		struct s_header_data
		{
			uint32 allocation_crc;
			char level[256];
			tag_string version;
			int16 player_spawn_count;
			_enum game_difficulty;
			uint32 cache_crc;

			union {
				byte _unused[32];
				s_yelo_header_data yelo;
			};
		}; BOOST_STATIC_ASSERT( sizeof(s_header_data) == 0x14C );

		struct s_game_state_globals
		{
			void* base_address;
			uint32 cpu_allocation_size;
			PAD32; // unused
			uint32 crc;
			bool locked;
			bool saved;
			PAD16;
			uint32 revert_time;
			s_header_data* header;

			// etc... there are more fields to this but I could give a flying fuck less about them
		};
	};
};