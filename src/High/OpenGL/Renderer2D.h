#pragma once

#include "../Core/Base.h"
#include "Shader.h"
#include "VertexArray.h"

namespace High::OpenGL {
    class Renderer2D {
    public:
        static void Init();
        static void Shutdown();

        static void OnWindowResize(uint32_t width, uint32_t height);

        static void BeginScene();
        static void EndScene();

        static void Submit(const Shader& shader, const VertexArray& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

    private:
        glm::mat4 m_ViewProjectionMatrix = {};
    };
}