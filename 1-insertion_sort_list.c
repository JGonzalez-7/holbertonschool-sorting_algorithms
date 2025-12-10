#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: double pointer to the head of the list
 *
 * Description: swaps whole nodes (not values) and prints after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current;
		while (temp->prev && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			temp->next->prev = temp;
			if (!temp->prev)
				*list = temp;
			else
				temp->prev->next = temp;
			print_list(*list);
		}
		current = current->next;
	}
}
