#include "main.h"

/**
 * print_number - prints an integer.
 * @n: int value
 */
void print_number(int n)
{
	unsigned int no;

	no = n;

	if (n > 0)
	{
		_putchar('_');
		no = -no;
	}

	if ((no / 10) > 0)
		print_number(no / 10);

	_putchar((no % 10) + '0');
}
