#include "binary_trees.h"
#include <limits.h>

/**
 * height - height of a tree
 * @tree: tree
 *
 * Return: height of the tree
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = height(tree->left);
	right_height = height(tree->right);

	return (1 + ((left_height > right_height) ? left_height : right_height));
}

/**
 * is_bst - checks if a binary tree is a BST
 * @tree: pointer to the root node
 * @prev: pointer to the int holding traversed value
 * Return: 1 if valid BST, 0 if not, 0 if tree is NULL
 */
int is_bst(const binary_tree_t *tree, int *prev)
{
	if (tree == NULL)
		return (1);
	if (!is_bst(tree->left, prev))
		return (0);
	if (*prev >= tree->n)
		return (0);

	*prev = tree->n;

	return (is_bst(tree->right, prev));
}

/**
 * binary_tree_is_avl - checks if a BT is an AVL tree
 * @tree: pointer to the root node
 * Return: 1 if tree is valid AVL, 0 on failure
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int leftheight, rightheight, balancefactor;
	int prev = INT_MIN;

	if (tree == NULL)
		return (0);

	if (!is_bst(tree, &prev))
		return (0);

	leftheight = height(tree->left);
	rightheight = height(tree->right);
	balancefactor = leftheight - rightheight;

	return ((balancefactor >= -1 && balancefactor <= 1) &&
		binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
