#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node
 * Return: 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t leftsize, rightsize;

	if (tree == NULL)
		return (0);

	leftsize = binary_tree_size(tree->left);
	rightsize = binary_tree_size(tree->right);

	return (leftsize + rightsize + 1);
}
