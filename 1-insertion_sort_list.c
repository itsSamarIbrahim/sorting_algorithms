#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *prev_prev, *curr_next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		prev = curr->prev;
		while (prev != NULL && prev->n > curr->n)
		{
			prev_prev = prev->prev;
			curr_next = curr->next;

			if (prev_prev != NULL)
				prev_prev->next = curr;
			else
				*list = curr;

			curr->prev = prev_prev;
			curr->next = prev;
			prev->prev = curr;
			prev->next = curr_next;

			if (curr_next != NULL)
				curr_next->prev = prev;

			print_list(*list);

			prev = curr->prev;
		}
		curr = curr->next;
	}
}
