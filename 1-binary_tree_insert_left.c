#include "binary_trees.h"

/**
 * binary_tree_insert_left -function inserts left child
 * @parent: the pointer to the node to insert the left child
 * @value: value to store in the left child
 * Return: pointer to the left child || NULL on failure or parent is NULL
 * replace with new node and set, if parent already has a left child
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *leftchild;

	if (parent == NULL)
		return (NULL);

	leftchild = malloc(sizeof(binary_tree_t));

	if (leftchild == NULL)
		return (NULL);

	leftchild->parent = parent;
	leftchild->n = value;
	/*replacing old left child if it was already there*/
	leftchild->left = parent->left;
	leftchild->right = NULL;
	/*point left child of parent to new left child*/
	parent->left = leftchild;

	/*set old left child as new left child if was alreay there*/
	if (leftchild->left)
	{
		leftchild->left->parent = leftchild;
	}

	return (leftchild);
}
