#include "main.h"

/**
 * swap_int - swaps the values of two integers.
 * @a: Variable of int.
 * @b: Variable of int
 *
 * Return: Always 0.
 */
void swap_int(int *a, int *b)
{
	int i;

	i = *a;
	*a = *b;
	*b = i;
}
