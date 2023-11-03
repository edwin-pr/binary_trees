#include "binary_trees.h"

/**
 * binary_tree_preorder -function to pre-order travesal
 * @tree: the pointer to the root node
 * @func:a pointer to a function to call for each node
 * value of the node must passed a param to this function
 * if tree or func is NULL do nothing
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Root to left subtree then to right subtree*/

	func(tree->n);

	binary_tree_preorder(tree->left, func);

	binary_tree_preorder(tree->right, func);
}
