#include "main.h"

/**
 * print_number - a function that prints an integer.
 * @n: the integer to print
 *
 * Return: the integer.
 */
void print_number(int n)
{
	unsigned int u;

	if (n < 0)
	{
		_putchar('-');
		u = -n;
	}
	if (u / 10 != 0)
	{
		print_number(u / 10);
	}
	_putchar('0' + u % 10);
}
