//
// Created by ZZK on 2023/1/4.
//

#include <Hazel/Renderer/RenderCommand.h>
#include <Platform/OpenGL/OpenGLRendererAPI.h>

namespace Hazel
{
    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}