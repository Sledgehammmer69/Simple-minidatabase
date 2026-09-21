CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = database
OBJ = main.o candidate.o

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

main.o: src/main.c include/candidate.h
	$(CC) $(CFLAGS) -c $< -o $@

candidate.o: src/candidate.c include/candidate.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(TARGET) $(OBJ)