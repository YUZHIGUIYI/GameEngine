//
// Created by ZZK on 2022/12/31.
//

#pragma once

#include <Hazel/Core/Base.h>
#include <Hazel/Core/Window.h>
#include <Hazel/Core/LayerStack.h>
#include <Hazel/Events/Event.h>
#include <Hazel/Events/ApplicationEvent.h>

#include <Hazel/ImGui/ImGuiLayer.h>

#include <Hazel/Core/Timestep.h>

// Make run-loop only accessible on the engine side
int main(int argc, char** argv);

namespace Hazel
{

    struct ApplicationCommandLineArgs
    {
        int Count = 0;
        char** Args = nullptr;

        const char* operator[](int index) const
        {
            HZ_CORE_ASSERT(index < Count);
            return Args[index];
        }
    };

    class Application
    {
    public:
        Application(const std::string& name = "Hazel App", ApplicationCommandLineArgs args = ApplicationCommandLineArgs());
        virtual ~Application();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }

        void Close();

        ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

        inline static Application& Get() { return *s_Instance; }

        ApplicationCommandLineArgs GetCommandLineArgs() const { return m_CommandLineArgs; }

    private:
        void Run();
        bool OnWindowClose(WindowCloseEvent& e);
        bool OnWindowResize(WindowResizeEvent& e);

    private:
        ApplicationCommandLineArgs m_CommandLineArgs;
        Scope<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        bool m_Minimized = false;
        LayerStack m_LayerStack;
        float m_LastFrameTime = 0.0f;

    private:
        static Application* s_Instance;
        friend int ::main(int argc, char** argv);    // Make run-loop only accessible on the engine side
    };

    // To be defined in CLIENT
    Application* CreateApplication(ApplicationCommandLineArgs args);

}























