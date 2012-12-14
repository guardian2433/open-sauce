/*
	Yelo: Open Sauce SDK

	See license\OpenSauce\OpenSauce for specific license information
*/
#pragma once

#include <blamlib/tag_files/tag_groups_base.hpp>

namespace Yelo
{
	namespace Enums
	{
		enum {
			k_maximum_field_byte_swap_codes = 1024,

			k_tag_field_scan_stack_size = 16,

			k_tag_block_format_buffer_size = 512,
		};
		enum field_type : _enum
		{
			_field_string,
			_field_char_integer,
			_field_short_integer,
			_field_long_integer,
			_field_angle,
			_field_tag,
			_field_enum,
			_field_long_flags,
			_field_word_flags,
			_field_byte_flags,
			_field_point_2d,
			_field_rectangle_2d,
			_field_rgb_color,
			_field_argb_color,
			_field_real,
			_field_real_fraction,
			_field_real_point_2d,
			_field_real_point_3d,
			_field_real_vector_2d,
			_field_real_vector_3d,
			_field_real_quaternion,
			_field_real_euler_angles_2d,
			_field_real_euler_angles_3d,
			_field_real_plane_2d,
			_field_real_plane_3d,
			_field_real_rgb_color,
			_field_real_argb_color,
			_field_real_hsv_color,
			_field_real_ahsv_color,
			_field_short_bounds,
			_field_angle_bounds,
			_field_real_bounds,
			_field_real_fraction_bounds,
			_field_tag_reference,
			_field_block,
			_field_short_block_index,
			_field_long_block_index,
			_field_data,
			_field_array_start,
			_field_array_end,
			_field_pad,
			_field_skip,
			_field_explanation,
			_field_custom,
			_field_terminator,

			k_number_of_tag_field_types,
		};
	};

	namespace Flags
	{
		enum {
			// Never streamed, unless the tag is loaded with _tag_load_verify_bit
			_tag_data_never_streamed_bit = 0,
			_tag_data_is_text_data_bit,
			// ie, 'debug data'
			_tag_data_not_streamed_to_cache_bit,

			// checked in the tag reference solving code.
			// last condition checked after an assortment of conditionals
			// and if this is TRUE, it won't resolve
			_tag_reference_unknown0_bit = 0,
			_tag_reference_non_resolving_bit,

			_tag_block_dont_read_children_bit =	0,

			_tag_group_initialized_bit = 0,
			_tag_group_unknown1_bit,
			_tag_group_unknown2_bit,
			_tag_group_unknown3_bit,

			_tag_load_for_runtime_bit = 0,
			// Verify the tag file exists first
			_tag_load_verify_exist_first_bit,
			// If set: child references of the tag being loaded are not loaded themselves
			// Else, child references are loaded from disk
			_tag_load_non_resolving_references_bit,
		};
	};


	struct tag_field
	{
		_enum type; PAD16;
		cstring name;
		void* definition;

		template<typename T> API_INLINE T* Definition() const { return CAST_PTR(T*, definition); }
	}; BOOST_STATIC_ASSERT( sizeof(tag_field) == 0xC );

	typedef bool (PLATFORM_API* proc_tag_block_postprocess_element)(void* element, bool for_runtime);
	// if [formatted_buffer] returns empty, the default block formatting is done
	typedef cstring (PLATFORM_API* proc_tag_block_format)(datum_index tag_index, tag_block* block, int32 element, char formatted_buffer[Enums::k_tag_block_format_buffer_size]);
	typedef void (PLATFORM_API* proc_tag_block_delete_element)(tag_block* block, int32 element_index);
	struct tag_block_definition
	{
		cstring name;
		long_flags flags;
		int32 maximum_element_count;
		uint32 element_size;
		PAD32;
		tag_field* fields;
		void* add_proc;
		proc_tag_block_postprocess_element postprocess_proc;
		proc_tag_block_format format_proc;
		proc_tag_block_delete_element delete_proc;
		int32* byteswap_codes;
	}; BOOST_STATIC_ASSERT( sizeof(tag_block_definition) == 0x2C );

	struct tag_data_definition
	{
		cstring name;
		long_flags flags;
		uint32 maximum_size;
		void* byte_swap_proc;
	}; BOOST_STATIC_ASSERT( sizeof(tag_data_definition) == 0x10 );

	struct tag_reference_definition
	{
		long_flags flags;
		tag group_tag;
		tag* group_tags;
	}; BOOST_STATIC_ASSERT( sizeof(tag_reference_definition) == 0xC );

	// Postprocess a tag definition (eg, automate the creation of fields, etc)
	// [for_runtime] - if true, prepare the tag for use in-game (Sapien and when building a cache)
	typedef bool (PLATFORM_API* proc_tag_group_postprocess)(datum_index tag_index, bool for_runtime);
	struct tag_group
	{
		cstring name;
		long_flags flags;
		tag group_tag;
		tag parent_group_tag;
		int16 version; PAD16;
		proc_tag_group_postprocess postprocess_proc;
		tag_block_definition* header_block_definition;
		tag child_group_tags[Enums::k_maximum_children_per_tag];
		int16 child_count; PAD16;
	}; BOOST_STATIC_ASSERT( sizeof(tag_group) == 0x60 );


	struct s_tag_instance
	{
		datum_index header;			// 0x0
		char filename[Enums::k_max_tag_name_length+1];			// 0x4
		tag group_tag;				// 0x104
		tag parent_group_tags[2];	// 0x108 0x10C
		bool is_verified;			// 0x110 was loaded with Flags::_tag_load_verify_bit
		bool is_read_only;			// 0x111
		bool is_orphan;				// 0x112
		bool null_definition;		// 0x113
		PAD32;						// 0x114
		uint32 file_checksum;		// 0x118
		tag_block root_block;		// 0x11C, 0x120, 0x124
	}; BOOST_STATIC_ASSERT( sizeof(s_tag_instance) == 0x128 );
	// Note: the datum count below is the 'stock' count used by the engine. Yelo can override this.
	typedef Memory::DataArray<s_tag_instance, 5120> tag_instance_data_t;


	namespace TagGroups
	{
		struct s_tag_field_scan_state
		{
			const tag_field* fields;
			void* fields_address;
			long_flags field_types[BIT_VECTOR_SIZE_IN_DWORDS(Enums::k_number_of_tag_field_types)];
			int16 field_index;
			int16 field_size;
			int32 field_offset;
			bool done; PAD8;
			int16 stack_index;
			struct {
				int16 field_index;
				int16 count;
			}stack[Enums::k_tag_field_scan_stack_size];

			const tag_field* found_field;
			void* found_field_address;
		}; BOOST_STATIC_ASSERT( sizeof(s_tag_field_scan_state) == 0x64 );


		class c_tag_field_scanner
		{
			s_tag_field_scan_state m_state;

		public:
			inline int32 GetFieldIndex() const			{ return m_state.field_index; }
			inline size_t GetFieldSize() const			{ return CAST(size_t, m_state.field_size); }
			inline size_t GetFieldOffset() const		{ return CAST(size_t, m_state.field_offset); }

			inline const tag_field* GetTagField() const	{ return m_state.found_field; }
			template<typename T>
			inline T* GetFieldAs() const				{ return CAST_PTR(T*, m_state.found_field); }

		public:
			c_tag_field_scanner(const tag_field* fields, void* fields_address);

			c_tag_field_scanner& AddFieldType(Enums::field_type field_type);

			void AddAllFieldTypes();

			bool Scan();

			bool TagFieldIsStringId() const;
		};
	};
};