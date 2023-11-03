#include "binary_trees.h"

size_t _max(size_t a, size_t b);

/**
 * binary_tree_is_perfect - check if a binary tree is perfect
 * @tree: tree
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int r = 1;

	if (!tree || binary_tree_balance(tree) != 0)
		return (0);
	if (tree->left)
		r = r & binary_tree_is_perfect(tree->left);
	if (tree->right)
		r = r & binary_tree_is_perfect(tree->right);
	return (r);
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: tree
 *
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	binary_tree_t *tempChild = NULL, *tempTree = (binary_tree_t *) tree;
	int lh = 0, rh = 0;

	if (!tree)
		return (0);
	tempChild = tempTree->right;
	tempTree->right = NULL;
	lh = (int) binary_tree_height(tempTree);
	tempTree->right = tempChild;
	tempChild = tempTree->left;
	tempTree->left = NULL;
	rh = (int) binary_tree_height(tempTree);
	tempTree->left = tempChild;
	return (lh - rh);
}
/**
 * binary_tree_height - height of a tree
 * @tree: tree
 *
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree && (tree->left || tree->right))
		return (1 + _max(binary_tree_height(tree->left),
					binary_tree_height(tree->right)));
	return (0);
}
/**
 * _max - find max of two number
 * @a: number
 * @b: number
 *
 * Return: max of two number
 */
size_t _max(size_t a, size_t b)
{
	return (a > b ? a : b);
}
