# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -g -DDEBUG -D_ASSERT_H
LDFLAGS =  # Add additional linker flags here if needed

# Enable parallel builds (use available CPU cores)
MAKEFLAGS += -j$(shell nproc 2>/dev/null || echo 4)

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
TEST_BUILD_DIR = $(BIN_DIR)/tests

# Library directories and files
LIB_DIR = $(BIN_DIR)/lib
LIB_INCLUDE_DIR = $(LIB_DIR)/include
LIB_STATIC = $(LIB_DIR)/libalgds.a

# Header files - found once and cached
PUBLIC_HEADERS := $(shell find $(SRC_DIR) -name "*.h")
COPIED_HEADERS := $(addprefix $(LIB_INCLUDE_DIR)/,$(notdir $(PUBLIC_HEADERS)))

# Source and object files - found once and cached
SRC_FILES := $(shell find $(SRC_DIR) -name "*.c" -not -name "*.test.c")
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Test files - found once and cached
TEST_FILES := $(shell find $(SRC_DIR) -name "*.test.c")
TEST_BINS := $(patsubst $(SRC_DIR)/%.test.c,$(TEST_BUILD_DIR)/%.test,$(TEST_FILES))

# Create required directories
$(shell mkdir -p $(BUILD_DIR) $(BIN_DIR) $(TEST_BUILD_DIR) $(LIB_DIR) $(LIB_INCLUDE_DIR) $(sort $(dir $(OBJ_FILES))))

# Define all phony targets at once
.PHONY: all lib test format clean help check install uninstall

# Default target
all: help

# Special rule for copying headers with flattening directory structure
copy-headers:
	@mkdir -p $(LIB_INCLUDE_DIR)
	@find $(SRC_DIR) -name "*.h" -exec cp {} $(LIB_INCLUDE_DIR)/ \;

# Build static library
lib: $(LIB_STATIC) copy-headers

# Include generated dependencies
-include $(OBJ_FILES:.o=.d)

# Compile object files from src/ with automatic dependency generation
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# Create static library from object files
$(LIB_STATIC): $(OBJ_FILES)
	ar rcs $@ $^

# Copy header files to include directory (flattened structure)
$(LIB_INCLUDE_DIR)/%: $(SRC_DIR)/**/%
	@mkdir -p $(dir $@)
	cp $< $@

# Handle headers in the root src directory
$(LIB_INCLUDE_DIR)/%: $(SRC_DIR)/%
	@mkdir -p $(dir $@)
	cp $< $@

# Build and run all tests
test: $(TEST_BINS)
	@echo "--------------------"
	@echo "Running all tests..."
	@echo "--------------------"
	@echo
	@for test in $(TEST_BINS); do \
		echo "Running $${test}..."; \
		if ! $${test}; then \
			echo "\nTest failed: $${test}"; \
			exit 1; \
		fi; \
		echo; \
	done
	@echo "--------------------"
	@echo "All tests passed!"
	@echo "--------------------"

# Build test binaries using object files directly (not static library)
# This allows tests to access internal functions
$(TEST_BUILD_DIR)/%.test: $(SRC_DIR)/%.test.c $(OBJ_FILES)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $< $(filter-out $(BUILD_DIR)/main.o,$(OBJ_FILES))

# Format source code with clang-format
format:
	find $(SRC_DIR) -name "*.c" -o -name "*.h" | xargs clang-format -i -style=file

# TODO
# Static code analysis and linting
check:
	@echo "Running static code analysis"
	@# Add your preferred static analysis tools here
	@# Example: cppcheck --enable=all $(SRC_DIR)
	@echo "Static analysis completed"

# Install the library and headers to system directories
install: lib
	@echo "Installation placeholder"
	@# mkdir -p $(DESTDIR)/usr/local/lib $(DESTDIR)/usr/local/include/algds
	@# cp $(LIB_STATIC) $(DESTDIR)/usr/local/lib/
	@# cp -r $(LIB_INCLUDE_DIR)/* $(DESTDIR)/usr/local/include/algds/
	@echo "Installation would copy library to /usr/local/lib and headers to /usr/local/include/algds"

# Uninstall the library and headers
uninstall:
	@echo "Uninstallation placeholder"
	@# rm -f $(DESTDIR)/usr/local/lib/libalgds.a
	@# rm -rf $(DESTDIR)/usr/local/include/algds
	@echo "Uninstallation would remove library from /usr/local/lib and headers from /usr/local/include/algds"

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Help target
help:
	@echo "Available targets:"
	@echo "  lib              - Build static library and copy all headers to build/lib/include"
	@echo "  test             - Compile and run all unit tests in the project"
	@echo "  format           - Format all .c and .h files using clang-format"
	@echo "  check            - Run static code analysis and linting tools"
	@echo "  install          - Install the library and headers (placeholder)"
	@echo "  uninstall        - Remove installed library and headers (placeholder)"
	@echo "  clean            - Remove all build and binary files"
	@echo "  help             - Show this help message"
