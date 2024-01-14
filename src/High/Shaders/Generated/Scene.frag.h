#pragma once

#include "../../OpenGL/Shader.h"

namespace High::Shaders
{
    inline OpenGL::Shader* LoadSceneFragShader()
    {
        const auto SceneFragShaderSource = R"(
            #version 460 core
            out vec4 FragColor;
            
            void main()
            {
                FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
            }
        )";
        const auto SceneFragShader = new High::OpenGL::Shader(High::OpenGL::ShaderType::Fragment);
        SceneFragShader->Load(SceneFragShaderSource);
        return SceneFragShader;
    }
}

