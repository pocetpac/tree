CC=gcc
CFLAGS=-Wall -Wextra -Wmissing-prototypes
objects=main.o tree.o my_putchar.o

.PHONY: all clean

all: a.out
	./a.out | echo -n
	./a.out 2

a.out: $(objects)
	$(CC) -o a.out $(objects)

main.o: tree.h
tree.o: tree.h my_putchar.h
my_putchar.o: my_putchar.h

clean:
	rm -f a.out $(objects)
