//
// Created by ZZK on 2023/1/14.
//

#include <Hazel.h>
#include <Hazel/Core/EntryPoint.h>
#include <Hazelnut/EditorLayer.h>

namespace Hazel
{

    class Hazelnut : public Application
    {
    public:
        Hazelnut()
                : Application("Hazelnut")
        {
            PushLayer(new EditorLayer());
        }

        ~Hazelnut()
        {
        }
    };

    Application* CreateApplication()
    {
        return new Hazelnut();
    }

}






