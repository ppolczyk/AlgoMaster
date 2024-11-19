# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I$(INCLUDE_DIR)   # C++17, includes headers from include/

# Directories
INCLUDE_DIR = ./include
SRC_DIR = ./src
TEST_DIR = ./tests
BUILD_DIR = ./build

# Files
TESTS = $(wildcard $(TEST_DIR)/*.cpp)                 # Automatically includes all test files
VECTOR_SRC = $(wildcard $(SRC_DIR)/*.cpp)             # All source files in src/
VECTOR_HDR = $(wildcard $(INCLUDE_DIR)/*.h)           # All headers in include/

# Google Test library path (replace with your actual location if different)
GTEST_LIB = -lgtest -lgtest_main -pthread             # Google Test linking

# Output
TARGET_TEST = $(BUILD_DIR)/runTests                   # Executable name for tests

# Default target: Build and run tests
all: $(TARGET_TEST)
	./$(TARGET_TEST)

# Compile the tests executable
$(TARGET_TEST): $(TESTS) $(VECTOR_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(TESTS) $(VECTOR_SRC) $(GTEST_LIB) -o $(TARGET_TEST)

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean the build directory
clean:
	rm -rf $(BUILD_DIR)/*
