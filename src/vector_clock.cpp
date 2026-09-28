#include "vector_clock.hpp"

#include <sstream>

VectorClock::VectorClock(int process_id, int process_count)
    : process_id_(process_id), time_(static_cast<std::size_t>(process_count), 0) {}

void VectorClock::on_internal_event() {
    // TODO: Update the component belonging to this process.
}

void VectorClock::on_send_event() {
    // TODO: Update the local component before sending the vector.
}

void VectorClock::on_receive_event(const std::vector<int>& remote_timestamp) {
    // TODO: Validate sizes, merge both vectors, and record the receive event.
    (void)remote_timestamp;
}

std::vector<int> VectorClock::timestamp() const {
    return time_;
}

std::string VectorClock::to_string() const {
    std::ostringstream out;
    out << '[';
    for (std::size_t i = 0; i < time_.size(); ++i) {
        if (i != 0) out << ',';
        out << time_[i];
    }
    out << ']';
    return out.str();
}

