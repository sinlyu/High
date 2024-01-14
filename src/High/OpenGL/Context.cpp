#include "Context.h"

#include <iostream>
#include <ostream>
#include <glad/glad.h>

namespace High::OpenGL {
    Context::Context(GLFWwindow* nativeWindow) {
        m_NativeWindow = nativeWindow;
    }

    void Context::Init() const {
        glfwMakeContextCurrent(m_NativeWindow);
        int status = gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));

        // TODO: Check if gladLoadGLLoader failed
        // TODO: Implement proper logging

        std::cout << "GLAD status: " << status << std::endl;
        std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
        std::cout << "OpenGL vendor: " << glGetString(GL_VENDOR) << std::endl;
        std::cout << "OpenGL renderer: " << glGetString(GL_RENDERER) << std::endl;
    }

    void Context::SwapBuffers() const {
        glfwSwapBuffers(m_NativeWindow);
    }
}
