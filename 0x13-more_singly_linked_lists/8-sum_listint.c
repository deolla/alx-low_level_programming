#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n).
 * @head: a pointer.
 *
 * Description: a function that returns the sum of all
 * the data (n) of a listint_t linked list.
 * Return: sum of all the data (n).
 */
int sum_listint(listint_t *head)
{
	int v = 0;

	if (head == NULL)
	{
		return (0);
	}

	while (head != NULL)
	{
		v += head->n;
		head = head->next;
	}

	return (v);
}
