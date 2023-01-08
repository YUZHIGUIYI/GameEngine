//
// Created by ZZK on 2023/1/7.
//

#include <Sandbox/Sandbox2D.h>
#include <imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <chrono>

template<typename Fn>
class Timer
{
public:
    using float_ms = std::chrono::duration<float, std::micro>;

    Timer(const char* name, Fn&& func)
        : m_Name(name), m_Func(func), m_Stopped(false)
    {
        m_StartTimepoint = std::chrono::steady_clock::now();
    }

    ~Timer()
    {
        if (!m_Stopped)
        {
            Stop();
        }
    }

    void Stop()
    {
        auto endTimepoint = std::chrono::steady_clock::now();

        float duration = 0.001f * std::chrono::duration_cast<float_ms>(endTimepoint - m_StartTimepoint).count();

        m_Stopped = true;

        m_Func({ m_Name, duration });
    }

private:
    const char* m_Name;
    Fn m_Func;
    std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
    bool m_Stopped;
};

#define PROFILE_SCOPE(name) Timer timer##__LINE__(name, [&](ProfileResult profileResult) { m_ProfileResults.push_back(profileResult); })

Sandbox2D::Sandbox2D()
    : Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f, true)
{

}

void Sandbox2D::OnAttach()
{
    m_CheckerboardTexture = Hazel::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{

}

void Sandbox2D::OnUpdate(Hazel::TimeStep ts)
{
    PROFILE_SCOPE("Sandbox2D::OnUpdate");

    // Update
    {
        PROFILE_SCOPE("CameraController::OnUpdate");
        m_CameraController.OnUpdate(ts);
    }

    // Render
    {
        PROFILE_SCOPE("Renderer Prepare");
        Hazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0 });
        Hazel::RenderCommand::Clear();
    }

    {
        PROFILE_SCOPE("Renderer Draw");
        Hazel::Renderer2D::BeginScene(m_CameraController.GetCamera());
        Hazel::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, m_SquareColor);
        Hazel::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
        Hazel::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
        Hazel::Renderer2D::EndScene();
    }

}

void Sandbox2D::OnImGuiRender()
{
    ImGui::Begin("Settings");
    ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

    for (auto& result : m_ProfileResults)
    {
        char label[50];
        strcpy_s(label, "%.3fms ");
        strcat_s(label, result.Name);
        ImGui::Text(label, result.TIme);
    }
    m_ProfileResults.clear();

    ImGui::End();
}

void Sandbox2D::OnEvent(Hazel::Event &event)
{
    m_CameraController.OnEvent(event);
}


















