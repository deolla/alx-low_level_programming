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
	if (array == NULL || size == 0)
		return (-1);

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
int recursive_advanced_binary(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (mid = left; mid < right; mid++)
		printf("%d, ", array[mid]);
	printf("%d\n", array[mid]);

	mid = left + (right - left) / 2;
	if (array[mid] == value && (mid == left || array[mid - 1] != value))
		return (mid);
	if (array[mid] >= value)
		return (recursive_advanced_binary(array, left, mid, value));
	return (recursive_advanced_binary(array, mid + 1, right, value));
}
