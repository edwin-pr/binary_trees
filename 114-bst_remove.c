#include "binary_trees.h"

/**
 * bst_findMin - finds the minimum value
 * @node: pointer to the node
 * Return: NULL if node is NULL
 */

bst_t *bst_findMin(bst_t *node)
{
	if (node == NULL)
		return (NULL);

	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_remove - removes a node from a BST
 * @root: pointer to the root node of the BST
 * @value: value to remove from the BST
 * Return: pointer to the new root node
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = bst_findMin(root->right);
		root->n = temp->n;

		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
