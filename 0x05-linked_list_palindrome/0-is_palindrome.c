#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - check if a list is palindrome
 * @head: head of the list
 * Return: 1 if true else 0
 */
int is_palindrome(listint_t **head)
{
	listint_t node;
	listint_t *tail = *head, *before_head;

	node.next = *head;
	before_head = &node;

	return (is_list_palindrome(&before_head, tail));
}

/**
 * is_list_palindrome - check if list is palindrome
 * @first: head of the list
 * @last: tail of the list
 * Return: 1 if true 0 otherwise
 */
int is_list_palindrome(listint_t **first, listint_t *last)
{
	int result;

	if (!last)
		return (1);
	result = is_list_palindrome(first, last->next);

	if (!result)
		return (0);

	*first = (*first)->next;
	if (last->n == (*first)->n)
		return (1);
	return (0);
}
