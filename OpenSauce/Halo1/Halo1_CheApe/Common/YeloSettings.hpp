/*
	Yelo: Open Sauce SDK
		Halo 1 (Editing Kit) Edition

	See license\OpenSauce\Halo1_CheApe for specific license information
*/
#pragma once

#include <YeloLib/Halo1/open_sauce/settings/yelo_shared_settings.hpp>

namespace Yelo
{
	namespace Settings
	{
		struct s_profile
		{
			bool is_valid;
			bool has_affinity_mask;
			bool is_ignored;	// is this profile ignored by any tools?
			PAD8;
			bool ignored_by[3]; // index with PLATFORM_ID
			PAD8;

			uint32 affinity_mask;

			char root_path[MAX_PATH];

			struct {
				char data[MAX_PATH];
				char maps[MAX_PATH];
				char tags[MAX_PATH];
				char tags_folder_name[64];
			}paths;

			struct {
				bool do_full_crashdump;
				bool disable_exception_handling;
				PAD16;
				uint32 base_address_override; // Tag memory base address override
			}tool;

			void Parse(TiXmlElement* element);

			// The profile will be valid if all elements of the XML settings 
			// were properly parsed
			inline bool IsValid() const		{ return is_valid; }

			// The profile will be ignored if the XML settings have an ignore setting for this platform 
			// or the profile wasn't properly parsed
			inline bool IsIgnored() const	{ return is_ignored && ignored_by[PLATFORM_ID - 1]; }

			inline cstring GetRootPath() const			{ return root_path [0] == '\0' ? nullptr : root_path; }
			inline cstring GetDataOverridePath() const	{ return paths.data[0] == '\0' ? nullptr : paths.data; }
			inline cstring GetMapsOverridePath() const	{ return paths.maps[0] == '\0' ? nullptr : paths.maps; }
			inline cstring GetTagsOverridePath() const	{ return paths.tags[0] == '\0' ? nullptr : paths.tags; }
		};
		struct s_settings
		{
			s_profile active_profile;

			void Parse(TiXmlElement* element, cstring arg_profile, cstring default_profile);

			inline cstring GetRootPath() const
			{
				cstring result = active_profile.GetRootPath();

				return !active_profile.IsIgnored() && result != nullptr ? result 
					: "";
			}

			inline cstring GetDataPath() const
			{
				cstring result = active_profile.GetDataOverridePath();

				return !active_profile.IsIgnored() && result != nullptr ? result
					: "data\\";
			}

			inline cstring GetTagsPath() const
			{
				cstring result = active_profile.GetTagsOverridePath();

				return !active_profile.IsIgnored() && result != nullptr ? result
					: "tags\\";
			}

			inline cstring GetMapsPath() const
			{
				cstring result = active_profile.GetMapsOverridePath();

				return !active_profile.IsIgnored() && result != nullptr ? result
					: "maps\\";
			}
		};
		const s_settings& Get();

		void Initialize();
		void Dispose();

		void LoadSettings();
		void SaveSettings();

		void ParseEnvironmentVariablesCheApe(std::string& parse_string);
	};
};