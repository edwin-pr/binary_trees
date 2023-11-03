#include "binary_trees.h"

/**
 * bst_insert -function to inserts a value in a BST
 * @tree: double pointer to the root node
 * @value: value to store in the node to be inserted
 * If the address stored in tree is NULL,
 * the created node must become the root node.
 * Return: pointer to the created node || NULL on failure
 */


bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *tree_2;

	if (tree == NULL || *tree == NULL)
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
		return (new);
	}

	tree_2 = *tree;

	while (tree_2 != NULL)
	{
		if (tree_2->n == value)
			return (NULL);
		if (tree_2->n > value)
		{
			if (tree_2->left == NULL)
			{
				tree_2->left = binary_tree_node(tree_2, value);
				return (tree_2->left);
			}
			tree_2 = tree_2->left;
		}
		if (tree_2->n < value)
		{
			if (tree_2->right == NULL)
			{
				tree_2->right = binary_tree_node(tree_2, value);
				return (tree_2->right);
			}
			tree_2 = tree_2->right;
		}
	}
	return (NULL);
}
