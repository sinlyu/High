//
// Created by Uther on 14.01.2024.
//

#include "VertexBuffer.h"
#include "../Core/Base.h"

namespace High::OpenGL {
    VertexBuffer::VertexBuffer(const uint32_t size) {
        glCreateBuffers(1, &m_RendererID);
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
        glBufferData(GL_ARRAY_BUFFER,size, nullptr, GL_STATIC_DRAW);
    }

    VertexBuffer::~VertexBuffer() {
        glDeleteBuffers(1, &m_RendererID);
    }

    void VertexBuffer::Bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    }

    void VertexBuffer::Unbind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void VertexBuffer::SetData(const void *data, uint32_t size) const {
        Bind();
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    }
}
