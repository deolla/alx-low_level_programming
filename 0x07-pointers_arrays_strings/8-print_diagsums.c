#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - a function that prints the sum of the
 * two diagonals of a square matrix of integers.
 * @a: pointer
 * @size: size of the matrix
 */
void print_diagsums(int *a, int size)
{
	int m, sum1 = 0, sum2 = 0;

	for (m = 0; m < size; m++)
	{
		sum1 += *(a + m * size + m);
		sum2 += *(a + m * size + size - 1 - m);
	}
	printf("Sum of the first diagonal = %d\n", sum1);
	printf("Sum of the second diagonal = %d\n", sum2);
}
