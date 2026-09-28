CXX := mpicxx
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Iinclude
LDFLAGS :=

TARGET := bin/logical_clocks
SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(patsubst src/%.cpp,build/%.o,$(SOURCES))

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS) | bin
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

build bin:
	mkdir -p $@

run: $(TARGET)
	mpirun -np 4 ./$(TARGET) --clock lamport --events 10

clean:
	rm -rf build bin

