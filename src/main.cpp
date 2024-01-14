#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "High/Core/Application.h"
#include "High/Core/Window.h"
#include "High/OpenGL/ShaderProgram.h"
#include "High/OpenGL/VertexArray.h"
#include "High/OpenGL/VertexBuffer.h"

#include "High/Shaders/Generated/Scene.vert.h"
#include "High/Shaders/Generated/Scene.frag.h"

int main() {
    const float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    const auto SceneVertShader = High::Shaders::LoadSceneVertShader();
    const auto SceneFragShader = High::Shaders::LoadSceneFragShader();

    // Create a shader program
    const auto shaderProgram = High::OpenGL::ShaderProgram();
    shaderProgram.Attach(SceneVertShader);
    shaderProgram.Attach(SceneFragShader);
    shaderProgram.Link();

    const High::OpenGL::VertexArray vertexArray;
    vertexArray.Bind();

    const High::OpenGL::VertexBuffer vertexBuffer(sizeof(vertices));
    vertexBuffer.SetData(vertices, sizeof(vertices));

    // TODO: Move this to a High::OpenGL::VertexBufferLayout class
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), static_cast<void *>(nullptr));
    glEnableVertexAttribArray(0);

    High::OpenGL::VertexBuffer::Unbind();
    High::OpenGL::VertexArray::Unbind();



    glfwTerminate();

    return 0;
}

