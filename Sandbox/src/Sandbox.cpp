#include <cngine.h>
//#include "imgui/imgui.h"
class ExampleLayer : public Cngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//CG_INFO("ExampleLayer::Update");
	}

	void OnEvent(Cngine::Event& event) override
	{
		//CG_TRACE("{0}", event.ToString());
	}
	//virtual void OnImGuiRender() override
	//{
	//	ImGui::Begin("Test");
	//	ImGui::Text("Hello World");
	//	ImGui::End();
	//}
};
class Sandbox: public Cngine::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {
	}
};

Cngine::Application* Cngine::CreateApplication() {
	return new Sandbox();
}
