#pragma once
#include "VertexBuffer.h"

namespace High::OpenGL {
    class VertexArray {
    public:
        VertexArray();
        ~VertexArray();

        void Bind() const;
        void AddVertexBuffer(const VertexBuffer* vertexBuffer) const;

        static void Unbind();

    private:
        uint32_t m_RendererID{};
        uint32_t m_VertexBufferIndex{};
    };
}