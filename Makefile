CC ?= clang
CFLAGS ?= -Wall -Wextra -pedantic -std=c11
SRC := src/search_test.c
BIN_DIR := build
BIN := $(BIN_DIR)/search_test

.PHONY: all run clean

all: $(BIN)

$(BIN): $(SRC)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN) $(SRC)

run: $(BIN)
	./$(BIN)

clean:
	rm -rf $(BIN_DIR)
