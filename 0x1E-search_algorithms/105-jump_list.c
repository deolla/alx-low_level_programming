#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list of integers.
 * @list: Pointer to the head of the list to search in.
 * @size: Number of nodes in the list.
 * @value: Value to search.
 *
 * Return: Pointer to the first node where the value is located, or NULL.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, cur = 0, index = 0;
	listint_t *prev = NULL;

	if (list == NULL || size == 0)
		return (NULL);

	step = (size_t)sqrt((double)size);
	do {
		prev = list;
		cur++;
		index = cur * step;

		while (list->next && list->index < index)
			list = list->next;

		if (list->next == NULL && index != list->index)
			index = list->index;

		printf("Value checked at index [%d] = [%d]\n", (int)index, list->n);

	} while (index < size && list->next && list->n < value);

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)prev->index, (int)list->index);

	for (; prev && prev->index <= list->index; prev = prev->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)prev->index, prev->n);
		if (prev->n == value)
			return (prev);
	}
	return (NULL);
}
