/*
	BlamLib: .NET SDK for the Blam Engine

	See license\BlamLib\BlamLib for specific license information
*/
using System;
using System.ComponentModel;
using System.Xml;
using System.Xml.Serialization;
using System.Collections.Generic;
using BlamLib.Render.COLLADA.Validation;

namespace BlamLib.Render.COLLADA.Core
{
	[SerializableAttribute()]
	[XmlTypeAttribute(AnonymousType = true)]
	public partial class ColladaController : ColladaElement
	{
		#region Fields
		ColladaObjectAttribute<ColladaID<ColladaController>> _id;
		ColladaObjectAttribute<ColladaNCName> _name;

		ColladaObjectElement<ColladaAsset> _asset;
		ColladaObjectElement<ColladaSkin> _skin;
		ColladaObjectElement<ColladaMorph> _morph;
		ColladaObjectElementList<ColladaExtra> _extra;
		#endregion

		#region Attributes
		[XmlAttribute("id"), DefaultValue(""), ColladaID("controller-{0}")]
		public string ID
		{ get { return _id.Value; } set { _id.Value = value; } }

		[XmlAttribute("name"), DefaultValue("")]
		public string Name
		{ get { return _name.Value; } set { _name.Value = value; } }
		#endregion

		#region Children
		[XmlElement("asset")]
		public ColladaAsset Asset
		{ get { return _asset.Value; } set { _asset.Value = value; } }

		[XmlElement("skin")]
		public ColladaSkin Skin
		{ get { return _skin.Value; } set { _skin.Value = value; } }

		[XmlElement("morph")]
		public ColladaMorph Morph
		{ get { return _morph.Value; } set { _morph.Value = value; } }

		[XmlElement("extra")]
		public List<ColladaExtra> Extra
		{ get { return _extra.Value; } set { _extra.Value = value; } }
		#endregion

		public ColladaController() : base(Enums.ColladaElementType.Core_Controller)
		{
			Fields.Add(_id = new ColladaObjectAttribute<ColladaID<ColladaController>>(""));
			Fields.Add(_name = new ColladaObjectAttribute<ColladaNCName>(""));
			Fields.Add(_asset = new ColladaObjectElement<ColladaAsset>());
			Fields.Add(_skin = new ColladaObjectElement<ColladaSkin>());
			Fields.Add(_morph = new ColladaObjectElement<ColladaMorph>());
			Fields.Add(_extra = new ColladaObjectElementList<ColladaExtra>());

			List<ColladaObject> mutually_exclusive = new List<ColladaObject>();
			mutually_exclusive.Add(_skin);
			mutually_exclusive.Add(_morph);

			ValidationTests.Add(new ColladaMutuallyExclusive(Enums.ColladaElementType.All, mutually_exclusive));
			ValidationTests.Add(new ColladaOneRequired(Enums.ColladaElementType.All, mutually_exclusive));
		}
	}
}