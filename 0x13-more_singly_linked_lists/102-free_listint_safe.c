#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list.
 * @h: double pointer.
 *
 * Return:  size of the list.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t i = 0;
	listint_t *m, *next;

	if (h == NULL || *h == NULL)
		return (0);

	m = *h;
	*h = NULL;

	while (m != NULL)
	{
		next = m->next;
		free(m);
		i++;

		if (next >= m)
			break;
		current = next;
	}

	return (i);
}
