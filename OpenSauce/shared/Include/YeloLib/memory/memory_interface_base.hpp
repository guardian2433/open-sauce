/*
	Yelo: Open Sauce SDK

	See license\OpenSauce\OpenSauce for specific license information
*/
#pragma once

//////////////////////////////////////////////////////////////////////////
// Engine pointer markup system
//
//-Reference based interface
//	ENGINE_DPTR
//		Define a platform variant reference to a pointer in the engine's memory
//	ENGINE_PTR
//		Define a platform variant reference to a value in the engine's memory
//	Macro parameter notes:
//		* If [PTR_NULL], labels that when compiling for that platform we don't 
//			make use of the 'reference' we defined
//		* If [PTR_UNKNOWN], labels that when compiling for that platform we don't 
//			know the address of the 'reference' we're trying to create. In this 
//			situation, compilation of the source will be halted and no output 
//			executable will be created.
//
//-Constant based interface
//	FUNC_PTR
//		Declare a platform variant constant representing a engine function's address
//	DATA_PTR
//		Declare a platform variant constant representing a engine variable's address
//	Macro parameter notes:
//		* See the 'reference' based interface notes.
//		* FUNC_PTR uses: [FUNC_PTR_NULL], [FUNC_PTR_UNKNOWN]
//		* DATA_PTR uses: [DATA_PTR_NULL], [DATA_PTR_UNKNOWN]
//	PLATFORM_VALUE
//		Inline a platform variant constant (could be a number, string, code, etc)
//////////////////////////////////////////////////////////////////////////

// Use this value for platforms where this pointer does not matter
#define PTR_NULL			0x1337BEEF
// Use this value for platforms where this pointer hasn't been located yet
#define PTR_UNKNOWN			NULL
// Use this value for platforms where this function does not matter
#define FUNC_PTR_NULL		0xDEADC0DE
// Use this value for platforms where this function hasn't been located yet
#define FUNC_PTR_UNKNOWN	NULL
// Use this value for platforms where this data does not matter
#define DATA_PTR_NULL		0xDEADBEEF
// Use this value for platforms where this data hasn't been located yet
#define DATA_PTR_UNKNOWN	NULL

// Gets the enum value of [name]
#define GET_FUNC_PTR(name) BOOST_PP_CAT(PTR_,name)
#define GET_DATA_PTR(name) BOOST_PP_CAT(PTR_,name)
// Type casts [name] to a void*, since FUNC_PTRs are really enums
#define GET_FUNC_VPTR(name) (CAST_PTR(void*, GET_FUNC_PTR(name) ))
#define GET_DATA_VPTR(name) (CAST_PTR(void*, GET_FUNC_PTR(name) ))

// Double pointer inline get
#define GET_DPTR2(name)		BOOST_PP_CAT(pp,name)
// Pointer inline get
#define GET_PTR2(name)		BOOST_PP_CAT(p,name)
// Double pointer inline dereference-get
#define GET_DPTR(name)		( *GET_DPTR2(name) )
// Pointer inline dereference-get
#define GET_PTR(name)		( *GET_PTR2(name) )

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Macro glue for getting a pointer to game engine data, with various levels of pointer asserts. </summary>
/// <remarks>	va_args allow the callee to specify a de-reference operator. </remarks>
/// <param name="get_ptr_macro">	Macro for getting the PTR object. </param>
/// <param name="get_macro">		Macro for getting PTR_IMPL's value. </param>
/// <param name="name">				The name of the PTR object. </param>
#define PTR_IMPL_GET_GUTS(get_ptr_macro, get_macro, name, ...)							\
	/* validate pointer is available for this platform */								\
{	auto name = get_ptr_macro(name);													\
	assert(CAST_PTR(void*,PTR_UNKNOWN) != name && CAST_PTR(void*,PTR_NULL) != name); }	\
	/* validate pointer is initialized */												\
	auto name = get_macro(name);														\
	YELO_ASSERT(name);																	\
	return __VA_ARGS__ name;

// Double pointer implement get by-value
#define DPTR_IMP_GET(name)		{ PTR_IMPL_GET_GUTS(GET_DPTR2, GET_DPTR , name) }
// Double pointer implement get by-reference
#define DPTR_IMP_GET2(name)		{ PTR_IMPL_GET_GUTS(GET_DPTR2, GET_DPTR2, name) }
// Pointer implement get by-value
#define PTR_IMP_GET(name)		{ PTR_IMPL_GET_GUTS(GET_PTR2 , GET_PTR  , name) }
// Pointer implement get by-reference
#define PTR_IMP_GET2(name)		{ PTR_IMPL_GET_GUTS(GET_PTR2 , GET_PTR2 , name) }

// Double pointer implement get by-reference, with debug assert
#define DPTR_IMP_GET_BYREF(name){ PTR_IMPL_GET_GUTS(GET_DPTR2, GET_DPTR, name, *) }


//////////////////////////////////////////////////////////////////////////
// Engine value markup system
//
// [game_value]		: value for use in Runtime (ie, Client or Dedi) builds
// [editor_value]	: value for use in Editor (ie, HEK) builds
//
//////////////////////////////////////////////////////////////////////////
#if PLATFORM_IS_EDITOR
	#define PLATFORM_ENGINE_VALUE(game_value, editor_value) editor_value
#else
	#define PLATFORM_ENGINE_VALUE(game_value, editor_value) game_value
#endif

namespace Yelo
{
	namespace Enums
	{
		enum x86_opcode : byte {
			// push imm16\32
			_x86_opcode_push_imm = 0x68,

			// jz short imm8
			_x86_opcode_jz_short = 0x74,
			// jnz short imm8
			_x86_opcode_jnz_short = 0x75,
			// jge short imm8
			_x86_opcode_jge_short = 0x7D,

			_x86_opcode_nop = 0x90,

			// mov [e]ax, [offset]
			_x86_opcode_mov_eax_y_offset = 0xA1,

			// mov [offset], [e]ax
			_x86_opcode_mov_offset_y_eax = 0xA3,

			// return near imm16\32
			_x86_opcode_retn = 0xC2,
			// regular return near
			_x86_opcode_ret = 0xC3,
			// call near imm16\32
			_x86_opcode_call_near = 0xE8,
			// jmp near imm16\32
			_x86_opcode_jmp_near = 0xE9,

			// jmp short imm8
			_x86_opcode_jmp_short = 0xEB,
		};
		enum x86_opcode_twobyte : uint16 {
			// call ds:[address]
			_x86_opcode_call_abs = 0x15FF, /*FF 15*/
			// call ds:[address]
			_x86_opcode_jmp_abs = 0x25FF, /*FF 25*/
		};
		BOOST_STATIC_ASSERT( sizeof(Enums::x86_opcode_twobyte)==2 );
	};

	namespace Memory
	{
		struct Opcode
		{
			struct s_call
			{
				byte Op;
				uint32 Address;
			};

			struct s_call_ret : s_call
			{
				byte Ret;
				uint16 Count;
			};

			// absolute call opcode
			struct s_call_abs
			{
				uint16 Op;
				uint32 Address;
			};

			// absolute call opcode with return
			struct s_call_abs_ret : s_call_abs
			{
				byte Ret;
				uint16 Count;
			};
		};

		// Copies [size] bytes of [src] to [address]
		// Changes the protection of [address] while its coping [src]
		// Then changes the protection of [address] back
		BOOL WriteMemory(void* address, const void* src, int32 size);
		// makes the 32 bits at [address] equal [value]
		BOOL WriteMemory(void* address, void* value);


		// At [hook_address] writes 'call [hook]' plus user specified end opcode (total: 6 bytes)
		void CreateHookRelativeCall(void* hook, void* hook_address, byte end);

		// At [jmp_address]+1, write the relative address of [to_address] (total: 5 bytes)
		// Writes '0xE9' if [write_opcode]
		// returns the original jmp address (absolute)
		uintptr_t WriteRelativeJmp(void* to_address, void* jmp_address, bool write_opcode = false);

		// At [call_address]+1, write the relative address of [to_address] (total: 5 bytes)
		// Writes '0xE8' if [write_opcode]
		// returns the original call address (absolute)
		uintptr_t WriteRelativeCall(void* to_address, void* call_address, bool write_opcode = false);


		// [call] buffer containing the data we wish to write
		// [address] address to put [call]
		void Write(Opcode::s_call& call, void* address);
		// [call_buffer] is a buffer to receive the old bytes
		// [address] address to put\overwrite a call
		// [target] address to make the call goto
		void WriteCall(void* call_buffer, void* address, const void* target);

		// [call_ret_buffer] is a buffer to receive the old bytes
		// [address] address to put\overwrite a call and ret
		// [target] address to make the call goto
		void WriteCallRet(void* call_ret_buffer, void* address, const void* target);
		// [call_ret_buffer] is a buffer to receive the old bytes
		// [address] address to put\overwrite a call and ret
		// [target] address to make the call goto
		// [count] number of 32-bit args in the function we're modding. If there are any 
		// 64-bit arguments, count them twice!
		void WriteCallRet(void* call_ret_buffer, void* address, const void* target, const uint16 count);
		// [call] buffer containing the data we wish to write
		// [address] address to put [call]
		void WriteRet(Opcode::s_call_ret& call, void* address);
		// [call] buffer containing the data we wish to write
		// [address] address to put [call]
		void WriteRetn(Opcode::s_call_ret& call, void* address);

		// [jmp_buffer] is a buffer to receive the old bytes
		// [address] address to put\overwrite a jmp
		// [target] address to make the jmp goto
		void WriteJmp(void* jmp_buffer, void* address, const void* target);

		// [jmp_buffer] is a buffer to receive the old jmp address
		// [address] address to overwrite a jmp
		// [target] address to make the jmp goto
		// REMARKS:
		// Jmp type can be anything as long as the address used is 32bits
		void OverwriteJmp(void* jmp_buffer, void* address, const void* target);


		struct s_memory_exec_change_data {
			void* const ExecAddress;	/// <summary>	'to_address', address to be executed (jmp or call) </summary>
			void* const MemoryAddress;	/// <summary>	'call_address', memory address to apply the execution modification. </summary>

			const bool WriteOpcode;
			bool IsInitialized;
			PAD16;
			std::array<byte,5> UndoData;/// <summary>	internal buffer to store. </summary>
			PAD24;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>
			/// 	At [MemoryAddress], modify the assembly code to jump to the code stored at address [ExecAddress].
			/// </summary>
			///
			/// <remarks>	Total: 5 bytes. See: [WriteRelativeJmp]. </remarks>
			void ApplyAsRelativeJmp();
			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>
			/// 	At [MemoryAddress], modify the assembly code to execute the code stored at address [ExecAddress].
			/// </summary>
			///
			/// <remarks>	Total: 5 bytes. See: [WriteRelativeCall]. </remarks>
			void ApplyAsRelativeCall();

			/// <summary>	Restore the memory back to it's original data. </summary>
			void Undo();

		private:
			void Initialize();
		}; BOOST_STATIC_ASSERT( sizeof(s_memory_exec_change_data) == 0x14 );
#define DEFINE_MEMORY_EXEC_CHANGE(name, to_address, call_address, ...)	\
	static Yelo::Memory::s_memory_exec_change_data name = {				\
			CAST_PTR(void*, (to_address) ),								\
			CAST_PTR(void*, (call_address) ),							\
			__VA_ARGS__													\
		};


		// Overwrite the memory at [address] with [array]
		// Copies the original memory at [address] into [array] before returning
		// This is useful when writing an array of opaque bytes to game memory
		template<typename T, size_t TSizeOfArray>
		void OverwriteMemoryArray(void* address, T(& array)[TSizeOfArray])
		{
			T old_memory[TSizeOfArray];
			// Copy the old memory from the address
			memcpy(old_memory, address, TSizeOfArray);
			// Write the new memory to the address
			memcpy(address, array, TSizeOfArray);
			// Fill [array] with the old memory
			memcpy(array, old_memory, TSizeOfArray);
		}
		// Overwrite the memory at [address] with [array]
		// Does NOT copy the original memory at [address] into [array] before returning
		// This is useful when writing an array of opaque bytes to game memory, esp. during unwinding operations
		template<typename T, size_t TSizeOfArray>
		void OverwriteMemorySansCopyArray(void* address, const T(& array)[TSizeOfArray])
		{
			// Write the new memory to the address
			memcpy(address, array, TSizeOfArray);
		}
		// Overwrite the memory at [address] with [data]
		// Copies the original memory at [address] into [data] before returning
		// This is useful when writing a concrete object to game memory
		template<typename T>
		void OverwriteMemory(void* address, T& data)
		{
			T old_memory;
			// Copy the old memory from the address
			memcpy(&old_memory, address, sizeof(T));
			// Write the new memory to the address
			memcpy(address, &data, sizeof(T));
			// Fill [data] with the old memory
			memcpy(&data, &old_memory, sizeof(T));
		}
		// Overwrite the memory at [address] with [data]
		// Does NOT copy the original memory at [address] into [data] before returning
		// This is useful when writing a concrete object to game memory, esp. during unwinding operations
		template<typename T>
		void OverwriteMemorySansCopy(void* address, const T& data)
		{
			// Write the new memory to the address
			memcpy(address, &data, sizeof(T));
		}


