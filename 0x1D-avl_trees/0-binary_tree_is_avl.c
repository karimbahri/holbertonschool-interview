#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * binary_tree_is_avl - check if a binary tree is avl
 * @tree: binary tree to check
 * Return: 1 if valid otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_is_avl_recursive(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_is_avl_recursive - recursive sub-function for binary_tree_is_avl
 * @tree: tree to target
 * @min: min
 * @max: max
 * Return: 1 if valid avl otherwise 0
 */
int binary_tree_is_avl_recursive(const binary_tree_t *tree, int min, int max)
{
	int left = 0;
	int right = 0;

	if (!tree)
		return (1);

	right = length_tree(tree->right);
	left = length_tree(tree->left);

	if (left - right > 1 || left - right < -1)
		return (0);

	if (tree->n < min)
		return (0);
	if (tree->n > max)
		return (0);

	return (binary_tree_is_avl_recursive(tree->left, min, tree->n - 1) &&
			binary_tree_is_avl_recursive(tree->right, tree->n + 1, max));
}

/**
 * length_tree - return the length of the tree
 * @tree: tree to target
 * Return: height of the tree
 */
int length_tree(binary_tree_t *tree)
{
	int left = 0;
	int right = 0;
	int length = 0;

	if (tree == NULL)
		return (0);

	left = length_tree(tree->left);
	right = length_tree(tree->right);

	if (left > right)
		length = left + 1;
	else
		length = right + 1;

	return (length);
}
