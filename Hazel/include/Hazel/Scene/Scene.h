//
// Created by ZZK on 2023/1/18.
//

#pragma once

#include <entt/entt.hpp>
#include <Hazel/Core/Timestep.h>
#include <Hazel/Renderer/EditorCamera.h>

class b2World;

namespace Hazel
{

    class Entity;

    class Scene
    {
    public:
        Scene();
        ~Scene();

        Entity CreateEntity(const std::string& name = std::string());
        void DestroyEntity(Entity entity);

        void OnRuntimeStart();
        void OnRuntimeStop();

        void OnUpdateRuntime(TimeStep ts);
        void OnUpdateEditor(TimeStep ts, EditorCamera& camera);
        void OnViewportResize(uint32_t width, uint32_t height);

        Entity GetPrimaryCameraEntity();

    private:
        template<typename T>
        void OnComponentAdded(Entity entity, T& component);

    private:
        entt::registry m_Registry;
        uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;

        b2World* m_PhysicsWorld = nullptr;

        friend class Entity;
        friend class SceneSerializer;
        friend class SceneHierarchyPanel;   // TODO: In Hazelnut
    };
}











