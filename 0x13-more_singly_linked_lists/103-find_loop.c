#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: pointer.
 *
 * Return: address of the node or NULL.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *q, *v;

	q = head;
	v = head;

	while (head && q && q->next)
	{
		head = head->next;
		q = q->next->next;

		if(head == q)
		{
			head = v;
			v = q;
			while (1)
			{
				q = v;
				while (q->next != head && q->next != v)
				{
					q = q->next;
				}
				
				if(q->next == head)
					break;

				head = head->next;
			}
			return (q->next)
		}
	}
	return (NULL);
}
