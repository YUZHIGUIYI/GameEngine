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
        void OnViewportResize(uint32_t width, uint32_t height);

    private:
        entt::registry m_Registry;
        uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;

        friend class Entity;
        friend class SceneHierarchyPanel;   // TODO: In Hazelnut
    };
}











