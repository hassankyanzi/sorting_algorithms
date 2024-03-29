#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: A pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			/* Swap temp and temp->prev */
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;

			if (temp->prev != NULL)
				temp->prev->next = temp;

			if (temp->next != NULL)
				temp->next->prev = temp;

			if (temp->prev == NULL)
				*list = temp;

			/* Print the list after each swap */
			print_list(*list);
		}

		current = current->next;
	}
}

