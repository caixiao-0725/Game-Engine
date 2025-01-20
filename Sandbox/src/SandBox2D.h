#pragma once

#include "Cngine.h"

class Sandbox2D : public Cngine::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Cngine::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Cngine::Event& e) override;
private:
	Cngine::OrthographicCameraController m_CameraController;

	// Temp
	Cngine::Ref<Cngine::VertexArray> m_SquareVA;
	Cngine::Ref<Cngine::Shader> m_FlatColorShader;
	Cngine::Ref<Cngine::Texture2D> m_CheckerboardTexture;
	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};