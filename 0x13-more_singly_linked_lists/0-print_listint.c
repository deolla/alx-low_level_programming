#include "lists.h"

/**
 * print_listint -  prints all the elements of a listint_t list.
 * @h: pointer pointing to the list.
 *
 * Description: a function that prints all the
 * elements of a listint_t list.
 * Return: the number of nodes.
 */
size_t print_listint(const listint_t *h)
{
	unsigned int y;

	for (y = 0; h != NULL; h = h->next, y++)
		printf("%d\n", h->n);
	return (y);
}
