#include "binary_trees.h"

/**
 * binary_tree_node -function creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: Value to put in the new node
 * Return: ponter to the new node || NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	/* allocate memory to the root node */
	newnode = malloc(sizeof(binary_tree_t));

	/* check if mem allocation was a success */
	if (newnode == NULL)
		return (NULL);

	/* node with value but no children */
	newnode->parent = parent;
	newnode->n = value;
	newnode->left = NULL;
	newnode->right = NULL;

	return (newnode);
}
