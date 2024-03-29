#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "my_putchar.h"
#include "tree.h"

static int last_line(int size)
{
	int jump;
	int lastline;

	lastline = 7;
	jump = 6;

	for (int i = 1; i < size; i++) {
		if ((i % 2) != 0) {
			lastline += jump;
		} else if (i !=  1) {
			jump += 2;
			lastline += jump;
		}
	}

	return lastline;
}

static int first_line(int size)
{
	int jump;
	int firstline;

	firstline = 1;
	jump = 4;

	for (int i = 1; i < size; i++) {
		if ((i % 2) != 0) {
			firstline += jump;
		} else if (i !=  1) {
			jump += 2;
			firstline += jump;
		}
	}

	return (firstline);
}


static void draw_tronc(int size)
{
	int blank;
	int largeur_tronc;
	int hauteur_tronc;

	if ((size % 2) != 0)
		largeur_tronc = size;
	else
		largeur_tronc = size + 1;

	hauteur_tronc = size;
	blank = (last_line(size) / 2) - (largeur_tronc / 2);

	for (int i = 0; i < hauteur_tronc; i++) {
		for (int j = 0; j < blank; j++)
			my_putchar(' ');
		for (int j = 0; j < largeur_tronc; j++)
			my_putchar('|');
		my_putchar('\n');
	}
}


static void draw(int num, int size)
{
	int blank;
	int stars;
	int hauteur_branche;

	blank = last_line(size) / 2 - first_line(num) / 2;
	stars = first_line(num) - 1;
	hauteur_branche = num + 3;

	for (int i = 0; i < hauteur_branche; i++) {
		for (int j = 0; j < blank; j++)
			my_putchar(' ');
		for (int j = 0; j < stars; j++)
			my_putchar('*');

		blank--;
		stars += 2;
		my_putchar('*');
		my_putchar('\n');
	}
}


static void my_putstr(int fd, char *s)
{
	write(fd, s, strlen(s));
}

void my_put_err(char *s)
{
	my_putstr(2, s);
	my_putstr(2, "\n");
}

void tree(int size)
{
	if (size < 0) {
		my_put_err("Size should be > 0");
		exit(84);
	}

	if (size == 0)
		return;

	for (int i = 1; i <= size; i++)
		draw(i, size);

	draw_tronc(size);
}
