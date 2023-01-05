//
// Created by ZZK on 2023/1/3.
//

#include "hzpch.h"
#include <Hazel/Renderer/Shader.h>

#include <Hazel/Renderer/Renderer.h>
#include <Platform/OpenGL/OpenGLShader.h>

namespace Hazel
{
    Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
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
                return new OpenGLShader(vertexSrc, fragmentSrc);
            }
        }

        HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}
































