#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Platform/OpenGL/OpenGLShader.h"

#include <chrono>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	m_CheckerboardTexture = Cngine::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(Cngine::Timestep ts)
{
	CG_PROFILE_FUNCTION();
	Cngine::Renderer2D::ResetStats();
	// Update
	m_CameraController.OnUpdate(ts);
	{
		CG_PROFILE_SCOPE("CameraController::OnUpdate");
		m_CameraController.OnUpdate(ts);
	}
	{
		CG_PROFILE_SCOPE("Renderer Prep");
		Cngine::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Cngine::RenderCommand::Clear();
	}
	
	{
		CG_PROFILE_SCOPE("Renderer Draw");
		Cngine::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Cngine::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Cngine::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
		Cngine::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture,10.0f);
		Cngine::Renderer2D::EndScene();

		Cngine::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
				Cngine::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}
		Cngine::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	CG_PROFILE_FUNCTION();
	
		ImGui::Begin("Settings");
		//auto stats = Hazel::Renderer2D::GetStats();
		//ImGui::Text("Renderer2D Stats:");
		//ImGui::Text("Draw Calls: %d", stats.DrawCalls);
		//ImGui::Text("Quads: %d", stats.QuadCount);
		//ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
		//ImGui::Text("Indices: %d", stats.GetTotalIndexCount());
		ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
		uint32_t textureID = m_CheckerboardTexture->GetRendererID();
		ImGui::Image((void*)textureID, ImVec2{ 1280, 720 });
		ImGui::End();
}

void Sandbox2D::OnEvent(Cngine::Event& e)
{
	m_CameraController.OnEvent(e);
}