#include "Window.h"
#include "Application.h"

namespace High::Core
{
    Window::Window(const std::string& title, const int width, const int height)
    {
        static bool s_GLFWInitialized = false;
        if (!s_GLFWInitialized) Init();

        m_Width = width;
        m_Height = height;
        m_Title = title;

        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);

        m_Context = new OpenGL::Context(m_Window);
        m_Context->Init();

        // sub to viewport resize
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* nativeWindow, const int newWidth, const int newHeight) {
            // TODO: Implement Event System
            Application::GetInstance()->GetWindow()->SetSize(newWidth, newHeight);
            Application::GetInstance()->OnWindowResize(newWidth, newHeight);
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
        {
            // TODO: Implement Event System
            Application::GetInstance()->OnWindowClose();
        });
    }

    GLFWwindow* Window::GetNativeWindow() const {
        return m_Window;
    }

    Window* Window::Create(const WindowProps &props) {
        return new Window(props.Title, props.Width, props.Height);
    }

    int Window::GetWidth() const {
        return m_Width;
    }

    int Window::GetHeight() const {
        return m_Height;
    }

    void Window::SetSize(const int width, const int height) {
        m_Width = width;
        m_Height = height;
    }

    void Window::OnUpdate() const {
        glfwPollEvents();
        m_Context->SwapBuffers();
    }

    void Window::Init() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
}
