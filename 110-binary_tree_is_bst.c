#include "binary_trees.h"
#include <limits.h>

/**
 * is_valid_BST - function to perform inorder travesal
 * @node: a pointer to the node
 * @prev: pointer to the int holding traversed value
 * Return: 1 || 0
 */

int is_valid_BST(const binary_tree_t *node, int *prev)
{
	if (node == NULL)
		return (1);

	if (!is_valid_BST(node->left, prev))
		return (0);

	if (*prev >= node->n)
		return (0);

	*prev = node->n;

	return (is_valid_BST(node->right, prev));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a BST
 * @tree: pointer to the root node
 * Return: 1 if valid || 0 if not || 0 if tree is NULL
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev = INT_MIN;

	if (tree == NULL)
		return (0);


	return (is_valid_BST(tree, &prev));
}

