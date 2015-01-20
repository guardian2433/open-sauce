/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/

#include <YeloLib/Halo1/ai/c_actor_variant_transform_manager.hpp>

namespace Yelo
{
	namespace AI { namespace Transform
	{
		static c_actor_variant_transform_manager g_actor_variant_transform_manager;

		void UnitUpdate(const datum_index unit_index)
		{
			g_actor_variant_transform_manager.UnitUpdate(unit_index);
		}

		void UnitDamaged(const datum_index unit_index, const Objects::s_damage_data* damage_data)
		{
			g_actor_variant_transform_manager.UnitDamaged(unit_index, damage_data);
		}

		void InitializeForNewMap()
		{
			g_actor_variant_transform_manager.LoadActorVariantTransforms();
		}

		void DisposeFromOldMap()
		{
			g_actor_variant_transform_manager.UnloadActorVariantTransforms();
			g_actor_variant_transform_manager.ClearInProgressTransforms();
		}

		bool& TransformsEnabled()
		{
			return g_actor_variant_transform_manager.TransformsEnabled();
		}

		void* HS_AITransformActor(void** arguments)
		{
			struct s_arguments {
				const datum_index unit_index;
				cstring transform_name;
				cstring target_name;
			}* args = CAST_PTR(s_arguments*, arguments);
			
			TypeHolder result;

			result.boolean = g_actor_variant_transform_manager.TransformActor(args->unit_index, args->transform_name, args->target_name);

			return result.pointer;
		}

		void* HS_AITransformActors(void** arguments)
		{
			struct s_arguments {
				const datum_index unit_list_index;
				cstring transform_name;
				cstring target_name;
			}* args = CAST_PTR(s_arguments*, arguments);
			
			TypeHolder result;

			result.boolean = g_actor_variant_transform_manager.TransformActors(args->unit_list_index, args->transform_name, args->target_name);

			return result.pointer;
		}

		void* HS_AITransformActorsByType(void** arguments)
		{
			struct s_arguments {
				const datum_index unit_list_index;
				const datum_index tag_index;
				cstring transform_name;
				cstring target_name;
			}* args = CAST_PTR(s_arguments*, arguments);
			
			TypeHolder result;

			result.boolean = g_actor_variant_transform_manager.TransformActorsByType(args->unit_list_index, args->tag_index, args->transform_name, args->target_name);

			return result.pointer;
		}
	};};
};