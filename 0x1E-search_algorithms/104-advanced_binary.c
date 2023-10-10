#include "search_algos.h"

/**
 * recursive_advanced_binary - Searches for value in a sorted array of integers
 * @array: Pointer to the first element of the array to search.
 * @left: Index of the left bound of the search range.
 * @right: Index of the right bound of the search range.
 * @value: Value to search.
 *
 * Return: Index where the value is located, or -1 if not found.
 */
int recursive_advanced_binary(int *array, size_t left, size_t right, int value)
{
	size_t mid;
	size_t i;

	if (left > right)
		return (-1);

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
	{
		if (mid == left || array[mid - 1] != value)
			return (mid);
		else
			return (recursive_advanced_binary(array, left, mid, value));
	}
	else if (array[mid] < value)
		return (recursive_advanced_binary(array, mid + 1, right, value));
	else
		return (recursive_advanced_binary(array, left, mid - 1, value));
}

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
	if (array == NULL || size == 0)
		return (-1);

	return (recursive_advanced_binary(array, 0, size - 1, value));
}
