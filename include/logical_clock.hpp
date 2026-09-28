#pragma once

#include <string>
#include <vector>

// Common interface used by the simulation. Each implementation must update
// its state for internal, send, and receive events.
class LogicalClock {
public:
    virtual ~LogicalClock() = default;

    virtual void on_internal_event() = 0;
    virtual void on_send_event() = 0;
    virtual void on_receive_event(const std::vector<int>& remote_timestamp) = 0;

    virtual std::vector<int> timestamp() const = 0;
    virtual std::string to_string() const = 0;
};

