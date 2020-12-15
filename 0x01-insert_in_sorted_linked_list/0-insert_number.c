#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert node in sorted linked list
 * @head: pointer refer to the head of the list
 * @number: value to insert
 * Return: address of the new node otherwise NULL
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node, *new = NULL, *tmp = NULL;

	if (!head)
		return (NULL);

	node = *head;
	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (!*head || node->n > number)
	{
		tmp = node;
		node = new;
		new->next = tmp;
		*head = new;
		return (new);
	}
	while (node->next)
	{
		if (node->next->n > number)
		{
			tmp = node->next;
			node->next = new;
			new->next = tmp;
			return (new);
		}
		node = node->next;
	}
	node->next = new;
	return (node);
}
