#include "sort.h"

/**
 * swap_nodes - swap the nodes themselves.
 * @current: pointer.
 * @current_old: pointer.
 * @list: doubly linked list
 */
void swap_nodes(listint_t **list, listint_t *current, listint_t *current_old)
{
	listint_t *temp1 = current->next;
	listint_t *temp2 = current_old->prev;

	if (temp1 != NULL)
		temp1->prev = current_old;
	if (temp2 != NULL)
		temp2->next = current;
	current->prev = temp2;
	current_old->next = temp1;
	current->next = current_old;
	current_old->prev = current;
	if (*list == current_old)
		*list = current;
	print_list(*list);
}

/**
 * cocktail_sort_list - Cocktail Shaker Sort algorithm for a doubly linked list.
 * @list: doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *check = *list, *first = NULL, *last = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	do {
		while (check->next)
		{
			if (check->n > check->next->n)
				swap_nodes(list, check->next, check);
			else
				check = check->next;
		}
		last = check;
		while (check->prev != first)
		{
			if (check->n < check->prev->n)
				swap_nodes(list, check, check->prev);
			else
				check = check->prev;
		}
		first = check;
	} while (first != last);
}

