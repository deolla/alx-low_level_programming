#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list.
 * @head: a double pointer.
 *
 * Return: head node’s data.
 */
int pop_listint(listint_t **head)
{
	listint_t *tem;
	int n;

	if (head != NULL)
	{
		return (0);
	}
	
	n = (*head)->n;
	tem = *head;
	*head = (*head)->next;
	free(tem);


	return (n);
}
