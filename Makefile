CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = build/database
OBJ = build/main.o build/candidate.o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

build/%.o: src/%.c include/candidate.h | build
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

build:
	mkdir -p build

clean:
	rm -rf build

-include $(OBJ:.o=.d)