#include <unistd.h>

#include "my_putchar.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}
