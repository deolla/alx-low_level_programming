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
	listint_t *m = *h, *next = NULL;

	while (m != NULL)
	{
		i++;
		next = m->next;
		free(m);
		m = next;

		if (m == *h)
		{
			*h = NULL;
			break;
		}
	}

	return (i);
}
