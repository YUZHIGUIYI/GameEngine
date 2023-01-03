//
// Created by ZZK on 2023/1/3.
//
#include <Hazel/Renderer/VertexArray.h>
#include <Hazel/Renderer/Renderer.h>

#include <Platform/OpenGL/OpenGLVertexArray.h>

namespace Hazel
{
    VertexArray* VertexArray::Create()
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::None:
            {
                HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
                return nullptr;
            }
            case RendererAPI::OpenGL:
            {
                return new OpenGLVertexArray();
            }
        }

        HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}



















