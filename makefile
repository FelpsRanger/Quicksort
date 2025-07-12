CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = quicksort_seminar
SOURCE = quicksort_seminar.c

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
