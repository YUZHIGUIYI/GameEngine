//
// Created by ZZK on 2023/1/8.
//

#include <hzpch.h>
#include <Hazel/Renderer/GraphicsContext.h>
#include <Hazel/Renderer/Renderer.h>
#include <Platform/OpenGL/OpenGLContext.h>

namespace Hazel
{
    Scope<GraphicsContext> GraphicsContext::Create(void* window)
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
                return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
            }
        }

        HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}