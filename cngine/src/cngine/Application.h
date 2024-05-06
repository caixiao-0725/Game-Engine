#pragma once
#include "core.h"
#include "Events/Event.h"
#include "Window.h"
#include "cngine/Events/ApplicationEvent.h"

#include "cngine/LayerStack.h"


namespace Cngine {


	class CG_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be defined in client
	Application* CreateApplication();
}
