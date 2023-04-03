#include "lists.h"

/**
 * free_listint2 - frees a listint_t list.
 * @head: a pointer to the node.
 *
 * Return: no return
 */
void free_listint2(listint_t **head)
{
	listint_t *tem, *next;

	if (head == NULL || *head == NULL)
	{
		return;
	}
	if (head == NULL)
	{
		return;
	}

	tem = *head;

	while (tem != NULL)
	{
		next = tem->next;
		free(tem);
		tem = next;
	}
	*head = NULL;
}
