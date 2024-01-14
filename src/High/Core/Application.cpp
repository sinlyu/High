#include "Application.h"

namespace High::Core {
    Application* Application::s_Instance = nullptr;

    Application::Application() {
        s_Instance = this;
        // TODO: Pass window properties to Window::Create()
        m_Window = Window::Create(WindowProps());

        // TODO: Move to Framebuffer
        glViewport(0, 0, m_Window->GetWidth(), m_Window->GetHeight());
    }

    Application::~Application() {
        delete m_Window;
    }

    Application* Application::GetInstance() {
        return s_Instance;
    }

    void Application::Run() const {
        while(m_Running) {
            m_Window->OnUpdate();
        }
    }

    void Application::OnWindowClose() {
        m_Running = false;
    }

    void Application::OnWindowResize(const int width, const int height) {
        // TODO: Move to Framebuffer
        glViewport(0, 0, width, height);
    }

    Window* Application::GetWindow() const {
        return m_Window;
    }
}
