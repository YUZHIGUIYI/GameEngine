//
// Created by ZZK on 2023/1/3.
//

#pragma once

namespace Hazel
{
    enum class RendererAPI
    {
        None = 0, OpenGL=1
    };

    class Renderer
    {
    public:
        inline static RendererAPI GetAPI() { return s_RendererAPI; }

    private:
        static RendererAPI s_RendererAPI;
    };
}





































