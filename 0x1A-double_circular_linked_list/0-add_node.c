#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

List *add_node_end(List **list, char *str)
{
	List *node = NULL, *posList = *list;

	node = malloc(sizeof(List));

	if (!node)
		return (NULL);

	node->str = strdup(str);
	if (!node->str)
	{
		free(node);
		return (NULL);
	}
	node->next = NULL;

	if (!posList)
	{
		posList = node;
		posList->prev = node;
		posList->next = node;
		*list = posList;
	}
	else
	{
		node->next = posList;
		node->prev = posList->prev;
		node->prev->next = node;
		node->next->prev = node;
	}
	return (node);
}

List *add_node_begin(List **list, char *str)
{
	List *node = NULL, *posList = *list;

	node = malloc(sizeof(List));

	if (!node)
		return (NULL);

	node->str = strdup(str);
	if (!node->str)
	{
		free(node);
		return (NULL);
	}

	if (!posList || !list)
	{
		node->next = node;
		node->prev = node;
	}

	else
	{
		node->next = posList;
		node->prev = posList->prev;
		node->prev->next = node;
		node->next->prev = node;
	}

	*list = node;

	return (node);
}