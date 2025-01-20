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
 
		//CG_CORE_INFO("  OpenGL Info:");
		//CG_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		//CG_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		//CG_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
#ifdef CG_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);
		CG_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "cngine requires at least OpenGL version 4.5!");
#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}