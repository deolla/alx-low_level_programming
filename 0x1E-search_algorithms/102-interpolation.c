#include "search_algos.h"

/**
 * interpolation_search - earches for a value in a sorted array of integers.
 * @array: pointer to the first element of the array to search.
 * @size: number of elements in array.
 * @value: value to search.
 *
 * Return: -1 or new array.
 */
int interpolation_search(int *array, size_t size, int value)
{
	int low = 0, high = size - 1;
	int index, element;
	size_t pos;

	while (low <= high && value >= array[low] && value <= array[high])
	{
		pos = low + ((double)(high - low) / (array[high] - array[low])) *
				(value - array[low]);
		index = (int)pos;
		element = array[index];
		printf("Value checked array[%ld] = [%d]\n", pos, element);
		if (element < value)
			low = index + 1;
		else if (element > value)
			high = index - 1;
		else
			return (index);
	}
	printf("Value checked array[%ld] is out of range\n", pos);
	return (-1);
}
