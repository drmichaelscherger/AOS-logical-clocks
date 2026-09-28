#pragma once

#include <vector>

enum class EventType { Internal, Send, Receive };

// A simple in-memory representation. Students must decide how to serialize
// the timestamp for MPI_Send/MPI_Recv (or use two MPI messages).
struct Message {
    int sender = -1;
    int sequence = 0;
    std::vector<int> timestamp;
};

