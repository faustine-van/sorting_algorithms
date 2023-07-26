#include "sort.h"


/**
 * sort_insert - Sorting an linked lists of integers INSERTION SORT
 *
 * @list: pointer point to be head of list usorted
 * @new_node: pointer point to be new of list sorted
 *
 * Return: nothing
 */
void sort_insert(listint_t **list, listint_t *new_node)
{
	listint_t *current;

	if (*list == NULL)
	{
		*list = new_node;
		return;
	}
	else if ((*list)->n >= new_node->n)
	{
		new_node->next = *list;
		new_node->next->prev = new_node;
		*list = new_node;
		return;
	}
	else
	{
		current = *list;
		while (current->next != NULL && current->next->n < new_node->n)
			current = current->next;

		new_node->next = current->next;

		if (current->next != NULL)
			new_node->next->prev = new_node;

		current->next = new_node;
		new_node->prev = current;
	}

}
/**
 * insertion_sort_list - Sorting an linked lists of integers INSERTION SORT
 *
 * @list: pointer point to be head of list usorted
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *sorted = NULL;

	if (list == NULL  || *list == NULL)
		return;

	current = *list;
	while (current != NULL)
	{
		next = current->next;
		current->prev = current->next = NULL;

		sort_insert(&sorted, current);

		if (sorted->prev == NULL)
			*list = sorted;
		current = next;
		print_list(*list);

	}
}
