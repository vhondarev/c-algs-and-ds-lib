# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -g -DDEBUG -D_ASSERT_H

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
TEST_BUILD_DIR = $(BUILD_DIR)/tests

# Find all source files (excluding test files)
SRC_FILES = $(shell find $(SRC_DIR) -name "*.c" -not -name "*.test.c")
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Find all test files
TEST_FILES = $(shell find $(SRC_DIR) -name "*.test.c")
TEST_BINS = $(patsubst $(SRC_DIR)/%.test.c,$(TEST_BUILD_DIR)/%.test,$(TEST_FILES))

# Include main.c from root directory
MAIN_OBJ = $(BUILD_DIR)/main.o
TARGET = $(BIN_DIR)/algds
TARGET_RELEASE = $(BIN_DIR)/algds-release

# Ensure build directories exist
$(shell mkdir -p $(BUILD_DIR) $(BIN_DIR) $(TEST_BUILD_DIR) $(dir $(OBJ_FILES)))

# Default target - debug build
all: build

# Build target (debug mode by default)
build: $(TARGET)

$(TARGET): $(MAIN_OBJ) $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Release build target (no debug, optimized)
release: clean-objects $(TARGET_RELEASE)

$(TARGET_RELEASE): CFLAGS += -O2 -DNDEBUG
$(TARGET_RELEASE): CFLAGS := $(filter-out -DDEBUG -D_ASSERT_H,$(CFLAGS))
$(TARGET_RELEASE): $(MAIN_OBJ) $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Helper target to ensure clean build for release
clean-objects:
	rm -f $(MAIN_OBJ) $(OBJ_FILES)

$(MAIN_OBJ): main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Test targets
test: build $(TEST_BINS)
	@echo "--------------------"
	@echo "Running all tests..."
	@echo "--------------------"
	@for test in $(TEST_BINS); do \
		echo "\nRunning $${test}...\n"; \
		$${test} || exit 1; \
	done
	@echo ""
	@echo "--------------------"
	@echo "All tests passed!"
	@echo "--------------------"

$(TEST_BUILD_DIR)/%.test: $(SRC_DIR)/%.test.c $(OBJ_FILES)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $< $(filter-out $(MAIN_OBJ), $(OBJ_FILES))

# Run target (debug mode by default)
run: build
	./$(TARGET)

# Run release target
run-release: release
	./$(TARGET_RELEASE)

# Format target (using clang-format)
format:
	find . -name "*.c" -o -name "*.h" | xargs clang-format -i -style=file

# Clean target
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all build release clean-objects run run-release format clean test
