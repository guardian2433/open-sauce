﻿/*
    BlamLib: .NET SDK for the Blam Engine

    Copyright (C) 2005-2010  Kornner Studios (http://kornner.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma warning disable 1591 // "Missing XML comment for publicly visible type or member"
using System;
using TI = BlamLib.TagInterface;

namespace BlamLib.Blam.Cache.Tags
{
	/// <summary>
	/// Factory for generating cache file resource definitions for tag data
	/// </summary>
	public class CacheFileResourceDefinitionFactory
	{
		public virtual TI.Definition GenerateRenderGeometryApiResource()				{ return new render_geometry_api_resource_definition(); }
		public virtual TI.Definition GenerateBitmapTextureInteropResource()				{ return new bitmap_texture_interop_resource_reference(); }
		public virtual TI.Definition GenerateModelAnimationTagResource()				{ return new model_animation_tag_resource(); }
		public virtual TI.Definition GenerateSoundResourceResource()					{ return new sound_resource_definition(); }
		public virtual TI.Definition GenerateBitmapTextureInterleavedInteropResource()	{ return new bitmap_texture_interleaved_interop_resource_reference(); }
		public virtual TI.Definition GenerateStructureBspTagResource()					{ return new Halo3.Tags.scenario_structure_bsp_group.structure_bsp_tag_resources(); }
		public virtual TI.Definition GenerateStructureBspCacheFileTagResource()			{ throw new NotImplementedException(); }

		internal virtual void InsertDataSizeIntoFauxDefinitionData(byte[] definition_data, uint data_size)
		{
			sound_resource_definition.InsertDataSizeIntoFauxDefinitionData(definition_data, 0, (uint)data_size);
		}
	};

	#region bitmap_group
	#region bitmap_texture_interop_resource_reference
	[TI.Definition(1, 12)]
	public class bitmap_texture_interop_resource_reference : TI.Definition
	{
		#region bitmap_texture_interop_resource
		[TI.Definition(1, 52)]
		public class bitmap_texture_interop_resource : TI.Definition
		{
			public TI.Data BitmapData;
			public TI.Data UnknownData;
			public TI.ShortInteger Width, Height;
			public TI.ByteInteger Unknown2C, Unknown2D, Unknown2E, Unknown2F;
			public TI.LongInteger Unknown30;

			public bitmap_texture_interop_resource() : base(4)
			{
				Add(BitmapData = new TI.Data(this));
				Add(UnknownData = new TI.Data(this));
				Add(Width = new TI.ShortInteger());
				Add(Height = new TI.ShortInteger());
				Add(Unknown2C = new TI.ByteInteger());
				Add(Unknown2D = new TI.ByteInteger());
				Add(Unknown2E = new TI.ByteInteger());
				Add(Unknown2F = new TI.ByteInteger());
				Add(Unknown30 = new TI.LongInteger());
			}
		};
		#endregion

		public TI.StructReference<bitmap_texture_interop_resource> Reference;

		public bitmap_texture_interop_resource_reference() : base(1)
		{
			Add(Reference = new TI.StructReference<bitmap_texture_interop_resource>(this));
		}
	};
	#endregion

	#region bitmap_texture_interleaved_interop_resource_reference
	[TI.Definition(1, 12)]
	public class bitmap_texture_interleaved_interop_resource_reference : TI.Definition
	{
		#region bitmap_texture_interleaved_interop_resource
		[TI.Definition(1, 52)]
		public class bitmap_texture_interleaved_interop_resource : TI.Definition
		{
			public TI.Data BitmapData;
			public TI.Data UnknownData;

			public TI.ShortInteger Width, Height;
			public TI.ByteInteger Unknown2C, Unknown2D, Unknown2E, Unknown2F;
			public TI.LongInteger Unknown30;

			public TI.ShortInteger Width2, Height2;
			public TI.ByteInteger Unknown38, Unknown39, Unknown3A, Unknown3B;
			public TI.LongInteger Unknown3C;

			public bitmap_texture_interleaved_interop_resource() : base(4)
			{
				Add(BitmapData = new TI.Data(this));
				Add(UnknownData = new TI.Data(this));
				Add(Width = new TI.ShortInteger());
				Add(Height = new TI.ShortInteger());
				Add(Unknown2C = new TI.ByteInteger());
				Add(Unknown2D = new TI.ByteInteger());
				Add(Unknown2E = new TI.ByteInteger());
				Add(Unknown2F = new TI.ByteInteger());
				Add(Unknown30 = new TI.LongInteger());

				Add(Width2 = new TI.ShortInteger());
				Add(Height2 = new TI.ShortInteger());
				Add(Unknown38 = new TI.ByteInteger());
				Add(Unknown39 = new TI.ByteInteger());
				Add(Unknown3A = new TI.ByteInteger());
				Add(Unknown3B = new TI.ByteInteger());
				Add(Unknown3C = new TI.LongInteger());
			}
		};
		#endregion

		public TI.StructReference<bitmap_texture_interleaved_interop_resource> Reference;

		public bitmap_texture_interleaved_interop_resource_reference() : base(1)
		{
			Add(Reference = new TI.StructReference<bitmap_texture_interleaved_interop_resource>(this));
		}
	};
	#endregion
	#endregion

	#region model_animation_tag_resource
	[TI.Definition(1, 12)]
	public class model_animation_tag_resource : TI.Definition
	{
		#region resource
		[TI.Definition(1, 48)]
		public class resource : TI.Definition
		{
			public TI.LongInteger Unknown00, Unknown04;
			public TI.ShortInteger Unknown08,
				Unknown0A; // this may be two bytes
			public TI.ByteInteger Unknown0C, Unknown0D;
			public TI.ShortInteger Unknown0E; // this may be two bytes
			public TI.LongInteger Unknown10,
				Unknown14, // dword, only seen as zero
				Unknown18;
			public TI.Data Data;

			public resource() : base(11)
			{
				Add(Unknown00 = new TI.LongInteger());
				Add(Unknown04 = new TI.LongInteger());
				Add(Unknown08 = new TI.ShortInteger());
				Add(Unknown0A = new TI.ShortInteger());
				Add(Unknown0C = new TI.ByteInteger());
				Add(Unknown0D = new TI.ByteInteger());
				Add(Unknown0E = new TI.ShortInteger());
				Add(Unknown10 = new TI.LongInteger());
				Add(Unknown14 = new TI.LongInteger());
				Add(Unknown18 = new TI.LongInteger());
				Add(Data = new TI.Data(this));
			}
		};
		#endregion

		public TI.Block<resource> Resources;

		public model_animation_tag_resource() : base(1)
		{
			Add(Resources = new TI.Block<resource>(this));
		}
	};
	#endregion

	#region render_geometry_api_resource_definition
	[TI.Definition(1, 48)]
	public partial class render_geometry_api_resource_definition : TI.Definition
	{
		//    2 - 0x18
		//    3 - 0x20
		//  0xB - 0xC
		// 0x14 - 0x10 (bsp only?)
		#region s_tag_d3d_vertex_buffer
		[TI.Definition(1, 28)]
		public class s_tag_d3d_vertex_buffer : TI.Definition
		{
			public TI.LongInteger VertexCount;
			public TI.Enum VertxType;
			public TI.ShortInteger VertexSize;
			public TI.Data VertexBuffer;

			public s_tag_d3d_vertex_buffer() : base(4)
			{
				Add(VertexCount = new TI.LongInteger());
				Add(VertxType = new TI.Enum());
				Add(VertexSize = new TI.ShortInteger());
				Add(VertexBuffer = new TI.Data(this));
			}
		};
		#endregion

		#region s_tag_d3d_vertex_buffer_reference
		[TI.Definition(1, 12)]
		public class s_tag_d3d_vertex_buffer_reference : TI.Definition
		{
			public TI.StructReference<s_tag_d3d_vertex_buffer> Reference;

			public s_tag_d3d_vertex_buffer_reference() : base(1)
			{
				Add(Reference = new TI.StructReference<s_tag_d3d_vertex_buffer>(this));
			}
		};
		#endregion

		#region s_tag_d3d_index_buffer
		[TI.Definition(1, 24)]
		public class s_tag_d3d_index_buffer : TI.Definition
		{
			public TI.LongInteger Unknown;
			public TI.Data IndexBuffer;

			public s_tag_d3d_index_buffer() : base(2)
			{
				Add(Unknown = new TI.LongInteger());
				Add(IndexBuffer = new TI.Data(this));
			}
		};
		#endregion

		#region s_tag_d3d_index_buffer_reference
		[TI.Definition(1, 12)]
		public class s_tag_d3d_index_buffer_reference : TI.Definition
		{
			public TI.StructReference<s_tag_d3d_index_buffer> Reference;

			public s_tag_d3d_index_buffer_reference() : base(1)
			{
				Add(Reference = new TI.StructReference<s_tag_d3d_index_buffer>(this));
			}
		};
		#endregion

		public TI.Block<s_tag_d3d_vertex_buffer_reference> VertexBuffers;
		public TI.Block<s_tag_d3d_index_buffer_reference> IndexBuffers;

		public render_geometry_api_resource_definition() : base(4)
		{
			// i think these two blocks are actually the 'raw' data
			// versions of the vertex and index buffers, so we wont
			// ever see them in a cache file
			Add(TI.UnknownPad.BlockHalo3);
			Add(TI.UnknownPad.BlockHalo3);

			Add(VertexBuffers = new TI.Block<s_tag_d3d_vertex_buffer_reference>(this, 0));
			Add(IndexBuffers = new TI.Block<s_tag_d3d_index_buffer_reference>(this, 0));
		}
	};
	#endregion

	#region sound_resource_definition
	[TI.Definition(1, sound_resource_definition.kSizeOf)]
	public class sound_resource_definition : TI.Definition
	{
		public const int kSizeOf = 20;

		public TI.Data Data;

		public sound_resource_definition() : base(1)
		{
			Add(Data = new TI.Data(this, TI.DataType.Sound));
		}

		internal static void InsertDataSizeIntoFauxDefinitionData(byte[] definition_data, int offset, uint data_size)
		{
			IO.ByteSwap.SwapUDWordAndInsert(data_size, definition_data, offset);
		}
	};
	#endregion


	#region cache_file_sound
	public abstract class cache_file_sound_group_gen3 : cache_file_sound_group_gen2
	{
		public TI.LongInteger ResourceIndex;

		protected cache_file_sound_group_gen3(int field_count) : base(field_count) { }

		public DatumIndex ResourceDatumIndex { get { return ResourceIndex.Value; } }
	};
	#endregion

	#region sound_cache_file_gestalt
	public abstract class sound_cache_file_gestalt_group_gen3 : sound_cache_file_gestalt_group_gen2
	{
		protected sound_cache_file_gestalt_group_gen3(int field_count) : base(field_count) { }
	};
	#endregion

	#region cache_file_resource_layout_table
	public abstract partial class cache_file_resource_layout_table : TI.Definition
	{
		#region compression_codec_block
		[TI.Definition(1, 16)]
		public partial class compression_codec_block : TI.Definition
		{
			public TI.Skip Guid;

			public compression_codec_block() : base(1)
			{
				Add(Guid = new TI.Skip(16));
			}
		}
		#endregion

		#region shared_cache_block
		[TI.Definition(1, 264)]
		public partial class shared_cache_block : TI.Definition
		{
			public TI.String CachePath;
			public TI.ShortInteger Unknown100;
			public TI.Flags Flags;
			public TI.LongInteger Unknown104;

			public shared_cache_block() : base(4)
			{
				Add(CachePath = new TI.String(TI.StringType.Ascii, 256));
				Add(Unknown100 = new TI.ShortInteger());
				Add(Flags = new TI.Flags(TI.FieldType.WordFlags));
				Add(Unknown104 = new TI.LongInteger());
			}
		}
		#endregion

		// runtime resource locations
		#region pages_block
		[TI.Definition(1, 88)]
		public partial class pages_block : TI.Definition
		{
			public TI.ShortInteger Header; // datum's salt value
			public TI.Flags Flags;
			public TI.BlockIndex CompressionCodec;

			public TI.BlockIndex SharedCache;
			public TI.ShortInteger Unknown006; // Index of something
			public TI.LongInteger BlockOffset; // (aligned to 4096 blocks)
			public TI.LongInteger BlockSizeCompressed;
			public TI.LongInteger BlockSizeUncompressed;

			// s_resource_checksum
			public TI.LongInteger Crc;
			public TI.Skip EntireBufferHash; // 7BFD8BA3F41CDBCD23065111ABA46E7D436FAC61
			public TI.Skip FirstChunkHash;
			public TI.Skip LastChunkHash;

			public TI.ShortInteger Unknown054; // ?
			public TI.ShortInteger Unknown056; // Index?

			public pages_block()
			{
				Add(Header = new TI.ShortInteger());
				Add(Flags = new TI.Flags(TI.FieldType.ByteFlags));
				Add(CompressionCodec = new TI.BlockIndex(TI.FieldType.ByteBlockIndex));

				Add(SharedCache = new TI.BlockIndex());
				Add(Unknown006 = new TI.ShortInteger());
				Add(BlockOffset = new TI.LongInteger());
				Add(BlockSizeCompressed = new TI.LongInteger());
				Add(BlockSizeUncompressed = new TI.LongInteger());

				Add(Crc = new TI.LongInteger());
				Add(EntireBufferHash = new TI.Skip(20));
				Add(FirstChunkHash = new TI.Skip(20));
				Add(LastChunkHash = new TI.Skip(20));

				Add(Unknown054 = new TI.ShortInteger());
				Add(Unknown056 = new TI.ShortInteger());
			}
		};
		#endregion

		#region cache_file_resource_layout_table_24_block
		[TI.Definition(1, 16)]
		public partial class cache_file_resource_layout_table_24_block : TI.Definition
		{
			#region block_4
			[TI.Definition(1, 16)]
			public partial class block_4 : TI.Definition
			{
				public TI.LongInteger Unknown00;
				public TI.LongInteger Unknown04;
				public TI.LongInteger Unknown08;
				public TI.LongInteger Unknown0C;

				public block_4() : base(4)
				{
					Add(Unknown00 = new TI.LongInteger());
					Add(Unknown04 = new TI.LongInteger());
					Add(Unknown08 = new TI.LongInteger());
					Add(Unknown0C = new TI.LongInteger());
				}
			}
			#endregion

			public TI.LongInteger Size;
			public TI.Block<block_4> Unknown04;

			public cache_file_resource_layout_table_24_block() : base(2)
			{
				Add(Size = new TI.LongInteger());
				Add(Unknown04 = new TI.Block<block_4>(this));
			}
		}
		#endregion

		#region page_segment_block
		[TI.Definition(1, 16)]
		public partial class page_segment_block : TI.Definition // http://en.wikipedia.org/wiki/Segmentation_(memory)
		{
			public TI.BlockIndex RequiredPageIndex;
			public TI.BlockIndex OptionalPageIndex;
			public TI.LongInteger RequiredSegmentOffset;
			public TI.LongInteger OptionalSegmentOffset;
			public TI.LongInteger DatumIndexBlock24; // seems like only sounds use this...

			public page_segment_block() : base(5)
			{
				Add(RequiredPageIndex = new TI.BlockIndex());
				Add(OptionalPageIndex = new TI.BlockIndex());
				Add(RequiredSegmentOffset = new TI.LongInteger());
				Add(OptionalSegmentOffset = new TI.LongInteger());
				Add(DatumIndexBlock24 = new TI.LongInteger());
			}
		};
		#endregion

		public TI.Block<compression_codec_block> CompressionCodecs;
		public TI.Block<shared_cache_block> SharedCaches;
		public TI.Block<pages_block> Pages; // 18
		public TI.Block<cache_file_resource_layout_table_24_block> Block24; // 24
		public TI.Block<page_segment_block> PageSegments; // 30

		protected cache_file_resource_layout_table(int field_count) : base(field_count) { }
	};
	#endregion

	#region cache_file_resource_gestalt
	public abstract partial class cache_file_resource_gestalt_group : TI.Definition
	{
		#region resource_type_block
		[TI.Definition(1, 28)]
		public partial class resource_type_block : TI.Definition
		{
			public TI.Skip Guid;
			public TI.ShortInteger Unknown010;
			public TI.ShortInteger Unknown012;
			public TI.ShortInteger Unknown014;
			public TI.ShortInteger Unknown016;
			public TI.StringId Name;

			public resource_type_block() : base(6)
			{
				Add(Guid = new TI.Skip(16));
				Add(Unknown010 = new TI.ShortInteger());
				Add(Unknown012 = new TI.ShortInteger());
				Add(Unknown014 = new TI.ShortInteger());
				Add(Unknown016 = new TI.ShortInteger());
				Add(Name = new TI.StringId());
			}
		};
		#endregion

		#region resource_structure_type_block
		[TI.Definition(1, 20)]
		public partial class resource_structure_type_block : TI.Definition
		{
			public TI.Skip Guid;
			public TI.StringId Name;

			public resource_structure_type_block() : base(2)
			{
				Add(Guid = new TI.Skip(16));
				Add(Name = new TI.StringId());
			}
		};
		#endregion

		#region cache_file_resource_gestalt_tag_resource_block
		[TI.Definition(1, 64)]
		public partial class cache_file_resource_gestalt_tag_resource_block : TI.Definition
		{
			#region resource_fixup_block
			[TI.Definition(1, 8)]
			public partial class resource_fixup_block : TI.Definition
			{
				public TI.LongInteger BlockOffset; // [offset in tag data sub-buffer]
				public TI.LongInteger Address; // fix-up address (either in the data sub-buffer, or a cache-resource offset)

				public resource_fixup_block() : base(2)
				{
					Add(BlockOffset = new TI.LongInteger());
					Add(Address = new TI.LongInteger());
				}
			}
			#endregion

			#region resource_definition_fixup_block
			[TI.Definition(1, 8)]
			public partial class resource_definition_fixup_block : TI.Definition
			{
				public TI.LongInteger Offset; // offset in the data sub-buffer
				public TI.BlockIndex StructureTypeIndex;

				public resource_definition_fixup_block() : base(2)
				{
					Add(Offset = new TI.LongInteger());
					Add(StructureTypeIndex = new TI.BlockIndex(TI.FieldType.LongBlockIndex));
				}
			}
			#endregion

			public TI.TagReference Reference;
			public TI.ShortInteger Header;
			public TI.BlockIndex ResourceType;
			public TI.Flags Flags; // ?
			public TI.LongInteger BlockOffset, BlockSize, UnknownOffset; // (in the tag data field)
			public TI.ShortInteger Unknown020; // if this is <= 0, this block is ignored (and probably invalid)
			public TI.ShortInteger SegmentIndex; // 5th tag block in cache_file_resource_layout_table, page_segment_block
			// eg, if this is a structure bsp resource, this will point to the main
			// tag block in the definition buffer
			public TI.LongInteger DefinitionOffset; // resource definition offset, uses fixup ptr scheme
			public TI.Block<resource_fixup_block> ResourceFixups;
			public TI.Block<resource_definition_fixup_block> ResourceDefinitionFixups;

			#region Ctor
			public cache_file_resource_gestalt_tag_resource_block() : base(12)
			{
				Add(Reference = new TI.TagReference(this));
				Add(Header = new TI.ShortInteger());
				Add(ResourceType = new TI.BlockIndex(TI.FieldType.ByteBlockIndex));
				Add(Flags = new TI.Flags(TI.FieldType.ByteFlags));
				Add(BlockOffset = new TI.LongInteger());
				Add(BlockSize = new TI.LongInteger());
				Add(UnknownOffset = new TI.LongInteger());
				Add(Unknown020 = new TI.ShortInteger());
				Add(SegmentIndex = new TI.ShortInteger());
				Add(DefinitionOffset = new TI.LongInteger());
				Add(ResourceFixups = new TI.Block<resource_fixup_block>(this, 0));
				Add(ResourceDefinitionFixups = new TI.Block<resource_definition_fixup_block>(this, 0));
			}
			#endregion
		};
		#endregion

		#region Fields
		public TI.Enum CacheType;
		public TI.Flags Flags;
		public TI.Block<resource_type_block> ResourceTypes;
		public TI.Block<resource_structure_type_block> ResourceStructureTypes;

		public TI.Block<cache_file_resource_gestalt_tag_resource_block> TagResources;

		public TI.Data ResourceDefinitionData;

		public TI.Skip MapId;
		#endregion

		protected cache_file_resource_gestalt_group(int field_count) : base(field_count) { }
	};
	#endregion
}