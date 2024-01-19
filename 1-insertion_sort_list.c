#include "sort.h"

/**
 * insertion_sort_list - Sorts a linked list of integers
 *
 * @list: Pointer to the head node of the linked list
 * Return: Nothing
 * Description: Each element is compared to every other element
 * preceeding it in the linked list and is placed in the right
 * position. While this is done iteratively, a sorted list grows
 * from the left
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i;
	listint_t *j;
	listint_t *temp;

	i = (*list)->next;
	while (i)
	{
		j = i;
		while ((j && j->prev) && j->prev->n > j->n)
		{
			temp = i->prev;
			temp->next = i->next;
			if (i->next)
				i->next->prev = temp;
			i->next = temp;
			i->prev = temp->prev;
			if (temp->prev)
				temp->prev->next = i;
			temp->prev = i;
			/* Find the first node in the list */
			while (i->prev)
				i = i->prev;
			*list = i;
			print_list(*list);
			j = j->prev;
		}
		i = i->next;
	}
}
