//
// Created by ZZK on 2023/1/18.
//

#pragma once

#include <entt/entt.hpp>
#include <Hazel/Core/Timestep.h>

namespace Hazel
{

    class Scene
    {
    public:
        Scene();
        ~Scene();

        entt::entity CreateEntity();

        // Temp
        entt::registry& Reg() { return m_Registry; }

        void OnUpdate(TimeStep ts);

    private:
        entt::registry m_Registry;
    };
}











