#include "VertexArray.h"

#include <glad/glad.h>

namespace High::OpenGL {
    VertexArray::VertexArray() {
        glCreateVertexArrays(1, &m_RendererID);
    }

    VertexArray::~VertexArray() {
        glDeleteVertexArrays(1, &m_RendererID);
    }

    void VertexArray::Bind() const {
        glBindVertexArray(m_RendererID);
    }

    void VertexArray::AddVertexBuffer(const VertexBuffer* vertexBuffer) {
        glBindVertexArray(m_RendererID);
        vertexBuffer->Bind();
    }

    void VertexArray::Unbind() {
        glBindVertexArray(0);
    }


}
