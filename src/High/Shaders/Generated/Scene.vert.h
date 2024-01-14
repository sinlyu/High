#pragma once

#include "../../OpenGL/Shader.h"

namespace High::Shaders
{
    inline OpenGL::Shader* LoadSceneVertShader()
    {
        const auto SceneVertShaderSource = R"(
            #version 460 core
            layout (location = 0) in vec3 aPos;
            
            void main()
            {
                gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
            }
        )";
        const auto SceneVertShader = new High::OpenGL::Shader(High::OpenGL::ShaderType::Vertex);
        SceneVertShader->Load(SceneVertShaderSource);
        return SceneVertShader;
    }
}

