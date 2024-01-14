#pragma once
#include "Shader.h"
#include "../../../vendor/GLFW/src/internal.h"

namespace High::OpenGL {
    class ShaderProgram {
    public:
        ShaderProgram();
        ~ShaderProgram();
        void Attach(const Shader* shader) const;
        void Link() const;
        void Use() const;

    private:
        GLuint m_ShaderProgram{};
    };
}
