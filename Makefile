# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

# File names
HEADERS = list.hpp
SOURCES = list.cpp unit_test_cases.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXEC = final_program

# Target to build the executable
$(EXEC): $(OBJECTS)
	@echo "Linking object files..."
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)

# Compile the .cpp files into .o object files
%.o: %.cpp $(HEADERS)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	@echo "Cleaning up..."
	rm -f $(OBJECTS) $(EXEC)

# Run the tests
run: $(EXEC)
	@echo "Running tests..."
	./$(EXEC)

# Rebuild everything
rebuild: clean $(EXEC)

# Default target to build the executable
all: $(EXEC)
