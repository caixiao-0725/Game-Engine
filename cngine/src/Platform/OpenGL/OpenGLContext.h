#pragma once

#include "Cngine/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Cngine {

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};

}