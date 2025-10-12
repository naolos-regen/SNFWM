CC               = gcc
CFLAGS           = -Wall -Wextra -I./include
CLIBS            = -lX11
CTEST_LIBS       = -lX11 -lcriterion
DEBUG_FLAGS      = -g -DDEBUG
RELEASE_FLAGS    = -O2

SRC_DIR          = src
TEST_DIR         = test
INCLUDE_DIR      = include
BIN_DIR          = bin
OBJ_DIR          = obj

MAIN_SRC         = $(SRC_DIR)/main.c
SRCS             = $(wildcard $(SRC_DIR)/*.c) \
                   $(wildcard $(SRC_DIR)/logger/*.c) \
		   $(wildcard $(SRC_DIR)/linkedlist/*.c) \
                   $(wildcard $(SRC_DIR)/x11_helpers/*.c) \
		   $(wildcard $(SRC_DIR)/x11_events/*c) \
		   $(wildcard $(SRC_DIR)/x11_events/jobs/*.c) \
		   $(wildcard $(SRC_DIR)/x11_events/events/*c)

OBJS             = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

EXECUTABLE       = snfwm
TEST_EXECUTABLE  = run_tests

# Recursively find all .c test files in test directory
TEST_SRCS        := $(shell find $(TEST_DIR) -name '*.c')
TEST_SRCS        := $(filter-out $(SRC_DIR)/main.c,$(TEST_SRCS))

all : debug

$(OBJ_DIR) $(BIN_DIR):
	@mkdir -p $@
	@mkdir -p $(OBJ_DIR)/logger
	@mkdir -p $(OBJ_DIR)/x11_helpers

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(CLIBS)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(BIN_DIR)/$(EXECUTABLE)

release: CFLAGS += $(RELEASE_FLAGS)
release: $(BIN_DIR)/$(EXECUTABLE)

$(BIN_DIR)/$(EXECUTABLE): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(CLIBS)

test: $(BIN_DIR)/$(TEST_EXECUTABLE)

$(BIN_DIR)/$(TEST_EXECUTABLE): $(SRCS) $(TEST_SRCS) | $(BIN_DIR)
	@if [ -z "$(TEST_SRCS)" ]; then \
		echo "No test files found in $(TEST_DIR)."; \
		exit 1; \
	fi
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) \
		-I./include \
		$(filter-out $(SRC_DIR)/main.c,$(SRCS)) \
		$(TEST_SRCS) \
		-o $@ \
		$(CTEST_LIBS)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

run: debug
	./runner.sh

run-test: test
	./$(BIN_DIR)/$(TEST_EXECUTABLE)

.PHONY: all debug release test clean run run-test
