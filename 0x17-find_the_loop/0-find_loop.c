#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * find_listint_loop - detect loop in linked list
 * @head: list to check
 * Return: reference of the first node if true otherwise NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	if (!slow || !slow->next || !slow->next->next)
		return (NULL);

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			return (slow);
	}

	return (NULL);
}
