//
// Created by ZZK on 2023/1/14.
//

#include <Hazel.h>
#include <Hazel/Core/EntryPoint.h>
#include <HazelEditor/EditorLayer.h>

namespace Hazel
{

    class HazelEditor : public Application
    {
    public:
        HazelEditor()
                : Application("Hazel Editor")
        {
            PushLayer(new EditorLayer());
        }

        ~HazelEditor()
        {
        }
    };

    Application* CreateApplication()
    {
        return new HazelEditor();
    }

}






