#include "binary_trees.h"
size_t recurse_for_height(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
void recurse_for_levelorder(const binary_tree_t *tree,
	void (*func)(int), size_t level);
/**
 * binary_tree_levelorder - traverse tree by level
 * @tree: tree to traverse
 * @func: function pointer
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level = 0;

	if (!tree || !func)
		return;

	/* retrieve height */
	height = binary_tree_height(tree);

	while (level <= height)
	{
		recurse_for_levelorder(tree, func, level);
		level++;
	}
}
void recurse_for_levelorder(const binary_tree_t *tree,
	void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;

	if (level == 0)
		func(tree->n);

	recurse_for_levelorder(tree->left, func, level - 1);
	recurse_for_levelorder(tree->right, func, level - 1);
}
/**
 * binary_tree_height - measure height of tree
 * @tree: tree to measure
 *
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	return (recurse_for_height(tree) - 1);
}
/**
 * recurse_for_height - measure height
 * @tree: tree to measure
 *
 * Return: height
 */
size_t recurse_for_height(const binary_tree_t *tree)
{
	size_t heightR, heightL;

	if (!tree)
		return (0);

	heightL = recurse_for_height(tree->left);
	heightR = recurse_for_height(tree->right);

	if (heightL > heightR)
		return (heightL + 1);
	else
		return (heightR + 1);
}
