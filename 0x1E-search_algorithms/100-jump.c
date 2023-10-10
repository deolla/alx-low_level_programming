#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array of integers.
 * @array: pointer to the first element of the array to search.
 * @size: number of elements in array.
 * @value: value to search.
 *
 * Return: index or -1
 */
int jump_search(int *array, size_t size, int value)
{
	int i, step, k, prev;

	if (array == NULL || size == 0)
		return (-1);

	step = (int)sqrt((double)size);
	k = 0;
	prev = i = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", i, array[i]);

		if (array[i] == value)
			return (i);
		k++;
		prev = i;
		i = k * step;
	} while (i < (int)size && array[i] < value);

	printf("Value found between indexes [%d] and [%d]\n", prev, i);

	for (; prev <= i && prev < (int)size; prev++)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
	}

	return (-1);
}
