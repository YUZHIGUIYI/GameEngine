//
// Created by ZZK on 2023/1/4.
//

#pragma once

#include <Hazel/Renderer/RendererAPI.h>

namespace Hazel
{

    class RenderCommand
    {
    public:
        inline static void SetClearColor(const glm::vec4& color)
        {
            s_RendererAPI->SetClearColor(color);
        }

        inline static void Clear()
        {
            s_RendererAPI->Clear();
        }

        inline static void DrawIndexed(const Hazel::Ref<VertexArray>& vertexArray)
        {
            s_RendererAPI->DrawIndexed(vertexArray);
        }

    private:
        static RendererAPI* s_RendererAPI;
    };
}






















