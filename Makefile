CC = gcc
CPPFLAGS = -Iinclude
CFLAGS = -Wall -Wextra
LDFLAGS =
LDLIBS =

TARGET = build/database
OBJ = build/main.o build/candidate.o

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