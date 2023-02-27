#include <stdio.h>
#include "main.h"

/**
 * print_array - print elements of an array of integers
 * @a: array to be printed
 * @n: numbers of elements to be printed
 */
void print_array(int *a, int n)
{
	int m;

	for (m = 0; m < n; m++)
	{
		if (m == 0)
			printf("%d", a[m]);
		else
			printf(", %d", a[m]);
	}
	printf("\n");
}
