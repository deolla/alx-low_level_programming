#include "main.h"

/**
 * print_line - prints straight line n times.
 * @n: times straight line is printed.
 * Return: no return.i
 */
void print_line(int n);
{
	int times;

	for (times = 0; times < n; times++)
	{
		_putchar('_');
	}
	_putchar('\n');
}
