#include "lists.h"

/**
 * listint_len - returns the number of elements in a
 * linked listint_t list.
 * @h: pointer pointing to the next node.
 *
 * Description: a function that returns the number of
 * elements in a linked listint_t list.
 * Return: number of elements in a linked.
 */
size_t listint_len(const listint_t *h)
{
	size_t y;

	for (y = 0; h != NULL; h = h->next)
	{
		y++;
	}
	return (y);
}
