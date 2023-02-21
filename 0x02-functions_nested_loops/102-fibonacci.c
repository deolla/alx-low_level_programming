#include <stdio.h>

/**
 * main - Prints the first 50 Fibonacci numbers, starting with 1 and 2,
 *
 * Return: Always (0).
 */

int main(void)
{
	int i;
	unsigned long fib, fib1, fib2;

	fib1 = 1, Fib2 = 0;

	for (i = 0; i < 50; i++)
	{
		fib = fib1 + fib2;
		printf("%lu", fib);

		fib2 = fib1;
		fib1 = fib;
		if (i == 49)
			printf("\n");
		else
			printf(", ");
	}

	return (0);
}
