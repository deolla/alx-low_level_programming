#include "main.h"

/**
 * int print_sign(int n) - prints the sign of a number.
 * @n: the sign of a number 
 * Return : 1 if n is greater than 0, 0 if n is zero, -1 if n is less than zero
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar(48);
		return (0);
	}
	else (n < 0)
	{
		_putchar('-');
	}
		return (-1);
}
