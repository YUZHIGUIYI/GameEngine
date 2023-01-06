//
// Created by ZZK on 2023/1/3.
//

#pragma once

#include <Hazel/Renderer/RenderCommand.h>
#include <Hazel/Renderer/OrthographicCamera.h>
#include <Hazel/Renderer/Shader.h>

namespace Hazel
{

    class Renderer
    {
    public:
        static void Init();
        static void OnWindowResize(uint32_t width, uint32_t height);

        static void BeginScene(OrthographicCamera& camera);
        static void EndScene();

        static void Submit(const Hazel::Ref<Shader>& shader, const Hazel::Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

        inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

    private:
        struct SceneData
        {
            glm::mat4 ViewProjectionMatrix;
        };

        static SceneData* s_SceneData;
    };
}





































