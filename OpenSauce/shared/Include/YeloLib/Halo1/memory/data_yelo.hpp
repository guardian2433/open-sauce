/*
	Yelo: Open Sauce SDK

	See license\OpenSauce\OpenSauce for specific license information
*/
#pragma once

#include <blamlib/Halo1/memory/data.hpp>

namespace Yelo
{
	namespace Memory
	{
		template<typename DatumT,	size_t MaxDatumCount, 
									size_t MaxDatumCountUpgrade = MaxDatumCount>
		struct DataArray {
		private:
			typedef DataArray<DatumT,MaxDatumCount,MaxDatumCountUpgrade> DataArrayT;

		public:
			struct IteratorResult {
				datum_index index;
				DatumT* datum;

				IteratorResult(datum_index i, DatumT* d) : index(i), datum(d) {}

				DatumT* operator->() const { return datum; }
				DatumT& operator*() const { return *datum; }
			};

			struct Iterator {
			private:
				enum { k_end_hack_signature = 'hack', };

				s_data_iterator m_iterator;
				DatumT* m_current_instance;

			public:
				Iterator(DataArrayT& data) {
					blam::data_iterator_new(m_iterator, &data.Header);
					m_current_instance = nullptr;
				}

				DatumT* Next() {
					return m_current_instance = 
						CAST_PTR(DatumT*, blam::data_iterator_next( *CAST_PTR(s_data_iterator*, this) ));
				}

				datum_index Current() const { return this->m_iterator.index; }

				static const Iterator GetEndHack(DataArrayT& data)
				{
					auto hack = Iterator(data);
					hack.m_iterator.SetEndHack();
					return hack;
				}
				inline bool operator!=(const Iterator& other) const
				{
					return m_iterator != other.m_iterator;
				}
				inline Iterator& operator++()
				{
					Next();
					return *this;
				}
				inline IteratorResult operator*() const
				{
					return IteratorResult(m_iterator.index, m_current_instance);
				}
			};

			s_data_array Header;

		public:

			Iterator& IteratorNew(Iterator& iter) {
				return iter = Iterator(this);
			}

			API_INLINE DatumT* Datums() {
				return CAST_PTR(DatumT*, this->Header.data);
			}

			API_INLINE operator s_data_array*() {
				return &this->Header;
			}

			API_INLINE DatumT* operator [](datum_index handle)
			{
#if PLATFORM_IS_EDITOR
				return CAST_PTR(DatumT*, blam::datum_get(&this->Header, handle));
#else
				return &CAST_PTR(DatumT*, this->Header.data)[handle.index];
#endif
			}

			inline Iterator begin() /*const*/
			{
				auto iter = Iterator(*this);
				iter.Next();
				return iter;
			}
			inline const Iterator end() /*const*/
			{
				return Iterator::GetEndHack(*this);
			}

			inline void Verify() const	{ blam::data_verify(&Header); }

			inline void Dispose()		{ blam::data_dispose(&Header); }
			inline void MakeValid()		{ blam::data_make_valid(&Header); }
			inline void MakeInvalid()	{ blam::data_make_invalid(&Header); }
			inline void DeleteAll()		{ blam::data_delete_all(&Header); }

			inline datum_index NextIndex(datum_index cursor)	{ return blam::data_next_index(&Header, cursor); }
			inline datum_index NewAtIndex(datum_index index)	{ return blam::datum_new_at_index(&Header, index); }
			inline datum_index New()							{ return blam::datum_new(&Header); }
			inline void Delete(datum_index index)				{ return blam::datum_delete(&Header, index); }
		};
	};
};