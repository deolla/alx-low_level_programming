#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array to search.
 * @size: Number of elements in the array.
 * @value: Value to search.
 *
 * Return: Index where the value is located, or -1 if not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
	return (recursive_advanced_binary(array, 0, size - 1, value));
}

/**
 * recursive_advanced_binary - Searches a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search.
 * @left: Index of the left bound of the search range.
 * @right: Index of the right bound of the search range.
 * @value: Value to search.
 *
 * Return: Index where the value is located, or -1 if not found.
 */
int recursive_advanced_binary(int *array, int low, int high, int value)
{
	int mid, i;

	if (low > high)
		return (-1);

	mid = low + (high - low) / 2;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
		printf("%d, ", array[i]);
	printf("\n");

	if (array[mid] < value)
		return (recursive_advanced_binary(array, mid + 1, high, value));
	else if (array[mid] > value)
		return (recursive_advanced_binary(array, low, mid - 1, value));

	if (mid == 0 || array[mid - 1] != value)
		return (mid);
	else
		return (recursive_advanced_binary(array, low, mid - 1, value));
}
