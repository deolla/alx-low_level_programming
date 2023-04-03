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
	int info;

	if (head != NULL)
	{
		return (0);
	}
	else
	{
		tem = *head;
		info = tem->n;
		*head = tem->next;
		free(tem);
	}
	return (info);
}
