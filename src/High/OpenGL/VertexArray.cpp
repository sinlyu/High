#include "../Core/Base.h"
#include "VertexArray.h"

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

    void VertexArray::AddVertexBuffer(const VertexBuffer* vertexBuffer) const {
        glBindVertexArray(m_RendererID);
        vertexBuffer->Bind();
    }

    void VertexArray::Unbind() {
        glBindVertexArray(0);
    }
}
