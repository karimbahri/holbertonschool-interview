#include "search.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * linear_skip - search inside skipList
 * @list: list to target
 * @value: searched value
 * Return: element reference on success otherwise NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *n = list, *t, *l;

	if (!list)
		return (NULL);
	while (n->express && n->n < value)
	{
		t = n;
		n = n->express;

		printf("Value checked at index [%d] = [%d]\n", (int)n->index, n->n);
	}
	if (n->n >= value)
	{
		printf("Value found between indexes [%ld] and [%ld]\n", t->index, n->index);
		while (t != n->next)
		{
			printf("Value checked at index [%d] = [%d]\n", (int)t->index, t->n);
			if (t->n == value)
				return (t);
			t = t->next;
		}
	}
	else
	{
		l = n;
		while (l->next)
			l = l->next;
		printf("Value found between indexes [%ld] and [%ld]\n", n->index, l->index);
		while (n)
		{
			printf("Value checked at index [%d] = [%d]\n", (int)n->index, n->n);
			if (n->n == value)
				return (n);
			n = n->next;
		}
	}
	return (NULL);
}
