/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/
#pragma once

#include <blamlib/Halo1/bitmaps/bitmap_group.hpp>
#include <YeloLib/Halo1/open_sauce/project_yellow_scenario_definitions.hpp>

namespace Yelo
{
	namespace Render { namespace Lightmaps
	{
		class c_lightmap_manager final
		{
		public:
			enum renderable_lightmaps_flags : word_flags
			{
				_renderable_lightmaps_flags_standard_bit = 1,
				_renderable_lightmaps_flags_directional_bit = 2,
			};

		private:
			renderable_lightmaps_flags m_available_lightmaps;
			renderable_lightmaps_flags m_used_lightmaps;

			struct s_lightmap_tag_indices
			{
				datum_index standard_tag_index;					//!< Tag index for the current standard lightmap.
				datum_index directional_tag_indices[3];			//!< Tag indices for the current directional lightmaps.
			}m_current_lightmaps;

		public:
			typedef TagGroups::s_bitmap_data* (API_FUNC *proc_get_bitmap_data)(const datum_index, const int32);

			bool HasLightmaps(const renderable_lightmaps_flags flag) const;
			bool UsingLightmaps(const renderable_lightmaps_flags flag) const;

			void SetLightmapDatums(const datum_index standard_tag_index
				, const datum_index directional_1_tag_index
				, const datum_index directional_2_tag_index
				, const datum_index directional_3_tag_index);
			void SetLightmapSamplers(LPDIRECT3DDEVICE9 device
				, const int32 lightmap_index
				, const proc_get_bitmap_data get_bitmap_data);
		};
	};};
};