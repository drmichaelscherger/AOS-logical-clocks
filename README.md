# MPI Logical Clocks

Starter project for Advanced Operating Systems assignment on logical time in distributed systems. Students will complete an MPI-based simulation in C++17 and implement both Lamport scalar clocks and vector clocks.

## Learning objectives

By completing this assignment, you should be able to:

- apply clock-update rules to internal, send, and receive events;
- attach logical timestamps to MPI messages;
- explain causal ordering, concurrency, and the limits of Lamport clocks; and
- design a distributed program that terminates without deadlock.

## Prerequisites

Use a Linux system with a C++17 compiler and an MPI implementation.  Our servers will meet this requirement.

## Build and run

```bash
make
mpirun -np 4 ./bin/logical_clocks --clock lamport --events 10
mpirun -np 4 ./bin/logical_clocks --clock vector --events 10
```

## Assignment requirements

Complete the TODOs so that each MPI rank represents one process in a distributed system. Every process must produce a finite mixture of:

1. **Internal events** that do not communicate with another rank.
2. **Send events** that transmit an application message to another rank.
3. **Receive events** that incorporate the timestamp carried by a message.

Your program must:

- support both `--clock lamport` and `--clock vector`;
- update the selected clock on every internal, send, and receive event;
- transmit the complete logical timestamp with every application message;
- avoid self-sends and communication deadlock;
- log rank, event number/type, peer (when applicable), and resulting timestamp;
- validate command-line arguments and received timestamp sizes;
- terminate all ranks cleanly after the requested workload; and
- behave correctly with at least 2, 4, and 8 MPI processes.  Maximum number of processes is 10.

Use a reproducible pseudo-random seed or a deterministic event schedule so runs can be diagnosed. Do not infer correctness from output order alone: output from different ranks can be interleaved by the runtime.

## Suggested milestones

1. Implement and test each clock class without MPI communication.
2. Add deterministic point-to-point messages between two ranks.
3. Generalize the event loop to several ranks and mixed event types.
4. Add termination coordination and check for deadlock.
5. Analyze selected events for causal ordering or concurrency.

## Design questions for the report

- If event A has a smaller Lamport timestamp than event B, must A cause B?
- How can vector timestamps identify concurrent events?
- What invariant should hold for a process's own vector-clock component?
- What MPI design choices prevent unmatched sends or receives at termination?

## Project layout

```text
include/   Clock interfaces and message types
src/       MPI driver and clock implementation stubs
Makefile   Build and convenience run targets
```

## Academic integrity note

The starter intentionally omits the clock algorithms and event loop. Your submission should explain your design and reflect your own implementation.

## Cleaning

```bash
make clean
```

