#pragma once

#include "Event.h"

namespace High::Events {
    class WindowResizeEvent final : public Event
    {
    public:
        WindowResizeEvent(const int width, const int height)
            : m_Width(width), m_Height(height) {}

        [[nodiscard]] int GetWidth() const { return m_Width; }
        [[nodiscard]] int GetHeight() const { return m_Height; }

        [[nodiscard]] EventType GetEventType() const override { return EventType::WindowResize; }

    private:
        int m_Width;
        int m_Height;
    };
}

