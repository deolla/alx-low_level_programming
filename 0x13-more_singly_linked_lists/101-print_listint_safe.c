#include "lists.h"
/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: double pointer.
 *
 * Return: number of nodes.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 1;
	const listint_t *help *pls;

	if (head == NULL || head->next == NULL)
		return (0);

	help = head->next;
	pls = (head->next)->next;
	while (pls)
	{
		if (help == pls)
		{
			help = pls;
			while(help != pls)
			{
				count++;
				help = help->next;
				pls = pls->next;
			}
			help = help->next;
			while(help != pls)
			{
				count++;
				help = help->next;
			}
			return(count);
		}
		help = help-> next;
		pls = (pls->next)->next;
	}
	
	return (0);
}
