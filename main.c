#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "tree.h"

static void my_putstr(int fd, char *s)
{
	write(fd, s, strlen(s));
}

static void my_put_err(char *s)
{
	my_putstr(2, s);
	my_putstr(2, "\n");
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		my_put_err("Please enter the size");
		return 84;
	}

	tree(atoi(argv[1]));
}
