#include "main.h"

/**
 * print_line - prints straight line n times.
 * @n: times straight line is printed.
 * Return: no return.i
 */
void print_line(int n);
{
	int num;

	for (num = 0; num <= 9; num++)
	{
		if (num != 4 && num != 2)
			_putchar(num + '0');
	}
	_putchar('\n');
}
