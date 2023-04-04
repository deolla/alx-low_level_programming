#include "lists.h"

/**
 * delete_nodeint_at_index -  deletes the node at index.
 * @head: double pointer.
 * @index: index of node.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *m, *o;
	unsigned int q;

	if (*head == NULL)
		return (-1);

	m = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		free(m);
		return (1);
	}

	o = NULL;

	for (q = 0; q < index; q++)
	{
		if (m == NULL)
			return (-1);

		o  = m;
		m = m->next;
	}

	if (m == NULL)
		return (-1);

	o->next = m->next;
	free(m);

	return (1);
}
