# Variables
CXX = clang++
CXXFLAGS = -std=c++17 -stdlib=libc++ -g -fsanitize=address
SOURCE = ./main.cpp
OUTPUT = ./main

# Default target
all: debug

# Debugging build target
debug:
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(OUTPUT)

# Leak test target
leaks:
	leaks -atExit --list -- ./main > ./leaks.txt

# Clean target to remove generated files
clean:
	rm -f $(OUTPUT) ./leaks.txt

.PHONY: all debug leaks clean

