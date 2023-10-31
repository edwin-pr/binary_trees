#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree
 * @node: A pointer to the node for which to find the sibling
 * Return: A pointer to the sibling node or NULL if no sibling exists
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* determine if node is left or right child */
	if (node == node->parent->left)
	{
		return (node->parent->right);
	}
	else
		return (node->parent->left);
}
