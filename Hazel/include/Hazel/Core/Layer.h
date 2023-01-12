//
// Created by ZZK on 2022/12/31.
//

#pragma once

#include <Hazel/Core/Base.h>
#include <Hazel/Events/Event.h>
#include <Hazel/Core/Timestep.h>

namespace Hazel
{

    class Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate(TimeStep ts) {}
        virtual void OnImGuiRender() {}
        virtual void OnEvent(Event& event) {}

        inline const std::string& GetName() const { return m_DebugName; }
    protected:
        std::string m_DebugName;
    };
}




















