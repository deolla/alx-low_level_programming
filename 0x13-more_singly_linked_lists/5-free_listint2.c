#include "lists.h"

/**
 * free_listint2 - frees a listint_t list.
 * @head: a pointer to the node.
 *
 * Return: no return
 */
void free_listint2(listint_t **head)
{
	listint_t *tem, *pop;
	int g;

	if (*head == NULL || head == NULL)
	{
		return;
	}

	tem = *head;

	for (g = 0; tem != NULL; g++)
	{
		pop = tem->next;
		free(tem);
		tem = pop;
	}
	*head = NULL;
}
