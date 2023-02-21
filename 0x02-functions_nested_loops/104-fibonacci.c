#include <stdio.h>
#include "main.h"
/**
 * main - Prints the first 98 Fibonacci numbers, starting with
 *        1 and 2, separated by a comma followed by a space.
 *
 * Return: Always 0.
 */

int main(void)
{
	int cnt;
	unsigned long fib = 0, fib1 = 1, sum;
	unsigned long fib_half1, fib_half2, fib1_half1, fib1_half2;
	unsigned long half1, half2;

	for (cnt = 0; cnt < 92; cnt++)
	{
		sum = fib + fib1;
		printf("%lu, ", sum);
		fib = fib1;
		fib1 = sum;
	}
	fib_half1 = fib / 10000000000;
	fib1_half1 = fib1 / 10000000000;
	fib_half2 = fib % 10000000000;
	fib1_half2 = fib1 % 10000000000;

	for (cnt = 93; cnt < 99; cnt++)
	{
		half1 = fib_half1 + fib1_half1;
		half2 = fib_half2 + fib1_half2;
		if (fib_half2 + fib1_half2 > 9999999999)
		{
			half1 += 1;
			half2 %= 10000000000;
		}
		printf("%lu%lu", half1, half2);
		if (cnt != 98)
			printf(", ");

		fib_half1 = fib1_half1;
		fib_half2 = fib1_half2;
		fib1_half1 = half1;
		fib1_half2 = half2;
	}

	printf("\n");

	return (0);
}
