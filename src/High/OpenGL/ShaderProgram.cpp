#include "../Core/Base.h"
#include "ShaderProgram.h"
#include "Shader.h"

namespace High::OpenGL {
    ShaderProgram::ShaderProgram() {
        m_ShaderProgram = glCreateProgram();
    }

    ShaderProgram::~ShaderProgram() {
        glDeleteProgram(m_ShaderProgram);
    }

    void ShaderProgram::Attach(const Shader* shader) const {
        glAttachShader(m_ShaderProgram, shader->GetShader());
    }

    void ShaderProgram::Link() const {
        glLinkProgram(m_ShaderProgram);
    }

    void ShaderProgram::Use() const {
        glUseProgram(m_ShaderProgram);
    }
}
