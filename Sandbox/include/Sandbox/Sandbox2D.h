//
// Created by ZZK on 2023/1/7.
//

#pragma once

#include <Hazel.h>
#include <Sandbox/ParticleSystem.h>

class Sandbox2D : public Hazel::Layer
{
public:
    Sandbox2D();
    virtual ~Sandbox2D() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void OnUpdate(Hazel::TimeStep ts) override;
    virtual void OnImGuiRender() override;
    void OnEvent(Hazel::Event& event) override;

private:
    Hazel::OrthographicCameraController m_CameraController;

    // Temp
    Hazel::Ref<Hazel::VertexArray> m_SquareVA;
    Hazel::Ref<Hazel::Shader> m_FlatColorShader;

    Hazel::Ref<Hazel::Texture2D> m_CheckerboardTexture;

    glm::vec4 m_SquareColor;

    // Particle system
    ParticleProps m_Particle;
    ParticleSystem m_ParticleSystem;
};

























