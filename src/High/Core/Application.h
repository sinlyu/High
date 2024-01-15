#pragma once
#include "Window.h"

namespace High::Core {
    class Application final {
    public:
        Application();
        ~Application();
        void Run() const;

        void OnWindowClose();
        void OnWindowResize(int width, int height);

        [[nodiscard]] Window* GetWindow() const;
        [[nodiscard]] static Application *GetInstance();
    private:
        static Application *s_Instance;
        Window* m_Window;
        bool m_Running = true;
    };
}
