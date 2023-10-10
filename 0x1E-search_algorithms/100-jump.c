#include "search_algos.h"

/**
 * jump - searches for a value in a sorted array of integers.
 * array: pointer to the first element of the array to search.
 * size: number of elements in array.
 * value: value to search.
 *
 * Return: index or -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size);
	size_t prev = 0;

	if (array == NULL)
	{
		return (-1);
	}

	printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
	while (array[(int)fmin(step, size) - 1] < value)
	{
		prev = step;
		step += sqrt(size);

		if (prev >= size)
		{
			return (-1);
		}
		printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
	}
	printf("Value found between indexes [%ld] and [%ld]\n", prev, step);
	while (array[prev] < value)
	{
		prev++;
		if (prev == fmin(step, size))
		{
			return (-1);
		}
		printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
	}
	if (array[prev] == value)
	{
		return (prev);
	}
	return (-1);
}
