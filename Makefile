# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -I./src/include -Wall -Wextra -O3 -DMAP

# Directories
SRC_DIR = src/lib
INC_DIR = src/include
BUILD_DIR = build
BIN_DIR = bin
TEST_DIR = tests

# Source and test files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)

# Object files for main program and tests
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
TEST_OBJ_FILES = $(TEST_FILES:$(TEST_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Executable names
TARGET = $(BIN_DIR)/main
TEST_TARGET = $(BIN_DIR)/test

# Rules
all: $(TARGET)

# Link all object files with main.o to create the main executable
$(TARGET): $(OBJ_FILES) $(BUILD_DIR)/main.o
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp files from src/lib into .o files in build directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile main.cpp into main.o
$(BUILD_DIR)/main.o: src/main.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile and link all test files into a test executable
test: $(OBJ_FILES) $(TEST_OBJ_FILES)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $^
	./$(TEST_TARGET)

# Compile .cpp files from tests into .o files in build directory
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean test