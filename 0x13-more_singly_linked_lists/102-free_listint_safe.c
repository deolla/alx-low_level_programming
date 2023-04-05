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
	int b;
	listint_t *m;

	if (!h || !*h)
		return (0);
	while (*h)
	{
		b = *h - (*h)->next;
		if (b > 0)
		{
			m = (*h)->next;
			free(*h);
			*h = m;
			i++;
		}
		else
		{
			free(*h);
			*h = NULL;
			i++;
			break;
		}
	}
	*h = NULL;
	return (i);
}
