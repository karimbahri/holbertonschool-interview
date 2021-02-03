#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - detect loop in linked list
 * @list: list to check
 * Return: 1 if loop detected 0 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = list, *fast = list;

	if (!slow)
		return (0);

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			return (1);
	}

	return (0);
}
