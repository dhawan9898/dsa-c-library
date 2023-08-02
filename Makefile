CC = gcc
CFLAGS = -Wall -Werror -std=c99 -Iinclude

.PHONY: all clean

all: test_array array_example

test_array: tests/test_array.c src/array.c
	$(CC) $(CFLAGS) -o test_array tests/test_array.c src/array.c

array_example: examples/array_example.c src/array.c
	$(CC) $(CFLAGS) -o array_example examples/array_example.c src/array.c

clean:
	rm -f test_array array_example
