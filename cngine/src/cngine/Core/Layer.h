#pragma once

#include "cngine/Core/core.h"
#include "cngine/Events/Event.h"
#include "cngine/Core/Timestep.h"

namespace Cngine {

	class CG_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnEvent(Event& event) {}
		virtual void OnImGuiRender() {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}