# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Output executable name
TARGET = TaskForge

# Automatically gather all .cpp files and generate matching .o targets
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Link executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run program through Valgrind memory leak checker
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

# Remove built files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all valgrind clean
