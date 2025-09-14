#include "hzpch.h"
#include "Framebuffer.h"

#include "renderer.h"

#include "OpenGL/OpenGLFramebuffer.h"
namespace Hazel {
    Ref<Framebuffer> Framebuffer::Create(const Framebufferspecification& spec)
    {
        switch(Renderer::GetAPI())
        {
        case RendererAPI::API::None:  HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");return nullptr;
        case RendererAPI::API::OpenGL: return CreateRef<OpenGLFramebuffer> (spec);

        }
        HZ_CORE_ASSERT(false, "Unknown Renderer API!");
        return nullptr;
    }
}