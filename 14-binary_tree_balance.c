#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node
 * Return: 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t leftheight, rightheight;

	if (tree == NULL)
		return (0);

	leftheight = binary_tree_height(tree->left);
	rightheight = binary_tree_height(tree->right);

	return (leftheight - rightheight);
}

/**
 * binary_tree_height - calculate height of a binary tree
 * @tree: pointer to the root node
 * Return: 0 on failure || height of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftheight = 0;
	size_t rightheight = 0;

	if (tree == NULL)
		return (0);

	leftheight += 1 + binary_tree_height(tree->left);
	rightheight += 1 + binary_tree_height(tree->right);

	if (leftheight > rightheight)
		return (leftheight);
	else
		return (rightheight);
}
