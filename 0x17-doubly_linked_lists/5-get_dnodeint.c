#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 * @head: a pointer pointing to the first nod.
 * @index: the index of the node.
 *
 * Return: the nth node or NULL if the node does not exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int m = 0;

	while (head != NULL && m < index)
	{
		head = head->next;
		m++;
	}

	if (m == index)
	{
		return (head);
	}
	else
		return (NULL);

}
