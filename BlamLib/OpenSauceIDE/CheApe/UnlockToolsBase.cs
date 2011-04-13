/*
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
﻿using System;
using System.Collections.Generic;

namespace OpenSauceIDE.CheApeInterface
{
	abstract class UnlockToolsBase
	{
		public bool EncounteredInvalidExe = false;
		protected static bool ValidateExe(string path, long time_stamp_offset, uint time_stamp)
		{
			using (var fs = new System.IO.FileStream(path, System.IO.FileMode.Open, System.IO.FileAccess.Read))
			using (var s = new System.IO.BinaryReader(fs))
			{
				if (fs.Length > (time_stamp_offset+4))
				{
					fs.Seek(time_stamp_offset, System.IO.SeekOrigin.Begin);
					uint ts = s.ReadUInt32();

					return ts == time_stamp;
				}
			}

			return false;
		}

		protected enum Platform
		{
			Guerilla,
			Tool,
			Sapien,
		};

		protected struct PlatformAddress
		{
			public uint Guerilla, Tool, Sapien;

			public PlatformAddress(uint g, uint t, uint s) { Guerilla = g; Tool = t; Sapien = s; }

			public uint this[Platform p] {
				get {
					switch(p)
					{
						case Platform.Guerilla: return Guerilla;
						case Platform.Tool:		return Tool;
						case Platform.Sapien:	return Sapien;
						default: throw new Exception();
					}
				}
			}
		};

		protected class PlatformData
		{
			public byte[] Guerilla, Tool, Sapien;

			public PlatformData(byte[] g, byte[] t, byte[] s) { Guerilla = g; Tool = t; Sapien = s; }

			public byte[] this[Platform p]
			{
				get
				{
					switch (p)
					{
						case Platform.Guerilla:	return Guerilla;
						case Platform.Tool:		return Tool;
						case Platform.Sapien:	return Sapien;
						default: throw new Exception();
					}
				}
			}
		};

		protected abstract class PlatformInterfaceBase
		{
			protected Platform PlatformVersion;

			protected BlamLib.IO.EndianWriter output;

			protected PlatformInterfaceBase(Platform pv)
			{
				PlatformVersion = pv;
			}

			public void Close() { output.Close(); }

			public abstract void Unlock(bool debug);

			protected abstract bool ValidateExe(string path);
		};

		public abstract void Close();

		public abstract void Unlock(bool debug);
	};
}