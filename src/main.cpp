#include "lamport_clock.hpp"
#include "logical_clock.hpp"
#include "vector_clock.hpp"

#include <mpi.h>

#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <sstring>

namespace {

struct Options {
    std::string clock = "lamport";
    int events = 10;
};

Options parse_options(int argc, char** argv) {
    Options options;
    for (int i = 1; i < argc; ++i) {
        const std::string arg = argv[i];
        if (arg == "--clock" && i + 1 < argc) 
            options.clock = argv[++i];
        else if (arg == "--events" && i + 1 < argc) 
            options.events = std::atoi(argv[++i]);
    }
    return options;
}

}  // namespace

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank = 0;
    int process_count = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &process_count);

    const Options options = parse_options(argc, argv);
    std::unique_ptr<LogicalClock> clock;
    if (options.clock == "lamport") {
        clock = std::make_unique<LamportClock>(rank);
    } 
    else if (options.clock == "vector") {
        clock = std::make_unique<VectorClock>(rank, process_count);
    } 
    else {
        if (rank == 0) std::cerr << "Clock must be 'lamport' or 'vector'.\n";
        MPI_Finalize();
        return 1;
    }

    std::ostringstream outstr;
    outstr << "Process " << rank << '/' << process_count
              << " ready with clock " << clock->to_string() << '\n';
    std::cout << outstr.str();

    // TODO: Implement a finite event loop with internal, send, and receive events.
    // TODO: Choose destinations without sending to self.
    // TODO: Ensure receives cannot deadlock; consider MPI_Iprobe or nonblocking I/O.
    // TODO: Put the sender's logical timestamp in every application message.
    // TODO: Log event type, peer, sequence number, and clock after every event.
    (void)options.events;

    MPI_Finalize();
    return 0;
}

