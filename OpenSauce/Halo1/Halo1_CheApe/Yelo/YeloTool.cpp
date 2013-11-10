/*
	Yelo: Open Sauce SDK
		Halo 1 (Editing Kit) Edition

	See license\OpenSauce\Halo1_CheApe for specific license information
*/
#include "Common/Precompile.hpp"

#if PLATFORM_ID == PLATFORM_TOOL
#include <blamlib/Halo1/tool/tool.hpp>

#include <YeloLib/Halo1/cache/data_file_yelo.hpp>

#include "Common/YeloSettings.hpp"
#include "Engine/EngineFunctions.hpp"
#include "Tool/Tool_AnimationFixups.hpp"

#include "Tool/BuildCacheFile.hpp"
#include "Tool/ImportLightmapUV.hpp"
#include "Tool/ShaderPostprocess.hpp"
#include "Tool/BuildCppDefinition.hpp"
#include "Tool/RuntimeCacheView.hpp"
#include "Tool/TagMaintenance.hpp"
#include "Tool/ToolMisc.hpp"

namespace Yelo
{
	namespace Tool
	{
		enum {
			k_number_of_tool_import_classes = 0x15,
		};

		#include "Tool/Help.inl"


//////////////////////////////////////////////////////////////////////////
// Import classes

		static const s_import_class yelo_import_classes[] = {
			#include "Tool/ImportClassDefinitions.inl"
		};

		int __cdecl s_import_class_compare(void*, const void* lhs, const void* rhs)
		{
			return strcmp(CAST_PTR(const s_import_class*,lhs)->name, CAST_PTR(const s_import_class*,rhs)->name);
		}
		int __cdecl s_import_class_search_by_name(void*, const void* key, const void* element)
		{
			return strcmp(CAST_PTR(const char*,key), CAST_PTR(const s_import_class*,element)->name);
		}
		void ImportClassesInitialize()
		{
			// Tool's original import classes
			static const auto* tool_import_classes = CAST_PTR(s_import_class*, 0x6B01B0);
			// The new import class list which is made up of tool's
			// and [yelo_import_classes]
			static s_import_class import_classes[k_number_of_tool_import_classes + NUMBEROF(yelo_import_classes)];

			// copy official import classes
			memcpy_s(&import_classes[0], sizeof(import_classes),
				tool_import_classes, sizeof(s_import_class) * k_number_of_tool_import_classes);
			// copy yelo import classes
			memcpy_s(&import_classes[k_number_of_tool_import_classes], sizeof(yelo_import_classes),
				&yelo_import_classes[0], sizeof(yelo_import_classes));
			// Now I know my ABCs
			qsort_s(import_classes, NUMBEROF(import_classes), sizeof(s_import_class), s_import_class_compare, nullptr);


			static s_import_class** import_classes_references[] = {
				CAST_PTR(s_import_class**, 0x414E6C),
				CAST_PTR(s_import_class**, 0x414EAB),
			};
			static void** import_classes_references_to_usage[] = {
				CAST_PTR(void**, 0x41541D),
			};
			static byte* import_classes_count[] = {
				CAST_PTR(byte*, 0x414E82),
				CAST_PTR(byte*, 0x415412),
			};

			// update references to the import class definitions
			for(auto ptr : import_classes_references)			*ptr = &import_classes[0];
			// update references to the import class definition usages
			for(auto ptr : import_classes_references_to_usage)	*ptr = &import_classes[0].usage;
			// update code which contain the import class definitions count
			for(auto ptr : import_classes_count)				*ptr = NUMBEROF(import_classes);

			// Modify build-cache-file to use our own implementation
			{
				auto* bcf_definition = CAST_PTR(s_import_class*, 
					bsearch_s("build-cache-file", import_classes, NUMBEROF(import_classes), sizeof(s_import_class), s_import_class_search_by_name, nullptr));

				if(bcf_definition != nullptr)
					bcf_definition->import_proc = build_cache_file_for_scenario_stock_override;
				else
					YELO_WARN("CheApe: failed to override build-cache-file :s");
			}
		}

//////////////////////////////////////////////////////////////////////////

		void IntializeBeforeTagGroupsInitalize()
		{
		}

		void Initialize()
		{
			c_animation_fixups::Initialize();

			Yelo::DataFiles::SharedInitialize();
			ImportClassesInitialize();
		}

		void Dispose()
		{
			Yelo::DataFiles::SharedDispose();

			c_animation_fixups::Dispose();
		}
	};
};

#endif