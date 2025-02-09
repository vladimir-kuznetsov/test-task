# Makefile for C++17 project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Source files
SOURCES = Test_task.cpp

# Header files (not directly used in the Makefile, but included in the source)
HEADERS = list.hpp abstract.hpp

# Output executable
TARGET = Test_task

# Build target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Clean target to remove compiled files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean