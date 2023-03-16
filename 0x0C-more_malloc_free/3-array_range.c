#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers.
 * @min: value.
 * @max: value.
 *
 * Return: pointer or NULL.
 */
int *array_range(int min, int max)
{
	int *arr, m, size;

	if (min > max)
	{
		return (NULL);
	}

	size = max - min + 1;

	arr = (int *) malloc(sizeof(int) * size);

	if (arr == NULL)
	{
		return (NULL);
	}

	for (m = 0; m < size; m++)
	{
		arr[m] = min + m;
	}

	return (arr);
}

