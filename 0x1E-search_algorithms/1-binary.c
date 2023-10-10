#include "search_algos.h"

/**
 * binary_search - searches for a value in a sorted array of integers.
 * @array: pointer to the first element of the array to search.
 * @size: number of elements in array.
 * @value: value to search.
 *
 * Return: return -1 or index.
 */
int binary_search(int *array, size_t size, int value)
{
	int left = 0, right = size - 1, mid, i;

	if (array == NULL)
	{
		return (-1);
	}

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		printf("Searching in array: ");
		for (i = left; i <= right; i++)
		{
			if (i == right)
			{
				printf("%d\n", array[i]);
			}
			else
			{
				printf("%d, ", array[i]);
			}
		}

		if (array[mid] == value)
		{
			return (mid);
		}
		if (array[mid] < value)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return(-1);
}
