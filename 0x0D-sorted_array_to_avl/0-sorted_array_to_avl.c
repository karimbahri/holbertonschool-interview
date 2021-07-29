#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - convert sorted array to tree
 * @array: array to convert
 * @size: size of the array
 * Return: AVL Tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
		if (!array)
			return (NULL);
		return (convertToAVL(array, NULL, 0, size - 1));
}

/**
 * convertToAVL - recursive function to convert array to avl tree
 * @array: array to convert
 * @parent: root of the node
 * @beg: start array
 * @end: array breakpoint
 * Return: AVL tree
 */
avl_t *convertToAVL(int *array, avl_t *parent, int beg, int end)
{
	avl_t *node = NULL;
	int middle = (beg + end) / 2;


	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	if (beg <= end)
	{
		node->n = array[middle];
		node->parent = parent;
		if (middle > beg)
			node->left = convertToAVL(array, node, beg, middle - 1);
		if (middle < end)
			node->right = convertToAVL(array, node, middle + 1, end);
		return (node);
	}
	return (NULL);
}
