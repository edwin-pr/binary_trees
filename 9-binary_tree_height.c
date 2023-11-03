#include "binary_trees.h"

/**
 * binary_tree_height -func measures the height of a binary tree
 * @tree: pointer to the root node
 * Return: 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftheight = 0;
	size_t rightheight = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		leftheight += 1 + binary_tree_height(tree->left);

	if (tree->right)
		rightheight += 1 + binary_tree_height(tree->right);

	if (leftheight > rightheight)
		return (leftheight);
	else
		return (rightheight);
}
