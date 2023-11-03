#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node
 * A NULL pointer is not a leaf
 * Return: 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leftleaves, rightleaves;

	if (tree == NULL)
		return (0);

	/* nodes that have no children are called leaves */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* recursively count the leaves */
	leftleaves = binary_tree_leaves(tree->left);
	rightleaves = binary_tree_leaves(tree->right);

	return (leftleaves + rightleaves);
}
