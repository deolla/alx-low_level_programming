#include "main.h"

/**
 * print_line - draws a straight line in the terminal.
 * @n: value
 *
 * Return: Always 0
 */
void print_line(int n)
{
	int print;

	for (print = 0; print < n; print++)
	{
		_putchar('_');
	}
	_putchar('\n');
}
