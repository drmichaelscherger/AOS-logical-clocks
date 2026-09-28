#pragma once

#include "logical_clock.hpp"

class LamportClock final : public LogicalClock {
public:
    explicit LamportClock(int process_id);

    void on_internal_event() override;
    void on_send_event() override;
    void on_receive_event(const std::vector<int>& remote_timestamp) override;

    std::vector<int> timestamp() const override;
    std::string to_string() const override;

private:
    int process_id_;
    int time_ = 0;
};

