﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace OpenSauceIDE.ModelExtractor.TagIO
{
    /// <summary>   A helper class to process paths used in blam. </summary>
    public class BlamPath
    {
        public string AbsoluteFolder { get; private set; }
        public string EndFolder { get; private set; }
        public string Root { get; private set; }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// <summary>   Constructor. </summary>
        ///
        /// <param name="tagsPath"> Full pathname of the tags file. </param>
        public BlamPath(string tagsPath)
        {
            AbsoluteFolder = Path.GetFullPath(tagsPath);

            var splitPath = AbsoluteFolder.Split(new char[] { Path.DirectorySeparatorChar }, StringSplitOptions.RemoveEmptyEntries);

            EndFolder = splitPath.Last();
            Root = String.Join(Path.DirectorySeparatorChar.ToString(), splitPath.Take(splitPath.Length - 1));
        }
    }

    /// <summary>   A helper class to process tag paths used in blam. </summary>
    public class BlamTagPath
        : BlamPath
    {
        public string AbsoluteTagPath { get; private set; }
        public string TagPath { get; private set; }
        public string TagName { get; private set; }
        public string TagExtension { get; private set; }
        public string TagNameWithExtension { get; private set; }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// <summary>   Constructor. </summary>
        ///
        /// <param name="tagsPath"> Full pathname of the tags file. </param>
        public BlamTagPath(string tagsPath)
            : base(tagsPath)
        { }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// <summary>   Sets the path. </summary>
        ///
        /// <param name="tagPath">  Full pathname of the tag file. </param>
        public void SetPath(string tagPath)
        {
            AbsoluteTagPath = Path.GetFullPath(tagPath);

            TagName = Path.GetFileNameWithoutExtension(AbsoluteTagPath);
            TagExtension = Path.GetExtension(AbsoluteTagPath);
            TagExtension = TagExtension.TrimStart('.');
            TagNameWithExtension = Path.GetFileName(AbsoluteTagPath);

            var tagsRelative = Path.GetDirectoryName(AbsoluteTagPath);
            tagsRelative = tagsRelative.Replace(AbsoluteFolder, "");

            var tagsRelativeSplit = tagsRelative.Split(new char[] { Path.DirectorySeparatorChar }, StringSplitOptions.RemoveEmptyEntries).ToList();
            tagsRelativeSplit.Add(TagName);

            TagPath = String.Join(Path.DirectorySeparatorChar.ToString(), tagsRelativeSplit);
        }
    }
}
