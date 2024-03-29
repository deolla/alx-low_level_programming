#include "lists.h"

/**
 * sum_dlistint - sum of all the data (n) of a dlistint_t linked list.
 * @head: a pointer pointing to the first node.
 *
 * Return: the sum of all the data (n) or 0 if the list is empty.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head == NULL)
	{
		return (0);
	}

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
