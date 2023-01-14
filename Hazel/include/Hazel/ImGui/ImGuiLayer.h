//
// Created by ZZK on 2022/12/31.
//

#pragma once

#include <Hazel/Core/Layer.h>
#include <Hazel/Events/KeyEvent.h>
#include <Hazel/Events/MouseEvent.h>
#include <Hazel/Events/ApplicationEvent.h>

namespace Hazel
{

    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer() = default;

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnEvent(Event& event) override;

        void Begin();
        void End();

        void BlockEvents(bool block) { m_BlockEvents = block; }
    private:
        bool m_BlockEvents = true;
        float m_Time = 0.0f;
    };

}


