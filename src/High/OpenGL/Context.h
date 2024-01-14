#pragma once
#include "GLFW/glfw3.h"

namespace High::OpenGL {

class Context {
public:
    explicit Context(GLFWwindow* nativeWindow);
    void Init() const;
    void SwapBuffers() const;
private:
    GLFWwindow* m_NativeWindow;
};

}

