/*
	Yelo: Open Sauce SDK

	See license\OpenSauce\OpenSauce for specific license information
*/
#include "Common/Precompile.hpp"
#include <blamlib/Halo1/memory/data.hpp>

namespace Yelo
{
	namespace Memory
	{
		bool s_data_iterator::operator!=(const s_data_iterator& other) const
		{
			auto last_datum = this->data->last_datum;

			if(other.IsEndHack())
				return absolute_index != last_datum;
			else if(this->IsEndHack())
				return !other.absolute_index != last_datum;

			return this->absolute_index != other.absolute_index;
		}
	};

	namespace blam
	{
		using namespace Yelo::Memory;

#if !PLATFORM_IS_EDITOR
		void PLATFORM_API data_verify(const s_data_array* data)
		{
		}

		void PLATFORM_API data_make_valid(s_data_array* data)
		{
			data_verify(data);
			data->is_valid = true;
			data_delete_all(data);
		}
#endif

		void PLATFORM_API data_make_invalid(s_data_array* data)
		{
			data_verify(data);
			data->is_valid = false;
		}

		void data_iterator_new(s_data_iterator& iterator, s_data_array* data)
		{
			data_verify(data);
			ASSERT(data->is_valid, "invalid data array passed to " __FUNCTION__);

			iterator.data = data;
			iterator.signature = CAST_PTR(uintptr_t, data) ^ Enums::k_data_iterator_signature;
			iterator.absolute_index = 0;
			iterator.index = datum_index::null;
		}
	};
};