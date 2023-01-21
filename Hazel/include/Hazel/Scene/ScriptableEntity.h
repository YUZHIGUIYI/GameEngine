//
// Created by ZZK on 2023/1/20.
//

#pragma once

#include <Hazel/Scene/Entity.h>

namespace Hazel
{

    class ScriptableEntity
    {
    public:
        template<typename T>
        T& GetComponent()
        {
            return m_Entity.GetComponent<T>();
        }

    private:
        Entity m_Entity;
        friend class Scene;
    };
}
