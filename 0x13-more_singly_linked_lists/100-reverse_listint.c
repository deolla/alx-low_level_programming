#include "lists.h"

/**
 * *reverse_listint - reverses a listint_t linked list.
 * @head: double pointer.
 *
 * Description: a function that reverses a listint_t linked list.
 * Return: a pointer to the first node.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *next, *em;
	em = NULL;

	while (*head != NULL)
	{
		next = (*head)->next;
		(*head)->next = em;
		em = *head;
		*head = next;
	}
	return (em);
}
