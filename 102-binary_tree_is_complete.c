#include "binary_trees.h"

/**
 * binary_tree_size - counts the number of nodes in the binary tree
 * @root: pointer to the root node of the tree
 * Return: Number of nodes in the binary tree
 */

size_t binary_tree_size(const binary_tree_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + binary_tree_size(root->left) + binary_tree_size(root->right));
}

/**
 * is_complete_recursive - Recursive helper function
 * @root: pointer to the root of the node
 * @index: Index of the current node
 * @size: total number of node in the tree
 * Return: 1 if the tree is complete || 0 on failure
 */

int is_complete_recursive(const binary_tree_t *root, size_t index, size_t size)
{
	if (root == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete_recursive(root->left, 2 * index + 1, size) &&
		is_complete_recursive(root->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the node
 * Return: 0 if tree is NULL
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);
	return (is_complete_recursive(tree, 0, size));
}
