CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = database
OBJ = main.o candidate.o

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o main.o

candidate.o: src/candidate.c
	$(CC) $(CFLAGS) -c src/candidate.c -o candidate.o

.PHONY: clean

clean:
	rm -f $(TARGET) $(OBJ)