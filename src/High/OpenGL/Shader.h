#pragma once

namespace High::OpenGL {
    enum class ShaderType {
        Vertex,
        Fragment
    };

    class Shader {
    public:
        explicit Shader(ShaderType shaderType);
        ~Shader();

        void Load(const char* source) const;
        [[nodiscard]] GLuint GetShader() const;

    private:
        ShaderType m_ShaderType;
        GLuint m_Shader{};
    };
}
