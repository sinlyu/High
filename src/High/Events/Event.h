#pragma once

namespace High::Events {
    enum class EventType
    {
        None = 0,
        WindowResize,
    };

    class Event {
    public:
        virtual ~Event() = default;

        bool Handled = false;
        [[nodiscard]] virtual EventType GetEventType() const = 0;
    };
}