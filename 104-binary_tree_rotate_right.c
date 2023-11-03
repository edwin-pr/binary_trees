#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right rotation on a binary tree
 * @tree: the pointer to the root node
 * Return:a pointer to new node
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *newroot, *newrootrightchild, *parent;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	/*storing the ref of the nodes invloved */
	parent = tree;
	newroot = tree->left;
	newrootrightchild = newroot->right;

	/* rotating right */
	parent->left = newrootrightchild;
	if (newrootrightchild != NULL)
		newrootrightchild->parent = parent;

	newroot->right = parent;
	newroot->parent = parent->parent;
	parent->parent = newroot;

	return (newroot);
}
