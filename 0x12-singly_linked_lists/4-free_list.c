#include "lists.h"

/**
 * free_list - frees a list_t list.
 * @head: link list.
 *
 * Description: a function that frees a list_t list.
 * Return: no return.
 */
void free_list(list_t *head)
{
	if (head != NULL)
	{
		free(head->str);
		free_list(head->next);
	}
	free(head);
}
