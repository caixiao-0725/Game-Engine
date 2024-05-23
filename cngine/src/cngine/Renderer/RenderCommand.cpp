#include "cgpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Cngine {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}