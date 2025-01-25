#pragma once

#include "cngine/Core/Layer.h"
#include "cngine/Events/ApplicationEvent.h"
#include "cngine/Events/KeyEvent.h"
#include "cngine/Events/MouseEvent.h"

namespace Cngine {

	class CG_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemeColors();

	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};

}