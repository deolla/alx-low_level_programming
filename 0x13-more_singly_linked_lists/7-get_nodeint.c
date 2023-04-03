#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of
 * a listint_t linked list.
 * @head: pointer.
 * @index: index of the node.
 *
 * Return: nth node.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int z = 0;

	while (head != NULL && z < index)
	{
		head = head->next;
		z++;
	}

	if (z == index && head != NULL)
	{
		return (head);
	}

	return (NULL);
}
