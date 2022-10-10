#include "sort.h"

/**
 * insertion_sort_list -  sorts a doubly linked
 * list of integers in ascending order using the
 * Insertion sort algorithm
 *
 * @list: list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *save, *next;
	int swap_head = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			if (current->prev == *list)
				swap_head = 1;

			if (swap_head != 1)
				current->prev->prev->next = current;

			if (current->next != NULL)
				current->next->prev = current->prev;
			current->prev->next = current->next;
			current->next = current->prev;

			save = current->prev;
			current->prev = current->prev->prev;

			save->prev = current;

			if (swap_head == 1)
				*list = current;

			swap_head = 0;

			print_list(*list);
		}
		current = next;
	}
}
