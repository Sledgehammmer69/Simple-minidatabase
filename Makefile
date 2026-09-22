CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = database
OBJ = main.o candidate.o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: src/%.c include/candidate.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)