#pragma once
#include <string>
#include <utility>

#include "Base.h"
#include "../OpenGL/Context.h"

namespace High::Core
{
    struct WindowProps {
        std::string Title;
        int Width;
        int Height;

        explicit WindowProps(std::string title = "High Engine",
                             const int width = 1280,
                             const int height = 720)
            : Title(std::move(title)), Width(width), Height(height) {}
    };

    class Window
    {
    public:
        Window(const std::string& title, int width, int height);
        [[nodiscard]] GLFWwindow* GetNativeWindow() const;
        static Window* Create(const WindowProps& props = WindowProps());

        [[nodiscard]] int GetWidth() const;
        [[nodiscard]] int GetHeight() const;

        void OnUpdate() const;

    private:
        static void Init();
    private:
        GLFWwindow* m_Window;
        int m_Width;
        int m_Height;
        std::string m_Title;
        OpenGL::Context* m_Context;
    };
}
