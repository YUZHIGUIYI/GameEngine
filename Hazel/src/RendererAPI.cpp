//
// Created by ZZK on 2023/1/4.
//

#include <Hazel/Renderer/RendererAPI.h>
#include <Platform/OpenGL/OpenGLRendererAPI.h>

namespace Hazel
{
    RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

    Scope<RendererAPI> RendererAPI::Create()
    {
        switch (s_API)
        {
            case RendererAPI::API::None:
            {
                HZ_CORE_ASSERT(false, "RendererAPI::API::None is currently not supported!");
                return nullptr;
            }
            case RendererAPI::API::OpenGL:
            {
                return CreateScope<OpenGLRendererAPI>();
            }
        }

        HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}