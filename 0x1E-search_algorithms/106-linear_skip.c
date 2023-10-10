#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list to search in.
 * @value: Value to search.
 *
 * Return: Pointer to the first node where the value is located, or NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *cur, *express;

	if (list == NULL)
		return (NULL);

	for (cur = express = list; express->next != NULL && express->n < value;)
	{
		cur = express;
		if (express->express != NULL)
		{
			express = express->express;
			printf("Value checked at index [%ld] = [%d]\n",
					express->index, express->n);
		}
		else
		{
			while (express->next != NULL)
				express = express->next;
		}
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
			cur->index, express->index);

	for (; cur->index < express->index && cur->n < value; cur = cur->next)
		printf("Value checked at index [%ld] = [%d]\n", cur->index, cur->n);
	printf("Value checked at index [%ld] = [%d]\n", cur->index, cur->n);

	return (cur->n == value ? cur : NULL);
}
