#pragma once
#include "core.h"
#include "Events/Event.h"
#include "Window.h"
#include "cngine/Events/ApplicationEvent.h"

#include "cngine/LayerStack.h"
#include "cngine\ImGui\ImGuiLayer.h"

#include "cngine/Renderer/Shader.h"

#include "cngine/Renderer/Buffer.h"

#include "cngine/Renderer/VertexArray.h"

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


		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

	private:
		static Application* s_Instance;
	};

	//To be defined in client
	Application* CreateApplication();
}
