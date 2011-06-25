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
using System;
using System.Xml;
using System.Xml.Serialization;

namespace BlamLib.Render.COLLADA.Fx
{
	[SerializableAttribute()]
	[XmlTypeAttribute(AnonymousType = true)]
	public partial class ColladaPhong : ColladaElement
	{
		#region Fields
		ColladaObjectElement<ColladaCommonColorOrTextureType> _emission;
		ColladaObjectElement<ColladaCommonColorOrTextureType> _ambient;
		ColladaObjectElement<ColladaCommonColorOrTextureType> _diffuse;
		ColladaObjectElement<ColladaCommonColorOrTextureType> _specular;
		ColladaObjectElement<ColladaCommonFloatOrParamType> _shininess;
		ColladaObjectElement<ColladaCommonColorOrTextureType> _reflective;
		ColladaObjectElement<ColladaCommonFloatOrParamType> _reflectivity;
		ColladaObjectElement<ColladaCommonColorOrTextureType> _transparent;
		ColladaObjectElement<ColladaCommonFloatOrParamType> _transparency;
		ColladaObjectElement<ColladaCommonFloatOrParamType> _indexOfRefraction;
		#endregion

		#region Children
		[XmlElement("emission")]
		public ColladaCommonColorOrTextureType Emission
		{ get { return _emission.Value; } set { _emission.Value = value; } }

		[XmlElement("ambient")]
		public ColladaCommonColorOrTextureType Ambient
		{ get { return _ambient.Value; } set { _ambient.Value = value; } }

		[XmlElement("diffuse")]
		public ColladaCommonColorOrTextureType Diffuse
		{ get { return _diffuse.Value; } set { _diffuse.Value = value; } }

		[XmlElement("specular")]
		public ColladaCommonColorOrTextureType Specular
		{ get { return _specular.Value; } set { _specular.Value = value; } }

		[XmlElement("shininess")]
		public ColladaCommonFloatOrParamType Shininess
		{ get { return _shininess.Value; } set { _shininess.Value = value; } }

		[XmlElement("reflective")]
		public ColladaCommonColorOrTextureType Reflective
		{ get { return _reflective.Value; } set { _reflective.Value = value; } }

		[XmlElement("reflectivity")]
		public ColladaCommonFloatOrParamType Reflectivity
		{ get { return _reflectivity.Value; } set { _reflectivity.Value = value; } }

		[XmlElement("transparent")]
		public ColladaCommonColorOrTextureType Transparent
		{ get { return _transparent.Value; } set { _transparent.Value = value; } }

		[XmlElement("transparency")]
		public ColladaCommonFloatOrParamType Transparency
		{ get { return _transparency.Value; } set { _transparency.Value = value; } }

		[XmlElement("index_of_refraction")]
		public ColladaCommonFloatOrParamType IndexOfRefraction
		{ get { return _indexOfRefraction.Value; } set { _indexOfRefraction.Value = value; } }
		#endregion

		public ColladaPhong() : base(Enums.ColladaElementType.Fx_Phong)
		{
			Fields.Add(_emission = new ColladaObjectElement<ColladaCommonColorOrTextureType>());
			Fields.Add(_ambient = new ColladaObjectElement<ColladaCommonColorOrTextureType>());
			Fields.Add(_diffuse = new ColladaObjectElement<ColladaCommonColorOrTextureType>());
			Fields.Add(_specular = new ColladaObjectElement<ColladaCommonColorOrTextureType>());
			Fields.Add(_shininess = new ColladaObjectElement<ColladaCommonFloatOrParamType>());
			Fields.Add(_reflective = new ColladaObjectElement<ColladaCommonColorOrTextureType>());
			Fields.Add(_reflectivity = new ColladaObjectElement<ColladaCommonFloatOrParamType>());
			Fields.Add(_transparent = new ColladaObjectElement<ColladaCommonColorOrTextureType>());
			Fields.Add(_transparency = new ColladaObjectElement<ColladaCommonFloatOrParamType>());
			Fields.Add(_indexOfRefraction = new ColladaObjectElement<ColladaCommonFloatOrParamType>());
		}
	}
}