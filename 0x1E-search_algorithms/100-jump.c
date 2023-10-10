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
	int step, prev = 0, index;;

	if (array == NULL || size == 0)
		return (-1);

	step = (int)sqrt((double)size);
	for (index = 0; index < (int)size; index += step)
	{
		printf("Value checked array[%d] = [%d]\n", index, array[index]);
		if (array[index] == value)
			return (index);

		if (array[index] > value)
		{
			printf("Value found between indexes [%d] and [%d]\n", prev, index);
			for (; prev <= index && prev < (int)size; prev++)
			{
				printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
				if (array[prev] == value)
					return (prev);
			}
			return (-1); 
		}
		prev = index;
	}
	return (-1);
}
