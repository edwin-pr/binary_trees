#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree
 * @node: A pointer to the node for which to find the uncle
 * Return: A pointer to the uncle node or NULL if no uncle exists
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
	{
		return (NULL);
	}

	/* if given node is root, then there's no uncle */
	if (node->parent == NULL)
	{
		return (NULL);
	}

	/* check if there's a node on the same level as parent */
	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - determine sibling node
 * @node: node to find sibling of
 *
 * Return: pointer to sibling node; NULL on failure
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
