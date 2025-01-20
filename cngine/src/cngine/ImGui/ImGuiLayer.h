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
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};

}