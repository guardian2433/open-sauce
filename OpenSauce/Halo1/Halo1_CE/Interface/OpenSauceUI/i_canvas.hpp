/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/
#pragma once

#if !PLATFORM_IS_DEDI

#include "Interface/OpenSauceUI/i_control.hpp"

namespace Yelo
{
	namespace Interface { namespace OpenSauceUI
	{
		/// <summary>	Interface for an OpenSauceUI canvas. </summary>
		class i_canvas
			abstract
			: public i_control
		{
		public:
			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Initializes the implementations renderer. </summary>
			///
			/// <param name="device">	[in] The current render device. </param>
			virtual void Initialize(IDirect3DDevice9* device) = 0;
			
			/// <summary>	Releases the implementations renderer. </summary>
			virtual void Release() = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the size of the canvas. </summary>
			///
			/// <param name="width"> 	The width of the canvas. </param>
			/// <param name="height">	The height of the canvas. </param>
			virtual void SetSize(const int32 width, const int32 height) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the scale of the canvas. </summary>
			///
			/// <param name="scale">	The scale of the canvas. </param>
			virtual void SetScale(const real scale) = 0;

			/// <summary>	Draws the canvas. </summary>
			virtual void Draw() const = 0;
		};

		/// <summary>	Defines an alias representing a unique canvas pointer. </summary>
		typedef std::unique_ptr<i_canvas> t_canvas_ptr;
	};};
};
#endif