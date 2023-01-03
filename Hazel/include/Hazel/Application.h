//
// Created by ZZK on 2022/12/31.
//

#pragma once

#include <Hazel/Core.h>
#include <Hazel/Window.h>
#include <Hazel/LayerStack.h>
#include <Hazel/Events/Event.h>
#include <Hazel/Events/ApplicationEvent.h>
#include <Hazel/ImGui/ImGuiLayer.h>

namespace Hazel
{

    class HAZEL_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }

        inline static Application& Get() { return *s_Instance; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;
    private:
        static Application* s_Instance;
    };

    // To be defined in CLIENT
    Application* CreateApplication();

}
