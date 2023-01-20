//
// Created by ZZK on 2023/1/18.
//

#pragma once

#include <entt/entt.hpp>
#include <Hazel/Core/Timestep.h>

namespace Hazel
{

    class Entity;

    class Scene
    {
    public:
        Scene();
        ~Scene();

        Entity CreateEntity(const std::string& name = std::string());

        void OnUpdate(TimeStep ts);

    private:
        entt::registry m_Registry;

        friend class Entity;
    };
}











