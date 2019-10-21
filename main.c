#include <stdlib.h>

#include "tree.h"

int main(int argc, char **argv)
{
	if (argc != 2) {
		my_put_err("Please enter the size");
		return 84;
	}

	tree(atoi(argv[1]));
}
