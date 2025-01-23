#include "cgpch.h"
#include "Framebuffer.h"
#include "cngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLFramebuffer.h"
namespace Cngine {

	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    CG_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLFramebuffer>(spec);
		}
		CG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}