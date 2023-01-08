//
// Created by ZZK on 2023/1/4.
//

#include <Hazel/Renderer/RenderCommand.h>

namespace Hazel
{
    Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}