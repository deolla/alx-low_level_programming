#include "lists.h"

/**
 * list_len - returns the number of elements.
 * @h: const list_t.
 *
 * Description: a function that returns the number of elements.
 * Return: number of element.
 */
size_t list_len(const list_t *h)
{
	unsigned int tally = 0;

	for (tally = 0; h != NULL; tally++)
		h = h->next;

	return (tally);
}
