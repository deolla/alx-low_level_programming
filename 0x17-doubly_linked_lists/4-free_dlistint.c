#include "lists.h"

/**
 * free_dlistint -  frees a dlistint_t list.
 * @head: a pointer to the first node.
 *
 * Return: void.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *list = head;
	dlistint_t *next;

	while (list != NULL)
	{
		next = list->next;
		free(list);
		list = next;
	}
}
