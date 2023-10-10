#include "search_algos.h"

/**
 * _binary_search - Searches for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array to search.
 * @left: Index of the left bound of the search range.
 * @right: Index of the right bound of the search range.
 * @value: Value to search.
 *
 * Return: Index where the value is located, or -1 if not found.
 */
int _binary_search(int *array, size_t left, size_t right, int value)
{
	int mid;
	size_t i;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		printf("Searching in array: ");
		for (i = left; i <= right; i++)
		{
			printf("%d", array[i]);
			if (i < right)
				printf(", ");
			else
				printf("\n");
		}
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search.
 * @size: Number of elements in the array.
 * @value: Value to search.
 *
 * Return: Index where the value is located, or -1 if not found.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;

	if (array == NULL || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
		bound / 2, (bound < size) ? bound : size - 1);
	return (_binary_search(array, bound / 2,
			       (bound < size) ? bound : size - 1, value));
}
