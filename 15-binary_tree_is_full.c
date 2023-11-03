#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node
 *
 * full means a node has either zero or two children
 *
 * Return: 0 if tree is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* node has no children */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* if node has two children continue checking recursively */
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) &&
				binary_tree_is_full(tree->right));

	/* if node has only one child it's not full */
	return (0);
}
