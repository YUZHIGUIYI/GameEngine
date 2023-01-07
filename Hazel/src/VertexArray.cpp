//
// Created by ZZK on 2023/1/3.
//
#include <Hazel/Renderer/VertexArray.h>
#include <Hazel/Renderer/Renderer.h>

#include <Platform/OpenGL/OpenGLVertexArray.h>

namespace Hazel
{
    Ref<VertexArray> VertexArray::Create()
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
                return CreateRef<OpenGLVertexArray>();
            }
        }

        HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}



















