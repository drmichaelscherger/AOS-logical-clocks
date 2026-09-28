#pragma once

#include "logical_clock.hpp"

#include <vector>

class VectorClock final : public LogicalClock {
public:
    VectorClock(int process_id, int process_count);

    void on_internal_event() override;
    void on_send_event() override;
    void on_receive_event(const std::vector<int>& remote_timestamp) override;

    std::vector<int> timestamp() const override;
    std::string to_string() const override;

private:
    int process_id_;
    std::vector<int> time_;
};

