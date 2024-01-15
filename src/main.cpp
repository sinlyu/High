#include "High/Core/Application.h"
#include "High/Shaders/Generated/Scene.frag.h"

/*
*const float vertices[] = {
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
*/

int main() {
    High::Core::Application().Run();
    return 0;
}

