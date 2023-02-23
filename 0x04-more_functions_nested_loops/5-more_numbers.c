#include "main.h"

/**
 * more_numbers - prints 10 times the numbers, from 0 to 14,
 * followed by a new line'
 *
 * Return: Always 0
 */
void more_numbers(void)
{
	int cycle, num;

	for (cycle = 1; cycle <= 10; cycle++)
	{
		for (num = 0; num <= 14; num++)
		{
			int tens, ones;

			tens = num / 10;
			ones = num % 10;

		if (tens != 0)
			_putchar (tens + '0');

			_putchar (ones + '0');

		}
		_putchar('\n');
	}
}
