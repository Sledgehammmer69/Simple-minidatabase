CC = gcc
CPPFLAGS = -Iinclude
CFLAGS = -Wall -Wextra
LDFLAGS =
LDLIBS =

TARGET = build/database
SRC = src/main.c src/candidate.c
OBJ = $(SRC:src/%.c=build/%.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@ $(LDLIBS)

build/%.o: src/%.c include/candidate.h | build
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

build:
	mkdir -p build

clean:
	rm -rf build

-include $(OBJ:.o=.d)