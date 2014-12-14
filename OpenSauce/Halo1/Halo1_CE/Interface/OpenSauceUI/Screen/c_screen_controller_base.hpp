/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/
#pragma once

#if !PLATFORM_IS_DEDI

#include "Interface/OpenSauceUI/Screen/i_screen.hpp"
#include "Interface/OpenSauceUI/Screen/i_screen_controller.hpp"
#include "Interface/OpenSauceUI/Definitions/c_screen_definition.hpp"

namespace Yelo
{
	namespace Interface { namespace OpenSauceUI { namespace Screen
	{
		/// <summary>	Base screen controller. </summary>
		class c_screen_controller_base
			abstract
			: public i_screen_controller
		{
			/// <summary>	Defines an alias representing a dynamic property update function. </summary>
			typedef std::function<void(Control::i_control&, Control::i_property_interface&)> t_dynamic_property_update;

			struct s_dynamic_property
			{
				Control::i_control& m_control;
				Control::i_property_interface& m_property;
				const t_dynamic_property_update m_update;
			};

			std::vector<s_dynamic_property> m_dynamic_properties;

		protected:
			t_screen_ptr m_target_screen;
			Definitions::c_screen_definition m_screen_definition;

		public:
			c_screen_controller_base(Definitions::c_screen_definition& definition);
			
#pragma region i_screen_controller
		public:
			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Builds the screen and adds it to the canvas. </summary>
			///
			/// <param name="control_factory">	  	[in] The control factory. </param>
			/// <param name="target_canvas">	  	[in] Target canvas. </param>
			void BuildScreen(ControlFactory::c_control_factory& control_factory
				, Control::i_canvas& target_canvas) final override;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Removes the screen from the canvas and destroys it. </summary>
			///
			/// <param name="target_canvas">	[in] Target canvas. </param>
			void DestroyScreen(Control::i_canvas& target_canvas) final override;

			/// <summary>	Updates the screen. </summary>
			void Update() final override;

		private:
			/// <summary>	Unbinds a screens dynamic properties. </summary>
			void UnbindDynamicProperties() final override;
#pragma endregion

#pragma region Property Setup
		private:
			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Searches for a control and property. </summary>
			///
			/// <param name="control_id">  	Identifier for the control. </param>
			/// <param name="property_id"> 	Identifier for the property. </param>
			/// <param name="control_out"> 	[out] The found control. </param>
			/// <param name="property_out">	[out] The found property. </param>
			void FindControlAndProperty(const uint32 control_id, const uint32 property_id, Control::t_control_ptr& control_out, Control::i_property_interface*& property_out);

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Set control property implementation. </summary>
			///
			/// <typeparam name="Type">	Type of the property. </typeparam>
			/// <param name="control_id"> 	Identifier for the control. </param>
			/// <param name="property_id">	Identifier for the property. </param>
			/// <param name="value">	  	The value to set. </param>
			template<typename Type>
			void SetControlPropertyImpl(const uint32 control_id, const uint32 property_id, Type value);

		protected:
			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets a bool control property. </summary>
			///
			/// <param name="control_id"> 	Identifier for the control. </param>
			/// <param name="property_id">	Identifier for the property. </param>
			/// <param name="value">	  	true to value. </param>
			void SetControlProperty(const uint32 control_id, const uint32 property_id, const bool value);

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets an int32 control property. </summary>
			///
			/// <param name="control_id"> 	Identifier for the control. </param>
			/// <param name="property_id">	Identifier for the property. </param>
			/// <param name="value">	  	The value. </param>
			void SetControlProperty(const uint32 control_id, const uint32 property_id, const int32 value);

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets a string control property. </summary>
			///
			/// <param name="control_id"> 	Identifier for the control. </param>
			/// <param name="property_id">	Identifier for the property. </param>
			/// <param name="value">	  	The value. </param>
			void SetControlProperty(const uint32 control_id, const uint32 property_id, cstring value);

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Adds a dynamic property. </summary>
			///
			/// <param name="control_id"> 	Identifier for the control. </param>
			/// <param name="property_id">	Identifier for the property. </param>
			/// <param name="update">	  	The update function. </param>
			void AddDynamicProperty(const uint32 control_id, const uint32 property_id, const t_dynamic_property_update& update);
#pragma endregion

#pragma region Event Setup
			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Attaches an event callback to a control. </summary>
			///
			/// <param name="control_id"> 	Identifier for the control. </param>
			/// <param name="event_id">   	Identifier for the event. </param>
			/// <param name="callback_id">	Identifier for the callback. </param>
			/// <param name="userdata">   	[in] The userdata for the callback. </param>
			/// <param name="function">   	The callback function. </param>
			void AttachEvent(const uint32 control_id, const uint32 event_id, const uint32 callback_id, void* userdata, Control::t_event_callback function);

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Detach event. </summary>
			///
			/// <param name="control_id"> 	Identifier for the control. </param>
			/// <param name="event_id">   	Identifier for the event. </param>
			/// <param name="callback_id">	Identifier for the callback. </param>
			void DetachEvent(const uint32 control_id, const uint32 event_id, const uint32 callback_id);
#pragma endregion

#pragma region i_visibility_toggle
		public:
			/// <summary>	Shows the screen. </summary>
			void Show() override;

			/// <summary>	Hides the screen. </summary>
			void Hide() override;
#pragma endregion
		};
	};};};
};
#endif