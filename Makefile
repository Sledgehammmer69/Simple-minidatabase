CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = database
OBJ = main.o candidate.o

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: src/%.c include/candidate.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(TARGET) $(OBJ)