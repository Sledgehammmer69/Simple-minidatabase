CC = gcc

DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O2

DEBUG_DIR = build/debug
RELEASE_DIR = build/release

DEBUG_TARGET = $(DEBUG_DIR)/database
RELEASE_TARGET = $(RELEASE_DIR)/database

DEBUG_OBJ = $(SRC:src/%.c=$(DEBUG_DIR)/%.o)
RELEASE_OBJ = $(SRC:src/%.c=$(RELEASE_DIR)/%.o)

CPPFLAGS = -Iinclude
CFLAGS = -Wall -Wextra

LDFLAGS =
LDLIBS =

TARGET = build/database
SRC = src/main.c src/candidate.c
OBJ = $(SRC:src/%.c=build/%.o)

.PHONY: all debug release clean

all: $(TARGET)
debug: $(DEBUG_TARGET)
release: $(RELEASE_TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@ $(LDLIBS)

$(DEBUG_TARGET): $(DEBUG_OBJ)
	$(CC) $(LDFLAGS) $(DEBUG_OBJ) -o $@ $(LDLIBS)

$(RELEASE_TARGET): $(RELEASE_OBJ)
	$(CC) $(LDFLAGS) $(RELEASE_OBJ) -o $@ $(LDLIBS)

build/%.o: src/%.c include/candidate.h | build
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

build/debug/%.o: src/%.c include/candidate.h | build/debug
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEBUG_FLAGS) -MMD -MP -c $< -o $@

build/release/%.o: src/%.c include/candidate.h | build/release
	$(CC) $(CPPFLAGS) $(CFLAGS) $(RELEASE_FLAGS) -MMD -MP -c $< -o $@


build:
	mkdir -p build

build/debug:
	mkdir -p build/debug

build/release:
	mkdir -p build/release

clean:
	rm -rf build

-include $(OBJ:.o=.d) $(DEBUG_OBJ:.o=.d) $(RELEASE_OBJ:.o=.d)