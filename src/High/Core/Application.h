#pragma once
#include "Window.h"

namespace High::Core {
    class Application final {
    public:
        Application();
        ~Application();
        void Run() const;

        void OnWindowClose();
        void OnWindowResize(const int width, const int height);

        [[nodiscard]] Window* GetWindow() const;
        [[nodiscard]] static Application *GetInstance();
    private:
        static Application *s_Instance;
        Window* m_Window;
        bool m_Running = true;
    };
}
