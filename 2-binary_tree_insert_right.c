#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: A pointer to the node to insert the right-child in
 * @value: The value to store in the new node
 * Return: A pointer to the created node,NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	/* declare pointer to right child */
	binary_tree_t *right_child = NULL;

	/* if there's no parent */
	if (parent == NULL)
		return (NULL);

	/* allocate memory for right child but if fail, return NULL */
	right_child = malloc(sizeof(binary_tree_t));
	if (right_child == NULL)
		return (NULL);

	/* assign values to right child */
	right_child->n = value;
	right_child->left = NULL;
	right_child->right = NULL;
	right_child->parent = parent;

	/* if there's already a right child */
	if (parent->right != NULL)
	{
		right_child->right = parent->right;
		(parent->right)->parent = right_child;
	}
	parent->right = right_child;
	return (right_child);
}
