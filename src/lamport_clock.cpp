#include "lamport_clock.hpp"

#include <sstream>

LamportClock::LamportClock(int process_id) : process_id_(process_id) {}

void LamportClock::on_internal_event() {
    // TODO: Apply the Lamport rule for a local event.
}

void LamportClock::on_send_event() {
    // TODO: Apply the Lamport rule before attaching a timestamp to a message.
}

void LamportClock::on_receive_event(const std::vector<int>& remote_timestamp) {
    // TODO: Validate the timestamp and apply the Lamport receive rule.
    (void)remote_timestamp;
}

std::vector<int> LamportClock::timestamp() const {
    return {time_};
}

std::string LamportClock::to_string() const {
    std::ostringstream out;
    out << time_;
    return out.str();
}

