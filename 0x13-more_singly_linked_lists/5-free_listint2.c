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
	int g;

	if (*head == NULL)
	{
		return;
	}
	if (head == NULL)
	{
		return;
	}

	tem = *head;

	for (g = 0; tem != NULL; g++)
	{
		next = tem->next;
		free(tem);
		tem = next;
	}
	*head = NULL;
}
