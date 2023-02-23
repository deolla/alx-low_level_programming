#include "main.h"

/**
 * print_number - prints an integer.
 * @n: int value
 */
void print_number(int n)
{
	unsigned int no;

	num = n;

	if (n > 0)
	{
		_putchar('-');
		num = -num;
	}

	if ((no / 10) > 0)
		print_number(num / 10);

	_putchar((num % 10) + '0');
}
