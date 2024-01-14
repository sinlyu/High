#pragma once
#include <cstdint>

namespace High::OpenGL {

class VertexBuffer {
public:
    explicit VertexBuffer(uint32_t size);
    ~VertexBuffer();

    void Bind() const;

    static void Unbind();

    void SetData(const void* data, uint32_t size) const;

private:
    uint32_t m_RendererID{};
};

} // OpenGL

