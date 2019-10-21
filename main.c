#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "tree.h"

static bool isnumber(char *s)
{
	while (*s != '\0') {
		if (!isdigit(*s))
			return false;
		s++;
	}

	return true;
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		my_put_err("Only one argument required: the size");
		return 84;
	}

	if (!isnumber(argv[1])) {
		my_put_err("Argument should be a digit");
		return 84;
	}

	tree(atoi(argv[1]));
}
