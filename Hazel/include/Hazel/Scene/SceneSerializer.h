//
// Created by ZZK on 2023/1/23.
//

#pragma once

#include <Hazel/Scene/Scene.h>

namespace Hazel
{

    class SceneSerializer
    {
    public:
        SceneSerializer(const Ref<Scene>& scene);

        void Serialize(const std::string& filepath);
        void SerializeRuntime(const std::string& filepath);

        bool Deserialize(const std::string& filepath);
        bool DeserializeRuntime(const std::string& filepath);

    private:
        Ref<Scene> m_Scene;
    };
}



