		template<void* k_memory_address, size_t k_memory_address_size>
		struct s_memory_change_data {
		protected:
			static volatile bool g_initialized;
			static volatile bool g_memory_changed;
			// the bytes found at [k_memory_address], before any changes were ever applied
			static byte g_undo_buffer[k_memory_address_size];

			static void InitializeUndoBuffer()
			{
				if(!g_initialized)
				{
					g_initialized = true;
					memcpy(g_undo_buffer, k_memory_address, k_memory_address_size);
				}
			}
		public:
			// At [k_memory_address], write enough asm nop codes to fill [k_memory_address_size]
			static void MemoryApplyNopCodes()
			{
				InitializeUndoBuffer();

				memset(k_memory_address, Enums::_x86_opcode_nop, k_memory_address_size);
				g_memory_changed = true;
			}
			// Revert [k_memory_address] back to the memory bytes it had when this was initialized
			static void MemoryApplyUndo()
			{
				InitializeUndoBuffer();

				if(g_memory_changed)
				{
					OverwriteMemorySansCopyArray(k_memory_address, g_undo_buffer);
					g_memory_changed = false;
				}
			}
		};
		template<void* k_memory_address, size_t k_memory_address_size>
			volatile bool s_memory_change_data<k_memory_address, k_memory_address_size>::g_initialized;
		template<void* k_memory_address, size_t k_memory_address_size>
			volatile bool s_memory_change_data<k_memory_address, k_memory_address_size>::g_memory_changed;
		template<void* k_memory_address, size_t k_memory_address_size>
			byte s_memory_change_data<k_memory_address, k_memory_address_size>::g_undo_buffer[k_memory_address_size];

		template<void* k_memory_address, size_t k_memory_address_size>
		struct s_memory_change_data_object : s_memory_change_data<k_memory_address,k_memory_address_size>
		{
			byte m_new_memory[k_memory_address_size];

			// At [k_memory_address], write the contents of [m_new_memory]
			void ApplyChanges()
			{
				InitializeUndoBuffer();

				OverwriteMemorySansCopyArray(k_memory_address, m_new_memory);
				g_memory_changed = true;
			}
			// Revert [k_memory_address] back to the memory bytes it had when this was initialized
			void ApplyUndo()
			{
				MemoryApplyUndo();
			}
		};


		template<typename T>
		static T* RebasePointer(T* pointer, uintptr_t base_address, uintptr_t virtual_base_address)
		{
			T* result = CAST_PTR(T*,
				(CAST_PTR(byte*,pointer) - base_address) + virtual_base_address);

			return result;
		}
		template<typename T>
		static T* AlignPointer(T* pointer, unsigned alignment_bit)
		{
			uintptr_t aligned_ptr = CAST_PTR(uintptr_t, pointer);
			const uintptr_t alignment_mask = (1<<alignment_bit) - 1;

			if(aligned_ptr & alignment_mask)
				aligned_ptr = (aligned_ptr | alignment_mask) + 1;

			return CAST_PTR(T*, aligned_ptr);
		}

#if 0
		template<typename TWord>
		bool IsZeroMemoryImpl(const TWord* words, size_t word_count)
		{
			TWord i_am_zero = 0;
			for (const TWord* words_end = words+word_count; words != words_end; words++)
				i_am_zero |= *words;

			return i_am_zero == 0;
		}

		bool IsZeroMemory(const byte* buffer, size_t element_count)		{ return IsZeroMemoryImpl<byte>  (buffer, element_count); }
		bool IsZeroMemory(const uint16* buffer, size_t element_count)	{ return IsZeroMemoryImpl<uint16>(buffer, element_count); }
		bool IsZeroMemory(const uint32* buffer, size_t element_count)	{ return IsZeroMemoryImpl<uint32>(buffer, element_count); }

		template<typename T>
		bool IsZeroMemory(const T& obj)
		{

		}
		template<typename T, size_t TSizeOfArray>
		bool IsZeroMemory(const T(& array)[TSizeOfArray])
		{
		}
		template<size_t TSizeOfArray>
		bool IsZeroMemory(const byte(& array)[TSizeOfArray])	{ return IsZeroMemory(&array[0], TSizeOfArray); }
		template<size_t TSizeOfArray>
		bool IsZeroMemory(const uint16(& array)[TSizeOfArray])	{ return IsZeroMemory(&array[0], TSizeOfArray); }
		template<size_t TSizeOfArray>
		bool IsZeroMemory(const uint32(& array)[TSizeOfArray])	{ return IsZeroMemory(&array[0], TSizeOfArray); }
#endif


		uint32 CRC(uint32& crc_reference, const void* buffer, int32 size);
	};
};