#include "../Core/Base.h"
#include "Shader.h"

namespace High::OpenGL {
    Shader::Shader(const ShaderType shaderType) {
        m_ShaderType = shaderType;

        switch (m_ShaderType) {
            case ShaderType::Vertex:
                m_Shader = glCreateShader(GL_VERTEX_SHADER);
                break;
            case ShaderType::Fragment:
                m_Shader = glCreateShader(GL_FRAGMENT_SHADER);
                break;
        }
    }

    void Shader::Load(const char *source) const {
        glShaderSource(m_Shader, 1, &source, nullptr);
        glCompileShader(m_Shader);
    }

    GLuint Shader::GetShader() const {
        return m_Shader;
    }

    Shader::~Shader() {
        glDeleteShader(m_Shader);
    }
}
