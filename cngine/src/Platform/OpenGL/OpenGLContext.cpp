#include "cgpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Cngine {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		CG_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		CG_CORE_ASSERT(status, "Failed to initialize Glad!");

		CG_CORE_INFO("  OpenGL Info:");
		//CG_CORE_INFO("  Vendor: {0}", std::string(glGetString(GL_VENDOR)));
		//CG_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		//CG_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}