//
// Created by ZZK on 2023/1/6.
//

#include <Hazel/Renderer/Texture.h>
#include <Hazel/Renderer/Renderer.h>
#include <Platform/OpenGL/OpenGLTexture.h>

namespace Hazel
{

    Ref<Texture2D> Texture2D::Create(const std::string &path)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
            {
                HZ_CORE_ASSERT(false, "RendererAPI::API::None is currently not supported!");
                return nullptr;
            }
            case RendererAPI::API::OpenGL:  return std::make_shared<OpenGLTexture2D>(path);
        }

        HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}


















