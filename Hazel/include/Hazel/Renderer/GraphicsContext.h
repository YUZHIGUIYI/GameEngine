//
// Created by ZZK on 2022/12/31.
//

#pragma once

namespace Hazel
{

    class GraphicsContext
    {
    public:
        virtual void Init() = 0;
        virtual void SwapBuffers() = 0;
    };

}