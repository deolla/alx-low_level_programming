#include <stddef.h>
#include "function_pointers.h"

/**
 * int_index - searches for an integer.
 * @size: number of elements in the array.
 * @array: array.
 * @cmp: a pointer to the function.
 *
 * Return: first element or -1.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int m;

	if (size <= 0)
	{
		return (-1);
	}
	if (array && cmp)
	{
		for (m = 0; m < size; m++)
		{
			cmp(array[m]);
			if (cmp(array[m]) == 1)
			{
				return (m);
			}
		}
	}

	return (-1);
}
