//
// Created by ZZK on 2023/1/1.
//

#include <Hazel.h>
#include <Hazel/Core/EntryPoint.h>

#include <Sandbox/Sandbox2D.h>
#include <Sandbox/ExampleLayer.h>

class Sandbox : public Hazel::Application
{
public:
    Sandbox()
    {
        // PushLayer(new ExampleLayer());
        PushLayer(new Sandbox2D());
    }

    ~Sandbox()
    {

    }
};

Hazel::Application* Hazel::CreateApplication()
{
    return new Sandbox();
}
























