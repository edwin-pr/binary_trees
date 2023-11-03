#include "binary_trees.h"

/**
 * binary_tree_insert_right - it inserts right child
 * @parent: pointer to the node to insert right-child in
 * @value: value to store the new node
 * Return: pointer to right child || NULL on failure || parent is NULL
 * If parent already has a right-child, the new node must take its place
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *rightchild;

	if (parent == NULL)
		return (NULL);

	rightchild = malloc(sizeof(binary_tree_t));

	if (rightchild == NULL)
		return (NULL);

	rightchild->parent = parent;
	rightchild->n = value;
	rightchild->left = NULL;
	rightchild->right = parent->right;

	parent->right = rightchild;

	if (rightchild->right)
	{
		rightchild->right->parent = rightchild;
	}

	return (rightchild);
}
