//
// Created by ZZK on 2023/1/13.
//

#include <Hazel/Renderer/Framebuffer.h>
#include <Hazel/Renderer/Renderer.h>
#include <Platform/OpenGL/OpenGLFramebuffer.h>

namespace Hazel
{

    Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification &spec)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
            {
                HZ_CORE_ASSERT(false, "RendererAPI::API::None is currently not supported!");
                return nullptr;
            }
            case RendererAPI::API::OpenGL:
            {
                return CreateRef<OpenGLFramebuffer>(spec);
            }
        }

        HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}
























